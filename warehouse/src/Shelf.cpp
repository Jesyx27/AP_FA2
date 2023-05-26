#include "include/Shelf.hpp"
#include "iostream"

Shelf::Shelf(): pallets() {}

/// @brief Swap two pallets' locations within the shelf
/// @param slot The index of the first pallet
/// @param slot2 The index of the second pallet
/// @return Whether the swap could be completed
bool Shelf::SwapPallet(unsigned int slot, unsigned int slot2) {
    // If slot and slot2 are in range of pallets; swap them
    if (0 <= slot && slot < static_cast<unsigned int>(this->pallets.size()) && 0 <= slot2 && slot2 < static_cast<unsigned int>(this->pallets.size())) {
        std::swap(pallets[slot], pallets[slot2]);
        return true;
    }
    return false;
}


/// @brief Wheter the shelf fully contains only empty pallets, inherited off IContainer
/// @return Wheter the pallet is empty
bool Shelf::isEmpty() {
    unsigned int actualSize = 0;

    for (Pallet p : this->pallets) {
        if (p.getItemCount() == 0) {
            actualSize++;
        }
    }

    return actualSize == pallets.size();
}

/// @brief Wheter the shelf fully contains only full pallets, also returns true if their capacity is zero, inherited off IContainer
/// @return Wheter the pallet is full
bool Shelf::isFull() {
    unsigned int actualSize = 0;

    for (Pallet p : this->pallets) {
        if (p.getRemainingSpace() != 0) {
            actualSize++;
        }
    }

    return actualSize == 0;
}