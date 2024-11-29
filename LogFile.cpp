//
// Created by 毅黄 on 2024/11/18.
//

#include "LogFile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void saveOrdersToCSV(const vector<OrderData>& orders, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to save the file：" << filename << endl;
        return;
    }

    for (const auto& order : orders) {
        // 写入订单基本信息
        file << order.getOrderID() << ","
             << order.getDate() << ","
             << order.getMerchant() << ","
             << order.getPayer() << "\n";

        // 写入物品表头
        file << "name,category,owner,price,quantity,tax,totalPrice\n";

        // 写入每条物品记录
        for (const auto& item : order.getItems()) {
            file << item.getName() << ","
                 << item.getCategory() << ","
                 << item.getUser() << ","
                 << item.getUnitPrice() << ","
                 << item.getQuantity() << ","
                 << item.getTaxRate() << ","
                 << item.getTotalPrice()<< "\n";
        }

        // Add separating flag
        file << "#ENDORDER\n";
    }

    file.close();
    cout << "All order records are saved to file ：" << filename << endl;
}

int loadOrdersFromCSV(vector<OrderData>& orders, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to load records from ：" << filename << endl;
        return 0;
    }

    int ordersCount = 0;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        // 读取订单基本信息
        istringstream orderInfoStream(line);
        string orderIDstr, date, merchant, payer;

        getline(orderInfoStream, orderIDstr, ',');
        getline(orderInfoStream, date, ',');
        getline(orderInfoStream, merchant, ',');
        getline(orderInfoStream, payer, ',');

        int orderID = stoi(orderIDstr);
        OrderData order(orderID,date, merchant, payer);

        // 跳过表头
        getline(file, line);

        // 读取物品记录
        while (getline(file, line)) {
            if (line == "#ENDORDER") break; // 结束当前订单

            istringstream itemStream(line);
            string name, category, user, unitPriceStr, quantityStr, taxRateStr, totalPriceStr;

            getline(itemStream, name, ',');
            getline(itemStream, category, ',');
            getline(itemStream, user, ',');
            getline(itemStream, unitPriceStr, ',');
            getline(itemStream, quantityStr, ',');
            getline(itemStream, taxRateStr, ',');
            getline(itemStream, totalPriceStr, ',');

            double unitPrice = stod(unitPriceStr);
            double quantity = stod(quantityStr);
            double taxRate = stod(taxRateStr);

            ItemData item(name, category, user, unitPrice, quantity, taxRate);
            order.addItem(item);
        }

        // 将订单加入订单列表
        orders.push_back(order);
        ordersCount++;
    }

    file.close();
    cout << "All records are loaded from ：" << filename << endl;

    return ordersCount;
}