//
//  Menu.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

/*
 The way the menu is set up in the text file is:
 1.)"Title:"
 Sets the name of the menu incase the user wants to rename the name of their menus and categorize the way the wants it.
 2.) "Item:"
 the word after "Item:" will set the name of the item whatever they want to call their item. the code is make so they can add more than one word to an item. example, if they want to add hot dog to their menu the program would recognize that there are more words to follow that particular menu item
 3.) "Price:"
 After "Price:" the user is able to set the price of the item
 4.) "Done"
 once the programs read "done", it means that the current menu is done and is now time to move to the next menu
 */


#include "Menu.hpp"

Menu* menu; //= new Menu();
Menu* menuhead;

void menuPopulate()
{
    ifstream infile;
    ofstream outfile;
    string Word;
    //menu = new Menu(); // pointer menu is now pointing to a new menu
    //menuhead; // pointer head to be used to point to the first menu
    int f = 0;
    int p = 0;
    string price;
    infile.open("/Users/Sanjay/Downloads/Menu 2/Menu.txt");
    outfile.open("/Users/Sanjay/Downloads/Menu 2/Menu_output.txt");
    infile >> Word;
    menu = new Menu();
    menuhead = menu;
    while(!infile.eof())
    {
        if(Word == "Title:") // the word Title is used to name the menu incase anyone who is meking the menu wants to change the catergories
        {
            
            infile >> menu->Name; // sets the name of the menu
            infile >> Word; // reads the next string
            
        }
        if (Word == "Item:")
        { // if it reads "Item" it means that the next word is going to be a menu item
            infile >> menu->Item[f];// stores the name of the item into Item[number of the item in the array]
            f++;// moves to the next cell of the array
            infile >> Word; // reads another string
            if (Word != "Price:")
            { // if the word is not price then it means there is more to the word so it adds more words to the previous Item array
                while(Word != "Price:")
                { // continues to add words the the previous array cell till the word is finished
                    menu->Item[f-1].append(" ");
                    menu->Item[f-1].append(Word);
                    infile >> Word; // keeps reading in a string till the word is price
                }
            }
        }
        if (Word == "Price:")
        { // when the word is price it add the price to the [p element of the array]
            infile >> price;
            menu->Price[p] = stoi(price);
            p++;// moves to the next cell of the price array
            infile >> Word; // reads in another string
        }
        if (Word == "Done")
        { // if the keyword "Done" is read then it means that the particular menu is done and now a new menu needs to be made
            Menu *np = new Menu(); // creates a pointer and points it to a  new menu
            menu->next = np; // sets menus next to be set to the new menu
            menu = np; // menu now points to the new menu
            infile >> Word; // reads in the next work to start the process all over again
            np = nullptr;
            f = 0;
            p = 0;
        }
    }
    infile.close(); // closes the input stream
    outfile.close();
    //PrintMenu(); // prints the menu items
    
    //return;
}

void PrintMenu()
{
    Menu *front = menuhead; // pointer front points to the head of the menu
    while (front->Name != "")
    { // continues to print the menu till the menus end
        cout << endl << front->Name << " Menu:" << endl; // print the name of the menu
        for (int i, j= 0; i < 100; i++,j++)
        { // for loop to go through the arrays
            if (front->Item[i] == "")
            { // if there is a new item in the array sine the array contains 100 cells, i dont want to keep printing the "" cells
                // once the Items and prices are done printing resets the arrays to 0 for both arrays
                i = 0;
                j=0;
                break;
            } // since it is done with the items in the array then it breaks to the next menu if there is another
            else
            {
                cout << j+1 << " -  " << front->Item[i]<< "  " ; // since there are more items in the menu, this prints out the name of the menu item
            }
            cout << front->Price[j]<< endl; // prints out the price to the menu item
        }
        if (front->next != nullptr)
        { // if there are more menus then move to the next menu since the previous menu is done with items
            front = front->next; // points pointer front to the new menu and continues the process
        }
        else
        {
            break;  // if there are no more menus then break and the printing menu function is now finished.
        }
    }
}
