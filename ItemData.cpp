//
// Created by 毅黄 on 2024/11/17.
//

#include "ItemData.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Item 类实现
ItemData::ItemData(const string& name, const string& category, const string& user, double unitPrice, double quantity, double taxRate)
    : name(name), category(category), user(user), unitPrice(unitPrice), quantity(quantity), taxRate(taxRate) {}

string ItemData::getName() const { return name; }
string ItemData::getCategory() const { return category; }

string ItemData::getUser() const { return user; }

double ItemData::getUnitPrice() const { return unitPrice; }
double ItemData::getQuantity() const { return quantity; }

double ItemData::getTaxRate() const { return taxRate; }

void ItemData::display() const {
    cout << left << setw(30) << name
        << right << setw(10) << category
        << setw(10) << user
        << setw(10) << unitPrice
        << setw(10) << quantity
        << setw(10) << taxRate
        << setw(10) << getTotalPrice() << endl;
}

double ItemData::getTotalPrice() const {
    return unitPrice * quantity * (1 + taxRate);
}
