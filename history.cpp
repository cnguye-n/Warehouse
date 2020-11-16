#include "history.h"

/**************************************************************
* History()
* ____________________________________________________________
* Constructor
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
History::History(){

}

//Go through _history linked list
Item History::getThatNode(Date date){
   assert(!_history.isEmpty());
   Node<Item> *walker=_history.ReturnHead();
   for(;walker!=nullptr;walker=walker->next){
       if(walker->_item.get_date() == date){
           return walker->_item;
       }
   }
   //idk what to put if doesn't find it
}

/**************************************************************
* Product History::getThatProduct(string name)
* ____________________________________________________________
* Returns product by name
* ___________________________________________________________
* PRE-CONDITIONS
* -Product must exist
* POST-CONDITIONS
* -None
***************************************************************/
Product History::getThatProduct(string name)
{
    Node<Product>* walker = _unique.ReturnHead();

    while (walker != nullptr)
    {
        if (walker->_item.name == name)
            break;
        else
            walker = walker->next;
    }

    if (walker == nullptr)
        return Product();
    else
        return walker->_item;
}

/**************************************************************
* bool History::dateIsUnique(Date d)
* ____________________________________________________________
* Checks if date is unique
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
bool History::dateIsUnique(Date d){
     Node<Item> *walker=_history.ReturnHead();
    if(_history.isEmpty())
    {
        return true;
    }
    for(;walker!=nullptr;walker=walker->next)
    {
        if(walker->_item.get_date() == d)
            return false;
    }
    return true;
}

/**************************************************************
* void History::set_history(Item item)
* ____________________________________________________________
* Sets item in _history
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -History adds item to _history
***************************************************************/
void History::set_history(Item item)
{
    //if purchase info for the date isn't there yet
    if(dateIsUnique(item.get_date())){
       _history.insertAsc(item);
    }
    else{
        Node<Item> *walker=_history.ReturnHead();
        size_t i=0;
        //go to that node and update
        while(walker->_item.get_date() != item.get_date()
              && i < _history.getSize()){
            i++;
            walker=walker->next;
        }
        //update that day's purchase by "merging" info
        for(size_t i=0; i < item.get_size(); i++)
        {
           walker->_item.add(item._purchases[i]);
        }
   }
}

/**************************************************************
* bool History::productIsUnique(Product p)
* ____________________________________________________________
* Checks if product is unique
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
bool History::productIsUnique(Product p){
    Node<Product> *walker=_unique.ReturnHead();
    if(_unique.isEmpty()){
        return true;
    }
    for(;walker!=nullptr;walker=walker->next){
        //have to go through array in node
        if(walker->_item.name == p.name)
            return false;
    }
    return true;
}

/**************************************************************
* void History::set_unique(Product p)
* ____________________________________________________________
* Sets product in _unique
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Product is added in to _unique
***************************************************************/
void History::set_unique(Product p){
    if(productIsUnique(p)){
       _unique.insertAsc(p);
    }
    else{
        Node<Product> *walker=_unique.ReturnHead();
        size_t i=0;
        //go to existing product to update count
        while(p.name != walker->_item.name && i < _unique.getSize()){
            walker=walker->next;
            i++;
        }
        walker->_item.count += p.count;
    }
    //also what about storing info if the price changed?
    //could implement in the future
}

/**************************************************************
* float History::calcRebate()
* ____________________________________________________________
* Calculates rebate of member
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Return >=0
***************************************************************/
float History::calcRebate(){
    double sum=0;
    Node<Item> *walker=_history.ReturnHead();
    for(;walker!=nullptr;walker=walker->next){
        sum+=walker->_item.get_rebate();
    }
    return sum;
}

/**************************************************************
* size_t History::totalPurchases()
* ____________________________________________________________
* Returns total purchases of member
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Return >=0
***************************************************************/
size_t History::totalPurchases(){
    size_t sum=0;
    Node<Item> *walker=_history.ReturnHead();
    for(;walker!=nullptr;walker=walker->next){
        sum+=walker->_item.get_dailyCount();
    }
    return sum;
}

