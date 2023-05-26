#include "include/Pallet.hpp"

Pallet::Pallet(): Pallet("", 0, 0) {}
// Cap itemCapacity and itemCount to 0 if smaller than it
Pallet::Pallet(std::string itemName, unsigned int itemCapacity, unsigned int itemCount): itemName(itemName), itemCapacity(itemCapacity), itemCount(itemCount) {}

/// @brief Get the name of the items on the pallet
/// @return Name of items on the pallet
std::string Pallet::getItemName() const {
    return this->itemName;
}

/// @brief Get the amount of items on the pallet
/// @return Amount of items on the pallet 
unsigned int Pallet::getItemCount() const {
    // Return the item count, but multiply it by boolean wheter the count is larger than zero, (bottom limt = 0)
    return this->itemCount;
}

/// @brief Get remaining space that can be occupied by items on the pallet
/// @return Remaining space on the pallet
unsigned int Pallet::getRemainingSpace() const {
    // Return the remaining space, but multiply it by boolean wheter the resulting value is larger than zero, (bottom limt = 0)
    return (this->itemCapacity - this->itemCount) * ((this->itemCapacity - this->itemCount) > 0);
}

/// @brief Change the pallet designation of a pallet which is empty, if not the action cannot be completed
/// @param itemName The new name of the pallet
/// @param itemCapacity The new item capacity of the pallet
/// @return Whether the reallocation could be completed
bool Pallet::reallocateEmptyPallet(std::string itemName, unsigned int itemCapacity) {
    if (!this->isEmpty()) { return false; }

    this->itemName = itemName;
    this->itemCapacity = itemCapacity;

    return true;
}

/// @brief Take one item off the pallet
/// @return Wheter the operation could be completed
bool Pallet::takeOne() {
    if (this->itemCount <= 0) {
        return false;
    }

    this->itemCount--;
    return true;
}

/// @brief Put one item on the pallet
/// @return Wheter the operation could be completed
bool Pallet::putOne() {
    if (this->itemCount >= this->itemCapacity) {
        return false;
    }

    this->itemCount++;
    return true;
}

/// @brief Wheter the pallet is empty, inherited off IContainer
/// @return Whether the pallet it empty
bool Pallet::isEmpty() {
    return (this->itemCount == 0); 
}

/// @brief Wheter the pallet is full, also returns true if the capacity is zero, inherited off IContainer
/// @return Wheter the pallet is full
bool Pallet::isFull() {
    return getRemainingSpace() == 0;
}

bool operator==(const Pallet lhs, const Pallet rhs) {
    // Two Pallets are concidered to be equal if they have the same itemName and itemCount
    return (lhs.getItemName() == rhs.getItemName()) && (lhs.getItemCount() == rhs.getItemCount()) && (lhs.getRemainingSpace() == rhs.getRemainingSpace());
}

std::ostream& operator<<(std::ostream& os,  const Pallet& p) { 
    // Throw useful inforation into the output stream in the format:
    //      "({std::string itemName}, {unsigned int itemCount}/{unsigned int itemCount + unsigned int remainingSpace})"
    os << "(" << p.getItemName() << ", " << p.getItemCount() << "/" << (p.getItemCount() + p.getRemainingSpace()) << ")";
    return os;
}