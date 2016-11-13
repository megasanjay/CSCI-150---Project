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

using namespace std;

void menuEdit();
void menuPopulate();
void printMenu();

struct Menu{
    string Name;
    string Item[100];
    string Price[100];
    string Option[100];
    Menu *next;
};

#endif /* Menu_hpp */
