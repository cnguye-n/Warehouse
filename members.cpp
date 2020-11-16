#include "members.h"
#include <algorithm>
//CONSTRUCTORS
/**************************************************************
* Members
* ____________________________________________________________
* This default constructor initializes values to zero
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  none
* POST-CONDITION
* Item object is inialized
***************************************************************/
Members::Members()
{

}
/**************************************************************
* Members(string name, string id, string type, Date expiration)
* ____________________________________________________________
* This constructor initializes private member variables by
the parameter values
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  string name, string id, stirng type, Date expiration
* POST-CONDITION
* Member object is inialized
***************************************************************/
Members::Members(string name, string id, string type, Date expiration)
    :_name(name), _id(id), _expiration(expiration)
{
    set_type(type);
}


bool Members::upgrade()
{
//    if(_type == BASIC && total_amount() >= 100) //the total_amount can be changed
//    {
//        _type = PREFERRED;
//        return true;
//    }
//    return false;
}


bool Members::downgrade()
{
//    if (_type == PREFERRED && total_amount() < 100) //the total_amount can be changed
//    {
//        _type = BASIC;
//        return true;
//    }
//    return false;
}
/**************************************************************
* void Members::set_type(string s)
* ____________________________________________________________
* This function will set the member type based on the string
input
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  string s
* POST-CONDITION
* member type is changed
***************************************************************/
void Members::set_type(string s)
{
    if (s == "PREFERRED" || s == "Preferred" || s == "preferred")
    {
        _type = PREFERRED;
    }
    if (s == "BASIC" || s == "Basic" || s== "basic")
    {
        _type = BASIC;
    }
}
/**************************************************************
* double Members::total_amount
* ____________________________________________________________
* This function will return the total amount the customer
spent
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* totaSpent
* POST-CONDITION
* total amount is returned
***************************************************************/
double Members::total_amount()
{
    return information().totalSpent();
}

/**************************************************************
* double Members::rebate_amount()
* ____________________________________________________________
* This function returns the rebate amount
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
* rebate
* POST-CONDITION
* rebate amount returned
***************************************************************/
double Members::rebate_amount()
{
    return _information.calcRebate();
}

/**************************************************************
* double Members::payment()
* ____________________________________________________________
* This function returns the amount the member needs to pay
based on the type
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  none
* POST-CONDITION
* _payment is returned
***************************************************************/
double Members::payment()
{
    if(_type == PREFERRED)
    {
        _payment = 75.0;
    }
    if(_type == BASIC)
    {
        _payment = 60.0;
    }
    return _payment;
}

/**************************************************************
* bool Members::operator==(const Members& b)
* ____________________________________________________________
* This function checks if the members are the same
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  Members& b
* POST-CONDITION
* bool value is returned
***************************************************************/
bool Members::operator==(const Members& b)  //it can be used in the warehouse to check if the members are the same
{
    if(_id == b._id || _name == b._name) {return true;}
    return false;
}

/**************************************************************
* bool Members::operator!=(const Members& b)
* ____________________________________________________________
* This function checks if the members are not the same
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  Members& b
* POST-CONDITION
* bool value is returned
***************************************************************/
bool Members::operator!=(const Members& b)
{
    return !(*this == b);
}

/**************************************************************
* History& Members::information()
* ____________________________________________________________
* This function returns the History object
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  _information
* POST-CONDITION
* referenece to the object is returned
***************************************************************/
History& Members::information()
{
    return _information;
}

/**************************************************************
* size_t Members::UniqueSize()
* ____________________________________________________________
* This function returns the size of the _unique linked list
in the member's History object
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  _unique
* POST-CONDITION
* size is returned
***************************************************************/
size_t Members::UniqueSize()
{
    return _information.Unique_size();
}

/**************************************************************
* Product& Members::GetProductat(size_t position)
* ____________________________________________________________
* This function returns the Product at specified position
______________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  size_t position
* POST-CONDITION
* reference to the Product object is returned
***************************************************************/
Product& Members::GetProductat(size_t position)
{
    return _information.GetProduct(position);
}
