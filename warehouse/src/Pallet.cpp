#include "include/Pallet.hpp"

Pallet::Pallet(): Pallet("", 0, 0) {}
// Cap itemCapacity and itemCount to 0 if smaller than it
Pallet::Pallet(std::string itemName, unsigned int itemCapacity, unsigned int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

std::string Pallet::getItemName() const {
    return this->itemName;
}

unsigned int Pallet::getItemCount() const {
    // Return the item count, but multiply it by boolean wheter the count is larger than zero, (bottom limt = 0)
    return this->itemCount;
}

unsigned int Pallet::getRemainingSpace() const {
    // Return the remaining space, but multiply it by boolean wheter the resulting value is larger than zero, (bottom limt = 0)
    return (this->itemCapacity - this->itemCount) * ((this->itemCapacity - this->itemCount) > 0);
}

bool Pallet::reallocateEmptyPallet(std::string itemName, unsigned int itemCapacity) {
    if (!this->isEmpty()) { return false; }

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

bool operator==(const Pallet lhs, const Pallet rhs) {
    return (lhs.getItemName() == rhs.getItemName()) && (lhs.getItemCount() == rhs.getItemCount()) && (lhs.getRemainingSpace() == rhs.getRemainingSpace());
}