#include "item.h"

//CONSTRUCTORS
/**************************************************************
* CharStack
* ____________________________________________________________
* This default constructor initializes values to zero
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*  none
* POST-CONDITION
* Item object is inialized
***************************************************************/
Item::Item():_rebateAmount(0.0), _nonTaxedDailySpent(0.0), _taxedDailySpent(0.0),
_dailyCount(0), _size(0)
{

}

//MUTATORS
/**************************************************************
* void Item::set_date(Date d)
* ____________________________________________________________
* This sets the private member variable _date
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   Date d -> parameter must have a value
* POST-CONDITION
* _date is set
***************************************************************/
void Item::set_date(Date d){
    _date=d;
}


/**************************************************************
* void Item::set_dailySpent()
* ____________________________________________________________
* This function calculates how much the customer spent BEFORE
* TAXES. This function will be used for calculating the
* rebate amount.
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   _purchases array must not be empty
* POST-CONDITION
* _nonTaxedDailySpent is set
***************************************************************/
void Item::set_dailySpent(){

    for(size_t i=0; i< get_size(); i++){
        _nonTaxedDailySpent+=_purchases[i].total_item_cost();
    }
}

/**************************************************************
* void Item::set_dailyRebate()
* ____________________________________________________________
* This function calculates the rebate.
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   _purchases array must not be empty
* POST-CONDITION
* _rebateAmount is set
***************************************************************/
void Item::set_dailyRebate(){
    _rebateAmount=get_nonTaxedSpent()*REBATE;
}

/**************************************************************
* void Item::set_taxedSpent()
* ____________________________________________________________
* This function calculates what the customer spent WITH taxes
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   _purchases array must not be empty
* POST-CONDITION
* _taxedDailySpent is set
***************************************************************/
void Item::set_taxedSpent(){

    double taxed=0.0;
    taxed=get_nonTaxedSpent()*TAX;
    _taxedDailySpent=get_nonTaxedSpent()+taxed;
}

/**************************************************************
* bool Item::checkUnique(string name)
* ____________________________________________________________
* This function checks if the product is already stored by
* looking at the name.This is a helper to the add function
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   _purchases array must exist
* POST-CONDITION
* bool value is returned
***************************************************************/
bool Item::checkUnique(string name){
    if(get_size()==0)
        return true;
   for(size_t i=0; i < get_size(); i++){
        if(name != _purchases[i].name){
            return true;
        }
        return false;
    }
   return true;
}

/**************************************************************
* bool Item::canBuyMore()
* ____________________________________________________________
* This function checks the customer can buy more -> there is
* a limit of 100 items so we check the _dailyCount, which is
* a count of all items bought
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   _purchases array must exist
*   num
* POST-CONDITION
* bool value is returned
***************************************************************/
bool Item::canBuyMore(size_t num){
    if (_dailyCount+num < MAX){
        return true;
    }
    return false;
}

/**************************************************************
* bool Item::canBuyMore()
* ____________________________________________________________
* This function checks the customer can buy more -> there is
* a limit of 100 items so we check the _dailyCount, which is
* a count of all items bought
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   _purchases array exists
* POST-CONDITION
* Product is added to the array, or struct count is updated
***************************************************************/
void Item::add(Product p){
    if(!canBuyMore(p.count))
    {
        cout << "Error!: Reached Maximum Item limit\n";
        assert(canBuyMore(p.count));
    }

    if(checkUnique(p.name))
    {
        _purchases[_size] = p;
        _size++;
    }
    else
    {
        updateProductCount(p);
    }

    _dailyCount+=p.count;

    set_dailySpent();
    set_taxedSpent();
    set_dailyRebate();
}

/**************************************************************
* void Item::updateProductCount(Product p)
* ____________________________________________________________
* This function edits the struct count. It is a helper function
* for add
* ___________________________________________________________
* PRE-CONDITIONS
* The following need previously defined values:
*   _purchases array exists
* POST-CONDITION
* struct count is updated
***************************************************************/
void Item::updateProductCount(Product p){
    if(get_size()==0){
        cout << "Error: size is 0, product count should not be called\n";
    }

    size_t i=0;
    //find index of existing product
    while(p.name!=_purchases[i].name && i<get_size()){
        i++;
    }
    _purchases[i].count += p.count;
}



void Item::print_stats(){
    //NEED TO CALL CALCULATION FUNCTIONS FIRST THEN PRINT SO YOU HAVE YOUR VALUES
    cout << "Date: " << get_date() << endl;
    cout <<"List of Purchases \n";
    cout <<"******************************************\n";
    for(size_t i=0; i < get_size(); i++){
        cout << _purchases[i] << endl;
    }
    cout <<"******************************************\n";
    cout << "Total Cost Before Taxes  : $" << get_nonTaxedSpent() << endl;
    cout << "Total Cost After Taxes   : $" << get_TaxedSpent() << endl;
    cout << "Rebate Amount            : $" << get_rebate() << endl;
    cout << "Sum of All Items         : $" << get_dailyCount() << endl;
    cout << "Amount of Unique Products: " << get_size() << endl;

}

string Item::print_stats_stream()
{
    stringstream s;

    s << "Date: " << get_date() << endl;
    s <<"List of Purchases \n";
    s <<"******************************************\n";
    for(size_t i=0; i < get_size(); i++){
        s << _purchases[i] << endl;
    }
    s <<"******************************************\n";
    s << "Total Cost Before Taxes  : $" << get_nonTaxedSpent() << endl;
    s << "Total Cost After Taxes   : $" << get_TaxedSpent() << endl;
    s << "Rebate Amount            : $" << get_rebate() << endl;
    s << "Sum of All Items         : $" << get_dailyCount() << endl;
    s << "Amount of Unique Products: " << get_size() << endl;

    return s.str();
}

string Item::print_name(int pos)
{
    return _purchases[pos].name;
}

int Item::print_count(int pos)
{
    return _purchases[pos].count;
}
