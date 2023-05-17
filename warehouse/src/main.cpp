#include <iostream>
#include <string>
#include "include/Pallet.hpp"

int main(void){
    Pallet myPallet = Pallet("Bread", 12, 3);
    myPallet.putOne();

    std::cout << myPallet.getItemName() << std::endl;
    
    while (myPallet.getItemCount() > 0) {
        myPallet.takeOne();
    }
    
    std::cout << myPallet.getItemCount() << myPallet.getItemName() << std::endl;
    myPallet.reallocateEmptyPallet("Eggs", 16);
    std::cout << myPallet.getRemainingSpace() << myPallet.getItemName() << std::endl;
}
