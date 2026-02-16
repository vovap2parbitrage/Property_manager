#pragma once
#include <string>

class Property {
    private:
    std::string address;
    
    public:
    Property(std::string a) : address(a) {}

    virtual ~Property() = default;

    std::string checkAddress() {return address; }
    virtual bool isAvailableForSale() = 0;
    virtual int checkPrice() = 0;

    virtual void changeStatus() = 0;

};