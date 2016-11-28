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
    char input;
    vector<int> inputvector;
    
    inputvector.clear();
    
    while ((p->classTableNum) != tablenum)
    {
        p = p->next;
    }
    system("CLS");
    cout << "Who wants to split bills?" << endl;
    cout << "Please choose one of the following customers. Enter '0' if there is no split " << endl ;
    for (int i = 0; i < 4; i++)
    {
        if ((p->Customer[0][i]).size() >= 1)
        {
            cout << i + 1 << " ";
        }
    }
    cout << endl << "------------------" << endl;
    cin.clear();
    cin >> input;
    while((input - '0') != 0)
    {
        if (((p->Customer[0][input - 1]).empty()) || (!isdigit(input)))
        {
            cout << "Invalid input. Please choose one of the following customers in order. Enter '0' when done " << endl ;
            for (int i = 0; (i < 4) && !((p->Customer[0][i]).empty()); i++)
            {
                cout << i+1 << "   ";
            }
            cout << endl << "------------------" << endl;
            cin >> input;
            continue;
        }
        
        if ((input - '0') == 0)
        {
            continue;
        }
        else
        {
            inputvector.push_back((input - '0') - 1 );
            system("CLS");
            cout << "Customer #" << (input - '0') + 1 << " added. Please selct another customer or enter '0' to exit" << endl;
            cin >> input;
        }
    }
    if (inputvector.empty())
    {
        nosplitTotal(tablenum, 0);
    }
    else
    {
        splitTotal(tablenum, inputvector);
    }
}

void nosplitTotal(int tablenum, float fulltotal)
{
    Table* p = head;
    Menu* q;
    string customchoice;
    int fooditem = 0;
    int foodtype, foodnum, foodcustom;
    float total = fulltotal;
    string price = "";
    stringstream stream;
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
            customchoice = "";
            
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
                if (foodcustom == 1)
                {
                    customchoice = " - Ketchup ";
                }
                if(foodcustom == 2)
                {
                    customchoice = " - Mustard ";
                }
            }
            
            if (fooditem == 2)
            {
                if (foodcustom == 1)
                {
                    customchoice = " - With Lemons";
                }
                if (foodcustom == 2)
                {
                    customchoice = " - No Ice";
                }
            }
            
            if (fooditem == 1)
            {
                for(int j = 1; j < foodtype; j++)
                {
                    q = q->next;
                }
                price  = "";
                stream.str("");
                stream << fixed << setprecision(2) << (q->Price[foodnum -1]);
                price = stream.str();
                
                outputvector.push_back((q->Item[foodnum - 1]) + customchoice + " - " + price);
                updatefoodStats(q->Name, q->Item[foodnum - 1]);
                total = total + q->Price[foodnum - 1];
                continue;
            }
            if (fooditem == 2)
            {
                while ((q->foodtype) != 'd')
                {
                    q = q->next;
                }
                for(int j = 1; j < foodtype; j++)
                {
                    q = q->next;
                }
                
                price = "";
                stream.str("");
                stream << fixed << setprecision(2) << (q->Price[foodnum -1]);
                price = stream.str();
                
                outputvector.push_back((q->Item[foodnum - 1]) + customchoice + " - " + price);
                updatefoodStats(q->Name, q->Item[foodnum - 1]);
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
    
    updateTotal(total);
    
    price  = "";
    stream.str("");
    stream << fixed << setprecision(2) << total;
    price = stream.str();
    
    cout << "\n" << "Total to be paid: " << price << endl;
}

void splitTotal(int tablenum, vector<int> &inputvector)
{
    Table* p = head;
    Menu* q;
    string customchoice;
    int customernum;
    int fooditem = 0;
    string price = "";
    stringstream stream;
    int foodtype, foodnum, foodcustom;
    int total = 0;
    float fulltotal = 0;
    vector<string> outputvector;
    
    outputvector.clear();
    system("CLS");
    
    while ((p->classTableNum) != tablenum)
    {
        p = p->next;
    }
    
    while (!inputvector.empty())
    {
        customernum = inputvector.back();
        inputvector.pop_back();
        
        while (p->Customer[0][customernum].empty())
        {
            q = menuhead;
            customchoice = "";
            total = 0;
            fooditem = (p->Customer[0][customernum]).back();
            (p->Customer[0][customernum]).pop_back();
            
            foodcustom = fooditem % 10;
            fooditem = fooditem / 10;
            foodnum = fooditem % 10;
            fooditem = fooditem /10;
            foodtype = fooditem % 10;
            fooditem = fooditem / 10;
            
            if (fooditem == 1)
            {
                if (foodcustom == 1)
                {
                    customchoice = " - Ketchup ";
                }
                if(foodcustom == 2)
                {
                    customchoice = " - Mustard ";
                }
            }
            
            if (fooditem == 2)
            {
                if (foodcustom == 1)
                {
                    customchoice = " - With Lemons ";
                }
                
                if (foodcustom == 2)
                {
                    customchoice = " - No Ice ";
                }
            }
            
            if (fooditem == 1)
            {
                for(int j = 1; j < foodtype; j++)
                {
                    q = q->next;
                }
                price  = "";
                
                stream << fixed << setprecision(2) << (q->Price[foodnum -1]);
                price = stream.str();
                
                outputvector.push_back((q->Item[foodnum - 1]) + customchoice + " - " + price);
                updatefoodStats(q->Name, q->Item[foodnum - 1]);
                
                total = total + q->Price[foodnum - 1];
                fulltotal = fulltotal + q->Price[foodnum - 1];
                continue;
            }
            if (fooditem == 2)
            {
                while ((q->foodtype) != 'd')
                {
                    q = q->next;
                }
                for(int j = 1; j < foodtype; j++)
                {
                    q = q->next;
                }
                price  = "";
                stream.str("");
                stream << fixed << setprecision(2) << (q->Price[foodnum -1]);
                price = stream.str();
                
                outputvector.push_back((q->Item[foodnum - 1]) + customchoice + " - " + price);
                updatefoodStats(q->Name, q->Item[foodnum - 1]);
                
                total = total + q->Price[foodnum - 1];
                fulltotal = fulltotal + q->Price[foodnum - 1];
                continue;
            }
        }
        cout << "-----------------------" << endl;
        while (!outputvector.empty())
        {
            cout << outputvector.back() << endl;
            outputvector.pop_back();
        }
        price  = "";
        stream.str("");
        stream << fixed << setprecision(2) << total;
        price = stream.str();
        
        cout << endl <<"Total: " << price << endl;
        cout << "-----------------------" << endl;
    }
    
    nosplitTotal(tablenum, fulltotal);
}

