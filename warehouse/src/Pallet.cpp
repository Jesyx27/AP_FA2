#include "include/Pallet.hpp"

Pallet::Pallet(): Pallet("", -1, -1) {}
Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

std::string Pallet::getItemName() const {
    return this->itemName;
}

int Pallet::getItemCount() const {
    return this->itemCount;
}

int Pallet::getRemainingSpace() const {
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

bool Pallet::isEmpty() {
    return (this->itemCount == 0); 
}

bool Pallet::isFull() {
    return getRemainingSpace() == 0;
}

std::ostream& operator<<(std::ostream& os,  const Pallet& p) { 
    os << "(" << p.getItemName() << ", " << p.getItemCount() << "/" << (p.getItemCount() + p.getRemainingSpace()) << ")";
    return os;
}