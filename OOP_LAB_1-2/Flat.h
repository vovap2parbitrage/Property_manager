#pragma once
#include <vector>
#include "Property.h"
#include "Room.h"

class Flat : public Property {
    private:
    std::vector<Room*> rooms;

    public:
    Flat(std::string a , Room* r1 , Room* r2) : Property(a) {
        rooms.push_back(r1);
        rooms.push_back(r2);
    }

    bool isAvailableForSale() override;
    int checkPrice() override;
    void changeStatus() override;

};