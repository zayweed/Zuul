/*
Zuul is a text based adventure game where you traverse Sunset High School in an effort to capture special items. In order to win, you must capture all 5 items and return back to the starting point, the I-20 Lab.
Commands 'NORTH', 'EAST', 'SOUTH', and 'WEST' move the player to the room that is in the respective direction if there is an exit. Command 'PICK' allows the player to pick up an item in the current room that they name and put it in their inventory. Command 'DROP' allows the player to drop an item in their inventory that they name into the room they are currently in. Command 'QUIT' quits the game.
Credits to Shivam Trivedi for letting me use his map for this project
Zayeed Saffat
1/11/2022
*/

#include <iostream>
#include <cstring>
#include <vector>

#include "room.h"
#include "item.h"

using namespace std;

//function that prints player inventory
void printInventory(vector<item*> inventory) {
    cout << "Items in your inventory:" << endl;
    for (item* i : inventory) {
        cout << i->getDescription() << endl;
    }
}

//function that introduces information the player should know before every turn: name of room, exits, items in room, and player inventory
void introduceRoom(room* currentRoom, vector<item*> inventory) {
    cout << "You are currently in the " << currentRoom->getDescription() << "." << endl;
    currentRoom->printExits();
    currentRoom->printItems();
    printInventory(inventory);
}

//function that says if an inventory has an item with the name that is given and also updates the index of that item within the inventory
bool inventoryHas(vector<item*> inventory, char itemDescription[100], int &index) {
    for (int i = 0; i > inventory.size(); i++) {
        if (strcmp(inventory[i]->getDescription(), itemDescription) == 0) {
            return true;
            index = i;
        }
    }

    return false;
}

int main() {
    vector<room*> roomList;
    vector<item*> inventory;

    //initializing each room and putting it into the room list
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
    
    //intializing each item and putting it into a room
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

    //making every exit for each room
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

    cout << "Welcome to Zuul, a text based adventure game where you traverse Sunset High School in an effort to capture special items. In order to win, you must capture all 5 items and return back to the starting point, the I-20 Lab. Good luck!" << endl;
    
    bool stillPlaying = true;
    while (stillPlaying == true) { //while loop for every turn
        cout << endl;
        introduceRoom(currentRoom, inventory);
        cout << "What would you like to do next? ('NORTH','EAST','SOUTH','WEST','PICK','DROP','QUIT')" << endl;
        char input[100];
        cin >> input;

        if (strcmp(input, "NORTH") == 0 || strcmp(input, "EAST") == 0 || strcmp(input, "SOUTH") == 0 || strcmp(input, "WEST") == 0) { //if a direction is inputted, checks if there is an exit and then sets current room
            if (currentRoom->hasExit(input) == true) {
                currentRoom = currentRoom->getExit(input);
            }
            else {
                cout << "An exit does not exist in that direction." << endl;
            }
        }
        
        else if (strcmp(input, "PICK") == 0) { //pick
            cout << "What is the name of the item you want to pick up?" << endl;
            char itemDescription[100];
            cin >> itemDescription;

            if (currentRoom->hasItem(itemDescription) == true) { //if inputted item is in the room, removes it from the room and adds it to player inventory
                newItem = new item(itemDescription);
                inventory.push_back(newItem);
                currentRoom->removeItem(itemDescription);
            }
            else {
                cout << "This item is not in the room." << endl;   
            }
        }

        else if (strcmp(input, "DROP") == 0) { //drop
            cout << "What is the name of the item you want to drop?" << endl;
            char itemDescription[100];
            cin >> itemDescription;

            int index;
            if (inventoryHas(inventory, itemDescription, index) == true) { //if inputted item is in player inventory, removes it from inventory and adds it to the room
                inventory.erase(inventory.begin()+index);
                newItem = new item(itemDescription);
                currentRoom->addItem(newItem);
            }
            else {
                cout << "This item is not in your inventory." << endl;   
            }
        }

        else if (strcmp(input, "QUIT") == 0) { //quits game
            stillPlaying = false;
        }

        else {
            cout << "Invalid input." << endl;
        }
        
        if (inventory.size() == 5 && strcmp(currentRoom->getDescription(), "I-20 Lab") == 0) { //checks if player has met win conditions and quits game
            cout << "You win! Congratulations." << endl;
            stillPlaying = false;
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
printInventory
introduceRoom
inventoryHas (DROP)
*/
