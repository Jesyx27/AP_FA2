#include "include/catch.hpp"
#include "../src/include/Shelf.hpp"

#pragma region pallets

Shelf createMockShelf(unsigned int addAmount = 4, unsigned int itemCapcity = 12, unsigned int itemCount = 6) {
    Shelf testShelf = Shelf();

    for (unsigned int i = 0; i < addAmount; i++) {
        testShelf.pallets[i] = Pallet(std::to_string(i), itemCapcity, itemCount);
    }

    return testShelf;
}

TEST_CASE("Test wether semi-full pallets works", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(4, 10, 5);

    REQUIRE(!testShelf.isFull());
    REQUIRE(!testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0].getItemCount() == 5);
    REQUIRE(testShelf.pallets[0].getRemainingSpace() == 5);
    REQUIRE(testShelf.pallets[0].getItemName() == "0");
    
    REQUIRE(testShelf.pallets[1].getItemCount() == 5);
    REQUIRE(testShelf.pallets[1].getRemainingSpace() == 5);
    REQUIRE(testShelf.pallets[1].getItemName() == "1");
    
    REQUIRE(testShelf.pallets[2].getItemCount() == 5);
    REQUIRE(testShelf.pallets[2].getRemainingSpace() == 5);
    REQUIRE(testShelf.pallets[2].getItemName() == "2");

    REQUIRE(testShelf.pallets[3].getItemCount() == 5);
    REQUIRE(testShelf.pallets[3].getRemainingSpace() == 5);
    REQUIRE(testShelf.pallets[3].getItemName() == "3");
}

TEST_CASE("Test wether full pallet works", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(4, 10, 10);

    REQUIRE(testShelf.isFull());
    REQUIRE(!testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0].getItemCount() == 10);
    REQUIRE(testShelf.pallets[0].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[0].getItemName() == "0");
    
    REQUIRE(testShelf.pallets[1].getItemCount() == 10);
    REQUIRE(testShelf.pallets[1].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[1].getItemName() == "1");
    
    REQUIRE(testShelf.pallets[2].getItemCount() == 10);
    REQUIRE(testShelf.pallets[2].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[2].getItemName() == "2");

    REQUIRE(testShelf.pallets[3].getItemCount() == 10);
    REQUIRE(testShelf.pallets[3].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[3].getItemName() == "3");
}

TEST_CASE("Test wether empty pallet works (add 0 pallets to pallets)", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(0, 10, 0);

    // isFull() because max items of standard cosntructor is 0, thus the pallet is full
    REQUIRE(testShelf.isFull());
    REQUIRE(testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0].getItemCount() == 0);
    REQUIRE(testShelf.pallets[0].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[0].getItemName() == "");
    
    REQUIRE(testShelf.pallets[1].getItemCount() == 0);
    REQUIRE(testShelf.pallets[1].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[1].getItemName() == "");
    
    REQUIRE(testShelf.pallets[2].getItemCount() == 0);
    REQUIRE(testShelf.pallets[2].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[2].getItemName() == "");

    REQUIRE(testShelf.pallets[3].getItemCount() == 0);
    REQUIRE(testShelf.pallets[3].getRemainingSpace() == 0);
    REQUIRE(testShelf.pallets[3].getItemName() == "");
}

TEST_CASE("Test wether empty pallet works (add 4 empty pallets to pallets)", "Shelf::pallets") {
    Shelf testShelf = createMockShelf(4, 10, 0);

    REQUIRE(!testShelf.isFull());
    REQUIRE(testShelf.isEmpty());

    REQUIRE(testShelf.pallets[0].getItemCount() == 0);
    REQUIRE(testShelf.pallets[0].getRemainingSpace() == 10);
    REQUIRE(testShelf.pallets[0].getItemName() == "0");
    
    REQUIRE(testShelf.pallets[1].getItemCount() == 0);
    REQUIRE(testShelf.pallets[1].getRemainingSpace() == 10);
    REQUIRE(testShelf.pallets[1].getItemName() == "1");
    
    REQUIRE(testShelf.pallets[2].getItemCount() == 0);
    REQUIRE(testShelf.pallets[2].getRemainingSpace() == 10);
    REQUIRE(testShelf.pallets[2].getItemName() == "2");

    REQUIRE(testShelf.pallets[3].getItemCount() == 0);
    REQUIRE(testShelf.pallets[3].getRemainingSpace() == 10);
    REQUIRE(testShelf.pallets[3].getItemName() == "3");
}

#pragma endregion pallets

#pragma region swapPallet

TEST_CASE("Normal Behavior Swap Pallets", "Shelf::swapPallet()") {
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

    REQUIRE(testShelf.pallets[0] == compareShelf.pallets[3]);
    REQUIRE(testShelf.pallets[1] == compareShelf.pallets[2]);
}

TEST_CASE("Swap pallets with invalid indices", "Shelf::swapPallet()") {
    Shelf testShelf = Shelf();
    Shelf compareShelf = Shelf();   

    REQUIRE(!testShelf.SwapPallet(0, 4));
    REQUIRE(!testShelf.SwapPallet(-1, 3));

    REQUIRE(testShelf.pallets[0] == compareShelf.pallets[0]);
    REQUIRE(testShelf.pallets[1] == compareShelf.pallets[1]);
    REQUIRE(testShelf.pallets[2] == compareShelf.pallets[2]);
    REQUIRE(testShelf.pallets[3] == compareShelf.pallets[3]);
}
