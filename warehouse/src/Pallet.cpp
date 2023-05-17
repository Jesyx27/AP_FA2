#include "include/pallet.hpp"
#include <string>
#include <iostream>

Pallet::Pallet(): itemName(""), itemCapacity(0), itemCount(0) {}
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) {}

std::string Pallet::getItemName() const {
    return itemName;
}

int Pallet::getItemCount() const {
    return this->itemCount;
}

int Pallet::getRemainingSpace() const {
    return this->itemCapacity - this->itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) const {
    if (this->itemCount != 0) { return false }

    this->itemName = itemName;
    this->itemCapacity = itemCapacity;

    return true;
}

bool takeOne() {
    if (this->itemCount <= 0) {
        return false;
    }

    this->itemCount -= 1;
    return true;
}

bool putOne() {
    if (this->itemCount >= this->itemCapacity) {
        
    }
}