//
//  Login.hpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/8/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#ifndef Login_hpp
#define Login_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
//#include <unistd.h>     //for mac
#include <fstream>
#include <windows.h>  //for windows
#include "Manager.hpp"
#include "Waitstaff.hpp"

using namespace std;

void login();
int checkusername(string name, string pass);
int checkpassword(int stype, string pass);
string encryptDecrypt(string toEncrypt);
void addlogin();
#endif /* Login_hpp */
