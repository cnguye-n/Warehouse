#include "warehouse.h"
#include <string>
#include <iomanip>

/******************************************************************************
 * Pre-Conditions:
 *  n/a
 *
 * Post-Conditions:
 *  vector of member objects are set in the container
 *
******************************************************************************/
Warehouse::Warehouse()
{
}
/******************************************************************************
 * Pre-Conditions:
 *  .txt file w/ shoppers is found within build folder of this project
 *
 * Post-Conditions:
 *  the container vector is filled with valid members
 *
******************************************************************************/
void Warehouse::updateMemberList()
{
    //string filename;
    string take;
    fstream fin;

    //cin >> filename;
    fin.open("warehouse shoppers.txt");

    if(fin.fail())
    {
        cout << "cannot find the file.\n";
        exit(1);
    }

    string name;
    string id;
    string type;
    Date date;
    while(getline(fin,name)) //first line --name
    {
        getline(fin,id); //second line -- id
        getline(fin,type); //third line -- type
        fin>>date; //forth line -- date
        Members m(name,id,type,date);
        addMember(m);
        getline(fin, take); // used for extra empty line created by >>
     }

    fin.close();
}
/******************************************************************************
 * Pre-Conditions:
 *  day .txt files found in build folder of project
 *
 * Post-Conditions:
 *  purchases made by members kept in linked lists organized by either
 * days bought or products bought
 *
******************************************************************************/
void Warehouse::updateSalesDays()
{
    string skip;
    fstream fin;
    string filenames[]={"day1.txt","day2.txt","day3.txt","day4.txt","day5.txt"};
    for (int i=0; i<5;i++)
    {
        fin.open(filenames[i]);
        if(fin.fail())
        {
            cout << "cannot open file.\n";
            exit(1);
        }
        Date date;
        string id;
        string productName;
        double price;
        size_t numberPurchased;

        while (fin >> date) //first line - date
        {
            getline(fin, skip);
            getline(fin,id); //second line - id
            getline(fin,productName); //third line - name
            fin >> price ; //forth line -- price and number of purchased
            fin >> numberPurchased;
            Product p(productName,price,numberPurchased);
            getline(fin, skip); // error line skip over

            //idk if there is a search function for member this is O(n)
            for (size_t i=0; i< wholesale_club.size();i++)
            {
                if(wholesale_club[i].id() == id)
                {
                    Item a;
                    a.set_date(date);
                    a.add(p);
                    //if the date exists, update by "merging" info
                    //if not, we add the item to the list
                    wholesale_club[i].information().set_history(a);
                    //push the product.
                    wholesale_club[i].information().set_unique(p);
                    break;
                }
            }

        }
        fin.close();
    }
}
/******************************************************************************
 * Pre-Conditions:
 *  member object to be placed into vector container
 *
 * Post-Conditions:
 *  member placed into vector container
 *
******************************************************************************/
bool Warehouse::addMember(Members &add_this)
{
    // check if member is already in container
    for (size_t i = 0; i < wholesale_club.size(); i++)
    {
        if (wholesale_club[i] == add_this)
            return false;
    }

    vector<Members>::iterator it;
    it = wholesale_club.begin();

    // insertion based on ID number (lowest to highest)
    for (int i = 0; i < wholesale_club.size(); i++)
    {
        if (stoi(wholesale_club[i].id()) > stoi(add_this.id()))
        {
            it += i;
            wholesale_club.insert(it, add_this);
            return true;
        }
    }

    // used when ID is highest for adding member
    wholesale_club.push_back(add_this);

    return true;
}
/******************************************************************************
 * Pre-Conditions:
 *  name or ID string for search, and bool to determine if name of ID
 *
 * Post-Conditions:
 *  a bool determining if member was successfully removed or not
 *
******************************************************************************/
bool Warehouse::removeMember(string nameID, bool nameOrID)
{
    // ID
    if (nameOrID == true)
    {
        for (size_t i = 0; i < wholesale_club.size(); i++)
        {
            if (wholesale_club[i].id() == nameID)
            {
                // vector iterator erases member
                vector<Members>::iterator it = wholesale_club.begin();
                it += i;
                wholesale_club.erase(it);
                return true;
            }
        }

        return false;
    }
    // NAME
    else if (nameOrID == false)
    {
        for (size_t i = 0; i < wholesale_club.size(); i++)
        {
            if (wholesale_club[i].name() == nameID)
            {
                // vector iterator erases member
                vector<Members>::iterator it = wholesale_club.begin();
                it += i;
                wholesale_club.erase(it);
                return true;
            }
        }

        return false;
    }
}

string Warehouse::MemberRebates()
{
    stringstream s;
    string take;

    s << "REBATES (PREFERRED MEMBERS ONLY):" << endl << endl;

    for(size_t i=0; i<wholesale_club.size(); i++)
    {
        if(wholesale_club[i].type()==PREFERRED)
        {
            s << wholesale_club[i].name() << "     \t(ID: "
              << wholesale_club[i].id() << ")     \t$"
              << setprecision(2) << fixed << wholesale_club[i].rebate_amount() << endl;
        }
    }

    take = s.str();
    return take;
}

