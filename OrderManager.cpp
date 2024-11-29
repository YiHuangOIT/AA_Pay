//
// Created by 毅黄 on 2024/11/24.
//
#include "OrderManager.h"
#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

void addOrder(vector<OrderData>& orders) {
    string date, merchant, payer;
    int orderID, payerID;

    // create orderIndex based on previous order
    orderID = orders.size() + 1 ;

    // Enter valid Date;
    regex datePattern(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01])$)");
    while (!regex_match(date, datePattern))
        {
        cout << "Date (YYYY-MM-DD): ";
        cin >> date;
        }

    // Enter name of Merchant
    cout << "Merchant: ";
    cin.ignore();
    getline(cin, merchant);

    // Choose the payer of bill
    do {
        cout << "Payer (1-Randolph, 2-Mike): ";
        cin >> payerID;
    } while (payerID != 1 && payerID != 2);

    switch (payerID) {
        case 1: payer = "Randolph"; break;
        case 2: payer = "Mike"; break;
    }

    cin.ignore();


    // 创建订单对象
    OrderData order( orderID, date, merchant, payer);

    // Enter Items to current order one by one
    char choice;
    do {
        string name, category, user;
        double unitPrice, taxRate;
        int quantity, categoryID, taxRateID, userID;

        cout << "Name of Item: ";
        getline(cin, name);

        // Choose Category for the item
        do {
            cout << "Category (0-Other, 1-Meat, 2-Dairy/Egg," << endl;
            cout << "3-Staples, 4-Fruit/Vegetable, 5-Beverage): ";
            cin >> categoryID;
        } while (categoryID < 0 || categoryID > 5);

        switch (categoryID) {
            case 0: category = "Other"; break;
            case 1: category = "Meat"; break;
            case 2: category = "Dairy/Egg"; break;
            case 3: category = "Staples"; break;
            case 4: category = "FFV"; break;
            case 5: category = "Beverage"; break;
        }

        // Choose tax rate of item
        do {
            cout << "TaxRate (0=0%, 1=13%): ";
            cin >> taxRateID;
        } while (taxRateID < 0 || taxRateID > 1);

        switch (taxRateID) {
            case 0: taxRate = 0; break;
            case 1: taxRate = 0.13; break;
        }

        // Choose the user of item
        do {
            cout << "User (0-Shared, 1-Randolph, 2-Mike): ";
            cin >> userID;
        } while (userID < 0 || userID > 2);

        switch (userID) {
            case 0: user = "Shared"; break;
            case 1: user = "Randolph"; break;
            case 2: user = "Mike"; break;
        }

        // Enter unit price of item
        cout << "Unit Price: ";
        cin >> unitPrice;

        // Enter Quantity of item
        cout << "Item Quantity: ";
        cin >> quantity;
        cin.ignore(); // clean input buffer

        // add item to order
        ItemData item(name, category, user, unitPrice, quantity, taxRate);
        order.addItem(item);

        cout << "Next item？(y/n): ";
        cin >> choice;
        cin.ignore(); // clean input buffer again
    } while (choice == 'y' || choice == 'Y');

    // add order to orders
    orders.push_back(order);


    // 显示订单信息和物品列表
    order.display();

}