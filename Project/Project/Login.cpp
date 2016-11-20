//
//  Login.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "Login.hpp"

//int stafftype = 0;


vector < pair<string,string> > manager;
vector < pair<string,string> > waiter;

void login()
{
    string username;
    string password;
    int count = 0;
    ifstream infile;
    string word;
    int stafftype = 0;
    
    infile.open("/Users/Sanjay/Documents/CSCI 150 - Project/Project/Project/login.txt");

    // Create local password storage;
    
    while (!infile.eof())
    {
        infile >> word;
        if (encryptDecrypt(word) == "manager")
        {
            infile >> username;
            infile >> password;
            while (encryptDecrypt(username) != "waiting")
            {
                manager.push_back(make_pair(encryptDecrypt(username),encryptDecrypt(password)));
                count++;
                infile >> username;
                infile >> password;
            }
        }
        if (encryptDecrypt(username) == "waiting")
        {
            username = password;
            infile >> password;
            count = 0;
        }
        while (!infile.eof())
        {
            waiter.push_back(make_pair(encryptDecrypt(username),encryptDecrypt(password)));
            count++;
            infile >> username;
            infile >> password;
        }
    }
    
    count = 1;
    
    while (stafftype == 0)
    {
        if (count > 3 )
        {
            system("CLS");
            cout << "3 attempts used. Please wait 5 seconds." << endl << endl;
            count = 1;
			//Sleep(5000); for windows
            sleep(5); // for mac
        }
        system("CLS");
        cout << "Enter 'quit' in the 'Username' field to exit the login process or type in your username:" << endl;
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
    for(int i = 0; i < manager.size(); i++ )
    {
        if (manager[i].first == username)
        {
            if (manager[i].second == password)
            {
                return 1;
            }
        }
    }
    
    for(int i = 0; i < waiter.size(); i++ )
    {
        if (waiter[i].first == username)
        {
            if (waiter[i].second == password)
            {
                return 2;
            }
        }
    }
    
    return 0;
}

string encryptDecrypt(string toEncrypt)
{
    char key[3] = {'K', 'C', 'Q'}; //Any chars will work
    string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    
    return output;
}

void addlogin()
{
    int input = 0;
    bool exit = false;
    ofstream outfile;
    string username;
    string password;
    string output = "";
    int count = 0;
    
    outfile.open("/Users/Sanjay/Documents/CSCI 150 - Project/Project/Project/login.txt");

    cout << "Adding a new user..." << endl;
    cout << "Type '1' if the new user is a Manager or '9' if the new user is a member of the wait staff. Press '0' to exit: " << endl;
    cin >> input;
    
    if (input == 0)
    {
        exit = true;
    }
    
    while (exit == false)
    {
        if (input == 1)
        {
            cout << "Input Manager username:" << endl;
            cin >> username;
            cout << "Input Manager password:" << endl;
            cin >> password;
            
            while (manager[count].first != "")
            {
                count++;
            }
            
            manager.push_back(make_pair(username,password));
            
            exit = true;
        }
        if (input == 9)
        {
            cout << "Input Wait-Staff username:" << endl;
            cin >> username;
            cout << "Input Wait-Staff password:" << endl;
            cin >> password;
            
            while (waiter[count].first != "")
            {
                count++;
            }
            
            waiter.push_back(make_pair(username,password));
            
            exit = true;
        }
        if ((input != 1) && (input != 9))
        {
            cout << "Invalid choice. Please Type '1' if the new user is a Manager or '9' if the new user is a member of the wait staff. Press '0' to exit: " << endl;
            cin >> input;
            if (input == 0)
            {
                exit = true;
            }
        }
    }
    
    output = encryptDecrypt("Manager") + "\n" ;
    
    outfile << output;
    for(int i = 0; i < manager.size(); i++)
    {
        output  = encryptDecrypt(manager[i].first) + " " + encryptDecrypt(manager[i].second) + "\n";
        outfile << output;
    }
    output  = "\n" + encryptDecrypt("waiting") + "\n";
    outfile << output;
    for(int i = 0; i < waiter.size(); i++)
    {
        output = encryptDecrypt(waiter[i].first) + " " + encryptDecrypt(waiter[i].second) + "\n";
        outfile << output;
    }
    outfile.close();
}
