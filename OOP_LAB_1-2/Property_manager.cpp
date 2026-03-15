#include "Property_manager.h"

void Property_manager::addToAssortment(Property* property) {
    apartments_catalog.push_back(property);
}

int Property_manager::checkInAssortment(Property* property) {
    for(int i = 0 ; i < apartments_catalog.size() ; ++i) {
        if(apartments_catalog[i] == property && property->isAvailableForSale()) {
            return i;
        }
    }
    return -1;
}

void Property_manager::earn(Property* property) {
    earning += property->checkPrice();
}

void Property_manager::taxDeclaration() {
    int counterOfAccess = 0;
    for(int i = 0 ; i < apartments_catalog.size() ; ++i) {
        if(apartments_catalog[i] -> isAvailableForSale()) counterOfAccess++;
    }
    if(counterOfAccess != 0) {
        std::cout << name << " has in catalog [ ";
        for(int i = 0 ; i < apartments_catalog.size() ; ++i) {
            if(apartments_catalog[i]->isAvailableForSale()) {
                std::cout << apartments_catalog[i]->checkAddress();
                counterOfAccess--;
            }
            if(counterOfAccess > 1) std::cout << " , ";
        }
        std::cout << "]\n";
    }
    else {
        std::cout << name << " sold all catalog of property\n";
    }
    std::cout << "Earned: " << earning << " and payed tax " << earning*0.235 << "\n"; 
}