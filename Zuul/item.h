//declarations for 'item.cpp'
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class item { //local variables
    char description[100];

public: //constructer and functions
    item(char* newDescription);
    char* getDescription();
};

#endif
