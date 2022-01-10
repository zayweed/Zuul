#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class room {
    char description[100];
    vector<item*> items;
    map<char*, room*> exits;

public:
    room(char* newDescription);
    void addItem(item* newItem);
    void addExit(char* direction, room* newRoom);
};

#endif