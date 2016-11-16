//
//  CreateOrders.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "CreateOrders.hpp"



void Orders()
{
    char m;
    char a;
    int i = 1;
    int o, time, custom, customer;
    int choice, choicea;
    int tablenum = 0;
    Table* p = head;
    string input = "";
    vector<int> inputvector;
    
    while (input!= "exit")
    {
        cout << "Type 'exit' to return to main menu" << endl;
        ///Select Table
        cout << "Input table number for current order" << endl;
        cin >> tablenum;
        
        while ((p->classTableNum) != tablenum)
        {
            p = p->next;
        }
        
        while (i == 1)
        {
            ///Select Customer
            cout << "Please input customer number" << endl;
            cin >> customer; //Varies depending on how customers are stored
            while ((p->Customer[0][customer]).empty()){
                cout << "Incorrect input. Please choose a different number." << endl ;
                cin >> customer;
            }
            ///Select food or drink
            PrintMenu();
            cout << "Press 1 for Food, 2 for Drink" << endl;
            cin >> choice;
            switch (choice)
            {
                case 1 : //Food
                    cout << "(1) Lunch (2) Dinner" << endl;
                    cin >> time;
                    switch (time)
                    {
                        case 1 : //Lunch
                            cout << "What food? (1) Burger (2) Cheese burger (3) fries (4) hotdog (5) bacon cheeseburger" << endl;
                            cin >> choicea;
                            switch (choicea) {
                                case 1 : //Burger
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard";
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1111;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1112;
                                                break;
                                        }
                                    }
                                    o = 1110;
                                    break;
                                case 2 : //Cheese Burger
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard"<< endl;
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1121;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1122;
                                                break;
                                        }
                                    }
                                    o = 1120;
                                    break;
                                case 3 : //Fries
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard"<< endl;
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1131;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1132;
                                                break;
                                        }
                                    }
                                    o = 1130;
                                    break;
                                case 4 : //Hotdog
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard"<< endl;
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1141;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1142;
                                                break;
                                        }
                                    }
                                    o = 1140;
                                    break;
                                case 5 : //Bacon CheeseBurger
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard"<< endl;
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1151;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1152;
                                                break;
                                        }
                                    }
                                    o = 1150;
                                    break;
                            }
                        case 2 : //Dinner
                            cout << "What food? (1) Turkey (2) Chicken (3) Tri-Tip"<< endl;
                            cin >> choicea;
                            switch (choicea) {
                                case 1 : //Turkey
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard"<< endl;
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1211;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1212;
                                                break;
                                        }
                                    }
                                    o = 1210;
                                    break;
                                case 2 : //Chicken
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard"<< endl;
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1221;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1222;
                                                break;
                                        }
                                    }
                                    o = 1220;
                                    break;
                                case 3 : //Tri-Tip
                                    cout << "Customize order? (Y/N)" << endl;
                                    cin >> a;
                                    if (a == 'Y') {
                                        cout << "Choose a customization for customer: (1) Ketchup (2) Mustard"<< endl;
                                        cin >> custom;
                                        switch (custom) {
                                            case 1 :
                                                //add Ketchup
                                                o = 1231;
                                                break;
                                            case 2 :
                                                //add mustard
                                                o = 1232;
                                                break;
                                        }
                                    }
                                    o = 1230;
                                    break;
                            }
                    }
                    break;
                case 2 : //Drink
                    cout << "What drink? (1) Water (2) Soda"<< endl;
                    cin >> choicea;
                    switch (choicea) {
                        case 1 : //Water
                            cout << "Customize order? (Y/N)" << endl;
                            cin >> a;
                            if (a == 'Y') {
                                cout << "Choose a customization for customer: (1) Lemon (2) No Ice"<< endl;
                                cin >> custom;
                                switch (custom) {
                                    case 1 :
                                        //add lemon
                                        o = 2110;
                                    case 2 :
                                        //No ice
                                        o = 2120;
                                }
                            }
                            o = 2100;
                            break;
                        case 2 : //Soda
                            cout << "Customize order? (Y/N)" << endl;
                            cin >> a;
                            if (a == 'Y') {
                                cout << "Choose a customization for customer: (1) Extra Large (2) No Ice"<< endl;
                                cin >> custom;
                                switch (custom) {
                                    case 1 :
                                        //Make large
                                        o = 2210;
                                    case 2 :
                                        //No ice
                                        o = 2220;
                                }
                            }
                            o = 2200;
                            break;
                    }
                default :
                    break;
            }
            cout << "Are there more customer orders for current table? (Y/N)" << endl;
            cin >> m;
            if (m == 'N'){
                i = 0;
                while(customer!= 0)
                {
                    inputvector.push_back(o);
                    cout << "Press 0 to exit current customer" << endl;
                    cin >> customer;
                }
                updateStats();
                return;
            }
            while(customer!= 0)
            {
                inputvector.push_back(o);
                cout << "Press 0 to exit current customer" << endl;
                cin >> customer;
            }
        }
    }
    updateStats();
    splitBills(tablenum);

    return;
}
