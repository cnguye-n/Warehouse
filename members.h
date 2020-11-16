#ifndef MEMBERS_H
#define MEMBERS_H

#include <string>
#include <iostream>
#include "date.h"
#include "history.h"
using namespace std;


enum TYPE{BASIC, PREFERRED, ALL};
/**************************************************************************
 * Members Class
 *   This class stores all the information for each member. Each member
 will be assigned a status of Basic,Preffereed, or All and can be changed
 based on the number of purchases. Each member will also have a history
 object which contains information from all of their shopping trips
 **************************************************************************/
class Members
{
public:

    /********************************
     **  CONSTRUCTOR  **
     ********************************/
    /*******************************************
    * Members()
    * Constructor: initializes default values
    * Parameters : none
    * Return     : none
    ******************************************/
    Members();
    /*******************************************
    * Members(string name, string id,
               string type, Date expiration)
    * Constructor: initializes private member
                    variables to parameter
                    values
    * Parameters : string, string, string, Date
    * Return     : none
    ******************************************/
    Members(string name, string id, string type, Date expiration);

    /********************************
     **  MUTATORS  **
     ********************************/
    /*******************************************
    * bool upgrade()
    * Mutator: see if basic member should upgrade
    * Parameters : none
    * Return     : bool
    ******************************************/
    bool upgrade(); //for basic
    /*******************************************
    * bool downgrade()
    * Mutator: see if preferred member should
               downgrade
    * Parameters : none
    * Return     : bool
    ******************************************/
    bool downgrade(); //for preferred
    /*******************************************
    * set_type(string s)
    * Mutator: change the type of member
    * Parameters : string
    * Return     : none
    ******************************************/
    void set_type(string s);

    /********************************
     **  ACESSORS  **
     ********************************/
    /*******************************************
    * string name()
    * Acessor	 : returns the name
    * Parameters : none
    * Return     : string
    ******************************************/
    string name(){return _name;}
    /*******************************************
    * string id()
    * Acessor	 : returns the id
    * Parameters : none
    * Return     : string
    ******************************************/
    string id(){return _id;}
    /*******************************************
    * TYPE type
    * Acessor	 : returns the member type
    * Parameters : none
    * Return     : TYPE
    ******************************************/
    TYPE type(){return _type;}
    /*******************************************
    * Date expiration()
    * Acessor	 : returns member expiration
    * Parameters : none
    * Return     : Date
    ******************************************/
    Date expiration(){return _expiration;}
    /*******************************************
    * double total_amount()
    * Acessor	 : returns amount spent
    * Parameters : none
    * Return     : double
    ******************************************/
    double total_amount(); //this is calculated
    /*******************************************
    * double rebate_amount()
    * Acessor	 : returns rebate for preferred
                   members
    * Parameters : none
    * Return     : double
    ******************************************/
    double rebate_amount(); //preferred only
    /*******************************************
    * double payment()
    * Acessor	 : returns payment
    * Parameters : none
    * Return     : double
    ******************************************/
    double payment();


    /*******************************************
    * bool operator==(const Members& b)
    * Operator	 : checks if Members are the same
    * Parameters : Members
    * Return     : bool
    ******************************************/
    bool operator==(const Members& b);
    /*******************************************
    * bool operator!=(const Members& b)
    * Operator	 : checks if Members are diff.
    * Parameters : Members
    * Return     : bool
    ******************************************/
    bool operator!=(const Members& b);

    /*******************************************
    * History& information();
    * Acessor	 : returns information from
                   History class
    * Parameters : none
    * Return     : bool
    ******************************************/
    History& information();
    /*******************************************
    * size_t UniqueSize();
    * Acessor	 : returns size of _unique
                   linked list from History
    * Parameters : none
    * Return     : size_t
    ******************************************/
    size_t UniqueSize();
    /*******************************************
    * Product &GetProductat(size_t position)
    * Acessor	 : returns struct at position
    * Parameters : size_t
    * Return     : Product
    ******************************************/
    Product &GetProductat(size_t position);

private:
    bool _paid_dues;		//if member paid their dues
    string _name= " ";		//name of member
    string _id= " ";		//member id
    TYPE _type;  			//member type
    Date _expiration;		//expiration date of membership
    double _payment=0.0;	//bill member have to pay based on type
    History _information;	//History object of purchases

};


#endif // MEMBERS_H
