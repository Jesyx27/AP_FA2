#pragma once
#include "Pallet.hpp"
#include <array>

class Shelf {
    public:
        std::array<Pallet, 4> pallets;

        Shelf();
        
        bool SwapPallet(int slot, int slot2);
};