#include "include/Shelf.hpp"

Shelf::Shelf(): pallets(std::array<Pallet, 4> {}) {}

bool Shelf::SwapPallet(int slot, int slot2) {
    if ((0 < slot < pallets.size()) && (0 < slot2 < pallets.size())) {
        std::swap(pallets[slot], pallets[slot2]);
        return true;
    }
}