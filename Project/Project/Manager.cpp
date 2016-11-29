//
//  Manager.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "Manager.hpp"

void managermodule()
{
    //menuEdit();
    char choice = '1';
    
    cout << "Welcome" << endl;
    while (choice != '0')
    {
        cout << "What do you want to do today?" << endl;
        cout << "Please select 1 for stat checking " << endl;
        cout << "Please select 2 for adding a new  login" << endl;
        cout << "Please select 3 to check all the orders" << endl;
        cout << "Please select 0 to logout" << endl << ">> ";
        cin >> choice;
        
        if ((isalpha(choice)) || ((choice != '1') && (choice != '2')  && (choice != '3') && (choice != '0')))
        {
            cout << "Invalid Input. Try again" << endl;
            continue;
        }
        
        if (choice == '1')
        {
            statsCheck();
            cout << "Returning back to the Main menu..." << endl;
            continue;
        }
        
        if (choice == '2')
        {
            addlogin();
            cout << "Returning back to the Main menu..." << endl;
            continue;
        }
        
        if (choice == '3')
        {
            checkOrders();
            cout << endl << endl << "Type in any character to continue... " << endl;
            cin.ignore();
        }
    }
    cout << "Logging out..." << endl;
    cout << "Returning back to the Login screen" << endl;
}

