//
//  BillSplit.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "BillSplit.hpp"

void splitBills(int tablenum)
{
    Table* p = head;
    int input = 0;
    vector<int> inputvector;
    
    inputvector.clear();
    
    while ((p->classTableNum) != tablenum)
    {
        p = p->next;
    }
    cout << "Who wants to split bills?" << endl;
    cout << "Please choose one of the following customers. Enter '0' if there is no split " << endl ;
    for (int i = 0; (i < 4) && !((p->Customer[0][i]).empty()); i++)
    {
        cout << i + 1 << " ";
    }
    cout<<"------------------" << endl;
    cin >> input;
    while(input!= 0)
    {
        if (((p->Customer[0][input - 1]).empty()) && (isdigit(input)))
        {
            cout << "Incorrect input. Please choose one of the following customers in order. Enter '0' when done " << endl ;
            for (int i = 0; (i < 4) && !((p->Customer[0][i]).empty()); i++)
            {
                cout << i+1 << " ";
            }
            cout << "------------------" << endl;
            cin >> input;
            continue;
        }
        inputvector.push_back(input - 1 );
        cout << "Customer #" << input + 1 << " added. Please selct another customer or enter '0' to exit" << endl;
        cin >> input;
    }
    if (inputvector.empty())
    {
        nosplitTotal(tablenum);
    }
    else
    {
        // Calculate split and total
    }
}

void nosplitTotal(int tablenum)
{
    Table* p = head;
    Menu* q;
    int f = 0;
    int fooditem = 0;
    int foodtype, foodnum, foodcustom;
    int total = 0;
    vector<string> outputvector;
    //int i = 0;
    
    outputvector.clear();
    
    while ((p->classTableNum) != tablenum)
    {
        p = p->next;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if ((p->Customer[0][i]).empty())
        {
            continue;
        }
        
        while (!p->Customer[0][i].empty())
        {
            q = menuhead;
            fooditem = (p->Customer[0][i]).back();
            (p->Customer[0][i]).pop_back();
            foodcustom = fooditem % 10;
            fooditem = fooditem / 10;
            foodnum = fooditem % 10;
            fooditem = fooditem /10;
            foodtype = fooditem % 10;
            fooditem = fooditem / 10;
            if (fooditem == 1)
            {
                if (foodtype == 1)
                {
                    while ((q->Name) != "Lunch")
                    {
                        q = q->next;
                    }
                    outputvector.push_back((q->Item[foodnum - 1]) + " - " + to_string(q->Price[foodnum - 1]));
                    total = total + q->Price[foodnum - 1];
                    continue;
                }
                if (foodtype == 2)
                {
                    while ((q->Name) != "Dinner")
                    {
                        q = q->next;
                    }
                    outputvector.push_back((q->Item[foodnum - 1]) + " - " + to_string(q->Price[foodnum - 1]));
                    total = total + q->Price[foodnum - 1];
                    continue;
                }
            }
            if (fooditem == 2)
            {
                while ((q->Name) != "Drinks")
                {
                    q = q->next;
                }
                outputvector.push_back((q->Item[foodnum - 1]) + " - " + to_string(q->Price[foodnum - 1]));
                total = total + q->Price[foodnum - 1];
                continue;
            }
        }
    }
    
    while (!outputvector.empty())
    {
        cout << outputvector.back() << endl;
        outputvector.pop_back();
    }

}
