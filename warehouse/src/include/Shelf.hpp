#pragma once
#include "Pallet.hpp"
#include <array>

class Shelf : public IContainer {
    public:
        std::array<Pallet, 4> pallets;

        Shelf();
        
        bool SwapPallet(int slot, int slot2);
        bool isEmpty() override;
        bool isFull() override;
};