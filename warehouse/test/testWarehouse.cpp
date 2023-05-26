#include "include/catch.hpp"
#include "../src/include/warehouse.hpp"
#include <iostream>

///////////////////////////////////////////////////////////////
//                                                           //
//                    Warehouse unittests                    //
//                                                           //
///////////////////////////////////////////////////////////////
//                                                           //
// This file contains all testcases for the Warehouse class. //
// Currently it only contains tests for the rearranging of   //
// Shelves. All other Warehouse functions will also need to  //
// be tested. You will have to do this yourself.             //
//                                                           //
// For information on how to write testcases with catch2,    //
// see https://github.com/catchorg/Catch2.                   //
//                                                           //
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
//                Functions used in testcases                //
///////////////////////////////////////////////////////////////

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted Shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse(){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("Bob", true));

    return warehouse;
}


///////////////////////////////////////////////////////////////
//           Warehouse::rearrangeShelf test cases            //
///////////////////////////////////////////////////////////////

TEST_CASE("Rearrange empty shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and add empty shelf and forklift certified Employee.
    Warehouse warehouse = Warehouse();
    warehouse.addShelf(Shelf());
    warehouse.addEmployee(Employee("Bob", true));

    // Check if shelf is already arranged.
    // Empty shelf should already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Empty shelf should still be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);
}

TEST_CASE("Rearrange full shelf", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };

    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.

    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 10);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange half filled shelf", "Warehouse::rearrangeShelf"){
    // Construct empty warehouse and unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 20), 
        Pallet(), 
        Pallet()
    };
    
    warehouse.addEmployee(Employee("Bob", true));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 0);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should be successful
    REQUIRE(successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 0);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 40);
}

TEST_CASE("Rearrange shelf without qualified employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    warehouse.addEmployee(Employee("Bert", false));
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

TEST_CASE("Rearrange shelf with quallified, but busy, employee", "Warehouse::rearrangeShelf"){
    // Construct warehouse with unsorted shelf of books.
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 40), 
        Pallet("Books", 100, 30), 
        Pallet("Books", 100, 10)
    };
    
    Employee bert = Employee("Bert", true);
    bert.setBusy(true);

    warehouse.addEmployee(bert);
    warehouse.addShelf(shelf1);

    // Check if shelf is already arranged.
    // This shelf should not already be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);

    // Rearrange the first and only shelf of the warehouse.
    bool successful = warehouse.rearrangeShelf(warehouse.Shelves[0]);
    // Should fail
    REQUIRE(!successful);

    // Check if shelf is now correctly arranged.
    // Shelf should now still not be arranged.
    REQUIRE(warehouse.Shelves[0].pallets[0].getItemCount() == 20);
    REQUIRE(warehouse.Shelves[0].pallets[1].getItemCount() == 40);
    REQUIRE(warehouse.Shelves[0].pallets[2].getItemCount() == 30);
    REQUIRE(warehouse.Shelves[0].pallets[3].getItemCount() == 10);
}

#pragma region addEmployee

TEST_CASE("Test standard addition of Employees", "Warehouse::addEmployee()") {
    Warehouse testWarehouse = Warehouse();
    Employee testEmployee1 = Employee("Jane Doe", true);
    Employee testEmployee2 = Employee("John Doe", true);

    testWarehouse.addEmployee(testEmployee1);
    testWarehouse.addEmployee(testEmployee2);

    REQUIRE(testWarehouse.Employees[0] == testEmployee1);
    REQUIRE(testWarehouse.Employees[1] == testEmployee2);
    REQUIRE(testWarehouse.Employees.size() == 2);
}

