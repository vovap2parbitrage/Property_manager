#include <iostream>
#include <string>
#include <vector>

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

class Room {
    private:
    int price;
    bool isFree;

    public:
    Room(int p) : price(p) , isFree(true) {}

    bool checkAvailability() {return isFree; }
    int checkPrice() {return price; }

    void changeStatus() {
        if(isFree) {
            isFree = false;
            return;
        }
        isFree = true;
    }

};

class Flat : public Property {
    private:
    std::vector<Room*> rooms;

    public:
    Flat(std::string a , Room* r1 , Room* r2) : Property(a) {
        rooms.push_back(r1);
        rooms.push_back(r2);
    }

    bool isAvailableForSale() override{
        for(int i = 0 ; i < rooms.size() ; ++i) {
            if(!rooms[i]->checkAvailability()) {
                return false;
            }
        }
        return true;
    }

    int checkPrice() override{
        int totalPrice = 0;
        for(int i = 0 ; i < rooms.size() ; ++i) {
            totalPrice += rooms[i]->checkPrice();
        }
        return totalPrice;
    }

    void changeStatus() override{
        for(int i = 0 ; i < rooms.size() ; ++i) {
            rooms[i]->changeStatus();
        }
    }

};

class House : public Property {
    private:
    bool isFree;
    int price;

    public:
    House(std::string a , int p) : Property (a) , price(p) , isFree(true) {}

    bool isAvailableForSale() override{return isFree; }
    int checkPrice() override{return price; }

    void changeStatus() override{
        if(isFree) {
            isFree = false;
            return;
        }
        isFree = true;
    }

};

class Property_manager {
    private:
    std::string name;
    int earning;
    std::vector<Property*> apartments_catalog;

    public:
    Property_manager(std::string n) : name(n) , earning(0) {}

    ~Property_manager() = default;

    void addToAssortment(Property* property) {
        apartments_catalog.push_back(property);
    }

    int checkInAssortment(Property* property) {
        for(int i = 0 ; i < apartments_catalog.size() ; ++i) {
            if(apartments_catalog[i] == property && property->isAvailableForSale()) {
                return i;
            }
        }
        return -1;
    }

    void earn(Property* property) {
        earning += property->checkPrice();
    }

    void taxDeclaration() {
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

};

class Customer {
    private:
    std::string name;
    int capital;
    std::vector<Property*> ownedProperty;

    public:
    Customer(std::string n , int c) : name(n) , capital(c) {}

    ~Customer() = default;

    void buyProperty(Property* property , Property_manager &manager) {
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

    void taxDeclaration() {
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
};

int main() {

    Property_manager Boris("Boris");

    Customer Bogach("Bogach" , 1000000);
    Customer Serednii("Serednii" , 110000);

    Room room_a(30000);
    Room room_b(40000);
    Room room_c(50000);
    Room room_d(70000);

    Flat flat_1("Shevchenka_13" , &room_a , &room_d);
    House house_1("Ostrogradskogo_2" , 110000);
    Flat flat_2("Gutten_morgen_9" , &room_b , &room_c);

    Boris.addToAssortment(&flat_1);
    Boris.addToAssortment(&house_1);
    Boris.addToAssortment(&flat_2);

    Bogach.buyProperty(&flat_1 , Boris);
    Serednii.buyProperty(&flat_2 , Boris);
    Bogach.buyProperty(&flat_2 , Boris);
    Serednii.buyProperty(&house_1 , Boris);
    Bogach.buyProperty(&house_1 , Boris);

    Bogach.taxDeclaration();
    Serednii.taxDeclaration();

    Boris.taxDeclaration();

    return 0;
}