//declarations for 'room.cpp'
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "item.h"

using namespace std;

class room { //local variables
    char description[100];
    vector<item*> items;
    map<char*, room*> exits;

public: //constructer and functions
    room(char* newDescription);
    void addItem(item* newItem);
    void addExit(char* direction, room* newRoom);
    char* getDescription();
    void printItems();
    bool hasExit(char* direction);
    room* getExit(char* direction);
    void printExits();
    bool hasItem(char* itemDescription);
    void removeItem(char* itemDescription);
};

#endif
