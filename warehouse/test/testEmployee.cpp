#include "include/catch.hpp"
#include "../src/include/Employee.hpp"

////////////////////////////
//      Get Functions     //
////////////////////////////

TEST_CASE("Test name getting for default constructor", "Employee::getName()") {
    Employee testEmployee1 = Employee("John Doe", false);
    Employee testEmployee2 = Employee("Jane Doe", true);

    REQUIRE(testEmployee1.getName() == "John Doe");
    REQUIRE(testEmployee2.getName() == "Jane Doe");
}

TEST_CASE("Test forklift certificate getting for default constructor", "Employee::getForkliftCertificate()") {
    Employee testEmployee1 = Employee("John Doe", false);
    Employee testEmployee2 = Employee("Jane Doe", true);

    REQUIRE(!testEmployee1.getForkliftCertificate());
    REQUIRE(testEmployee2.getForkliftCertificate());
}

TEST_CASE("Test busy getting for default constructor", "Employee::getBusy()") {
    Employee testEmployee = Employee("Jane Doe", true);

    REQUIRE(!testEmployee.getBusy());
}

////////////////////////////
//      Set Functions     //
////////////////////////////

TEST_CASE("Test forklift certificate setting and getting for default constructor", "Employee::getForkliftCertificate()") {
    Employee testEmployee1 = Employee("John Doe", false);
    Employee testEmployee2 = Employee("Jane Doe", true);
    Employee testEmployee3 = Employee("Joe Biden", true);

    testEmployee1.setForkliftCertificate(true);
    testEmployee2.setForkliftCertificate(false);
    // Swap it twice to test occuring mutability 
    testEmployee3.setForkliftCertificate(false);
    testEmployee3.setForkliftCertificate(true);

    REQUIRE(testEmployee1.getForkliftCertificate());
    REQUIRE(!testEmployee2.getForkliftCertificate());
    REQUIRE(testEmployee3.getForkliftCertificate());
}

TEST_CASE("Test busy setting and getting for default constructor", "Employee::getBusy()") {
    Employee testEmployee1 = Employee("John Doe", false);
    Employee testEmployee2 = Employee("Jane Doe", true);
    Employee testEmployee3 = Employee("Joe Biden", true);

    testEmployee1.setBusy(true);
    testEmployee2.setBusy(false);
    // Swap it twice to test occuring mutability 
    testEmployee3.setBusy(false);
    testEmployee3.setBusy(true);

    REQUIRE(testEmployee1.getBusy());
    REQUIRE(!testEmployee2.getBusy());
    REQUIRE(testEmployee3.getBusy());
}
