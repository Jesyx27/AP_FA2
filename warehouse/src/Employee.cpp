#include "include/Employee.hpp"
#include <ostream>

Employee::Employee(std::string name, bool forkliftCertificate): name(name), forkliftCertificate(forkliftCertificate), busy(false) {}

/// @brief Gets the name of the employee
/// @return The name of the employee
std::string Employee::getName() const {
    return this->name;
}

/// @brief Get whether the employee is busy
/// @return Boolean whether the employee is busy
bool Employee::getBusy() const {
    return this->busy;
}

/// @brief Set the employee as busy or not busy
/// @param busy Whether the employee is busy
void Employee::setBusy(bool busy) {
    this->busy = busy;
}

/// @brief Get wheter the employee has a forklift certificate
/// @return Wheter the employee has a forklift certificate
bool Employee::getForkliftCertificate() const {
    return this->forkliftCertificate;
}

/// @brief Set wheter the employee has a forklift certificate 
/// @param forkliftCertificate Whether the employee has a forklift certificate
void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
}

bool operator==(const Employee& lhs, const Employee& rhs) {
    // Two employees are concidered to be equal if they have the same name and both have either a forklift certificate or both not
    return (lhs.getName() == rhs.getName()) && (lhs.getForkliftCertificate() == rhs.getForkliftCertificate());
}

std::ostream& operator<<(std::ostream& os, Employee& e) { 
    // Throw useful inforation into the output stream in the format:
    //      "(name: {std::string name}, forklift: {bool forkliftCertificate}, busy: {bool busy})"
    os << "(name:" << e.getName() << ", forklift: " << e.getForkliftCertificate() << ", busy: " << e.getBusy() << ")";
    return os;
}