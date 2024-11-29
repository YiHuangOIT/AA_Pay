## AA_Pay

a daily cost management application developed in C++


## Introduction

AA_Pay is an application developed for Daily Cost Management, it is wrote in C++.

I was using google table to trace the daily cost of mine and my room mate, but every month I spent lot of time in entering and generating a month report to clarify the cost resposibility between us.

To solve the task efficiently, I came up to the idea of developing this APP. It does make my life easier !

## Architecture

┌──────────────────────────────────────────────┐
│      Shopping List System                    │
├──────────────────────────────────────────────┤
│                                              │
│  ┌────────────────────────────────────────┐  │
│  │      Main Menu                         │  │
│  │----------------------------------------│  │
│  │  1. Add New Shopping List              │  │
│  │  2. Save Shopping List as CSV File     │  │
│  │  3. Review Shopping List (By Month)    │  │
│  │  4. Generate Cost Report (By Month)    │  │
│  │  5. Exit                               │  │
│  └────────────────────────────────────────┘  │
│                                              │
│  ┌────────────────────────────────────────┐  │
│  │    Vector of Orders                    │  │
│  │----------------------------------------│  │
│  │ . order #1                             │  │
│  │ . order #2                             │  │
│  │ . order #3                             │  │
│  │ . ....                                 │  │
│  └────────────────────────────────────────┘  │
│                                              │
│  ┌────────────────────────────────────────┐  │
│  │     Order Class                        │  │
│  │----------------------------------------│  │
│  │ - Order no.                            │  │
│  │ - Date                                 │  │
│  │ - Merchant                             │  │
│  │ - Payer                                │  │
│  │ + Vector <Item Class>                  │  │
│  │----------------------------------------│  │
│  │ + AddItem()                            │  │
│  │ + display()                            │  │
│  │ + GetItem()                            │  │
│  │ + calculateTotal()                     │  │
│  └────────────────────────────────────────┘  │
│                                              │
│                                              │
│  ┌────────────────────────────────────────┐  │
│  │     Item Class                         │  │
│  │----------------------------------------│  │
│  │ - name                                 │  │
│  │ - category                             │  │
│  │ - user                                 │  │
│  │ - unitPrice                            │  │
│  │ - quatity                              │  │
│  │ - taxRate                              │  │
│  │ + totalPrice                           │  │
│  │----------------------------------------│  │
│  │ + display()                            │  │
│  │ + GetTotalPrice()                      │  │
│  └────────────────────────────────────────┘  │
│                                              │
│  ┌────────────────────────────────────────┐  │
│  │     LogFile                            │  │
│  │----------------------------------------│  │
│  │ + saveOrdersToCSV()                    │  │
│  │ + loadOrdersFromCSV()                  │  │
│  └────────────────────────────────────────┘  │
│                                              │
│  ┌────────────────────────────────────────┐  │
│  │     Report                             │  │
│  │----------------------------------------│  │
│  │ + monthShopList()                      │  │
│  │ + monthCostReport()                    │  │
│  └────────────────────────────────────────┘  │
└──────────────────────────────────────────────┘

## Work Flow

The executable file "AAPay" is store at sub-directory of "cmake-build-debug". Follow below step can run the program.

1 - Clone the project to a folder on your local drive with link: https://github.com/YiHuangOIT/AA_Pay.git

2 - Change to the correct path with below code, replace <projectpath> by the folder path in step 1.
    cd <projectpath>/AAPay/cmake-build-debug

3 - Run the application with below code:
    ./AAPay


## Challenges and Future Enhancements.

The most impressive challenge is coming from implementing "ItemData" class inside "OrderData" class.
It will be eaiser to implement the function if there is only 1 type of data class, but keep item and order separately have the benifit of expanding the features in future.

The are two features to be enhanced in the future:
1 - Correct the typing error when adding new order.
2 - Generate report on where we spend the cost.


### Copyright and Licensing

This application is developed on personal interest and is free for use and distribute.
All risks are at the user themselves.

Copyright [2024] [Randolph.Yi.Huang]. All rights reserved.
