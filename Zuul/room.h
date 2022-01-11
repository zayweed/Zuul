#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "item.h"

using namespace std;

class room {
    char description[100];
    vector<item*> items;
    map<char*, room*> exits;

public:
    room(char* newDescription);
    void addItem(item* newItem);
    void addExit(char* direction, room* newRoom);
    char* getDescription();
    void printItems();
    bool hasExit(char* direction);
    room* getExit(char* direction);
    void printExits();
    /*
    bool hasItem(item* pickedItem);
    void removeItem(item* pickedItem);
    */
};

#endif