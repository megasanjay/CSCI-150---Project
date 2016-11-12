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
    
    while ((p->classTableNum) != tablenum)
    {
        p = p->next;
    }
    cout << "Who wants to split bills?" << endl;
    cout << "Please choose one of the following customers. Enter '0' if there is no split " << endl ;
    for (int i = 0; (i < 4) && !((p->Customer[0][i]).empty()); i++)
    {
        cout << i << " ";
    }
    cout<<"------------------" << endl;
    cin >> input;
    while(input!= 0)
    {
        if (!(p->Customer[0][input]).empty())
        {
            cout << "Incorrect input. Please choose one of the following customers in order. Enter '0' when done " << endl ;
            for (int i = 0; (i < 4) && !((p->Customer[0][i]).empty()); i++)
            {
                cout << i << " ";
            }
            cout<<"------------------" << endl;
            continue;
        }
        inputvector.push_back(input);
        cout << "Customer #" << input << " added. Please selct another customer or enter '0' to exit" << endl;
        cin >> input;
    }
    if (inputvector.empty())
    {
        // Calculate Total
    }
    else
    {
        // Calculate split and total
    }
}
