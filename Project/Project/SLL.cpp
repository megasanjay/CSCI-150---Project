//
//  SLL.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/3/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "SLL.hpp"
#include "Table.hpp"

int TableNum = 1;

Table* head;

SLL::SLL()
{
    head = NULL;
    tail = NULL;
}

/*
 ***********************************************
 ***********************************************
 ***********************************************
 *****DELETE THE LAST TABLE IN THE LIST*********
 ***********************************************
 ***********************************************
 ***********************************************
 */
void SLL::deleteBack(){
    
    Table *temp;
    temp = head;
    
    while(temp->next != tail){
        
        
        temp = temp->next;
        
    }
    
    if(head->next == NULL)
    {
        
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        tail = temp;
        
        temp = tail->next;
        
        delete temp;
        tail->next = NULL;
    }
}

/*
 ***********************************************
 ***********************************************
 ***********************************************
 *****DELETE A SPECIFIC TABLE FROM THE BACK*****
 ***********************************************
 ***********************************************
 ***********************************************
 */
void SLL::deleteKthNodeFromBack(int k){
    Table *temp; //Temporary Table Node
    Table *p;    //p Table node
    p = head;    //p Table node points to head
    temp = head; //temporary Table Node points to head
    
    int count = 0;
    while(temp != NULL){count++; temp = temp->next;} //counts number of Nodes in a list
    temp = head;
    int target = count - (k-1);
    count = 2; //resets
    
    while(count < target){
        count++;
        p = p->next;
    }
    
    temp = p->next;
    p->next = temp->next;
    delete temp;
    
}


/*
 ***********************************************
 ***********************************************
 ***********************************************
 *****INSERT NEW TABLE TO BACK OF THE LIST******
 ***********************************************
 ***********************************************
 ***********************************************
 */

void SLL::insertToBack(int TableNumber){
    
    Table *temp; //create temporary Table node
    temp = new Table; //Create new table
    temp->classTableNum = TableNumber; //assign table number
    TableNum++;  //increment global variable by one
    temp->next = NULL;
    
    if(head != NULL){
        tail->next = temp;
        tail = temp;
    }
    else{
        head = temp;
        tail = temp;
    }
    
}



/*
 ***********************************************
 ***********************************************
 ***********************************************
 *****PRINT ALL THE TABLES IN THE LINKED LIST***
 ***********************************************
 ***********************************************
 ***********************************************
 */
void SLL::printAll(){
    
    Table *p;
    p = head;
    // int count = 0;
    
    cout << "\n\n";
    
    while(p!=NULL){
        //count++;
        cout << p->classTableNum;
        
        if (p->next != NULL){
            cout << " -> ";
        }
        
        p = p->next;
    }
    
    cout << "\n\n\n\n";
    
}






