#include "src/include/Warehouse.hpp"

void test_misc() {
    Employee myEmployee = Employee("Michael Scott", false);

    std::cout << myEmployee.getName() << ", " << myEmployee.getBusy() <<  ", " << myEmployee.getForkliftCertificate() << std::endl;
    myEmployee.setBusy(true);
    myEmployee.setForkliftCertificate(true);
    std::cout << myEmployee.getName() << ", " << myEmployee.getBusy() << ", "  << myEmployee.getForkliftCertificate() << std::endl;

    Shelf myShelf = Shelf();
    myShelf.pallets[0] = Pallet("Name1", 12, 6);
    myShelf.pallets[1] = Pallet("Name2", 24, 3);
    std::cout << "pallets before swap: " << myShelf.pallets[0] << ", " << myShelf.pallets[1] << std::endl;
    myShelf.SwapPallet(0, 2);
    std::cout << "pallets after swap: " << myShelf.pallets[0] << ", " << myShelf.pallets[1] << std::endl;
}


void testIContainer() {
    Pallet broodShelf = Pallet("Brood", 128, 128);
    Pallet kartonShelf = Pallet("Karton", 128, 0);

    //std::cout << broodShelf.isFull() << std::endl;
    //std::cout << broodShelf.isEmpty() << std::endl;
    //std::cout << kartonShelf.isFull() << std::endl;
    //std::cout << kartonShelf.isEmpty() << std::endl;

    Shelf volleShelf = Shelf();
    Shelf legeShelf = Shelf();
    volleShelf.pallets[0] = kartonShelf;
    volleShelf.pallets[1] = kartonShelf;
    volleShelf.pallets[2] = kartonShelf;
    volleShelf.pallets[3] = kartonShelf;

    std::cout << legeShelf.isFull() << std::endl;
    std::cout << legeShelf.isEmpty() << std::endl;
    std::cout << volleShelf.isFull() << std::endl;
    std::cout << volleShelf.isEmpty() << std::endl;
}

void testWarehouse() {
    Warehouse myWarehouse = Warehouse();
    myWarehouse.addEmployee(Employee("John", false));
    myWarehouse.addEmployee(Employee("Jane", true));
    Shelf myShelf = Shelf();
    myWarehouse.rearrangeShelf(myShelf);

    for (Employee e: myWarehouse.Employees) {
        std::cout << e << std::endl;
    }
}

int main(void){
    testWarehouse();
    return 0;
}
