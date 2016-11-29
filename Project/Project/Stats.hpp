//
//  Stats.hpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#ifndef Stats_hpp
#define Stats_hpp

#include <stdio.h>
#include <unordered_map>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

void statsCheck();
void updatefoodStats(string name, string item);
void updateTotal(int total);
void populatestats();
void updateStats();

extern int totalcounter;

#endif /* Stats_hpp */
