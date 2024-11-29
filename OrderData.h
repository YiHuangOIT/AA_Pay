//
// Created by 毅黄 on 2024/11/17.
//

#ifndef ORDERINFO_H
#define ORDERINFO_H


#include "ItemData.h"
#include <vector>
#include <string>
using namespace std;

class OrderData {
private:
    int orderID;
    string date;
    string merchant;
    string payer;
    vector<ItemData> items;

public:
    OrderData(const int& orderID, const string& date, const string& merchant, const string& payer);

    // Getter 方法
    int getOrderID() const;
    string getDate() const;
    string getMerchant() const;
    string getPayer() const;

    // 返回 items 的 const 引用
    const vector<ItemData>& getItems() const;


    // 添加物品记录
    void addItem(const ItemData& item);

    // 显示订单信息和所有物品
    void display() const;

    // 计算总金额
    double calculateTotal() const;
};


#endif //ORDERINFO_H
