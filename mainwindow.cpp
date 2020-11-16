#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
                                         ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _club.updateMemberList();
    _club.updateSalesDays();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_inventoryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_memberButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_membershipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_purchasesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_returnButton_sales_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton_inventory_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton_members_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton_membership_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_returnButton_purchases_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_deleteMember_button_clicked()
{
    ui->memberDisplay->clear();

    if (ui->delete_nameRadio->isChecked() == false &&
        ui->delete_IDRadio->isChecked() == false)
    {
        ui->memberDisplay->setText("Please select either Name or ID.\n");
    }
    else if (ui->deleteMember_box->text().size() == 0)
    {
        ui->memberDisplay
          ->setText("The text box for the name or ID is empty.\n"
                    "Please enter a valid name or ID.");
    }
    else if (ui->delete_nameRadio->isChecked())
    {
        string n = ui->deleteMember_box->text().toStdString();

        if (_club.removeMember(n, 0) == true)
        {
            ui->memberDisplay
              ->setText("Member has been successfully removed.");
            return;
        }
        else
        {
            ui->memberDisplay
              ->setText("Member was not found.\n"
                        "Please enter a valid name or ID.");
            return;
        }
    }
    else if (ui->delete_IDRadio->isChecked())
    {
        for (int i = 0; i < ui->deleteMember_box->text().size(); i++)
        {
            if (ui->deleteMember_box->text()[i].isLetter())
            {
                ui->memberDisplay->setText("An invalid ID has been entered.\n"
                                           "Please enter a valid name or ID.");
            }
        }

        string i = ui->deleteMember_box->text().toStdString();

        if (_club.removeMember(i, 1) == true)
        {
            ui->memberDisplay
              ->setText("Member has been successfully removed.");
            return;
        }
        else
        {
            ui->memberDisplay
              ->setText("Member was not found.\n"
                        "Please enter a valid name or ID.");
            return;
        }
    }
}

void MainWindow::on_addMember_button_clicked()
{
    ui->memberDisplay->clear();

    if (ui->addName_box->text().isEmpty() || ui->addID_box->text().isEmpty()
        || !ui->addExp_box->date().isValid())
    {
        ui->memberDisplay->setText("Not all information boxes are filled.\n"
                                   "Please fill out all information boxes.");
        return;
    }
    else if (!ui->basicRadio->isChecked() && !ui->preferredRadio->isChecked())
    {
        ui->memberDisplay->setText("Please select either Basic or Preferred"
                                   "for the member's membership type.\n");
        return;
    }

    stringstream info;
    string name = ui->addName_box->text().toStdString();
    string ID = ui->addID_box->text().toStdString();
    Date exp(ui->addExp_box->date().month(), ui->addExp_box->date().day(),
             ui->addExp_box->date().year());

    for (size_t i = 0; i < ID.size(); i++)
    {
        if (ID[i] != '1' && ID[i] != '2' && ID[i] != '3' && ID[i] != '4' &&
            ID[i] != '5' && ID[i] != '6' && ID[i] != '7' && ID[i] != '8' &&
            ID[i] != '9' && ID[i] != '0')
        {
            ui->memberDisplay->setText("An invalid ID number has "
                                                "been entered.\nPlease enter "
                                                "all numbers for the ID.\n");
            return;
        }
    }

    if (ui->basicRadio->isChecked())
    {
        bool check;
        Members add(name, ID, "BASIC", exp);

        check = _club.addMember(add);

        if (check == true)
        {
            info << "Member successfully added!" << endl;
            info << "Name: " << name << endl;
            info << "ID: " << ID << endl;
            info << "Membership Type: BASIC" << endl;
            info << "Expiration: " << exp << endl;

            QString a = QString::fromStdString(info.str());

            ui->memberDisplay->setText(a);

            return;
        }
        else
        {
            info << "Member was not added!" << endl;
            info << "A name or ID match was found." << endl;
            QString a = QString::fromStdString(info.str());

            ui->memberDisplay->setText(a);

            return;
        }
    }
    else if (ui->preferredRadio->isChecked())
    {
        bool check;
        Members add(name, ID, "PREFERRED", exp);

        check = _club.addMember(add);

        if (check == true)
        {
            info << "Member successfully added!" << endl;
            info << "Name: " << name << endl;
            info << "ID: " << ID << endl;
            info << "Membership Type: PREFERRED" << endl;
            info << "Expiration: " << exp << endl;

            QString a = QString::fromStdString(info.str());

            ui->memberDisplay->setText(a);

            return;
        }
        else
        {
            info << "Member was not added!" << endl;
            info << "A name or ID match was found." << endl;
            QString a = QString::fromStdString(info.str());

            ui->memberDisplay->setText(a);

            return;
        }

    }
}

