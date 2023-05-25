#include "include/Warehouse.hpp"
#include <algorithm>
#include "include/Warehouse.hpp"

Warehouse::Warehouse(): Employees(std::vector<Employee> {}), Shelves(std::vector<Shelf> {}){}

void Warehouse::addEmployee(Employee employee) {
    // If employee not yet in Employee(vector)
    if (std::find(std::begin(Employees), std::end(Employees), employee) == std::end(Employees)) {
        Employees.push_back(employee);
    }
}

void Warehouse::addShelf(Shelf shelf) {
    Shelves.push_back(shelf);
}

bool Warehouse::rearrangeShelf(Shelf& shelf) {
    // Create empty ref
    Employee* avalibleEmployee = NULL;

    for (unsigned int i = 0; i < Employees.size(); i++) {
        if ((Employees[i].getForkliftCertificate() && !Employees[i].getBusy())) {
            // Assign first avalible employee to ref and break loop
            avalibleEmployee = &Employees[i];
            break;
        }
    }

    // Return false if ref is still NULL
    if (avalibleEmployee == NULL) {
        return false;
    }

    avalibleEmployee->setBusy(true);

    while (true) {
        unsigned int count = 0;

        for (unsigned int i = 1; i < shelf.pallets.size(); i++) {
            if (shelf.pallets[i].getItemCount() < shelf.pallets[i - 1].getItemCount()) {
                shelf.SwapPallet(i, i - 1);
                break;
            }
            count++;
        }

        if (count == shelf.pallets.size() - 1) {
            break;
        }
    }
    
    avalibleEmployee->setBusy(false);

    return true;
}

bool Warehouse::pickItems(std::string itemName, int itemCount) {
    std::vector<Pallet*> pallets = std::vector<Pallet*>();
    int avalibleItems = 0;

    for (Shelf shelf: Shelves) {
        if (!shelf.isEmpty()) {
            for (Pallet pallet: shelf.pallets) {
                if (pallet.getItemName() == itemName && !pallet.isEmpty()) {
                    pallets.push_back(&pallet);
                    avalibleItems += pallet.getItemCount();
                }
            }
        }
    }

    if (avalibleItems < itemCount) {
        return false;
    }

    int itemsRemaining = itemCount;

    for (Pallet* p: pallets) {
        while (itemsRemaining > 0 && !p->isEmpty()) {
            p->takeOne();
            itemsRemaining--;
        }
    }

    return true;
}