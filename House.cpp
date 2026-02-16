#include "House.h"

void House::changeStatus() {
    if(isFree) {
        isFree = false;
        return;
    }
    isFree = true;
}