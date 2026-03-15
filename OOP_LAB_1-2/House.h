#pragma once
#include <string>
#include "Property.h"

class House : public Property {
    private:
    bool isFree;
    int price;

    public:
    House(std::string a , int p) : Property (a) , price(p) , isFree(true) {}

    bool isAvailableForSale() override{return isFree; }
    int checkPrice() override{return price; }

    void changeStatus() override;

};