#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Property.h"
#include "Property_manager.h"

class Customer {
    private:
    std::string name;
    int capital;
    std::vector<Property*> ownedProperty;

    public:
    Customer(std::string n , int c) : name(n) , capital(c) {}

    ~Customer() = default;

    void buyProperty(Property* property , Property_manager &manager);
    void taxDeclaration();

};