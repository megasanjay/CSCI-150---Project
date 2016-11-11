//
//  Login.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "Login.hpp"

//int stafftype = 0;


string manager [2][3] =
    {
        {"adam","casey","john"},
        {"1234" , "5678","3434"}
    };

string waiter [2][5] =
    {
        {"A","B","C","D","E"},
        {"1","2","3","4","5"}
    };

void login()
{
    string username;
    string password;
    int count = 1;
    int stafftype = 0;
    while (stafftype == 0)
    {
        if (count > 3 )
        {
            system("CLS");
            cout << "3 attempts used. Please wait 5 seconds." << endl << endl;
            count = 1;
			Sleep(5000);
        }
        system("CLS");
        cout << "Enter 'quit' int the 'Username' field to exit the program" << endl;
        cout << "Enter Username: ";
        cin >> username;
        if (username == "quit")
        {
            cout << "Quitting program" << endl;
            return;
        }
        cout << "Enter Password: ";
        cin >> password;
        stafftype = checkusername(username, password);
        if (stafftype == 0)
        {
            system("CLS");
            cout << "Incorrect username or password. Try again." << endl;
        }
        count++;
    }
    
    if (stafftype == 1)
    {
        system("CLS");
        cout << "Manager login recognized" << endl;
        managermodule();
    }
    if (stafftype == 2)
    {
        system("CLS");
        cout << "Wait Staff login recognized" << endl;
        waitermodule();
    }
}

int checkusername(string username, string password)
{
    for(int i = 0; i <3; i++ )
    {
        if (manager[0][i] == username)
        {
            if (manager[1][i] == password)
            {
                return 1;
            }
        }
    }
    
    for(int i = 0; i <5; i++ )
    {
        if (waiter[0][i] == username)
        {
            if (waiter[1][i] == password)
            {
                return 2;
            }
        }
    }
    
    return 0;
}
