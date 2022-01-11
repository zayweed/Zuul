//room functions
#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"
#include "item.h"

using namespace std;

room::room(char* newDescription) { //constructer
  strcpy(description, newDescription);
}

void room::addItem(item* newItem) { //adds item to room
    items.push_back(newItem);
}

void room::addExit(char* direction, room* newRoom) { //adds exit to room
    exits.insert(pair<char*, room*>(direction, newRoom));
}

char* room::getDescription() { //returns room description
  return description;
}

void room::printItems() { //prints the descriptions of every item in the room
    cout << "Items in the room:" << endl;
    for (item* i : items) {
        cout << i->getDescription() << endl;
    }
}

bool room::hasExit(char* direction) { //returns if the room has an exit in the inputted direction
    for (auto it = exits.begin(); it != exits.end(); it++) {
        if (strcmp(it->first, direction) == 0) {
            return true;
        }
    }

    return false;
}

room* room::getExit(char* direction) { //returns the room that is in the inputted direction
    for (auto it = exits.begin(); it != exits.end(); it++) {
        if (strcmp(it->first, direction) == 0) {
            return it->second;
        }
    }
}

void room::printExits() { //prints the direction and room description for each exit
    cout << "Room exits:" << endl;
    for (auto it = exits.begin(); it != exits.end(); it++) {
        cout << it->first << ": " << it->second->getDescription() << endl;
    }
}

bool room::hasItem(char* itemDescription) { //returns if the inputted item is in the room
    for (item* i : items) {
        if (strcmp(i->getDescription(), itemDescription) == 0) {
            return true;
        }
    }
    return false;
}

void room::removeItem(char* itemDescription) { //removes inputted item
    for (int i = 0; i < items.size(); i++) {
        if (strcmp(items[i]->getDescription(), itemDescription) == 0) {
            items.erase(items.begin()+i);
            break;
        }
    }
}

