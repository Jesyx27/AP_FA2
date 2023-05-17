#pragma once
#include <iostream>
#include <string>

class Pallet {
    private:
        int itemCount;
        std::string itemName;
        int itemCapacity;
    
    public:
        Pallet();
        Pallet(std::string itemName, int itemCapacity, int itemCount);

        std::string getItemName() const;
        int getItemCount() const;
        int getRemainingSpace() const;
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity) const;
        bool takeOne() const;
        bool putOne() const;
};