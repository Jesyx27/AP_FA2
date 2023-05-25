#include "include/Shelf.hpp"
#include "iostream"

Shelf::Shelf(): pallets() {}

bool Shelf::SwapPallet(unsigned int slot, unsigned int slot2) {
    // If slot and slot2 are in range of pallets; swap them
    if (0 <= slot && slot < static_cast<unsigned int>(this->pallets.size()) && 0 <= slot2 && slot2 < static_cast<unsigned int>(this->pallets.size())) {
        std::swap(pallets[slot], pallets[slot2]);
        return true;
    }
    return false;
}

bool Shelf::isEmpty() {
    unsigned int actualSize = 0;

    for (Pallet p : this->pallets) {
        if (p.getItemCount() == 0) {
            actualSize++;
        }
    }

    return actualSize == pallets.size();
}

bool Shelf::isFull() {
    unsigned int actualSize = 0;

    for (Pallet p : this->pallets) {
        if (p.getRemainingSpace() != 0) {
            actualSize++;
        }
    }

    return actualSize == 0;
}