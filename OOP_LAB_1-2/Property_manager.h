#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Property.h"

class Property_manager {
    private:
    std::string name;
    int earning;
    std::vector<Property*> apartments_catalog;

    public:
    Property_manager(std::string n) : name(n) , earning(0) {}

    ~Property_manager() = default;

    void addToAssortment(Property* property);
    int checkInAssortment(Property* property);
    void earn(Property* property);
    void taxDeclaration();

};