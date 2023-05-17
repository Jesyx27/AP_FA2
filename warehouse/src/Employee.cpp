#include <iostream>
#include <string>
#include "include/Employee.hpp"

Employee::Employee(): name(""), forkliftCertificate(false) {}
Employee::Employee(std::string name, bool forkliftCertificate) {}

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