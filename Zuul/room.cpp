#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"
#include "item.h"

using namespace std;

//constructor
room::room(char* newDescription) {
  strcpy(description, newDescription);
}

void room::addItem(item* newItem) {
    items.push_back(newItem);
}

void room::addExit(char* direction, room* newRoom) {
    exits.insert(pair<char*, room*>(direction, newRoom));
}

