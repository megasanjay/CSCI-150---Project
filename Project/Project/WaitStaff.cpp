//
//  WaitStaff.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "WaitStaff.hpp"

void waitermodule()
{
    //menuEdit();
    char choice = '1';
    
    cout << "Welcome" << endl;
    while (choice != '0')
    {
        cout << "What do you want to do today?" << endl;
        cout << "Please select 1 for Creating a new order" << endl;
        cout << "Please select 0 to logout" << endl;
        cin >> choice;
        
        if ((isalpha(choice)) || ((choice != '1') && (choice != 0)))
        {
            cout << "Invalid Input. Try again" << endl;
            continue;
        }
        
        if (choice == '1')
        {
            Orders();
            cout << "Returning back to the Main menu..." << endl;
            continue;
        }
        
    }
    cout << "Logging out..." << endl;
    cout << "Returning back to the Login screen" << endl;
}