void MainWindow::on_allMembers_button_clicked()
{
    stringstream info;

    info << "LIST OF ALL MEMBERS:" << endl;

    for (size_t i = 0; i < _club.wholesale_club.size(); i++)
    {
        info << "Name: " << _club.wholesale_club[i].name() << endl;
        info << "ID: " << _club.wholesale_club[i].id() << endl;

        if (_club.wholesale_club[i].type() == 0)
            info << "Membership Type: BASIC" << endl << endl;
        else
            info << "Membership Type: PREFERRED" << endl << endl;
    }

    QString a = QString::fromStdString(info.str());

    ui->memberDisplay->setText(a);

    return;
}

void MainWindow::on_membershipDues_button_clicked()
{
    ui->membershipDues_display->clear();
    stringstream s;

    if (ui->basicOnly_membership->isChecked())
    {
        s << "BASIC MEMBERSHIP DUES:" << endl << endl;

        for (size_t i = 0; i < _club.wholesale_club.size(); i++)
        {
            if (_club.wholesale_club[i].type() == BASIC)
            {
                s << _club.wholesale_club[i].name() << " (ID: ";
                s << _club.wholesale_club[i].id() << ")" << endl;
                s << "Membership Due: " << _club.wholesale_club[i].expiration();
                s << endl << "Amount Due: $" << _club.wholesale_club[i].payment();
                s << endl << endl;
            }
        }

        QString info = QString::fromStdString(s.str());
        ui->membershipDues_display->setText(info);
    }
    else if (ui->prefOnly_membership->isChecked())
    {
        s << "PREFERRED MEMBERSHIP DUES:" << endl << endl;

        for (size_t i = 0; i < _club.wholesale_club.size(); i++)
        {
            if (_club.wholesale_club[i].type() == PREFERRED)
            {
                s << _club.wholesale_club[i].name() << " (ID: ";
                s << _club.wholesale_club[i].id() << ")" << endl;
                s << "Membership Due: " << _club.wholesale_club[i].expiration();
                s << endl << "Amount Due: $" << _club.wholesale_club[i].payment();
                s << endl << endl;
            }
        }

        QString info = QString::fromStdString(s.str());
        ui->membershipDues_display->setText(info);
    }
    else if (ui->allMem_membership->isChecked())
    {
        s << "ALL MEMBERSHIP DUES:" << endl << endl;

        for (size_t i = 0; i < _club.wholesale_club.size(); i++)
        {
            s << _club.wholesale_club[i].name() << " (ID: ";
            s << _club.wholesale_club[i].id() << ")" << endl;
            s << "Membership Due: " << _club.wholesale_club[i].expiration();
            s << endl << "Amount Due: $" << _club.wholesale_club[i].payment();
            s << endl << endl;
        }

        QString info = QString::fromStdString(s.str());
        ui->membershipDues_display->setText(info);
    }
    else
    {
        ui->membershipDues_display->setText("Please select a filter for the "
                                            "search.\n");
        return;
    }
}

void MainWindow::on_expirings_button_clicked()
{
    stringstream s;
    QString info;
    int month;

    if (ui->monthBox->text().isEmpty())
    {
        ui->monthExpirings_display->setText("Please enter a month of the year "
                                            "(The number or full month name "
                                            "with the first letter capitalized");
        return;
    }
    else if (ui->monthBox->text() == "1" || ui->monthBox->text() == "January")
        month = 1;
    else if (ui->monthBox->text() == "2" || ui->monthBox->text() == "February")
        month = 2;
    else if (ui->monthBox->text() == "3" || ui->monthBox->text() == "March")
        month = 3;
    else if (ui->monthBox->text() == "4" || ui->monthBox->text() == "April")
        month = 4;
    else if (ui->monthBox->text() == "5" || ui->monthBox->text() == "May")
        month = 5;
    else if (ui->monthBox->text() == "6" || ui->monthBox->text() == "June")
        month = 6;
    else if (ui->monthBox->text() == "7" || ui->monthBox->text() == "July")
        month = 7;
    else if (ui->monthBox->text() == "8" || ui->monthBox->text() == "August")
        month = 8;
    else if (ui->monthBox->text() == "9" || ui->monthBox->text() == "September")
        month = 9;
    else if (ui->monthBox->text() == "10" || ui->monthBox->text() == "October")
        month = 10;
    else if (ui->monthBox->text() == "11" || ui->monthBox->text() == "November")
        month = 11;
    else if (ui->monthBox->text() == "12" || ui->monthBox->text() == "December")
        month = 12;
    else
    {
        ui->monthExpirings_display->setText("Invalid month choice!\n"
                                            "Please enter the full month name"
                                            " or the number associated.\n");
        return;
    }


    if (ui->basicOnly_membership->isChecked())
    {
        s << "BASIC MONTHLY EXPIRINGS:" << endl;

        for (size_t i = 0; i < _club.wholesale_club.size(); i++)
        {
            if (_club.wholesale_club[i].type() == BASIC &&
                    _club.wholesale_club[i].expiration().get_month() == month)
            {
                s << _club.wholesale_club[i].name();
                s << " (ID: " << _club.wholesale_club[i].id() << ")\n";
                s << "Membership Due: "
                  << _club.wholesale_club[i].expiration() << endl << endl;
            }
        }
        info = QString::fromStdString(s.str());
        ui->monthExpirings_display->setText(info);
        return;
    }
    else if (ui->prefOnly_membership->isChecked())
    {
        s << "PREFERRED MONTHLY EXPIRINGS:" << endl;

        for (size_t i = 0; i < _club.wholesale_club.size(); i++)
        {
            if (_club.wholesale_club[i].type() == PREFERRED &&
                    _club.wholesale_club[i].expiration().get_month() == month)
            {
                s << _club.wholesale_club[i].name();
                s << " (ID: " << _club.wholesale_club[i].id() << ")\n";
                s << "Membership Due: "
                  << _club.wholesale_club[i].expiration() << endl << endl;
            }
        }
        info = QString::fromStdString(s.str());
        ui->monthExpirings_display->setText(info);
        return;
    }
    else if (ui->allMem_membership->isChecked())
    {
        s << "ALL MONTHLY EXPIRINGS:" << endl;

        for (size_t i = 0; i < _club.wholesale_club.size(); i++)
        {
            if (_club.wholesale_club[i].expiration().get_month() == month)
            {
                s << _club.wholesale_club[i].name();
                s << " (ID: " << _club.wholesale_club[i].id() << ")\n";
                s << "Membership Due: "
                  << _club.wholesale_club[i].expiration() << endl << endl;
            }
        }
        info = QString::fromStdString(s.str());
        ui->monthExpirings_display->setText(info);
        return;
    }
    else
    {
        ui->membershipDues_display->setText("Please select a filter for the "
                                            "search.\n");
        return;
    }
}

