#include "Customer.h"

void Customer::buyProperty(Property* property , Property_manager &manager) {
    int propInd = manager.checkInAssortment(property);
    if(propInd == -1) {
        std::cout << "Property by address " << property->checkAddress() << " is no available!\n";
        return;
    }
    if(capital > property->checkPrice()) {
        capital -= property->checkPrice();
        manager.earn(property);
        property->changeStatus();
        ownedProperty.push_back(property);
        std::cout << name << " owned property on " << property->checkAddress() << "\n";
    }
    else {
        std::cout << name << " has no enough money to buy property on " << property->checkAddress() <<  "!\n";
    }
}

void Customer::taxDeclaration() {
    if(ownedProperty.size() != 0){
        std::cout << name << " has property by addresses: [";
        for(int i = 0 ; i < ownedProperty.size() ; ++i) {
            std::cout << ownedProperty[i]->checkAddress();
            if(i != ownedProperty.size() - 1) std::cout << " , ";
        }
        std::cout << "]\n";
        return;
    }
    std::cout << name << " has no property!\n";
}