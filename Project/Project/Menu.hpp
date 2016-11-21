//
//  Menu.hpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void menuEdit();

struct Menu{
    string Name;
    string Item[100];
    float Price[100];
    string Option[100];
    char foodtype;
    Menu* next;
};

void menuPopulate();
void PrintMenu();
//void printFoodMenu(Menu* q);

extern Menu* menu;
extern Menu* menuhead;


#endif /* Menu_hpp */
