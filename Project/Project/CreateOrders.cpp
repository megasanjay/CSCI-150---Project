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
    char m = 'n';
    char a = 'c';
    char continuation = 'n';
    char custom = 't';
    Menu* q = menuhead;
    Menu* r = menuhead;
    bool flag = true;
    //int i = 1;
    int time;
    char customernumber = 0;
    int choice, choicea;
    int tablenum = 0;
    //string foodname;
    char temp = 'c' ;
    string itablenum;
    int count = 0;
    int item = 0;
    Table* p = head;
    int input = 1;
    vector<int> inputvector;
    
    system("CLS");
    
    while (temp != 'e')
    {
        
        cout << "Type '0' to return to main menu or Input the table number for current order: " << endl << ">> ";
        cin.clear();
        cin >> itablenum;
        
        flag = true;
        
        if (itablenum.length() > 1)
        {
            for(int i = 0; i < itablenum.length(); i++)
            {
                if (!isdigit(itablenum[i]))
                {
                    cout << "Invalid input. Please try again: " << endl;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                input = stoi(itablenum);
            }
            else
            {
                continue;
            }
        }
        else
        {
            temp = itablenum[0];
            
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
            
        }
        
        tablenum = input;
        
        if (tablenum > TableNum)
        {
            cout << "This table is not in the list of tables present. Please try again." << endl;
            continue;
        }
        
        if (tablenum != 0)
        {
            while ((p->classTableNum) != tablenum)
            {
                p = p->next;
            }
        }
        
        system("CLS");
        p->isAvailable = false;
        
        while (input != 0)
        {
            ///Select Customer
            if (a == 'c')
            {
                cout << "Please input customer number: " << endl << ">> ";
                cin.clear();
                cin >> customernumber; //Varies depending on how customers are stored
                if (((customernumber - '0') >= 5) || ((customernumber - '0') < 0) || (!isdigit(customernumber)))//((p->Customer[0][customer]).empty())
                {
                    cout << "Incorrect input." << endl ;
                    continue;
                }
            }
            ///Select food or drink
            //--------------------------PrintMenu();
            system("CLS");
            cout << "Press 1 for Food, 2 for Drinks" << endl << ">> ";
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
                
                cout << "Your choice: ";
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
                custom = 't';
                while (custom == 't')
                {
                    cout << "Do you want to customize the order? Please 'y' if you do, or type 'n' to confirm order: " << endl << ">> ";
                    cin.clear();
                    cin >> custom;
                    
                    if ((!isalpha(custom)) || ( (custom != 'y') && (custom != 'n') ))
                    {
                        cout << "Invalid input. Try again." << endl;
                        custom = 't';
                        continue;
                    }
                    
                }
                if (custom == 'y')
                {
                    while (custom == 'y')
                    {
                        cout << "Do you want (1) - Ketchup or (2) - Mustard. Please select the item you want to add to the order: " << endl << ">> ";
                        cin.clear();
                        cin >> custom;
                        
                        if ((!isdigit(custom)) || (((custom - '0') <= 0 ) && ((custom - '0') >= 3)))
                        {
                            cout << "Invalid Input. Try again." << endl;
                            custom = 'y';
                            continue;
                        }
                    }
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + (custom - '0');
                    //updatefoodStats(q->Name, q->Item[choicea-1]);
                }
                if (custom == 'n')
                {
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + 0;
                    //updatefoodStats(q->Name, q->Item[choicea-1]);
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
                
                while (custom == 't')
                {
                    cout << "Do you want to customize the order? Please 'y' if you do, or type 'n' to confirm order: " << endl << ">> ";
                    cin.clear();
                    cin >> custom;
                    
                    if ((!isalpha(custom)) || ( (custom != 'y') && (custom != 'n') ))
                    {
                        cout << "Invalid input. Try again." << endl;
                        custom = 't';
                        continue;
                    }
                }
                
                if (custom == 'y')
                {
                    while (custom == 'y')
                    {
                        cout << "Do you want (1) - Lemons or (2) - Remove Ice. Please select the item you want to add to the order: " << endl << ">> ";
                        cin.clear();
                        cin >> custom;
                        
                        if ((!isdigit(custom)) || (((custom - '0') <= 0 ) && ((custom - '0') >= 3)))
                        {
                            cout << "Invalid Input. Try again." << endl;
                            custom = 'y';
                            continue;
                        }
                    }
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + (custom - '0');
                    //updatefoodStats(q->Name, q->Item[choicea-1]);
                }
                if (custom == 'n')
                {
                    item = (choice * 1000) + (time * 100) + (choicea * 10) + 0;
                    //updatefoodStats(q->Name, q->Item[choicea-1]);
                }
            }
            
            (p->Customer[0][(customernumber - '0') - 1]).push_back(item);
            //foodname = q->Name;
            //updatefoodStats(q->Name, q->Item[choicea-1]);
            cout << "Item added for customer #" << customernumber << ". " << endl;
            m = 'n';
            continuation = 'n';
            
            while (m == 'n')
            {
                cout << "Are there more orders for this customer?: Type 'y' for yes or 'n' for no." << endl << ">> ";
                cin.clear();
                cin >> m;
                
                if ((!(isalpha(m))) || ((m != 'y') && (m != 'n')))
                {
                    cout << "Invalid Input. Try again." << endl;
                    m = 'n';
                    continue;
                }
                
                if (m == 'y')
                {
                    a = 'n';
                    continue;
                }
                if (m == 'n')
                {
                    while (continuation == 'n')
                    {
                        system("CLS");
                        cout << "Are there more orders for this table? Type 'y' for yes or 'n' for no." << endl << ">> ";
                        cin.clear();
                        cin >> continuation;
                        
                        if ((!isalpha(continuation)) || ((continuation != 'y') && (continuation != 'n')))
                        {
                            cout << "Invalid Input. Try again." << endl;
                            continuation = 'n';
                            continue;
                        }
                        
                        if (continuation == 'y')
                        {
                            a = 'c';
                            continue;
                        }
                        if (continuation == 'n')
                        {
                            input = 0;
                            temp = 'e';
                            continuation = 'y';
                        }
                    }
                    m = 'y';
                }
            }
        }
    }
    return;
}
