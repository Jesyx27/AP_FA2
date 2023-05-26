#include "include/Warehouse.hpp"
#include <algorithm>
#include "include/Warehouse.hpp"

/// @brief Warehouse object that keeps track of its employees and shelves
Warehouse::Warehouse(): Employees(std::vector<Employee> {}), Shelves(std::vector<Shelf> {}){}

/// @brief Add one employee to the warehouse if it is not already added
/// @param employee The employee that is to be added to the warehouse
void Warehouse::addEmployee(Employee employee) {
    // If employee not yet in Employee(vector)
    if (std::find(std::begin(Employees), std::end(Employees), employee) == std::end(Employees)) {
        Employees.push_back(employee);
    }
}

/// @brief Add a shelf to the warehouse 
/// @param shelf The shelf that is to be added to the warehouse
void Warehouse::addShelf(Shelf shelf) {
    Shelves.push_back(shelf);
}

/// @brief Rearange pallets in a shelf, sorted by increasing item count
/// @param shelf The shelf in which the pallets are to be rearranged 
/// @return Wheter the operation could be completed
bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Create empty ref to store a suitable employee if found
    Employee* avalibleEmployee = NULL;

    for (unsigned int i = 0; i < Employees.size(); i++) {
        if ((Employees[i].getForkliftCertificate() && !Employees[i].getBusy())) {
            // Assign first avalible employee to ref and break loop
            avalibleEmployee = &Employees[i];
            break;
        }
    }

    // Return false if ref is still NULL, this means no suitible employee could be found
    if (avalibleEmployee == NULL) {
        return false;
    }

    avalibleEmployee->setBusy(true);

    // Rearrangement of pallets
    while (true) {
        unsigned int count = 0;

        // Iterate over shelfs to swap shelfs that are in the wrong order (bubble sort)
        for (unsigned int i = 1; i < shelf.pallets.size(); i++) {
            if (shelf.pallets[i].getItemCount() < shelf.pallets[i - 1].getItemCount()) {
                shelf.SwapPallet(i, i - 1);
                break;
            }
            count++;
        }

        // If at the end of the sort, end the while loop
        if (count == shelf.pallets.size() - 1) {
            break;
        }
    }
    
    avalibleEmployee->setBusy(false);

    return true;
}

/// @brief Pick items from a particular item in the warehouse, if not enough are found: fail the operation
/// @param itemName The item name that is to be picked
/// @param itemCount The amount of items that are to be picked 
/// @return Whether the opeation could succeed
bool Warehouse::pickItems(std::string itemName, unsigned int itemCount) {
    std::vector<Pallet*> pallets = std::vector<Pallet*>();
    unsigned int avalibleItems = 0;

    // Count the items and add Pallet* to list to take the items if enough are found
    for (unsigned int i = 0; i < this->Shelves.size(); i++) {
        if (!Shelves[i].isEmpty()) {
            for (unsigned int j = 0; j < Shelves[i].pallets.size(); j++) {
                if (Shelves[i].pallets[j].getItemName() == itemName && !Shelves[i].pallets[j].isEmpty()) {
                    pallets.push_back(&Shelves[i].pallets[j]);
                    avalibleItems += Shelves[i].pallets[j].getItemCount();
                }
            }
        }
    }

    // Return false if not enough items are found
    if (avalibleItems < itemCount) {
        return false;
    }

    unsigned int itemsRemaining = itemCount;

    // Take the items from the pallets
    for (unsigned int i = 0; i < pallets.size(); i++) {
        while (itemsRemaining > 0 && !pallets[i]->isEmpty()) {
            pallets[i]->takeOne();
            itemsRemaining--;
        }
    }

    return true;
}

/// @brief Pick items from a particular item in the warehouse, if not enough are found: fail the operation
/// @param itemName The item name that is to be picked
/// @param itemCount The amount of items that are to be picked 
/// @return Whether the opeation could succeed
bool Warehouse::putItems(std::string itemName, unsigned int itemCount) {
    std::vector<Pallet*> pallets = std::vector<Pallet*>();
    unsigned int avalibleSpaces = 0;

    // Count the items and add Pallet* to list to take the items if enough are found
    for (unsigned int i = 0; i < Shelves.size(); i++) {
        if (!Shelves[i].isEmpty()) {
            for (unsigned int j = 0; j < Shelves[i].pallets.size(); j++) {
                if (Shelves[i].pallets[j].getItemName() == itemName && !Shelves[i].pallets[j].isFull()) {
                    pallets.push_back(&(Shelves[i].pallets[j]));
                    avalibleSpaces += Shelves[i].pallets[j].getRemainingSpace();
                }
            }
        }
    }

    // Return false if not empty items are found
    if (avalibleSpaces < itemCount) {
        return false;
    }

    int itemsRemaining = itemCount;

    // Take the items from the pallets
    for (unsigned int i = 0; i < pallets.size(); i++) {
        while (itemsRemaining > 0 && !pallets[i]->isFull()) {
            pallets[i]->putOne();
            itemsRemaining--;
        }
    }

    return true;
}