TEST_CASE("Test addition of Employees that are already in the warehouse", "Warehouse::addEmployee()") {
    Warehouse testWarehouse = Warehouse();
    Employee testEmployee1 = Employee("Jane Doe", true);
    Employee testEmployee2 = Employee("John Doe", true);

    testWarehouse.addEmployee(testEmployee1);
    testWarehouse.addEmployee(testEmployee2);
    testWarehouse.addEmployee(testEmployee1);
    testWarehouse.addEmployee(testEmployee2);

    REQUIRE(testWarehouse.Employees[0] == testEmployee1);
    REQUIRE(testWarehouse.Employees[1] == testEmployee2);
    REQUIRE(testWarehouse.Employees.size() == 2);
}

#pragma region addShelf

TEST_CASE("Test regular addition of shelf", "Warehouse::AddShelf()") {
    Warehouse testWarehouse = Warehouse();
    Shelf testShelf1 = Shelf();
    Shelf testShelf2 = Shelf();
    Pallet testPallet1 = Pallet("Suomalainen Musta Kahvi Nam Nam", 12, 12);
    Pallet testPallet2 = Pallet("Karjalanpiirakka", 12, 3);
    
    testShelf1.pallets[0] = testPallet1;
    testShelf1.pallets[1] = testPallet2;

    testWarehouse.addShelf(testShelf1);
    testWarehouse.addShelf(testShelf2);

    REQUIRE(testWarehouse.Shelves.size() == 2);
    REQUIRE(testWarehouse.Shelves[0].pallets == testShelf1.pallets);
    REQUIRE(testWarehouse.Shelves[1].pallets == testShelf2.pallets);
}

TEST_CASE("Test addition of shelf, with twice the same pallet (should be able to)", "Warehouse::AddShelf()") {
    Warehouse testWarehouse = Warehouse();
    Shelf testShelf1 = Shelf();
    Pallet testPallet1 = Pallet("Suomalainen Musta Kahvi Nam Nam", 12, 12);
    Pallet testPallet2 = Pallet("Karjalanpiirakka", 12, 3);
    
    testShelf1.pallets[0] = testPallet1;
    testShelf1.pallets[1] = testPallet2;

    testWarehouse.addShelf(testShelf1);
    testWarehouse.addShelf(testShelf1);

    REQUIRE(testWarehouse.Shelves.size() == 2);
    REQUIRE(testWarehouse.Shelves[0].pallets == testShelf1.pallets);
    REQUIRE(testWarehouse.Shelves[1].pallets == testShelf1.pallets);
}

#pragma endregion addShelf

#pragma region pickItems

TEST_CASE("Testing pick items with more than enough items", "Warehouse::PickItems()") {
    // Has 40 + 20 + 20 + 15 + 5    = 100 Books
    // Has 10 + 20 + 30             = 60  Boxes
    // Has 20 + 10 + 30             = 60  Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    // Get half of items
    REQUIRE(testWarehouse.pickItems("Books", 50));
    REQUIRE(testWarehouse.pickItems("Boxes", 30));
    REQUIRE(testWarehouse.pickItems("Toy Bears", 30));

    // Get a quarter of items
    REQUIRE(testWarehouse.pickItems("Books", 25));
    REQUIRE(testWarehouse.pickItems("Boxes", 15));
    REQUIRE(testWarehouse.pickItems("Toy Bears", 15));
}   

TEST_CASE("Testing pick items with exactly enough items", "Warehouse::PickItems()") {
    // Has 40 + 20 + 20 + 15 + 5    = 100 Books
    // Has 10 + 20 + 30             = 60  Boxes
    // Has 20 + 10 + 30             = 60  Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    // Get all items
    REQUIRE(testWarehouse.pickItems("Books", 100));
    REQUIRE(testWarehouse.pickItems("Boxes", 60));
    REQUIRE(testWarehouse.pickItems("Toy Bears", 60));
}   

TEST_CASE("Testing pick items with more items than present", "Warehouse::PickItems()") {
    // Has 40 + 20 + 20 + 15 + 5    = 100 Books
    // Has 10 + 20 + 30             = 60  Boxes
    // Has 20 + 10 + 30             = 60  Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    // Get all items
    REQUIRE(!testWarehouse.pickItems("Books", 101));
    REQUIRE(!testWarehouse.pickItems("Boxes", 61));
    REQUIRE(!testWarehouse.pickItems("Toy Bears", 61));
}   

