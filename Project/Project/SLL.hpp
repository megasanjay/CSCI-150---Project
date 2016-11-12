//
//  SLL.hpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/3/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#ifndef SLL_hpp
#define SLL_hpp

#include <stdio.h>
#include <iostream>
#include "Table.hpp"

using namespace std;

/*
 ************************************************************************
 ************************************************************************
 This header file contains the Singly Linked List for the tables.
 Three classes were created:
 
 1. Customer
 2. Table
 3. Singly Linked List
 
 The customer will be implemented in a vector and it's part of each table.
 At first all tables are assumed to be empty (zero customers) and when
 customers are assigned a table then immediately a vector of customers
 needs to be created for that specific table.
 
 The SLL should be able to be traversed and printed. In case more tables need
 to be added, it should be able to do that as well.
 
 Table 1     Table 2     Table 3            Table N
 ****        ****        ****               ****
 |  |   -->  |  |  -->   |  |   --> ******  |  |
 |  |        |  |        |  |               |  |
 ****        ****        ****               ****
 
 ************************************************************************
 ************************************************************************
 */

extern Table* head;

class SLL
{
private:
    
    Table *tail;       //Node pointers to head and tail
    
    
public:
    
    SLL();               //default constructor
    
    
    ~SLL(){}            //default destructor
    
    
    void deleteBack();           //will delete current back Node
    void deleteKthNodeFromBack(int k); /*will delete the k-th node counting from the back
                                        of a SLL. A->B->-C->D->E->F
                                        deleteKthNodeFromBack(3) will delete D. The SLL will become A->B->-C->E->F.
                                        front points to A, back points to F
                                        If we call it again deleteKthNodeFromBack(5) will delete A.
                                        The SLL will become B->-C->E->F. front points to B, back points to F
                                        If we call it again deleteKthNodeFromBack(5) will delete nothing because there
                                        is only 4 nodes.*/
    void insertToBack(int TableNumber);
    void printAll(); //function that prints entire Linked List
    
    
    
};


#endif /* SLL_hpp */



