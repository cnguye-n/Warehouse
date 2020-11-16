#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "members.h"
#include "item.h"
#include "date.h"
#include "list.h"
#include "history.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Warehouse
{
public:
    // default constructor
    Warehouse();

    // read-in file functions
    void updateMemberList();
    void updateSalesDays();

    // vector mutators for the class
    bool addMember(Members& add_this);
    bool removeMember(string nameID, bool nameOrID);

    // reports for the displaying
    string dailySalesReport(Date d);  //Uses Quantity Sold,
    string yearlySalesReport();

    //Rebates for each members
    string MemberRebates();

    // total purchases for members
    string totalPurchasesBySingleMember(string nameID, bool nameorID);
    string totalPurchasesByAllMembers();

    // item inventory
    string itemsSold(string item_name);
    string totalItemsSold();

    //list of basic members that should promote to perferred
    string upgradeMember();
    //list of preferred members that should convert to basic
    string downgradeMember();

    // container for members
    vector <Members> wholesale_club;
};

#endif // WAREHOUSE_H
