//
// Created by 毅黄 on 2024/11/17.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;


class ItemData {
private:
    string name;     // 物品名称
    string category; // 类别
    string user;    // owner of the item
    double unitPrice;     // 单价
    double quantity;         // 数量
    double taxRate;     // tax rate of item
    double totalPrice;  // price with quantity and tax

public:
    ItemData(const string& name, const string& category, const string& user, double unitPrice, double quantity, double taxRate);

    // Getter 方法
    string getName() const;
    string getCategory() const;
    string getUser() const;
    double getUnitPrice() const;
    double getQuantity() const;
    double getTaxRate() const;

    // 显示单条记录
    void display() const;

    // 计算总价
    double getTotalPrice() const;
};

#endif //ITEM_H
