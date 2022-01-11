#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"
#include "item.h"

using namespace std;

room::room(char* newDescription) {
  strcpy(description, newDescription);
}

void room::addItem(item* newItem) {
    items.push_back(newItem);
}

void room::addExit(char* direction, room* newRoom) {
    exits.insert(pair<char*, room*>(direction, newRoom));
}

char* room::getDescription() {
  return description;
}

void room::printItems() {
    cout << "Items in the room:" << endl;
    for (item* i : items) {
        cout << i->getDescription() << endl;
    }
}

bool room::hasExit(char* direction) {
    for (auto it = exits.begin(); it != exits.end(); it++) {
        if (strcmp(it->first, direction) == 0) {
            return true;
        }
    }

    return false;
}

room* room::getExit(char* direction) {
    for (auto it = exits.begin(); it != exits.end(); it++) {
        if (strcmp(it->first, direction) == 0) {
            return it->second;
        }
    }
}

void room::printExits() {
    cout << "Room exits:" << endl;
    for (auto it = exits.begin(); it != exits.end(); it++) {
        cout << it->first << ": " << it->second->getDescription() << endl;
    }
}

/*
bool room::hasItem(item* pickedItem) {

}

void room::removeItem(item* pickedItem) {
    
}
*/

