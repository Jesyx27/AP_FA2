#pragma once
#include <iostream>
#include <string>
#include "IContainer.hpp"

class Pallet : public IContainer {
    private:
        std::string itemName;
        unsigned int itemCapacity;
        unsigned int itemCount;
    
    public:
        Pallet();
        Pallet(std::string itemName, unsigned int itemCapacity, unsigned int itemCount);

        std::string getItemName() const;
        unsigned int getItemCount() const;
        unsigned int getRemainingSpace() const;
        bool reallocateEmptyPallet(std::string itemName, unsigned int itemCapacity);
        bool takeOne();
        bool putOne();

        bool isEmpty() override;
        bool isFull() override;

        // Added to make debuggin easier
        friend std::ostream& operator<<(std::ostream& os, const Pallet& p);
        friend bool operator==(const Pallet lhs, const Pallet rhs);
};