/**************************************************************
* size_t History::TaxedtotalSpent()
* ____________________________________________________________
* Returns taxedtotalspent of member
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Return >=0
***************************************************************/
size_t History::TaxedtotalSpent(){
    size_t sum=0;
    Node<Item> *walker=_history.ReturnHead();
    for(;walker!=nullptr;walker=walker->next){
        sum+=walker->_item.get_TaxedSpent();
    }
    return sum;
}

/**************************************************************
* size_t History::totalSpent()
* ____________________________________________________________
* Returns total spend by member
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Return >=0
***************************************************************/
size_t History::totalSpent(){
    size_t sum=0;
    Node<Item> *walker=_history.ReturnHead();
    for(;walker!=nullptr;walker=walker->next){
        sum+=walker->_item.get_nonTaxedSpent();
    }
    return sum;
}

/**************************************************************
* size_t History::avgPurchases()
* ____________________________________________________________
* Return average of all purchases
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Return >=0
***************************************************************/
size_t History::avgPurchases(){
    size_t sum=totalPurchases();
    return (sum/_history.getSize());
}

/**************************************************************
* size_t History::avgSpent()
* ____________________________________________________________
* Return average spent
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Return >=0
***************************************************************/
size_t History::avgSpent(){
    size_t sum=totalSpent();
    return (sum/_history.getSize());
}

/**************************************************************
* void History::printHistory()
* ____________________________________________________________
* Prints _history
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
void History::printHistory(){
    Node<Item>* walker=_history.ReturnHead();
    for(;walker!=nullptr;walker=walker->next){
        walker->_item.print_stats();
    }
}

/**************************************************************
* void History::printUnique()
* ____________________________________________________________
* Prints _unique list
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -None
***************************************************************/
void History::printUnique(){
    Node<Product>* walker=_unique.ReturnHead();
    for(;walker!=nullptr;walker=walker->next){
        cout << walker->_item << endl;
    }
}

/**************************************************************
* string History::printUnique_str()
* ____________________________________________________________
* Prints _unique into a string
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Returns report into a string
***************************************************************/
string History::printUnique_str(){
    stringstream s;
    Node<Product>* walker=_unique.ReturnHead();
    for(;walker!=nullptr;walker=walker->next)
    {
        s << walker->_item << endl;
    }
    return s.str();
}

/**************************************************************
* size_t History::Unique_size()
* ____________________________________________________________
* Returns size of _unique list
* ___________________________________________________________
* PRE-CONDITIONS
* -None
* POST-CONDITIONS
* -Return >=0
***************************************************************/
size_t History::Unique_size()
{
    return _unique.getSize();
}

/**************************************************************
* Product& History::GetProduct(size_t pos)
* ____________________________________________________________
* Returns Product based on position of _unique list
* ___________________________________________________________
* PRE-CONDITIONS
* -Product must exist
* -Position must also exist, <size of list
* POST-CONDITIONS
* -Product can be edited because of &
***************************************************************/
Product& History::GetProduct(size_t pos)
{
    Node<Product>* walker = _unique.ReturnHead();
    for(size_t i=0; i<pos; i++)
    {
        walker=walker->next;
    }

    return walker->_item;

}

/**************************************************************
* string History::print_name(int pos)
* ____________________________________________________________
* Prints name of product based on position
* ___________________________________________________________
* PRE-CONDITIONS
* -Position must not exceed list size
* POST-CONDITIONS
* -Returns name into string
***************************************************************/
string History::print_name(int pos)
{
    Node<Product>* walker = _unique.ReturnHead();
    for(int i=0; i<pos; i++)
    {
        walker=walker->next;
    }

    return walker->_item.name;

}

/**************************************************************
* size_t History::Return_count(int pos)
* ____________________________________________________________
* Returns count of product based on product
* ___________________________________________________________
* PRE-CONDITIONS
* -Position does not exceed size of list
* POST-CONDITIONS
* -Count is returned
***************************************************************/
size_t History::Return_count(int pos)
{
    Node<Product>* walker = _unique.ReturnHead();
    for(int i=0; i<pos; i++)
    {
        walker=walker->next;
    }

    return walker->_item.count;
}
