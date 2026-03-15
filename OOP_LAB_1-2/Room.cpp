#include "Room.h"

bool Room::checkAvailability() {return isFree; }
int Room::checkPrice() {return price; }

void Room::changeStatus() {
    if(isFree) {
        isFree = false;
        return;
    }
    isFree = true;
}