/******************************************************************************
 * Author           : Kenneth Tiet, Christine Nguyen, Chak Hei Tin
 * Project          : Wholesale Club Management
 * CLASS            : CS 8
 * SECTION          : MW (9:45 - 11:10) TR (9:45 - 11:50)
 * Due Date         : 4/9/2020
******************************************************************************/
#include "mainwindow.h"
#include <QApplication>
/******************************************************************************
 * PROGRAM DESCRIPTION
 * ____________________________________________________________________________
 *
 * This program is designed to be a management software for a wholesale club.
 * Functionality of this program includes member statistics, information,
 * item inventory, sales reports, etc.
 * ____________________________________________________________________________
 * INPUT:
 * Through GUI implementation, the user is prompted to make selections on the
 * interface itself in order to demonstrate its functionality
 *
 * OUTPUT:
 * Depending on GUI selection, outputs can vary
 *
******************************************************************************/

int main(int argc, char *argv[])
{
    QApplication a (argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
