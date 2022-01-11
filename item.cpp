#include <iostream>
#include <cstring>

#include "item.h"

using namespace std;

item::item(char* newDescription) {
  strcpy(description, newDescription);
}

char* item::getDescription() {
    return description;
}