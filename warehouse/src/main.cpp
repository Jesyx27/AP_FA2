#include <iostream>
#include "include/Pallet.hpp"
#include "include/Employee.hpp"

int main(void){
    Employee myEmployee = Employee("Michael Scott", false);

    std::cout << myEmployee.getName() << ", " << myEmployee.getBusy() <<  ", " << myEmployee.getForkliftCertificate() << std::endl;
    myEmployee.setBusy(true);
    myEmployee.setForkliftCertificate(true);
    std::cout << myEmployee.getName() << ", " << myEmployee.getBusy() << ", "  << myEmployee.getForkliftCertificate() << std::endl;
}
