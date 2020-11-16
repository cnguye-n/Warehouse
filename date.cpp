#include "date.h"

/**************************************************************
* Date(int month, int day, int year)
* ____________________________________________________________
* Constructor
* ___________________________________________________________
* PRE-CONDITIONS
* -month, day, and year values to be made into a Date onj
* POST-CONDITIONS
* -Date obj created
***************************************************************/
Date::Date(int month, int day, int year): _m(month), _d(day), _y(year),_error(NO_ERROR)
{
    //changes _error value if date is invalid
    check_error();
}
/**************************************************************
* Date()
* ____________________________________________________________
* Constructor
* ___________________________________________________________
* PRE-CONDITIONS
* - None
* POST-CONDITIONS
* -Date obj created
***************************************************************/
Date::Date(){
    _m=0;
    _d=0;
    _y=0;
}

/**************************************************************
* set_date(int month, int day, int year)
*
* PRE-CONDITIONS
* -month, day, and year values
* POST-CONDITIONS
* -Date obj created
***************************************************************/
 void Date::set_date(int month, int day, int year)
 {
    _m = month;
    _d = day;
    _y = year;
 }
/**************************************************************
* set_day(int day)
*
* PRE-CONDITIONS
* -day value
* POST-CONDITIONS
* -day portion of date is set
***************************************************************/
 void Date::set_day(int day)
 {
     _d = day;
 }
/**************************************************************
* PRE-CONDITIONS
* -month value
* POST-CONDITIONS
* -month portion of date is set
***************************************************************/
 void Date::set_month(int month)
 {
     _m = month;
 }
/**************************************************************
* PRE-CONDITIONS
* -year value
* POST-CONDITIONS
* -year portion of date is set
***************************************************************/
 void Date::set_year(int year)
 {
     _y = year;
 }

/**************************************************************
* PRE-CONDITIONS
* - n/a
* POST-CONDITIONS
* - boolean value if valid date is set
***************************************************************/
 bool Date::date_is_valid()
 {
    bool debug=true;

    //A. check month
    if (get_month() > 12 || get_month() < 1)
    {
        debug=false;
    }
    //B. check day
    if (get_day() > days_in_month() || get_day() < 1)
    {
        debug =false;
    }

    //C. check year
    if (get_year() > 9999 || get_year() < 1970)
    {
        debug =false;
    }

    return debug;
 }
/**************************************************************
* PRE-CONDITIONS
* -day value
* POST-CONDITIONS
* -day portion of date is set
***************************************************************/
 int Date::days_in_month()
 {
     int days;
     switch(get_month())
     {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12:
             days=31;
             break;

         case 2:
         {
             days=28;
             if(is_leap())
                 days+=1;
         }
         break;

         case 4:
         case 6:
         case 9:
         case 11:
             days=30;
             break;

         default:
         days=0;
         cout << "days_in_months error\n";
     }
     return days;
 }
/**************************************************************
* PRE-CONDITIONS
* -n/a
* POST-CONDITIONS
* -bool value of whether year is a leap year
***************************************************************/
 bool Date::is_leap()//true if y is a leap year
 {
     bool year=true;
    if (get_year()%4==0 || (get_year()%100==0 && get_year()%400==0))
        year=true;
    else
        year=false;
     return year;
 }

 //PRIVATE FUNCTION
/**************************************************************
* PRE-CONDITIONS
* -n/a
* POST-CONDITIONS
* -valid date check
***************************************************************/
 int Date::check_error()
 {
     if (!date_is_valid())
     {
         return _error = INVALID_DATE;
     }
     else return _error=NO_ERROR;
 }

//ACESSORS/GETTERS
/******************************************************************/
 int Date::get_day() const
 {
     return _d;
 }
 int Date::get_month() const
 {
     return _m;
 }
 int Date::get_year() const
 {
     return _y;
 }

 bool Date::get_error() const{
     return _error;
 }

/**************************************************************
* PRE-CONDITIONS
* -Date for comparison
* POST-CONDITIONS
* -bool value for comparison below
***************************************************************/
bool Date::operator >(const Date& rhs) const{
  if(get_year() > rhs.get_year())
      return true;
  if(get_month() > rhs.get_month())
      return true;
  if(get_day() > rhs.get_day())
      return true;

    return false;
}
/**************************************************************
* PRE-CONDITIONS
* -Date for comparison
* POST-CONDITIONS
* -bool value for comparison below
***************************************************************/
bool Date::operator <(const Date& rhs) const{
  if(get_year() < rhs.get_year())
      return true;
  if(get_month() < rhs.get_month())
      return true;
  if(get_day() < rhs.get_day())
      return true;

    return false;
}
/**************************************************************
* PRE-CONDITIONS
* -Date for comparison
* POST-CONDITIONS
* -bool value for comparison below
***************************************************************/
bool Date::operator <=(const Date& rhs) const{
    if(this == &rhs)
        return true;
  if(get_year() < rhs.get_year())
      return true;
  if(get_month() < rhs.get_month())
      return true;
  if(get_day() < rhs.get_day())
      return true;

    return false;
}
/**************************************************************
* PRE-CONDITIONS
* -Date for comparison
* POST-CONDITIONS
* -bool value for comparison below
***************************************************************/
bool Date::operator >=(const Date& rhs) const{
    if(this == &rhs)
        return true;
  if(get_year() > rhs.get_year())
      return true;
  if(get_month() > rhs.get_month())
      return true;
  if(get_day() > rhs.get_day())
      return true;

    return false;
}
/**************************************************************
* PRE-CONDITIONS
* -Date for comparison
* POST-CONDITIONS
* -bool value for comparison below
***************************************************************/
bool Date::operator==(const Date& rhs) const{
    if (_m == rhs.get_month() && _d == rhs.get_day() && _y == rhs.get_year())
        return true;
    return false;
}
/**************************************************************
* PRE-CONDITIONS
* -Date for comparison
* POST-CONDITIONS
* -bool value for comparison below
***************************************************************/
bool Date::operator!=(const Date& rhs) const{
    if (_m != rhs.get_month() || _d != rhs.get_day() || _y != rhs.get_year())
        return true;
    return false;
}
/**************************************************************
* PRE-CONDITIONS
* -Date for printing
* POST-CONDITIONS
* -print of date
***************************************************************/
ostream& operator <<(ostream& outs, const Date& info)
{

   outs << info.get_month() << "/" << info.get_day() << "/" << info.get_year();
   return outs;
}
/**************************************************************
* PRE-CONDITIONS
* -Date for extraction
* POST-CONDITIONS
* -take in a string and get a Date obj
***************************************************************/
istream& operator >>(istream& ins, Date& info)
{
    char slash;
    int month, day, year;
    ins >> month >> slash >> day >> slash >> year;

    info.set_month(month);
    info.set_day(day);
    info.set_year(year);

    return ins;
}
