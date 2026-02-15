#include <iostream>
#include <string>
#include <vector>

class Property {
    private:
    std::string address;
    int price;
    bool isFree;
    
    public:
    Property(std::string a , int p) : address(a) , price(p) , isFree(true) {}

    ~Property() = default;

    std::string checkAddress() {return address; }
    bool isAvailableForSale() {return isFree; }
    int checkPrice() {return price; }

    void changeStatus() {
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
    int capital;
    std::vector<Property*> free_apartments;

    public:
    Property_manager(std::string n , int c) : name(n) , capital(c) {}

    ~Property_manager() = default;

    void addToAssortment(Property* property) {
        free_apartments.push_back(property);
    }

    int checkInAssortment(Property* property) {
        for(int i = 0 ; i < free_apartments.size() ; ++i) {
            if(free_apartments[i] = property) {
                return i;
            }
        }
        return -1;
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

    void buyProperty(Property* property , Property_manager manager) {
        int propInd = manager.checkInAssortment(property);
        if(propInd == -1  || !property->isAvailableForSale()) {
            std::cout << "Property by address " << property->checkAddress() << " is no available!\n";
            return;
        }
        if(capital > property->checkPrice()) {
            capital -= property->checkPrice();
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

    Property_manager Boris("Boris" , 0);

    Customer Bogach("Bogach" , 1000000);
    Customer Serednii("Serednii" , 100000);

    Property flat_1("Shevchenka_13" , 130000);
    Property flat_2("Ostrogradskogo_2" , 110000);
    Property flat_3("Gutten_morgen_9" , 90000);

    Boris.addToAssortment(&flat_1);
    Boris.addToAssortment(&flat_2);
    Boris.addToAssortment(&flat_3);

    Bogach.buyProperty(&flat_1 , Boris);
    Serednii.buyProperty(&flat_2 , Boris);
    Bogach.buyProperty(&flat_2 , Boris);
    Serednii.buyProperty(&flat_3 , Boris);
    Serednii.buyProperty(&flat_2 , Boris);

    Bogach.taxDeclaration();
    Serednii.taxDeclaration();

    return 0;
}