TEST_CASE("Testing pick items with enough items and then not enough", "Warehouse::PickItems()") {
    // Has 40 + 20 + 20 + 15 + 5    = 100 Books
    // Has 10 + 20 + 30             = 60  Boxes
    // Has 20 + 10 + 30             = 60  Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    // Get all items
    REQUIRE(testWarehouse.pickItems("Books", 99));
    REQUIRE(testWarehouse.pickItems("Boxes", 59));
    REQUIRE(testWarehouse.pickItems("Toy Bears", 59));

    REQUIRE(!testWarehouse.pickItems("Books", 2));
    REQUIRE(!testWarehouse.pickItems("Boxes", 2));
    REQUIRE(!testWarehouse.pickItems("Toy Bears", 2));
}   


//////////////////////////////////////
//      Warehouse::PutItems()       //
//////////////////////////////////////


TEST_CASE("Testing put items with more than enough items", "Warehouse::PickItems()") {
    // Has (100-40) + (100-20) + (100-20) + (100-15) + (100-5)  = 400 Book Spaces
    // Has (100-10) + (100-20) + (100-30)                       = 240  Boxes
    // Has (100-20) + (100-10) + (100-30)                       = 240  Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    // Put 100 items
    REQUIRE(testWarehouse.putItems("Books", 100));
    REQUIRE(testWarehouse.putItems("Boxes", 100));
    REQUIRE(testWarehouse.putItems("Toy Bears", 100));

    // Put 100 items once more
    REQUIRE(testWarehouse.putItems("Books", 100));
    REQUIRE(testWarehouse.putItems("Boxes", 100));
    REQUIRE(testWarehouse.putItems("Toy Bears", 100));
}   

TEST_CASE("Testing put items with exactly enough items", "Warehouse::PickItems()") {
    // Has (100-40) + (100-20) + (100-20) + (100-15) + (100-5)  = 400 Book Spaces
    // Has (100-10) + (100-20) + (100-30)                       = 240 Boxes
    // Has (100-20) + (100-10) + (100-30)                       = 240 Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    REQUIRE(testWarehouse.putItems("Books", 400));
    REQUIRE(testWarehouse.putItems("Boxes", 240));
    REQUIRE(testWarehouse.putItems("Toy Bears", 240));
}   

TEST_CASE("Testing put items with more items than present", "Warehouse::PickItems()") {
    // Has (100-40) + (100-20) + (100-20) + (100-15) + (100-5)  = 400 Book Spaces
    // Has (100-10) + (100-20) + (100-30)                       = 240 Boxes
    // Has (100-20) + (100-10) + (100-30)                       = 240 Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    REQUIRE(!testWarehouse.putItems("Books", 401));
    REQUIRE(!testWarehouse.putItems("Boxes", 241));
    REQUIRE(!testWarehouse.putItems("Toy Bears", 241));
}   

TEST_CASE("Testing put items with enough items and then not enough", "Warehouse::PickItems()") {
    // Has (100-40) + (100-20) + (100-20) + (100-15) + (100-5)  = 400 Book Spaces
    // Has (100-10) + (100-20) + (100-30)                       = 240 Boxes
    // Has (100-20) + (100-10) + (100-30)                       = 240 Toy Bears
    Warehouse testWarehouse = createMockWarehouse();
    
    REQUIRE(testWarehouse.putItems("Books", 399));
    REQUIRE(testWarehouse.putItems("Boxes", 239));
    REQUIRE(testWarehouse.putItems("Toy Bears", 239));

    REQUIRE(!testWarehouse.putItems("Books", 2));
    REQUIRE(!testWarehouse.putItems("Boxes", 2));
    REQUIRE(!testWarehouse.putItems("Toy Bears", 2));
}   
