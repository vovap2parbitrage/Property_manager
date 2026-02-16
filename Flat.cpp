#include "Flat.h"

bool Flat::isAvailableForSale() {
    for(int i = 0 ; i < rooms.size() ; ++i) {
        if(!rooms[i]->checkAvailability()) {
            return false;
        }
    }
    return true;
}

int Flat::checkPrice() {
    int totalPrice = 0;
    for(int i = 0 ; i < rooms.size() ; ++i) {
        totalPrice += rooms[i]->checkPrice();
    }
    return totalPrice;
}

void Flat::changeStatus() {
    for(int i = 0 ; i < rooms.size() ; ++i) {
        rooms[i]->changeStatus();
    }
}