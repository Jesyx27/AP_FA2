#pragma once
#include <string>

class Employee {
    private:
        const std::string name;
        bool busy;
        bool forkliftCertificate;

    public:
        Employee();
        Employee(std::string name, bool forkliftCertificate);

        std::string getName() const;
        bool getBusy() const;
        void setBusy(bool busy);
        bool getForkliftCertificate() const;
        void setForkliftCertificate(bool forkliftCertificate);
};