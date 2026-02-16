#include <iostream>
#include <string>
#include <vector>
#include "Flat.h"
#include "House.h"
#include "Property_manager.h"
#include "Customer.h"

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