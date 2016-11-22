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
    char a = 'c';
    Menu* q = menuhead;
    Menu* r = menuhead;
    //int i = 1;
    int time, custom, customernumber = 0;
    int choice, choicea;
    int tablenum = 0;
    char temp = 'c' ;
    int count = 0;
    int item = 0;
    Table* p = head;
    int input = 1;
    vector<int> inputvector;
    
    while (temp != 'e')
    {
        cout << "Type '0' to return to main menu or Input table number for current order: " << endl;
        cin.clear();
        cin >> temp;
        
        if (!isdigit(temp))
        {
            cout << "Invalid input. Please try again: " << endl;
            continue;
        }
        else
        {
            input = temp - '0';
        }
        
        if (input == 0)
        {
            continue;
        }
        
        tablenum = input;
        
        if (tablenum > TableNum)
        {
            cout << "This table is not in the list of tables present. Please try again :" << endl;
            continue;
        }
        
        if (tablenum != 0)
        {
            while ((p->classTableNum) != tablenum)
            {
                p = p->next;
            }
        }
        
        while (input != 0)
        {
            ///Select Customer
            if (a == 'c')
            {
                cout << "Please input customer number: " << endl;
                cin.clear();
                cin >> customernumber; //Varies depending on how customers are stored
                if ((customernumber >= 5) || (customernumber < 0))//((p->Customer[0][customer]).empty())
                {
                    cout << "Incorrect input." << endl ;
                    continue;
                }
            }
            ///Select food or drink
            //--------------------------PrintMenu();
            cout << "Press 1 for Food, 2 for Drink" << endl;
            cin.clear();
            cin >> choice;
            q  = menuhead;
            if (choice == 1)
            {
                cout << "Please select one of the below options:" << endl;
                count = 0;
                r = q;
                while(q->foodtype == 'f')
                {
                    cout << (count+1) << " - " << q->Name << endl;
                    q = q->next;
                    count++;
                }
                
                cout << "Your choice: " ;
                cin.clear();
                cin >> time;
                //r = menuhead;
                
                for (int i = 1; i < time;i++)
                {
                    r = r->next;
                }
                
                count = 0;
                cout << "Please select the number of the item the customer wants to order: " << endl;
                
                while (r->Item[count] != "")
                {
                    cout << count+1 << " - " << r->Item[count] << endl;
                    count++;
                }
                
                cout << "Your choice: ";
                cin.clear();
                cin >> choicea;
                
                cout << "Do you want to customize the order? Please '8' if you do, or type '0' to confirm order: ";
                cin.clear();
                cin >> custom;
                
                if (custom == 8)
                {
                    cout << "Do you want (1) - Ketchup or (2) - Mustard. Please select the item you want to add to the order: ";
                    cin.clear();
                    cin >> custom;
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + custom;
                }
                if (custom == 0)
                {
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + custom;
                }
                
            }
            if (choice == 2)
            {
                while(q->foodtype != 'd')
                {
                    q = q->next;
                }
                cout << "Please select one of the below options:" << endl;
                count = 0;
                r = q;
                while(q->foodtype == 'd')
                {
                    cout << (count+1) << " - " << q->Name << endl;
                    if (q->next == NULL)
                    {
                        break;
                    }
                    else
                    {
                        q = q->next;
                    }
                    count++;
                }
                
                cout << "Your choice: " ;
                cin.clear();
                cin >> time;
                //r = menuhead;
                
                for (int i = 1; i < time ;i++)
                {
                    r = r->next;
                }
                
                count = 0;
                cout << "Please select the number of the item the customer wants to order: " << endl;
                
                while (r->Item[count] != "")
                {
                    cout << count+1 << " - " << r->Item[count] << endl;
                    count++;
                }
                
                cout << "Your choice: ";
                cin.clear();
                cin >> choicea;
                
                cout << "Do you want to customize the order? Please '8' if you do, or type '0' to confirm order: ";
                cin.clear();
                cin >> custom;
                
                if (custom == 8)
                {
                    cout << "Do you want (1) - Lemons or (2) - Remove Ice. Please select the item you want to add to the order: ";
                    cin.clear();
                    cin >> custom;
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + custom;
                }
                if (custom == 0)
                {
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + custom;
                }
            }
            
            cout << "Are there more orders for this customer?: Type 'y' for yes or 'n' for no: ";
            cin.clear();
            cin >> m;
            (p->Customer[0][customernumber-1]).push_back(item);
            if (m == 'y')
            {
                updateStats(); // Update food stats
                a = 'n';
                continue;
            }
            else
            {
                cout << "Are there more orders for this table? Type 'y' for yes or 'n' for no: ";
                cin.clear();
                cin >> m;
                if (m == 'y')
                {
                    a = 'c';
                    continue;
                }
                else
                {
                    input = 0;
                    temp = 'e';
                }
            }
            
        }
    }
    if (tablenum != 0)
    {
        splitBills(tablenum);
    }
    return;
}
