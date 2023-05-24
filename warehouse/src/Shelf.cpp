#include "include/Shelf.hpp"
#include "iostream"

Shelf::Shelf(): pallets() {}

bool Shelf::SwapPallet(int slot, int slot2) {
    // If slot and slot2 are in range of pallets; swap them
    if (0 <= slot && slot < pallets.size() && 0 <= slot2 && slot2 < pallets.size()) {
        std::swap(pallets[slot], pallets[slot2]);
        return true;
    }
}

bool Shelf::isEmpty() {
    int actualSize = 0;

    for (Pallet p : this->pallets) {
        if (p.getItemCount() == 0) {
            actualSize++;
        }
    }

    return actualSize == 0;
}

bool Shelf::isFull() {
    int actualSize = 0;

    for (Pallet& p : this->pallets) {
        if (p.getItemName() == "") {
            actualSize++;
        }
    }
    
    return actualSize == pallets.size();
}