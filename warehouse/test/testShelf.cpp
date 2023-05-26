#include "include/catch.hpp"
#include "../src/include/Shelf.hpp"

/////////////////////////////
//      Shelf::pallets     //
/////////////////////////////

/// @brief 
/// Creates a mock shelf for testing Shelf::pallets functionality
/// @param addAmount Amount of added pallets in the Array
/// @param itemCapcity The item capacity of the pallets
/// @param itemCount The amount of items in each pallet
/// @return A mock shelf
Shelf createMockShelf(unsigned int addAmount = 4, unsigned int itemCapcity = 12, unsigned int itemCount = 6) {
    Shelf testShelf = Shelf();

    for (unsigned int i = 0; i < addAmount; i++) {
        testShelf.pallets[i] = Pallet(std::to_string(i), itemCapcity, itemCount);
    }

    return testShelf;
}

TEST_CASE("Test wether semi-full pallets works", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(4, 10, 5);

    // A semi-full pallet is neither full nor empty
    REQUIRE(!testShelf.isFull());
    REQUIRE(!testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0] == Pallet("0", 10, 5));
    REQUIRE(testShelf.pallets[1] == Pallet("1", 10, 5));
    REQUIRE(testShelf.pallets[2] == Pallet("2", 10, 5));
    REQUIRE(testShelf.pallets[3] == Pallet("3", 10, 5));
}

TEST_CASE("Test wether full pallet works", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(4, 10, 10);

    // The pallet is full because 10 out of 10 items are filled
    REQUIRE(testShelf.isFull());
    REQUIRE(!testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0] == Pallet("0", 10, 10));
    REQUIRE(testShelf.pallets[0].isFull());
    REQUIRE(testShelf.pallets[1] == Pallet("1", 10, 10));
    REQUIRE(testShelf.pallets[1].isFull());
    REQUIRE(testShelf.pallets[2] == Pallet("2", 10, 10));
    REQUIRE(testShelf.pallets[2].isFull());
    REQUIRE(testShelf.pallets[3] == Pallet("3", 10, 10));
    REQUIRE(testShelf.pallets[3].isFull());
}

TEST_CASE("Test wether empty pallet works (add 0 pallets to pallets)", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(0, 10, 0);

    // isFull() because max items of standard cosntructor is 0, thus the pallet is full (0/0; remainingItems == 0)
    REQUIRE(testShelf.isFull());
    REQUIRE(testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0] == Pallet("", 0, 0));
    REQUIRE(testShelf.pallets[1] == Pallet("", 0, 0));
    REQUIRE(testShelf.pallets[2] == Pallet("", 0, 0));
    REQUIRE(testShelf.pallets[3] == Pallet("", 0, 0));
}

TEST_CASE("Test wether empty pallet works (add 4 empty pallets to pallets)", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(4, 10, 0);

    // Should be empty, and not full because the capacity > 0
    REQUIRE(!testShelf.isFull());
    REQUIRE(testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0] == Pallet("0", 10, 0));
    REQUIRE(testShelf.pallets[0].isEmpty());
    REQUIRE(testShelf.pallets[1] == Pallet("1", 10, 0));
    REQUIRE(testShelf.pallets[1].isEmpty());
    REQUIRE(testShelf.pallets[2] == Pallet("2", 10, 0));
    REQUIRE(testShelf.pallets[2].isEmpty());
    REQUIRE(testShelf.pallets[3] == Pallet("3", 10, 0));
    REQUIRE(testShelf.pallets[3].isEmpty());
}

///////////////////////////////////
//      Shelf::swapPallets()     //
///////////////////////////////////

TEST_CASE("Normal Behavior Swap Pallets", "Shelf::swapPallets()") {
    Shelf testShelf = createMockShelf(4, 10, 5);
    Shelf compareShelf = createMockShelf(4, 10, 5);

    testShelf.SwapPallet(0, 3);
    testShelf.SwapPallet(1, 2);

    REQUIRE(testShelf.pallets[0] == compareShelf.pallets[3]);
    REQUIRE(testShelf.pallets[1] == compareShelf.pallets[2]);
}

TEST_CASE("Swap empty pallets", "Shelf::swapPallet()") {
    Shelf testShelf = Shelf();
    Shelf compareShelf = Shelf();

    testShelf.SwapPallet(0, 3);
    testShelf.SwapPallet(1, 2);

    // Swap shouldnt change anything as empty pallets are concidered the same object (same name, items and capacity)
    REQUIRE(testShelf.pallets == compareShelf.pallets);
}

TEST_CASE("Swap pallets with invalid indices", "Shelf::swapPallet()") {
    Shelf testShelf = Shelf();
    Shelf compareShelf = Shelf();   
    
    // Shouldn't work as pallets only have indexes 0, 1, 2 & 3, size = 4
    REQUIRE(!testShelf.SwapPallet(0, 4));
    REQUIRE(!testShelf.SwapPallet(-1, 3));

    REQUIRE(testShelf.pallets == compareShelf.pallets);
}