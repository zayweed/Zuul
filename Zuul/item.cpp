//item functions
#include <iostream>
#include <cstring>

#include "item.h"

using namespace std;

item::item(char* newDescription) { //constructer
  strcpy(description, newDescription);
}

char* item::getDescription() { //returns description
    return description;
}
