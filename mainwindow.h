#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "warehouse.h"
#include <sstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_salesButton_clicked();

    void on_memberButton_clicked();

    void on_inventoryButton_clicked();

    void on_returnButton_sales_clicked();

    void on_returnButton_inventory_clicked();

    void on_returnButton_members_clicked();

    void on_returnButton_membership_clicked();

    void on_returnButton_purchases_clicked();

    void on_membershipButton_clicked();

    void on_purchasesButton_clicked();

    void on_deleteMember_button_clicked();

    void on_addMember_button_clicked();

    void on_allMembers_button_clicked();

    void on_membershipDues_button_clicked();

    void on_expirings_button_clicked();

    void on_rebatesButton_clicked();

    void on_soloItemSold_button_clicked();

    void on_allItemsSold_button_clicked();

    void on_dailySalesButton_clicked();

    void on_convertToBasic_button_clicked();

    void on_convertToPreferred_button_clicked();

    void on_memberPurchase_button_clicked();

    void on_allMemberPurchase_button_clicked();

    void on_yearlySalesButton_clicked();

private:
    Ui::MainWindow *ui;
    Warehouse _club;
};
#endif // MAINWINDOW_H
