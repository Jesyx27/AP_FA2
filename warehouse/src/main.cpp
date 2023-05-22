#include "include/Pallet.hpp"
#include "include/Shelf.hpp"
#include "include/Employee.hpp"

int main(void){
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
