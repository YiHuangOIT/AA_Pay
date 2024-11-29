//
// Created by 毅黄 on 2024/11/17.
//

#include "OrderData.h"
#include "ItemData.h"
#include <iostream>
#include <iomanip>
using namespace std;

// OrderInfo class implementation
OrderData::OrderData(const int& orderID, const string& date, const string& merchant, const string& payer)
    : orderID(orderID), date(date), merchant(merchant), payer(payer) {}

int OrderData::getOrderID() const {
    return orderID;
}

string OrderData::getDate() const {
    return date;
}

string OrderData::getMerchant() const {
    return merchant;
}

string OrderData::getPayer() const {
    return payer;
}

const vector<ItemData> & OrderData::getItems() const{
    return items;
}

void OrderData::addItem(const ItemData& item) {
    items.push_back(item);
}

void OrderData::display() const {
    // Display order informaiton
    cout << "\n"
              << "Order No.: " << orderID << "\n"
              << "Date: " << date << "\n"
              << "Merchant: " << merchant << "\n"
              << "Payer: " << payer << "\n"
              << "------------------------------------------------------------------------------------------" << endl;

    // Display title of item information
    cout << left << setw(30) << "Description"
            << right << setw(10) << "Category"
            << setw(10) << "Owner"
            << setw(10) << "Price"
            << setw(10) << "Qty"
            << setw(10) << "Tax"
            << setw(10) << "Total" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;

    // Display item detail information one by one in current order
    for (const auto& item : items) {
        item.display();
    }

    // Calculate and show the total cost of current order
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "Summary of Cost: " << calculateTotal() << endl;
}

double OrderData::calculateTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.getTotalPrice();
    }
    return total;
}