string Warehouse::itemsSold(string item_name)
{
    stringstream s;
    Product total(item_name, 0.0, 0);
    Product hold;

    for (int i = 0; i < wholesale_club.size(); i++)
    {
        hold = wholesale_club[i].information().getThatProduct(item_name);

        if (hold != Product())
        {
            total.count += hold.count;
            total.price = hold.price;
        }
    }

    if (total.count == 0)
    {
        s << "Item was not listed as a purchase by any of the members.\n";
        return s.str();
    }
    else
    {
        s << "ITEM SOLD:" << endl << endl;
        s << "Item Name: " << item_name << endl;
        s << "Amount Sold: " << total.count << endl;
        s << "Total Sales Price: $" << (total.price * total.count) << endl;
        return s.str();
    }
}
string Warehouse::totalItemsSold()
{
    stringstream s;

       History temp1;

       for(size_t i=0; i < wholesale_club.size(); i++)
       {
           for(size_t j=0; j < wholesale_club[i].UniqueSize(); j++)
           {
               temp1.set_unique(wholesale_club[i].GetProductat(j));
           }
       }

       //now we print the Item temp object
       for(int k=0; k < temp1.Unique_size(); k++)
       {
           s<<"Name: " <<temp1.print_name(k) << setw(10) << right;
           s<<"Count: " << temp1.Return_count(k)<<endl;
       }

       return s.str();
}

string Warehouse::dailySalesReport(Date d)
{
    stringstream s;
    int b = 0;
    int p = 0;
    double total_revenue = 0.0;

    s << "DAY SALES REPORT:" << endl << endl;
    s << "Date: " << d << endl << endl;

    s << "Shopper List:" << endl;

    for (size_t i = 0; i < wholesale_club.size(); i++)
    {
        if (!wholesale_club[i].information().dateIsUnique(d))
        {
            if (wholesale_club[i].type() == BASIC)
                b++;
            else if (wholesale_club[i].type() == PREFERRED)
                p++;

            Node<Item>* walk = wholesale_club[i].information().history().ReturnHead();

            while (walk->_item.get_date() != d && walk != nullptr)
                walk = walk->next;

            if (walk != nullptr)
            {
                s << wholesale_club[i].name() << endl;
                total_revenue += walk->_item.get_TaxedSpent();
                s << walk->_item.print_stats_stream() << endl << endl;
            }
        }
    }
    s << "Total Revenue: $" << total_revenue << endl;
    s << "Number of Basic Members: " << b << endl;
    s << "Number of Preferred Members: " << p << endl;

    return s.str();
}
string Warehouse::yearlySalesReport()
{
    stringstream s;
        double total_revenue = 0.0;
        History temp;
        s << "YEARLY SALE REPORT: " << endl << endl;
        s << "List of items: " <<endl;
        for (size_t i=0; i<wholesale_club.size();i++)
        {
            //put all items to the temp history list
            for(size_t j=0; j < wholesale_club[i].UniqueSize(); j++)
            {
                temp.set_unique(wholesale_club[i].GetProductat(j));
            }
            //get the total revenue from all members
            Node<Item>* walker = wholesale_club[i].information().history().ReturnHead();
            for(;walker!=nullptr;walker=walker->next)
            {
                total_revenue+=walker->_item.get_TaxedSpent();
            }
        }
        for(int k=0; k < temp.Unique_size(); k++)
        {
            s<<"Name: " <<temp.print_name(k)<<" ";
            s<<"Count: " << temp.Return_count(k)<<endl;
        }
        s << endl;
        s << "Total Revenue: $" << total_revenue << endl ;

        //bubble sort the temp history
        Node<Product>* curr = temp.unique().ReturnHead();
        for (size_t i = temp.Unique_size(); i>1 ; i--)
        {
            Node<Product>* temp1, *swap1;
            swap1 = temp.unique().ReturnHead();
            for(size_t j=0; j < temp.Unique_size() -1 ; j++)
            {
                if(swap1->_item.count > swap1->next->_item.count)
                {
                    Node<Product>* swap2 = swap1->next;
                    swap1->next = swap2->next;
                    swap2->next = swap1;
                    if (swap1 == temp.unique().ReturnHead())
                    {
                        temp.unique().ReturnHead() = swap2;
                        swap1 = swap2;
                    }
                    else
                    {
                        swap1 = swap2;
                        temp1->next = swap2;
                    }
                    temp1 = swap1;
                    swap1 = swap1->next;
                }
            }
        }


        /*
        void Sort()
    {
        node* curr = HEAD;
        int count = 0;
        while(curr!=NULL)
        {
            count++;
            curr = curr->NEXT;
        }
        for(int i = count ; i > 1 ; i-- )
        {
            node *temp, *swap1;
            swap1 = HEAD;
            for(int j = 0 ; j < count-1 ; j++ )
            {
                if(swap1->DATA > swap1->NEXT->DATA)
                {
                    node *swap2 = swap1->NEXT;
                    swap1->NEXT = swap2->NEXT;
                    swap2->NEXT = swap1;
                    if(swap1 == HEAD)
                    {
                        HEAD = swap2;
                        swap1 = swap2;
                    }
                    else
                    {
                        swap1 = swap2;
                        temp->NEXT = swap2;
                    }
                }
                temp = swap1;
                swap1 = swap1->NEXT;
            }
        }
    }
        */
    /*
    void Sort()
    {
        node * list_end = NULL;
        while(list_end != HEAD)  // this also takes care of the HEAD == NULL case, which you forgot!
        {
            node *temp, *swap1;
            swap1 = HEAD;
            while( swap1->NEXT != list_end )
            {
                if(swap1->DATA > swap1->NEXT->DATA)
                {
                    node *swap2 = swap1->NEXT;
                    swap1->NEXT = swap2->NEXT;
                    swap2->NEXT = swap1;
                    if(swap1 == HEAD)
                    {
                        HEAD = swap2;
                        swap1 = swap2;
                    }
                    else
                    {
                        swap1 = swap2;
                        temp->NEXT = swap2;
                    }
                }
                temp = swap1;
                swap1 = swap1->NEXT;
            }
            // update the list_end to the last sorted element:
            list_end = swap1;
        }
    }
    */
        s << "Three most sold items: " << endl;
        for(int k=0; k < 3; k++)
        {
            s<<"Name: " <<temp.print_name(k)<<" ";
            s<<"Count: " << temp.Return_count(k)<<endl;
        }
        s << "Three least sold items: " << endl;
        for(int k=temp.Unique_size()-1; k < temp.Unique_size()-4; k++)
        {
            s<<"Name: " <<temp.print_name(k)<<" ";
            s<<"Count: " << temp.Return_count(k)<<endl;
        }

        return s.str();

}
string Warehouse::totalPurchasesBySingleMember(string nameID, bool nameorID)
{
    stringstream s;
    s  << "Total Purchases by: ";

    if(nameorID==true)
    {
        //id
    for (size_t i = 0; i < wholesale_club.size(); i++)
    {
        if (wholesale_club[i].id() == nameID)
        {
            s << wholesale_club[i].name() << " ID: "<< wholesale_club[i].id()<< endl;

            s << wholesale_club[i].information().printUnique_str();

        }
    }

    }
    else if(nameorID == false)
    {//name
        for (size_t i = 0; i < wholesale_club.size(); i++)
        {
            if (wholesale_club[i].name() == nameID)
            {

                s << wholesale_club[i].name() << " ID: "<< wholesale_club[i].id()<< endl;

                s << wholesale_club[i].information().printUnique_str();
            }
        }
    }

    return s.str();
}

