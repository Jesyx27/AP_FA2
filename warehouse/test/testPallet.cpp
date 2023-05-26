#include "include/catch.hpp"
#include "../src/include/Shelf.hpp"

/////////////////////////////////////
//      Pallet::GetItemCount()     //
/////////////////////////////////////

TEST_CASE("Get Pallet Name", "Pallet::getItemCount()") {
    // Create a pallet and test whether the name is accesible
    Pallet testPallet = Pallet("testName", 12, 3);
    REQUIRE(testPallet.getItemName() == "testName");
}

TEST_CASE("Get normal item count", "Pallet.getItemCount()") {
    // Create a pallet and test whether the item count is accesible
    Pallet testPallet = Pallet("testName", 5, 5);
    REQUIRE(testPallet.getItemCount() == 5);
}

TEST_CASE("Get item count as 0", "Pallet::getItemCount()") {
    // Test whether an empty pallet will return zero items
    Pallet testPallet = Pallet("testName", 0, 0);
    REQUIRE(testPallet.getItemCount() == 0);
}

TEST_CASE("Get item count of standard construction", "Shelf::pallets[0].getItemCount()") {
    // Test whether a non-defined Shelf will return zero items
    Shelf testShelf = Shelf();
    REQUIRE(testShelf.pallets[0].getItemCount() == 0);
}

//////////////////////////////////////////
//      Pallet::GetRemainingSpace()     //
//////////////////////////////////////////

TEST_CASE("Get the remaining space, regular", "Pallet::getRemainingSpace") {
    // Test regualar behavior for remaining space
    Pallet testPallet = Pallet("testName", 10, 3);
    REQUIRE(testPallet.getRemainingSpace() == 7);
}

TEST_CASE("Get the remaining space of (empty) standard construction (0-0)", "Shelf.pallets[0]::getRemainingSpace()") {
    // Test a non-defined shelf's remaining space, 0 - 0 = 0?
    Shelf testShelf = Shelf();
    REQUIRE(testShelf.pallets[0].getRemainingSpace() == 0);
}

/////////////////////////
//      IContainer     //
/////////////////////////

TEST_CASE("Get the full/ emptiness of an pallet with zero space", "Pallet::isFull(), Pallet::isEmpty()") {
    
    Pallet testPallet = Pallet();

    REQUIRE(testPallet.isFull());
    REQUIRE(testPallet.isEmpty());
}

TEST_CASE("Get the fullness of a full pallet", "Pallet::isFull()") {
    Pallet testPallet = Pallet("testName", 100, 100);

    REQUIRE(testPallet.isFull());
}

TEST_CASE("Get the fullness of a non-full (non-empty) pallet", "Pallet::isFull()") {
    Pallet testPallet = Pallet("testName", 100, 50);

    REQUIRE(!testPallet.isFull());
}

TEST_CASE("Get the fullness of an empty pallet", "Pallet::isFull()") {
    Pallet testPallet = Pallet("testName", 100, 0);

    REQUIRE(!testPallet.isFull());
}

TEST_CASE("Get the emptiness of an empty pallet", "Pallet::isEmpty()") {
    Pallet testPallet = Pallet("testName", 100, 0);

    REQUIRE(testPallet.isEmpty());
}

TEST_CASE("Get the emptiness of a non-full (non-empty) pallet", "Pallet::isEmpty()") {
    Pallet testPallet = Pallet("testName", 100, 50);

    REQUIRE(!testPallet.isEmpty());
}

TEST_CASE("Get the emptiness of a full pallet", "Pallet::isEmpty()") {
    Pallet testPallet = Pallet("testName", 100, 100);

    REQUIRE(!testPallet.isEmpty());
}

//////////////////////////////////////////////
//      Pallet::reallocateEmptyPallet()     //
//////////////////////////////////////////////

TEST_CASE("Reallocate an empty pallet", "Pallet::reallocateEmptyPallet") {
    Pallet testPallet = Pallet("testName", 100, 0);
    
    REQUIRE(testPallet.reallocateEmptyPallet("otherTestName", 30));
    REQUIRE(testPallet.isEmpty());
    REQUIRE(testPallet.getItemName() == "otherTestName");
    REQUIRE(testPallet.getRemainingSpace() == 30);
}

TEST_CASE("Reallocate a non-empty pallet", "Pallet::reallocateEmptyPallet") {
    Pallet testPallet = Pallet("testName", 100, 50);
    
    REQUIRE(!testPallet.reallocateEmptyPallet("otherTestName", 30));
    REQUIRE(testPallet.getItemName() == "testName");
    REQUIRE(testPallet.getItemCount() == 50);
    REQUIRE(testPallet.getRemainingSpace() == 100 - 50);
}

///////////////////////////////
//      Pallet::TakeOne()     //
///////////////////////////////

TEST_CASE("Take Item off of a semi-full Pallet", "Pallet::takeOne()") {
    Pallet testPallet1 = Pallet("testName1", 100, 10);
    Pallet testPallet2 = Pallet("testName2", 100, 10);

    // Try it once on one item and twice on another 
    REQUIRE(testPallet1.takeOne());
    REQUIRE(testPallet2.takeOne());
    REQUIRE(testPallet2.takeOne());

    REQUIRE(testPallet1.getItemCount() == 9);
    REQUIRE(testPallet2.getItemCount() == 8);
}

TEST_CASE("Try taking an Item off of an empty Pallet", "Pallet::takeOne()") {
    Pallet testPallet1 = Pallet("testName1", 100, 0);
    Pallet testPallet2 = Pallet("testName2", 100, 0);

    // Try it once on one item and twice on another 
    REQUIRE(!testPallet1.takeOne());
    REQUIRE(!testPallet2.takeOne());
    REQUIRE(!testPallet2.takeOne());

    REQUIRE(testPallet1.getItemCount() == 0);
    REQUIRE(testPallet2.getItemCount() == 0);
}

///////////////////////////////
//      Pallet::PutOne()     //
///////////////////////////////

TEST_CASE("Try putting an item on a semi-full pallet", "Pallet::putOne()") {
    Pallet testPallet1 = Pallet("testName1", 100, 10);
    Pallet testPallet2 = Pallet("testName2", 100, 10);

    // Try it once on one item and twice on another 
    REQUIRE(testPallet1.putOne());
    REQUIRE(testPallet2.putOne());
    REQUIRE(testPallet2.putOne());

    REQUIRE(testPallet1.getItemCount() == 11);
    REQUIRE(testPallet2.getItemCount() == 12);
}

TEST_CASE("Try putting an item on a full pallet", "Pallet::putOne()") {
    Pallet testPallet1 = Pallet("testName1", 100, 100);
    Pallet testPallet2 = Pallet("testName2", 100, 100);

    // Try it once on one item and twice on another 
    REQUIRE(!testPallet1.putOne());
    REQUIRE(!testPallet2.putOne());
    REQUIRE(!testPallet2.putOne());

    REQUIRE(testPallet1.getItemCount() == 100);
    REQUIRE(testPallet2.getItemCount() == 100);
}