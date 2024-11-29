//
// Created by 毅黄 on 2024/11/24.
//
#include "Report.h"
//#include "ItemData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
using namespace std;

void monthShopList(vector<OrderData>& orders) {
    string year_month;
    int recordCount = 0;

    // Enter month information
    cout << "Which month would you like to check (YYYY-MM): ";
    cin >> year_month;
    // Verify month information
    regex monthPattern(R"(^\d{4}-(0[1-9]|1[0-2])$)");
    while (!regex_match(year_month, monthPattern))
    {
        cout << "Invalid year-month, please enter in format YYYY-MM : ";
        cin >> year_month;
    }

    //Iterate through monthly shopping list
    for (const auto& order : orders) {
        if (year_month == order.getDate().substr(0, 7)) {
            order.display();
            recordCount++;
        }
    }
    if (recordCount == 0) {
        cout << "No matching record to the condition!\n";
    }
}

void monthCostReport(vector<OrderData>& orders) {
    string year_month;
    double monthTotalCost = 0;      // Monthly cost of everyone
    double monthShareCost_1 = 0;    // Monthly cost of User_1
    double monthShareCost_2 = 0;    // Monthly cost of User_2
    double monthPayment_1 = 0;    // Monthly cost paid by User_1
    double monthPayment_2 = 0;    // Monthly cost paid by User_2

    // Enter month information
    cout << "Which month would you like to check (YYYY-MM): ";
    cin >> year_month;
    // Verify month information
    regex monthPattern(R"(^\d{4}-(0[1-9]|1[0-2])$)");
    while (!regex_match(year_month, monthPattern))
    {
        cout << "Invalid year-month, please enter in format YYYY-MM : ";
        cin >> year_month;
    }

    //Iterate through moshly shopping list
    for (const auto& order : orders) {
        if (year_month == order.getDate().substr(0, 7)) {

            // Calculate total cost or payment
            monthTotalCost += order.calculateTotal();

            // Calculate payment of Randolph
            if (order.getPayer() == "Randolph") {
                monthPayment_1 += order.calculateTotal();
            }

            // Calculate payment of Mike
            if (order.getPayer() == "Mike") {
                monthPayment_2 += order.calculateTotal();
            }

            // Read detailed item information of the order.
            const auto& items = order.getItems();

            for (const auto& item : items) {

                // Account cost to Randolph when he is the user
                if (item.getUser() == "Randolph") {
                    monthShareCost_1 += item.getTotalPrice();
                }

                // Account cost to Mike when he is the user
                if (item.getUser() == "Mike") {
                    monthShareCost_2 += item.getTotalPrice();
                }

                // Account cost to Randolph & Mike when cost is shared
                if (item.getUser() == "Shared") {
                    monthShareCost_1 += item.getTotalPrice()/2;
                    monthShareCost_2 += item.getTotalPrice()/2;
                }
            }

        }
    }

        cout << "\nCost Report: " << year_month << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "This month, Randolph and Mike has spent $" << monthTotalCost << "(CAD) so far." << endl;
        cout << "Out of them, Randolph consumed $" << monthShareCost_1 << " and Mike consumed $" << monthShareCost_2 << "(CAD)." << endl; ;
        cout << "Out of them, Randolph paid $" << monthPayment_1 << " and Mike paid $" << monthPayment_2 << "(CAD)." << endl;
        cout << "---------------------------------------------------------------------" << endl;
        if (monthPayment_1 > monthShareCost_1) {
            cout << "At the end, Mike needs to charge $" << monthPayment_1 - monthShareCost_1 << "(CAD) to Randolph." << endl;
            }
        else if (monthPayment_2 > monthShareCost_2) {
                cout << "At the end, Randolph need to charge $" << monthPayment_2 - monthShareCost_2 << "(CAD) to Mike." << endl;
            }
        else {
            cout << "Consume and Pay is fair, no recharge in this month!" << endl;
        }

}