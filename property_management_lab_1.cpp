#include <iostream>
#include <string>
#include <vector>
#include "Flat.h"
#include "House.h"
#include "Property_manager.h"
#include "Customer.h"

int main() {

    bool isWorking = true;

    do
    {
        std::cout << "1. Create Property manager\n";
        std::cout << "2. Create House\n";
        std::cout << "3. Create Room\n";
        std::cout << "4. Create Flat\n";
        std::cout << "5. Create Customer\n";
        std::cout << "==================================\n";
        std::cout << "6. Choose existed Property manager\n";
        int a;
        std::cin >> a;

    } while (isWorking);


    return 0;
}