//
// Created by 毅黄 on 2024/11/18.
//

#ifndef SAVETOCSV_H
#define SAVETOCSV_H

#include "OrderData.h"
using namespace std;


void saveOrdersToCSV (const vector<OrderData>& orders, const string& filename);

int loadOrdersFromCSV (vector<OrderData>& orders, const string& filename);



#endif //SAVETOCSV_H
