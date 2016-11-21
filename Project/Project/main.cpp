//
//  main.cpp
//  CSCI 150 - Project
//
//  Created by Sanjay Soundarajan on 10/18/16.
//  Copyright © 2016 //INSERT TEAM NAME HERE. All rights reserved.
//

//#include <iostream>
//#include "Customer.hpp"
#include "SLL.hpp"
#include "Table.hpp"
#include "Login.hpp"
#include "Menu.hpp"
#include <unistd.h>
#include <stdlib.h>
//#include <curses.h>

using namespace std;

SLL RestTables;

int main(int argc, const char * argv[]) {
    // insert code here...
    string loginusername;
    string loginpassword;
    string quitstate = "";
    //Declare object for restaurant tables
    
    //How many tables are going to be created?
    int N;
    int i = 1;
    cout << "Please enter how many tables will be created: " << endl;
    //cin >> N;
    while(i <= 10){
        
        RestTables.insertToBack(i);
        i++;
    }
    
    
    RestTables.printAll();
    
    menuPopulate();     // Create the menu data structure
    
    //system("CLS");      // Clear screen in windows. Dooesn't work on macs
    //clear();
    //refresh();
    //cout << "\033[2J\033[1;1H";
    //system("clear");
    cout << "Logging in....." << endl;
    //sleep(2);
    system("CLS");
    //PrintMenu();
    while (quitstate != "exit")
    {
        login();
        cout << "Type 'exit' to exit the program or enter any character to continue: " << endl;
        cin >> quitstate;
    }
    
    return 0;
}
