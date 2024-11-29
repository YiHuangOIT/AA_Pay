#include "OrderData.h"
#include "OrderManager.h"
#include "LogFile.h"
#include "Report.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    vector<OrderData> orders;
    string filename = "orderslist.csv";

    loadOrdersFromCSV(orders, filename);

    int choice;
    do {
        cout << "\nShare Payment System\n";
        cout << "1. Add New Shopping List\n";
        cout << "2. Save Shopping List as CSV File\n";
        cout << "3. Review Shopping List (By Month)\n";
        cout << "4. Generate Cost Report (By Month)\n";
        cout << "5. Exit\n";
        cout << "Enter choice no.: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addOrder(orders);
            break;
            case 2:
                saveOrdersToCSV(orders, filename);
            break;
            case 3:
                monthShopList(orders);
            break;
            case 4:
                monthCostReport(orders);
            break;
            case 5:
                cout << "Bye, have a good day！\n";
            break;
            default:
                cout << "Invalid number, please try again！\n";
        }
    } while (choice != 5);

    return 0;
}
