#pragma once
#include <string>
#include <vector>
#include "Employee.hpp"
#include "Shelf.hpp"

class Warehouse {
    public:
        std::vector<Employee> Employees;
        std::vector<Shelf> Shelves;

        Warehouse();

        void addEmployee(Employee employee);
        void addShelf(Shelf shelf);
        bool rearrangeShelf(Shelf& shelf);
        bool pickItems(std::string itemName, unsigned int itemCount);
        bool putItems(std::string itemName, unsigned int itemCount);
};