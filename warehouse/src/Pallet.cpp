#include "include/Pallet.hpp"

Pallet::Pallet(): Pallet("", 0, 0) {}
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

std::string Pallet::getItemName() {
    return this->itemName;
}

int Pallet::getItemCount() {
    return this->itemCount;
}

int Pallet::getRemainingSpace() {
    return this->itemCapacity - this->itemCount;
}

bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity) {
    if (this->itemCount != 0) { return false; }

    this->itemName = itemName;
    this->itemCapacity = itemCapacity;

    return true;
}

bool Pallet::takeOne() {
    if (this->itemCount <= 0) {
        return false;
    }

    this->itemCount--;
    return true;
}

bool Pallet::putOne() {
    if (this->itemCount >= this->itemCapacity) {
        return false;
    }

    this->itemCount++;
    return true;
}