void MainWindow::on_rebatesButton_clicked()
{
    QString s = QString::fromStdString(_club.MemberRebates());
    ui->salesReportsDisplay->setText(s);
    return;
}

void MainWindow::on_soloItemSold_button_clicked()
{
    QString print;
    string hold;

    if (ui->itemSearch_box->text().isEmpty())
    {
        ui->inventoryDisplay->setText("Please enter an item name.\n");
        return;
    }
    else
    {
        hold = _club.itemsSold(ui->itemSearch_box->text().toStdString());
        print = QString::fromStdString(hold);
        ui->inventoryDisplay->setText(print);
        return;
    }
}

void MainWindow::on_allItemsSold_button_clicked()
{
    ui->inventoryDisplay->clear();
    QString print = QString::fromStdString(_club.totalItemsSold());
    ui->inventoryDisplay->setText(print);
    return;
}

void MainWindow::on_dailySalesButton_clicked()
{
    ui->salesReportsDisplay->clear();

    Date current;
    current.set_month(ui->daySales_select->date().month());
    current.set_day(ui->daySales_select->date().day());
    current.set_year(ui->daySales_select->date().year());

    QString print = QString::fromStdString(_club.dailySalesReport(current));
    ui->salesReportsDisplay->setText(print);
}


void MainWindow::on_convertToBasic_button_clicked()
{
    ui->memberDisplay->clear();
    QString print;
    string hold;

    hold = _club.downgradeMember();
    print = QString::fromStdString(hold);

    ui->memberDisplay->setText(print);
}

void MainWindow::on_convertToPreferred_button_clicked()
{
    ui->memberDisplay->clear();
    QString print;
    string hold;

    hold = _club.upgradeMember();
    print = QString::fromStdString(hold);

    ui->memberDisplay->setText(print);
}

void MainWindow::on_memberPurchase_button_clicked()
{
    ui->purchasesDisplay->clear();
    QString print;
    string hold;

    if (ui->memberPurchase_box->text().isEmpty())
    {
        ui->purchasesDisplay->setText("Please enter a name or ID.");
        return;
    }
    else if (!ui->namePurchase_option->isChecked() && !ui->idPurchase_option)
    {
        ui->purchasesDisplay->setText("Please select a name/ID filter.");
        return;
    }
    else if (ui->namePurchase_option->isChecked())
    {
        hold = ui->memberPurchase_box->text().toStdString();
        print = QString::fromStdString(_club.totalPurchasesBySingleMember(hold, 0));

        ui->purchasesDisplay->setText(print);
        return;
    }
    else if (ui->idPurchase_option->isChecked())
    {
        hold = ui->memberPurchase_box->text().toStdString();
        print = QString::fromStdString(_club.totalPurchasesBySingleMember(hold, 1));

        ui->purchasesDisplay->setText(print);
        return;
    }
}

void MainWindow::on_allMemberPurchase_button_clicked()
{
    ui->purchasesDisplay->clear();
    QString print;
    string hold;

    hold = _club.totalPurchasesByAllMembers();
    print = QString::fromStdString(hold);

    ui->purchasesDisplay->setText(print);
    return;
}

void MainWindow::on_yearlySalesButton_clicked()
{
    ui->salesReportsDisplay->clear();
    QString print;
    string hold;

    hold = _club.yearlySalesReport();
    print = QString::fromStdString(hold);

    ui->salesReportsDisplay->setText(print);
    return;
}
