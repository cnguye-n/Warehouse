#ifndef HISTORY_H
#define HISTORY_H

#include "item.h"
#include "list.h"

class History
{
public:
    History();

     //ACCESSOR
     //get Item from that day

    Item getThatNode(Date date);
     //get total info on that product
    Product getThatProduct(string name);

    List<Item>& history(){return _history;}
    List<Product>& unique(){return _unique;}


    //MUTATORS
    //add day to _history linked list
    void set_history(Item item);
   //add unique products to _unique list
    void set_unique(Product p);

    bool dateIsUnique(Date d);
    bool productIsUnique(Product p);

    //calculation functions
    size_t totalPurchases();        //num of all customer's purchases
    size_t TaxedtotalSpent();       //how much customer spent -taxed
    size_t totalSpent();            //how much customer spent NOT taxed
    size_t avgPurchases();          //avg num of purchases per trip
    size_t avgSpent();              //avg amount of $ spent per trip
    float calcRebate();

    //OUTPUT
    void printHistory();    //_history link list
    void printUnique();     //_unique link list
    string printUnique_str();     //_unique link list

    string print_name(int pos);
    size_t Return_count(int pos);

    size_t Unique_size();
    Product &GetProduct(size_t pos);

private:
    //items contains array of products
    List<Item> _history;     //linked list of all shopping days
    List<Product> _unique;   //all the unique products customer bought

};

/*******************************************
* History();
* Constructor: Constructor for History Class object
* Parameters : None
* Return     : None
******************************************/
/*******************************************
* Item getThatNode(Date date);
* Accessor   : Returns Item Object
* Parameters : Date object
* Return     : Item Object
******************************************/
/*******************************************
* Product getThatProduct(string name);
* Accessor   : Returns Product object
* Parameters : Name of Product
* Return     : Product object
******************************************/
/*******************************************
* List<Item>& history(){return _history;}
* Accessor   : _history linked list
* Parameters : None
* Return     : _history linked_list pointer
******************************************/
/*******************************************
* List<Product>& unique(){return _unique;}
* Accessor   : Returns _unique linked-linked_list
* Parameters : None
* Return     : Head Pointer To Linked List
******************************************/

//mutators
/*******************************************
* void set_history(Item item);
* Mutator    : Sets history linked linked_list
* Parameters : Item object
* Return     : None
******************************************/
/*******************************************
* void set_unique(Product p);
* Mutator    : Sets unique linked_list
* Parameters : Product object
* Return     : None
******************************************/
/*******************************************
* bool dateIsUnique(Date d);
* Accessor   : Checks for unique date
* Parameters : Date object
* Return     : Boolean Value
******************************************/
/*******************************************
* bool productIsUnique(Product p);
* Accessor   : Checks for unique product object
* Parameters : Product object
* Return     : Boolean Value
******************************************/
/*******************************************
* size_t totalPurchases();
* Accessor   : Returns Total purchase of all customers
* Parameters : None
* Return     : Count of purchases
******************************************/
/*******************************************
* size_t TaxedtotalSpent();
* Accessor   : Total Spent with taxed
* Parameters : None
* Return     : size_t number
******************************************/
/*******************************************
* size_t totalSpent();
* Accessor   : Total amount spent
* Parameters : None
* Return     : Amount spent
******************************************/
/*******************************************
* size_t avgPurchases();
* Accessor   : Average of all purchases
* Parameters : None
* Return     : Average
******************************************/
/*******************************************
* size_t avgSpent();
* Accessor   : Average spent
* Parameters : None
* Return     : Return average spent
******************************************/
/*******************************************
* float calcRebate();
* Accessor   : Calculates rebate of member
* Parameters : None
* Return     : Rebate amount
******************************************/
/*******************************************
* void printHistory();
* Accessor   : prints _history
* Parameters : None
* Return     : None
******************************************/
/*******************************************
* void printUnique();
* Accessor   : Prints _unique
* Parameters : None
* Return     : None
******************************************/
/*******************************************
* string printUnique_str();
* Accessor   : Prints _unique into a string
* Parameters : None
* Return     : String object
******************************************/
/*******************************************
* string print_name(int pos);
* Accessor   : Prints name of product
* Parameters : Position of product
* Return     : String
******************************************/
/*******************************************
* size_t Return_count(int pos);
* Accessor   : Prints count of product
* Parameters : Position of product
* Return     : Size_t
******************************************/
/*******************************************
* size_t Unique_size();
* Accessor   : Size of _unique
* Parameters : None
* Return     : size_t
******************************************/
/*******************************************
* Product &GetProduct(size_t pos);
* Accessor   : Returns product at certain position
* Parameters : Position of product
* Return     : Product
******************************************/

#endif // HISTORY_H
