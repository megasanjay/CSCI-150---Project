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
#include "Stats.hpp"
#include <Windows.h>
//#include <unistd.h>
#include <stdlib.h>

using namespace std;

SLL RestTables;

int main(int argc, const char * argv[]) {
    // insert code here...
    string loginusername;
    string loginpassword;
    string quitstate = "";
    totalcounter = 0;
    //Declare object for restaurant tables
    
    //How many tables are going to be created?
    int N;
    int i = 1;
    cout << "Please enter how many tables will be created: " << endl << ">> ";
    //cin >> N;
    while(i <= 10){
        
        RestTables.insertToBack(i);
        i++;
    }
    
    
    RestTables.printAll(); // Show Tables created
    
    menuPopulate();     // Create the menu data structure
    
    system("CLS");      // Clear screen in windows. Dooesn't work on macs
    cout << "Logging in....." << endl; 
	Sleep(1); //for windows
    //sleep(2);	// for mac
    system("CLS");
    //PrintMenu();
    while (quitstate != "exit")
    {
        login();
        cout << "Type 'exit' to exit the program or enter any character to continue: " << endl << ">> ";
        cin >> quitstate;
    }
    
    updateStats();
    // Testing commits
    return 0;
}
