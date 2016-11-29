//
//  Table.hpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/3/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
//#include "Customer.hpp"

using namespace std;

//int tTableNum = 1; //Global variable, it will be used to number tables when
//they are being created

/*
 ************************************************************************
 ************************************************************************
 This header file contains an object class for the restaurant's tables.
 This is my Table Node
 
 Table 1     Table 2     Table 3
 ****        ****        ****
 |  |   -->  |  |  -->   |  |
 |  |        |  |        |  |
 ****        ****        ****
 
 
 ************************************************************************
 ************************************************************************
 */
class Table
{
public:
    //Class constructor
    Table();
    /*The table number for each Table Node will be calculated using the global pointer*/
    int classTableNum; //What is the table number?
    bool isAvailable; //is the table available?
    int overflow;
    
    /*The idea here is to create a vector array of objects (customers)
     This is because we don't know how many people will be sitting at
     one table. All tables are assumed to have zero customers and when
     a table is assigned to an individual or a party we have to know
     how many people will be sitting at that table*/
    vector<int> Customer[1][4];
    //Pointer: It points to the next table on the list
    Table *next;
    
    
    //for sake of simplicity I will not use private:
    //all variables will be declared in public:
    //private:
};


#endif /* Table_hpp */

