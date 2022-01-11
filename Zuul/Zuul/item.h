#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class item {
    char description[100];

public:
    item(char* newDescription);
    char* getDescription();
};

#endif