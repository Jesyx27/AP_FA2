#pragma once
#include <iostream>
#include <string>
#include "IContainer.hpp"

class Pallet : public IContainer {
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
        bool reallocateEmptyPallet(std::string itemName, int itemCapacity);
        bool takeOne();
        bool putOne();

        bool isEmpty() override;
        bool isFull() override;

        // Added to make debuggin easier
        friend std::ostream& operator<<(std::ostream& os, const Pallet& p);
};