//
//  Table.cpp
//  Project
//
//  Created by Sanjay Soundarajan on 11/3/16.
//  Copyright © 2016 INSERT TEAM NAME HERE. All rights reserved.
//

#include "Table.hpp"

Table::Table()
{
    for (int i = 0; i < 4; i++)
    {
        this->Customer[0][i].clear();
    }
    this->isAvailable = true;
}
