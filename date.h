#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

/*******************************************
 * class Date
 * - This class is used to keep track of date
 * for days of purchases and expirations of
 * memberships
 ******************************************/
class Date{
public:
    enum ERROR_CODES{NO_ERROR,INVALID_DATE};

    Date(int day,int month,int year);
    Date();

    //ACESSORS
    int get_day() const;
    int get_month() const;
    int get_year() const;
    bool get_error() const; //see if date is invalid or not

    //MUTATORS
    void set_date(int month, int day, int year);
    void set_day(int day);
    void set_month(int month);
    void set_year(int year);

    //TO CHECK IF DATE IS VALID
    bool date_is_valid();
    int days_in_month();
    bool is_leap();
    int num_of_leap_years();

    //FRIEND FUNCTIONS
    bool operator >(const Date& rhs) const;
    bool operator <(const Date& rhs) const;
    bool operator <=(const Date& rhs) const;
    bool operator >=(const Date& rhs) const;
    bool operator ==(const Date& rhs) const;
    bool operator !=(const Date& rhs) const;

    friend ostream& operator <<(ostream& outs, const Date& info);
    friend istream& operator >>(istream& ins, Date& info);

private:
    int _m;       //month
    int _d;       //day
    int _y;       //year

    ERROR_CODES _error;
    int check_error();


};
/*******************************************
 * enum ERROR_CODES
 * - used for invalid dates
 ******************************************/
/*******************************************
 * Date(month, day, year)
 * Constructor: Constructs Date object
 * Parameters : month,day,year
 * Return     : none
 ******************************************/
/*******************************************
 * Date()
 * Constructor: Constructs empty Date object
 * Parameters : none
 * Return     : none
 ******************************************/
/*******************************************
 * get_month
 * Parameters : int month
 * Return     : _m
 ******************************************/
/*******************************************
 * get_day
 * Parameters : int day
 * Return     : _d
 ******************************************/
/*******************************************
 * get_year
 * Parameters : int year
 * Return     : _y
 ******************************************/
/*******************************************
 * get_error
 * Parameters : n/a
 * Return     : _error
 ******************************************/
/*******************************************
 * set_month
 * Parameters : int month
 * Return     : none
 ******************************************/
/*******************************************
 * set_day
 * Parameters : int day
 * Return     : none
 ******************************************/
/*******************************************
 * set_year
 * Parameters : int year
 * Return     : _y
 ******************************************/
/*******************************************
 * set_date
 * Parameters : int month, day, year
 * Return     : n/a
 ******************************************/
/*******************************************
 * comparison operators
 * Parameters : Date onj
 * Return     : bool value based on comp
 ******************************************/
/*******************************************
 * insertion,extraction operators
 * Parameters : Date obj
 * Return     : istream or ostream
 ******************************************/


#endif // DATE_H
