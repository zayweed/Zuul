#include <iostream>
#include <vector>
#include <cstring>

#include <room.h>
#include <item.h>

using namespace std;

int main() {
    vector<room*> roomList;
    vector<item*> inventory;

    char* newDescription;
    strcpy(newDescription, "Java Class");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Science Class");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "I-20");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Math Class");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Library");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Pub");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Outside");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Theater");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Cafeteria");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Lab");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Office");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Staff Lounge");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Gym");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Lecture Hall");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);
    strcpy(newDescription, "Auditorium");
    room* newRoom = new room(newDescription);
    roomList.push_back(newRoom);

    strcpy(newDescription, "robot");
    item* newItem = new item(newDescription);
    roomList[2]->addItem(newItem);
    strcpy(newDescription, "chair");
    item* newItem = new item(newDescription);
    roomList[5]->addItem(newItem);
    strcpy(newDescription, "microphone");
    item* newItem = new item(newDescription);
    roomList[7]->addItem(newItem);
    strcpy(newDescription, "beaker");
    item* newItem = new item(newDescription);
    roomList[9]->addItem(newItem);
    strcpy(newDescription, "plant");
    item* newItem = new item(newDescription);
    roomList[10]->addItem(newItem);

    char* north;
    strcpy(north, "NORTH");
    char* east;
    strcpy(east, "EAST");
    char* south;
    strcpy(south, "SOUTH");
    char* west;
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
    
}

/*
0 Java Class 
1 Science Class
2 I-20
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

robot
chair
microphone
beaker
plant
*/