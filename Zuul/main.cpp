#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"
#include "item.h"

using namespace std;

void printInventory(vector<item*> inventory) {
    cout << "Items in your inventory:" << endl;
    for (item* i : inventory) {
        cout << i->getDescription() << endl;
    }
}

void introduceRoom(room* currentRoom, vector<item*> inventory) {
    cout << "You are currently in the " << currentRoom->getDescription() << "." << endl;
    currentRoom->printExits();
    currentRoom->printItems();
    printInventory(inventory);
}

int main() {
    vector<room*> roomList;
    vector<item*> inventory;

    char newDescription[100];
    strcpy(newDescription, "Java Class");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Science Class");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "I-20 Lab");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Math Class");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Library");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Pub");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Outside");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Theater");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Cafeteria");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Lab");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Office");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Staff Lounge");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Gym");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Lecture Hall");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Auditorium");
    newRoom = new room(newDescription);
    roomList.push_back(newRoom); 
    

    strcpy(newDescription, "robot");
    item* newItem = new item(newDescription);
    roomList[2]->addItem(newItem);
    strcpy(newDescription, "chair");
    newItem = new item(newDescription);
    roomList[5]->addItem(newItem);
    strcpy(newDescription, "microphone");
    newItem = new item(newDescription);
    roomList[7]->addItem(newItem);
    strcpy(newDescription, "beaker");
    newItem = new item(newDescription);
    roomList[9]->addItem(newItem);
    strcpy(newDescription, "plant");
    newItem = new item(newDescription);
    roomList[10]->addItem(newItem);

    char north[100];
    strcpy(north, "NORTH");
    char east[100];
    strcpy(east, "EAST");
    char south[100];
    strcpy(south, "SOUTH");
    char west[100];
    strcpy(west, "WEST");

    roomList[0]->addExit(south, roomList[2]);

    roomList[1]->addExit(east, roomList[2]);

    roomList[2]->addExit(north, roomList[0]);
    roomList[2]->addExit(east, roomList[3]);
    roomList[2]->addExit(south, roomList[6]);
    roomList[2]->addExit(west, roomList[1]);

    roomList[3]->addExit(east, roomList[4]);
    roomList[3]->addExit(west, roomList[2]);

    roomList[4]->addExit(west, roomList[3]);

    roomList[5]->addExit(east, roomList[6]);
    roomList[5]->addExit(south, roomList[8]);

    roomList[6]->addExit(north, roomList[2]);
    roomList[6]->addExit(east, roomList[7]);
    roomList[6]->addExit(south, roomList[9]);
    roomList[6]->addExit(west, roomList[5]);

    roomList[7]->addExit(west, roomList[6]);

    roomList[8]->addExit(north, roomList[5]);
    roomList[8]->addExit(south, roomList[12]);

    roomList[9]->addExit(north, roomList[6]);
    roomList[9]->addExit(east, roomList[10]);

    roomList[10]->addExit(east, roomList[11]);
    roomList[10]->addExit(west, roomList[9]);

    roomList[11]->addExit(west, roomList[10]);

    roomList[12]->addExit(north, roomList[8]);
    roomList[12]->addExit(east, roomList[13]);

    roomList[13]->addExit(east, roomList[14]);
    roomList[13]->addExit(west, roomList[12]);

    roomList[14]->addExit(west, roomList[13]);
    
    room* currentRoom = roomList[2];
    
    bool stillPlaying = true;
    while (stillPlaying == true) {
        cout << endl;
        introduceRoom(currentRoom, inventory);
        cout << "What would you like to do next?" << endl;
        char input[100];
        cin >> input;

        if (strcmp(input, "NORTH") == 0 || strcmp(input, "EAST") == 0 || strcmp(input, "SOUTH") == 0 || strcmp(input, "WEST") == 0) {
            if (currentRoom->hasExit(input) == true) {
                currentRoom = currentRoom->getExit(input);
            }
            else {
                cout << "An exit does not exist in that direction." << endl;
            }
        }
        
        else if (strcmp(input, "PICK") == 0) {

        }

        else if (strcmp(input, "DROP") == 0) {
            
        }

        else if (strcmp(input, "QUIT") == 0) {
            stillPlaying = false;
        }

        else {
            cout << "Invalid input." << endl;
        }
    }

}

/*
Rooms:
0 Java Class 
1 Science Class
2 I-20 Lab
3 Math Class
4 Library
5 Pub
6 Outside
7 Theatre
8 Cafeteria
9 Lab
10 Office
11 Staff Lounge
12 Gym
13 Lecture Hall
14 Auditorium

Items:
robot
chair
microphone
beaker
plant

Commands:
NORTH/EAST/WEST/SOUTH
PICK
DROP
QUIT

Methods:
introduceRoom
inventoryHas (DROP)
*/