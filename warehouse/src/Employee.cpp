#include "include/Employee.hpp"
#include <ostream>

Employee::Employee(std::string name, bool forkliftCertificate): name(name), forkliftCertificate(forkliftCertificate), busy(false) {}

std::string Employee::getName() const {
    return this->name;
}

bool Employee::getBusy() const {
    return this->busy;
}

void Employee::setBusy(bool busy) {
    this->busy = busy;
}

bool Employee::getForkliftCertificate() const {
    return this->forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
}

bool operator==(const Employee& lhs, const Employee& rhs) {
    return (lhs.getName() == rhs.getName()) && (lhs.getForkliftCertificate() == rhs.getForkliftCertificate());
}

std::ostream& operator<<(std::ostream& os, Employee& e) { 
    std::cout << "(name:" << e.getName() << ", forklift: " << e.getForkliftCertificate() << ", busy: " << e.getBusy() << ")";
    return os;
}