string Warehouse::totalPurchasesByAllMembers()
{
    stringstream s;

    s << "Total Purchases of All Members: "<<endl;

    for (size_t i = 0; i < wholesale_club.size(); i++)
    {
        s << wholesale_club[i].name() << " ID: "<< wholesale_club[i].id()<< endl;

        s << wholesale_club[i].information().printUnique_str();
    }

    return s.str();
}

string Warehouse::upgradeMember()
{
    stringstream s;
    double totalPrice = 0.0;
    double avgPrice = 0.0;

    s << "List of basic members that should upgrade to preferred: \n";

    //go through all members to get the total price
    for (size_t i=0; i < wholesale_club.size(); i++)
    {
        Node<Product>* walker = wholesale_club[i].information().unique().ReturnHead();
        for(;walker!=nullptr;walker=walker->next)
        {
            totalPrice = walker->_item.total_item_cost();
        }
    }

    avgPrice = totalPrice/wholesale_club.size();

    //get total amount spent by each member and compare
    for (size_t i=0; i<wholesale_club.size(); i++)
    {
        double amountSpent =0.0;
        Node<Product>* walker = wholesale_club[i].information().unique().ReturnHead();
        for(;walker!=nullptr;walker=walker->next)
        {
            amountSpent = walker->_item.total_item_cost();
        }
        if(amountSpent >= avgPrice && wholesale_club[i].type() == BASIC)
        {
            s << wholesale_club[i].name() << endl;
        }
    }

    return s.str();
}

string Warehouse::downgradeMember()
{
    stringstream s;
    double totalPrice = 0.0;
    double avgPrice = 0.0;

    s << "List of preferred members that should convert to basic: \n";

    //go through all members to get the total price
    for (size_t i=0; i < wholesale_club.size(); i++)
    {
        Node<Product>* walker = wholesale_club[i].information().unique().ReturnHead();
        for(;walker!=nullptr;walker=walker->next)
        {
            totalPrice = walker->_item.total_item_cost();
        }
    }

    avgPrice = totalPrice/wholesale_club.size();

    //get total amount spent by each member and compare
    for (size_t i=0; i<wholesale_club.size(); i++)
    {
        double amountSpent =0.0;
        Node<Product>* walker = wholesale_club[i].information().unique().ReturnHead();
        for(;walker!=nullptr;walker=walker->next)
        {
            amountSpent = walker->_item.total_item_cost();
        }
        if(amountSpent < avgPrice && wholesale_club[i].type() == PREFERRED)
        {
            s << wholesale_club[i].name() << endl;
        }
    }

    return s.str();
}
