#ifndef ITEM_H
#define ITEM_H

#include "date.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;

//CONSTANTS
const double TAX=.0875;	   //TAX 8.75% of dailySpent
const double REBATE=.05;  //rebate is 5% of dailySpent without tax
const int MAX=100;
/*maximum purchases that can be bought in a day is 100
 -it is 100 bc worst case senario customer buys 100 different/unique items
 -each element in the array storing the products bought in a day
 is unique (like keyed bag)
*/

/**************************************************************************
 * Product structure
 *   This structure contains the information of each individual product
 * bought. Each struct will be stored in the class Item array
 **************************************************************************/
struct Product{
    Product(): name(""), price(0.0), count(0){}
    Product(string n,double p,size_t c):name(n),price(p),count(c){}

    //OVERLOADED OPERATOR
    friend std::ostream& operator <<(std::ostream& outs,const Product &p){
         int size=p.name.length();
         int width= abs(15-size);
        outs <<p.name << setw(width) << "$" << std::setprecision(2) << fixed
            << p.price << setw(6) << p.count << " \n";
        return outs;
    }
    friend std::istream& operator >>(istream& ins, Product& p){
        string name;
        double price;
        size_t count;
        //char slash;
        //ins >> name >> slash >> count; if we read in with dollar sign?
        ins >> name >> price >> count;
        p=Product(name,price,count);
        return ins;
    }
    //FOR COMPARISON OF STRING NAME IN CASE WANT TO INSERT ALPHABETICAL ORDER
    bool operator==(Product rhs){
        return (name == rhs.name);
    }
    bool operator !=(Product rhs){
        return (name != rhs.name);
    }
    bool operator >(Product rhs){
        return (name > rhs.name);
    }
    bool operator <(Product rhs){
        return (name < rhs.name);
    }
    bool operator >=(Product rhs){
        return (name >= rhs.name);
    }
    bool operator <=(Product rhs){
        return (name <= rhs.name);
    }

    //VARIABLES
    string name=" ";		  //name of product
    double price=0.0;		  //cost for one of this item
    size_t count=0;			  //how many of this item bought that day
    double total_item_cost(){ //count * price WITHOUT tax
        return price*count;}
};
/**************************************************************************
 * Item Class
 *   This class stores the products and calculations needed for the daily
 * sales report. One item object is equivalent to purchases in one day
 **************************************************************************/
class Item
{
public:
    /********************************
       **  CONSTRUCTOR  **
     ********************************/
    /*******************************************
     * Item()
     * Constructor: initializes values to 0
     * Parameters : none
     * Return     : none
     ******************************************/
    Item();

    /********************************
       **  ACCESSORS  **
     ********************************/
    /*******************************************
     * double get_rebate() const
     * Accessor   : returns the rebate amount
     * Parameters : none
     * Return     : _rebateAmount
     ******************************************/
    double get_rebate() const{return _rebateAmount;}              //a. return _rebateAmount

    /*******************************************
     * double get_TaxedSpent() const
     * Accessor   : returns taxed purcahse cost
     * Parameters : none
     * Return     : _taxedDailySpent
     ******************************************/
    double get_TaxedSpent() const{return _taxedDailySpent;} 	  //b. return _taxedDailySpent

    /*******************************************
     *  double get_nonTaxedSpent() const
     * Accessor   : returns the rebate amount
     * Parameters : none
     * Return     : _rebateAmount
     ******************************************/
    double get_nonTaxedSpent() const{return _nonTaxedDailySpent;} //c. return _nonTaxedDailySpent

    /*******************************************
     *  size_t get_dailyCount() const
     * Accessor   : returns number of all things
     *              bought that day
     * Parameters : none
     * Return     : _dailyCount
     ******************************************/
    size_t get_dailyCount() const{return _dailyCount;}            //d. return _dailyCount,

    /*******************************************
     *  size_t get_size() const
     * Accessor   : returns amount of array used
     * Parameters : none
     * Return     : _size
     ******************************************/
    size_t get_size() const{return _size;}

