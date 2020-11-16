/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *frontPage_0;
    QLabel *mainTitle;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *salesButton;
    QPushButton *inventoryButton;
    QPushButton *memberButton;
    QPushButton *membershipButton;
    QPushButton *purchasesButton;
    QWidget *salesReports_1;
    QPushButton *returnButton_sales;
    QLabel *salesReports_label;
    QTextBrowser *salesReportsDisplay;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_12;
    QLabel *dayLabel;
    QDateEdit *daySales_select;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *dailySalesButton;
    QPushButton *yearlySalesButton;
    QPushButton *rebatesButton;
    QWidget *inventory_3;
    QPushButton *returnButton_inventory;
    QTextBrowser *inventoryDisplay;
    QLabel *inventoryLabel;
    QPushButton *allItemsSold_button;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *itemSearch_label;
    QLineEdit *itemSearch_box;
    QPushButton *soloItemSold_button;
    QWidget *members_2;
    QPushButton *returnButton_members;
    QTextBrowser *memberDisplay;
    QLabel *memberTitle;
    QPushButton *addMember_button;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *delete_nameRadio;
    QRadioButton *delete_IDRadio;
    QLineEdit *deleteMember_box;
    QPushButton *deleteMember_button;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *addExp_label;
    QDateEdit *addExp_box;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *addID_label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *addID_box;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *addName_label;
    QLineEdit *addName_box;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *convertToBasic_button;
    QPushButton *convertToPreferred_button;
    QPushButton *allMembers_button;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *basicRadio;
    QRadioButton *preferredRadio;
    QWidget *membership_4;
    QPushButton *returnButton_membership;
    QLabel *membershipTitle;
    QTextBrowser *membershipDues_display;
    QTextBrowser *monthExpirings_display;
    QPushButton *membershipDues_button;
    QPushButton *expirings_button;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *monthLabel;
    QLineEdit *monthBox;
    QWidget *layoutWidget10;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *basicOnly_membership;
    QRadioButton *prefOnly_membership;
    QRadioButton *allMem_membership;
    QWidget *purchases_5;
    QPushButton *returnButton_purchases;
    QLabel *purchasesTitle;
    QTextBrowser *purchasesDisplay;
    QPushButton *allMemberPurchase_button;
    QWidget *layoutWidget11;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *memberPurchase_box;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *namePurchase_option;
    QRadioButton *idPurchase_option;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *memberPurchase_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1183, 787);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1393, 781));
        frontPage_0 = new QWidget();
        frontPage_0->setObjectName(QString::fromUtf8("frontPage_0"));
        mainTitle = new QLabel(frontPage_0);
        mainTitle->setObjectName(QString::fromUtf8("mainTitle"));
        mainTitle->setGeometry(QRect(250, 60, 691, 61));
        verticalLayoutWidget = new QWidget(frontPage_0);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(390, 130, 421, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        salesButton = new QPushButton(verticalLayoutWidget);
        salesButton->setObjectName(QString::fromUtf8("salesButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(salesButton->sizePolicy().hasHeightForWidth());
        salesButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(salesButton);

        inventoryButton = new QPushButton(verticalLayoutWidget);
        inventoryButton->setObjectName(QString::fromUtf8("inventoryButton"));
        sizePolicy1.setHeightForWidth(inventoryButton->sizePolicy().hasHeightForWidth());
        inventoryButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(inventoryButton);

        memberButton = new QPushButton(verticalLayoutWidget);
        memberButton->setObjectName(QString::fromUtf8("memberButton"));
        sizePolicy1.setHeightForWidth(memberButton->sizePolicy().hasHeightForWidth());
        memberButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(memberButton);

        membershipButton = new QPushButton(verticalLayoutWidget);
        membershipButton->setObjectName(QString::fromUtf8("membershipButton"));
        sizePolicy1.setHeightForWidth(membershipButton->sizePolicy().hasHeightForWidth());
        membershipButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(membershipButton);

        purchasesButton = new QPushButton(verticalLayoutWidget);
        purchasesButton->setObjectName(QString::fromUtf8("purchasesButton"));
        sizePolicy1.setHeightForWidth(purchasesButton->sizePolicy().hasHeightForWidth());
        purchasesButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(purchasesButton);

        stackedWidget->addWidget(frontPage_0);
        salesReports_1 = new QWidget();
        salesReports_1->setObjectName(QString::fromUtf8("salesReports_1"));
        returnButton_sales = new QPushButton(salesReports_1);
        returnButton_sales->setObjectName(QString::fromUtf8("returnButton_sales"));
        returnButton_sales->setGeometry(QRect(560, 710, 81, 31));
        salesReports_label = new QLabel(salesReports_1);
        salesReports_label->setObjectName(QString::fromUtf8("salesReports_label"));
        salesReports_label->setGeometry(QRect(404, 40, 391, 61));
        salesReportsDisplay = new QTextBrowser(salesReports_1);
        salesReportsDisplay->setObjectName(QString::fromUtf8("salesReportsDisplay"));
        salesReportsDisplay->setGeometry(QRect(70, 121, 1041, 461));
        layoutWidget = new QWidget(salesReports_1);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(690, 710, 411, 31));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        dayLabel = new QLabel(layoutWidget);
        dayLabel->setObjectName(QString::fromUtf8("dayLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dayLabel->sizePolicy().hasHeightForWidth());
        dayLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_12->addWidget(dayLabel);

        daySales_select = new QDateEdit(layoutWidget);
        daySales_select->setObjectName(QString::fromUtf8("daySales_select"));
        sizePolicy.setHeightForWidth(daySales_select->sizePolicy().hasHeightForWidth());
        daySales_select->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(daySales_select);

        layoutWidget1 = new QWidget(salesReports_1);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 620, 441, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        dailySalesButton = new QPushButton(layoutWidget1);
        dailySalesButton->setObjectName(QString::fromUtf8("dailySalesButton"));
        sizePolicy1.setHeightForWidth(dailySalesButton->sizePolicy().hasHeightForWidth());
        dailySalesButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(dailySalesButton);

        yearlySalesButton = new QPushButton(layoutWidget1);
        yearlySalesButton->setObjectName(QString::fromUtf8("yearlySalesButton"));
        sizePolicy1.setHeightForWidth(yearlySalesButton->sizePolicy().hasHeightForWidth());
        yearlySalesButton->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(yearlySalesButton);

        rebatesButton = new QPushButton(layoutWidget1);
        rebatesButton->setObjectName(QString::fromUtf8("rebatesButton"));
        sizePolicy.setHeightForWidth(rebatesButton->sizePolicy().hasHeightForWidth());
        rebatesButton->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(rebatesButton);

        stackedWidget->addWidget(salesReports_1);
        inventory_3 = new QWidget();
        inventory_3->setObjectName(QString::fromUtf8("inventory_3"));
        returnButton_inventory = new QPushButton(inventory_3);
        returnButton_inventory->setObjectName(QString::fromUtf8("returnButton_inventory"));
        returnButton_inventory->setGeometry(QRect(560, 710, 81, 31));
        inventoryDisplay = new QTextBrowser(inventory_3);
        inventoryDisplay->setObjectName(QString::fromUtf8("inventoryDisplay"));
        inventoryDisplay->setGeometry(QRect(50, 80, 1081, 561));
        inventoryLabel = new QLabel(inventory_3);
        inventoryLabel->setObjectName(QString::fromUtf8("inventoryLabel"));
        inventoryLabel->setGeometry(QRect(340, 10, 521, 71));
        allItemsSold_button = new QPushButton(inventory_3);
        allItemsSold_button->setObjectName(QString::fromUtf8("allItemsSold_button"));
        allItemsSold_button->setGeometry(QRect(690, 670, 441, 91));
        layoutWidget2 = new QWidget(inventory_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(50, 670, 461, 91));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        itemSearch_label = new QLabel(layoutWidget2);
        itemSearch_label->setObjectName(QString::fromUtf8("itemSearch_label"));

        horizontalLayout->addWidget(itemSearch_label);

        itemSearch_box = new QLineEdit(layoutWidget2);
        itemSearch_box->setObjectName(QString::fromUtf8("itemSearch_box"));

        horizontalLayout->addWidget(itemSearch_box);


        verticalLayout_3->addLayout(horizontalLayout);

        soloItemSold_button = new QPushButton(layoutWidget2);
        soloItemSold_button->setObjectName(QString::fromUtf8("soloItemSold_button"));
        sizePolicy1.setHeightForWidth(soloItemSold_button->sizePolicy().hasHeightForWidth());
        soloItemSold_button->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(soloItemSold_button);

        stackedWidget->addWidget(inventory_3);
        members_2 = new QWidget();
        members_2->setObjectName(QString::fromUtf8("members_2"));
        returnButton_members = new QPushButton(members_2);
        returnButton_members->setObjectName(QString::fromUtf8("returnButton_members"));
        returnButton_members->setGeometry(QRect(560, 710, 81, 31));
        memberDisplay = new QTextBrowser(members_2);
        memberDisplay->setObjectName(QString::fromUtf8("memberDisplay"));
        memberDisplay->setGeometry(QRect(75, 100, 521, 571));
        memberTitle = new QLabel(members_2);
        memberTitle->setObjectName(QString::fromUtf8("memberTitle"));
        memberTitle->setGeometry(QRect(80, 40, 511, 41));
        addMember_button = new QPushButton(members_2);
        addMember_button->setObjectName(QString::fromUtf8("addMember_button"));
        addMember_button->setGeometry(QRect(640, 260, 461, 51));
        layoutWidget3 = new QWidget(members_2);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(640, 350, 461, 41));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        delete_nameRadio = new QRadioButton(layoutWidget3);
        delete_nameRadio->setObjectName(QString::fromUtf8("delete_nameRadio"));

        horizontalLayout_6->addWidget(delete_nameRadio);

        delete_IDRadio = new QRadioButton(layoutWidget3);
        delete_IDRadio->setObjectName(QString::fromUtf8("delete_IDRadio"));

        horizontalLayout_6->addWidget(delete_IDRadio);

        deleteMember_box = new QLineEdit(layoutWidget3);
        deleteMember_box->setObjectName(QString::fromUtf8("deleteMember_box"));

        horizontalLayout_6->addWidget(deleteMember_box);

        deleteMember_button = new QPushButton(members_2);
        deleteMember_button->setObjectName(QString::fromUtf8("deleteMember_button"));
        deleteMember_button->setGeometry(QRect(640, 390, 461, 51));
        layoutWidget4 = new QWidget(members_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(640, 180, 461, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        addExp_label = new QLabel(layoutWidget4);
        addExp_label->setObjectName(QString::fromUtf8("addExp_label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addExp_label->sizePolicy().hasHeightForWidth());
        addExp_label->setSizePolicy(sizePolicy3);

        horizontalLayout_5->addWidget(addExp_label);

        addExp_box = new QDateEdit(layoutWidget4);
        addExp_box->setObjectName(QString::fromUtf8("addExp_box"));
        sizePolicy.setHeightForWidth(addExp_box->sizePolicy().hasHeightForWidth());
        addExp_box->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(addExp_box);

        layoutWidget5 = new QWidget(members_2);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(640, 140, 461, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        addID_label = new QLabel(layoutWidget5);
        addID_label->setObjectName(QString::fromUtf8("addID_label"));

        horizontalLayout_4->addWidget(addID_label);

        horizontalSpacer = new QSpacerItem(24, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        addID_box = new QLineEdit(layoutWidget5);
        addID_box->setObjectName(QString::fromUtf8("addID_box"));

        horizontalLayout_4->addWidget(addID_box);

        layoutWidget6 = new QWidget(members_2);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(640, 100, 461, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        addName_label = new QLabel(layoutWidget6);
        addName_label->setObjectName(QString::fromUtf8("addName_label"));

        horizontalLayout_3->addWidget(addName_label);

        addName_box = new QLineEdit(layoutWidget6);
        addName_box->setObjectName(QString::fromUtf8("addName_box"));

        horizontalLayout_3->addWidget(addName_box);

        layoutWidget7 = new QWidget(members_2);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(640, 610, 461, 61));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        convertToBasic_button = new QPushButton(layoutWidget7);
        convertToBasic_button->setObjectName(QString::fromUtf8("convertToBasic_button"));
        sizePolicy1.setHeightForWidth(convertToBasic_button->sizePolicy().hasHeightForWidth());
        convertToBasic_button->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(convertToBasic_button);

        convertToPreferred_button = new QPushButton(layoutWidget7);
        convertToPreferred_button->setObjectName(QString::fromUtf8("convertToPreferred_button"));
        sizePolicy1.setHeightForWidth(convertToPreferred_button->sizePolicy().hasHeightForWidth());
        convertToPreferred_button->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(convertToPreferred_button);

        allMembers_button = new QPushButton(members_2);
        allMembers_button->setObjectName(QString::fromUtf8("allMembers_button"));
        allMembers_button->setGeometry(QRect(640, 480, 461, 91));
        layoutWidget8 = new QWidget(members_2);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(780, 220, 181, 31));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        basicRadio = new QRadioButton(layoutWidget8);
        basicRadio->setObjectName(QString::fromUtf8("basicRadio"));
        sizePolicy1.setHeightForWidth(basicRadio->sizePolicy().hasHeightForWidth());
        basicRadio->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(basicRadio);

        preferredRadio = new QRadioButton(layoutWidget8);
        preferredRadio->setObjectName(QString::fromUtf8("preferredRadio"));
        sizePolicy1.setHeightForWidth(preferredRadio->sizePolicy().hasHeightForWidth());
        preferredRadio->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(preferredRadio);

        stackedWidget->addWidget(members_2);
        membership_4 = new QWidget();
        membership_4->setObjectName(QString::fromUtf8("membership_4"));
        returnButton_membership = new QPushButton(membership_4);
        returnButton_membership->setObjectName(QString::fromUtf8("returnButton_membership"));
        returnButton_membership->setGeometry(QRect(560, 710, 81, 31));
        membershipTitle = new QLabel(membership_4);
        membershipTitle->setObjectName(QString::fromUtf8("membershipTitle"));
        membershipTitle->setGeometry(QRect(390, 30, 421, 61));
        membershipDues_display = new QTextBrowser(membership_4);
        membershipDues_display->setObjectName(QString::fromUtf8("membershipDues_display"));
        membershipDues_display->setGeometry(QRect(80, 100, 431, 531));
        monthExpirings_display = new QTextBrowser(membership_4);
        monthExpirings_display->setObjectName(QString::fromUtf8("monthExpirings_display"));
        monthExpirings_display->setGeometry(QRect(690, 100, 401, 531));
        membershipDues_button = new QPushButton(membership_4);
        membershipDues_button->setObjectName(QString::fromUtf8("membershipDues_button"));
        membershipDues_button->setGeometry(QRect(80, 670, 431, 71));
        expirings_button = new QPushButton(membership_4);
        expirings_button->setObjectName(QString::fromUtf8("expirings_button"));
        expirings_button->setGeometry(QRect(689, 710, 401, 31));
        layoutWidget9 = new QWidget(membership_4);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(694, 663, 391, 41));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        monthLabel = new QLabel(layoutWidget9);
        monthLabel->setObjectName(QString::fromUtf8("monthLabel"));

        horizontalLayout_7->addWidget(monthLabel);

        monthBox = new QLineEdit(layoutWidget9);
        monthBox->setObjectName(QString::fromUtf8("monthBox"));

        horizontalLayout_7->addWidget(monthBox);

        layoutWidget10 = new QWidget(membership_4);
        layoutWidget10->setObjectName(QString::fromUtf8("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(540, 550, 131, 111));
        verticalLayout_5 = new QVBoxLayout(layoutWidget10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        basicOnly_membership = new QRadioButton(layoutWidget10);
        basicOnly_membership->setObjectName(QString::fromUtf8("basicOnly_membership"));

        verticalLayout_5->addWidget(basicOnly_membership);

        prefOnly_membership = new QRadioButton(layoutWidget10);
        prefOnly_membership->setObjectName(QString::fromUtf8("prefOnly_membership"));

        verticalLayout_5->addWidget(prefOnly_membership);

        allMem_membership = new QRadioButton(layoutWidget10);
        allMem_membership->setObjectName(QString::fromUtf8("allMem_membership"));

        verticalLayout_5->addWidget(allMem_membership);

        stackedWidget->addWidget(membership_4);
        purchases_5 = new QWidget();
        purchases_5->setObjectName(QString::fromUtf8("purchases_5"));
        returnButton_purchases = new QPushButton(purchases_5);
        returnButton_purchases->setObjectName(QString::fromUtf8("returnButton_purchases"));
        returnButton_purchases->setGeometry(QRect(560, 710, 81, 31));
        purchasesTitle = new QLabel(purchases_5);
        purchasesTitle->setObjectName(QString::fromUtf8("purchasesTitle"));
        purchasesTitle->setGeometry(QRect(410, 30, 381, 71));
        purchasesDisplay = new QTextBrowser(purchases_5);
        purchasesDisplay->setObjectName(QString::fromUtf8("purchasesDisplay"));
        purchasesDisplay->setGeometry(QRect(130, 120, 921, 501));
        allMemberPurchase_button = new QPushButton(purchases_5);
        allMemberPurchase_button->setObjectName(QString::fromUtf8("allMemberPurchase_button"));
        allMemberPurchase_button->setGeometry(QRect(680, 655, 451, 91));
        layoutWidget11 = new QWidget(purchases_5);
        layoutWidget11->setObjectName(QString::fromUtf8("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(40, 653, 481, 91));
        verticalLayout_4 = new QVBoxLayout(layoutWidget11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        memberPurchase_box = new QLineEdit(layoutWidget11);
        memberPurchase_box->setObjectName(QString::fromUtf8("memberPurchase_box"));

        verticalLayout_4->addWidget(memberPurchase_box);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        namePurchase_option = new QRadioButton(layoutWidget11);
        namePurchase_option->setObjectName(QString::fromUtf8("namePurchase_option"));

        horizontalLayout_8->addWidget(namePurchase_option);

        idPurchase_option = new QRadioButton(layoutWidget11);
        idPurchase_option->setObjectName(QString::fromUtf8("idPurchase_option"));

        horizontalLayout_8->addWidget(idPurchase_option);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_8);

        memberPurchase_button = new QPushButton(layoutWidget11);
        memberPurchase_button->setObjectName(QString::fromUtf8("memberPurchase_button"));

        verticalLayout_4->addWidget(memberPurchase_button);

        stackedWidget->addWidget(purchases_5);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mainTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">Wholesale Club</span></p></body></html>", nullptr));
        salesButton->setText(QCoreApplication::translate("MainWindow", "Sales Reports", nullptr));
        inventoryButton->setText(QCoreApplication::translate("MainWindow", "Inventory Management", nullptr));
        memberButton->setText(QCoreApplication::translate("MainWindow", "Member Management", nullptr));
        membershipButton->setText(QCoreApplication::translate("MainWindow", "Membership Management", nullptr));
        purchasesButton->setText(QCoreApplication::translate("MainWindow", "Purchases Management", nullptr));
        returnButton_sales->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        salesReports_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Sales Reports</span></p></body></html>", nullptr));
        dayLabel->setText(QCoreApplication::translate("MainWindow", "Day:", nullptr));
        dailySalesButton->setText(QCoreApplication::translate("MainWindow", "Daily Sales", nullptr));
        yearlySalesButton->setText(QCoreApplication::translate("MainWindow", "Yearly Sales", nullptr));
        rebatesButton->setText(QCoreApplication::translate("MainWindow", "Rebates", nullptr));
        returnButton_inventory->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        inventoryLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Inventory Management</span></p></body></html>", nullptr));
        allItemsSold_button->setText(QCoreApplication::translate("MainWindow", "Display All Items Information", nullptr));
        itemSearch_label->setText(QCoreApplication::translate("MainWindow", "Item Name: ", nullptr));
        soloItemSold_button->setText(QCoreApplication::translate("MainWindow", "Display Item Information", nullptr));
        returnButton_members->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        memberTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Member Management</span></p></body></html>", nullptr));
        addMember_button->setText(QCoreApplication::translate("MainWindow", "Add Member", nullptr));
        delete_nameRadio->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        delete_IDRadio->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        deleteMember_button->setText(QCoreApplication::translate("MainWindow", "Delete Member", nullptr));
        addExp_label->setText(QCoreApplication::translate("MainWindow", "Membership Ends:", nullptr));
        addID_label->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        addName_label->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        convertToBasic_button->setText(QCoreApplication::translate("MainWindow", "Convert to Basic List", nullptr));
        convertToPreferred_button->setText(QCoreApplication::translate("MainWindow", "Convert to Preferred List", nullptr));
        allMembers_button->setText(QCoreApplication::translate("MainWindow", "Show All Members", nullptr));
        basicRadio->setText(QCoreApplication::translate("MainWindow", "Basic", nullptr));
        preferredRadio->setText(QCoreApplication::translate("MainWindow", "Preferred", nullptr));
        returnButton_membership->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        membershipTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Membership Management</span></p></body></html>", nullptr));
        membershipDues_button->setText(QCoreApplication::translate("MainWindow", "Membership Dues", nullptr));
        expirings_button->setText(QCoreApplication::translate("MainWindow", "Expirings", nullptr));
        monthLabel->setText(QCoreApplication::translate("MainWindow", "Month:", nullptr));
        basicOnly_membership->setText(QCoreApplication::translate("MainWindow", "Basic", nullptr));
        prefOnly_membership->setText(QCoreApplication::translate("MainWindow", "Preferred", nullptr));
        allMem_membership->setText(QCoreApplication::translate("MainWindow", "All Members", nullptr));
        returnButton_purchases->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        purchasesTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/><span style=\" font-size:16pt; font-weight:600;\">Purchases Management</span></p></body></html>", nullptr));
        allMemberPurchase_button->setText(QCoreApplication::translate("MainWindow", "All Member Purchases", nullptr));
        namePurchase_option->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        idPurchase_option->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        memberPurchase_button->setText(QCoreApplication::translate("MainWindow", "Total Individual Purchases", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
