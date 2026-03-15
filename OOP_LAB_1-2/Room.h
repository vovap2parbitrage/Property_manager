#pragma once

class Room {
    private:
    int price;
    bool isFree;

    public:
    Room(int p) : price(p) , isFree(true) {}

    ~Room() = default;

    bool checkAvailability();
    int checkPrice();
    void changeStatus();

};