    /*******************************************
     * Date get_date() const
     * Accessor   : returns the date of this
     *              purchase
     * Parameters : none
     * Return     : _date
     ******************************************/
    Date get_date() const{return _date;}


    /********************************
       **  MUTATORS  **
     ********************************/
    //SETTING DATE
    /*******************************************
     * void set_date()
     * Mutator    : sets _date
     * Parameters : Date object
     * Return     : none
     ******************************************/
     void set_date(Date d);

    //PERTAINS TO SUM CALCULATIONS OF PRIVATE MEM VARIABLES
    /*******************************************
     * void set_dailyRebate()
     * Mutator    : calculates _rebateAmount
     * Parameters : none
     * Return     : none
     ******************************************/
    void set_dailyRebate(); 		//a. calculate _rebateAmount
    /*******************************************
     * void set_dailySpent()
     * Mutator    : calc $ spent W/OUT taxes
     * Parameters : none
     * Return     : none
     ******************************************/
    void set_dailySpent();			//b. how much customer spent WITHOUT taxes
    /*******************************************
     * void set_taxedSpent()
     * Mutator    : calculates how much customer
     *              spent WITH taxes
     * Parameters : none
     * Return     : none
     ******************************************/
    void set_taxedSpent();			//c. how much customer spent WITH taxes


    //PERTAINS TO ADDING ITEMS
    /*******************************************
     * void add(Product p)
     * Mutator    : if Product is unique, add
     *              item to array, else update
     *              the struct
     * Parameters : Product
     * Return     : none
     ******************************************/
    void add(Product p);               //e. if Product is unique, add item to array (edit array)
    /*******************************************
     * bool checkUnique(string name)
     * Mutator    : checks if the Product is
     *             already stored in the array
     * Parameters : string ->name of the Product
     * Return     : bool
     ******************************************/
    bool checkUnique(string name);	   //check if item exists already
    /*******************************************
     * bool canBuyMore()
     * Mutator    : checks if the member can buy
     *              more products as the limit
     *              is 100 items per day
     * Parameters : num of products customer
     *              planning to buy
     * Return     : bool
     ******************************************/
      bool canBuyMore(size_t num);              //check if member can actually buy more


     //PERTAINS TO EDITING STRUCT
    /*******************************************
     * void updateProductCount(Product p)
     * Mutator    : if an struct is not unique,
     *              it will update count
     *              of the existing product
     * Parameters : Product
     * Return     : none
     ******************************************/
    void updateProductCount(Product p); //if it is not unique, update count of existing product (edit struct)

    /********************************
       **  OTHER  **
     ********************************/
    //OUTPUT/TESTING PURPOSES
    /*******************************************
     * void print_stats()
     * Mutator    : this will print all values
     *              of private member values
     * Parameters : none
     * Return     : none
     ******************************************/
    void print_stats();

    string print_stats_stream();

    string print_name(int pos);

    int print_count(int pos);

    //BOOLEAN
    bool operator >(Item rhs){
        return (_date > rhs._date);
    }
    bool operator >=(Item rhs){
        return (_date >= rhs._date);
    }
    bool operator <(Item rhs){
        return (_date < rhs._date);
    }
    bool operator <=(Item rhs){
        return (_date <= rhs._date);
    }
    bool operator ==(Item rhs){
        return (_date == rhs._date);
    }
    bool operator !=(Item rhs){
        return (_date != rhs._date);
    }
friend class History;
private:
    double _rebateAmount;		   //a. rebate amount for that day
    double _nonTaxedDailySpent;	   //b. total amount spent without tax;
    double _taxedDailySpent;	   //c. daily spent with tax;
    size_t _dailyCount;  		   //d. sum of all the things customer bought that day
    Product _purchases[MAX];	   //e. stores the different products customer bought that day
                                   //   so this is array of structs
    size_t _size;                  //  size of array so this would imply number of different
                                   //   products customer bought -always reduces search time
    Date _date;                    //   day of this purchase
};

#endif // ITEM_H
