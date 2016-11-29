//
//  Stats.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "Stats.hpp"

unordered_map<string, int > statcounter;
unordered_map<string, int >::const_iterator pointer;

int totalcounter;

void statsCheck()
{
	struct tm newtime;
	__time32_t aclock;
	char buffer[32];
	errno_t errNum;
	_time32(&aclock);   // Get time in seconds.  
	_localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.
	errNum = asctime_s(buffer, 32, &newtime);

    pointer  = statcounter.begin();

    cout << "Statistics as of : " << buffer << endl;
    
    while (pointer != statcounter.end())
    {
        cout << pointer->first << right << setw(3) << pointer->second << endl;
        pointer++;
    }
    
    cout  << "Revenue generated for today : " << totalcounter << endl;
}

void updatefoodStats(string foodname, string fooditem)
{
    stringstream name;
    string input = " -- " + fooditem;
    
    name.str("");
    name << left << setw(10) << foodname << left << setw(25) << input << setw(4) << " - ";
    
    input = name.str();
    
    pointer = statcounter.find(input);
    
    if (pointer != statcounter.end())
    {
        statcounter[input]++;
    }
    else
    {
        statcounter[input] = 1;
    }
}

void updateTotal(int total)
{
    totalcounter = totalcounter + total;
}

void updateStats()
{
    fstream outfile;
    stringstream divider;
	struct tm newtime;
	__time32_t aclock;
	char buffer[32];
	errno_t errNum;
	_time32(&aclock);   // Get time in seconds.  
	_localtime32_s(&newtime, &aclock);   // Convert time to struct tm form.
	errNum = asctime_s(buffer, 32, &newtime);

    pointer  = statcounter.begin();
    divider.str("");
    divider << left << setfill('-') << setw(65) << "-" << endl;
    
    outfile.open("C:\\Users\\sanja\\OneDrive\\Documents\\C++\\CSCI - 150-- - Project\\Project\\Project\\Statistics.txt", ios::app);

    outfile << endl << divider.str();
    outfile << "The below statistics were recorded at : " << buffer << endl;
    
    while (pointer != statcounter.end())
    {
        outfile << pointer->first << right << setw(3) << pointer->second << endl;
        pointer++;
    }
    
    outfile << "Total - " << totalcounter << endl << endl << divider.str();
}
