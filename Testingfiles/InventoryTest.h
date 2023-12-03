#ifndef INVTEST_H
#define INVTEST_H

#include "Inventory.h"
#include <iostream>

class InventoryTest
{
private:
    Inventory inventory;

    void testMoneyAddTake()
    {
        int initialMoney = inventory.getMoney();

        // Test moneyAdd and moneyTake
        int amountToAdd = 100;
        inventory.moneyAdd(amountToAdd);
        if (inventory.getMoney() == initialMoney + amountToAdd)
        {
            std::cout << "Pass: Money add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Money add function is incorrect\n";
        }

        // Test moneyTake
        int amountToTake = 50;
        if (inventory.moneyTake(amountToTake) && inventory.getMoney() == (initialMoney + amountToAdd - amountToTake))
        {
            std::cout << "Pass: Money take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Money take function is incorrect\n";
        }
    }

    void testFertiliserAddTake()
    {
        int initialFertiliser = inventory.getFertiliser();

        // Test fertiliserAdd and fertiliserTake
        int amountToAdd = 20;
        inventory.fertiliserAdd(amountToAdd);
        if (inventory.getFertiliser() == initialFertiliser + amountToAdd)
        {
            std::cout << "Pass: Fertiliser add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Fertiliser add function is incorrect\n";
        }

        // Test fertiliserTake
        int amountToTake = 10;
        if (inventory.fertiliserTake(amountToTake) && inventory.getFertiliser() == (initialFertiliser + amountToAdd - amountToTake))
        {
            std::cout << "Pass: Fertiliser take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Fertiliser take function is incorrect\n";
        }
    }

    void testGrainAddTake()
    {
        int initialWheatGrain = inventory.getWheatGrain();
        int initialBarleyGrain = inventory.getBarleyGrain();

        // Test grain add and take for wheat
        int amountToAddWheat = 30;
        inventory.wheatGrainAdd(amountToAddWheat);
        if (inventory.getWheatGrain() == initialWheatGrain + amountToAddWheat)
        {
            std::cout << "Pass: Wheat grain add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Wheat grain add function is incorrect\n";
        }

        // Test grain take for wheat
        int amountToTakeWheat = 10;
        if (inventory.wheatGrainTake(amountToTakeWheat) && inventory.getWheatGrain() == (initialWheatGrain + amountToAddWheat - amountToTakeWheat))
        {
            std::cout << "Pass: Wheat grain take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Wheat grain take function is incorrect\n";
        }

        // Test grain add and take for barley
        int amountToAddBarley = 15;
        inventory.barleyGrainAdd(amountToAddBarley);
        if (inventory.getBarleyGrain() == initialBarleyGrain + amountToAddBarley)
        {
            std::cout << "Pass: Barley grain add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Barley grain add function is incorrect\n";
        }

        // Test grain take for barley
        int amountToTakeBarley = 5;
        if (inventory.barleyGrainTake(amountToTakeBarley) && inventory.getBarleyGrain() == (initialBarleyGrain + amountToAddBarley - amountToTakeBarley))
        {
            std::cout << "Pass: Barley grain take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Barley grain take function is incorrect\n";
        }
    }

    void testSeedAddTake()
    {
        int initialWheatSeed = inventory.getWheatSeed();
        int initialBarleySeed = inventory.getBarleySeed();

        // Test seed add and take for wheat
        int amountToAddWheat = 25;
        inventory.wheatSeedAdd(amountToAddWheat);
        if (inventory.getWheatSeed() == initialWheatSeed + amountToAddWheat)
        {
            std::cout << "Pass: Wheat seed add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Wheat seed add function is incorrect\n";
        }

        // Test seed take for wheat
        int amountToTakeWheat = 10;
        if (inventory.wheatSeedTake(amountToTakeWheat) && inventory.getWheatSeed() == (initialWheatSeed + amountToAddWheat - amountToTakeWheat))
        {
            std::cout << "Pass: Wheat seed take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Wheat seed take function is incorrect\n";
        }

        // Test seed add and take for barley
        int amountToAddBarley = 20;
        inventory.barleySeedAdd(amountToAddBarley);
        if (inventory.getBarleySeed() == initialBarleySeed + amountToAddBarley)
        {
            std::cout << "Pass: Barley seed add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Barley seed add function is incorrect\n";
        }

        // Test seed take for barley
        int amountToTakeBarley = 8;
        if (inventory.barleySeedTake(amountToTakeBarley) && inventory.getBarleySeed() == (initialBarleySeed + amountToAddBarley - amountToTakeBarley))
        {
            std::cout << "Pass: Barley seed take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Barley seed take function is incorrect\n";
        }
    }

    void testWoolAddTake()
    {
        int initialWool = inventory.getWool();

        // Test wool add and take
        int amountToAdd = 5;
        inventory.woolAdd(amountToAdd);
        if (inventory.getWool() == initialWool + amountToAdd)
        {
            std::cout << "Pass: Wool add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Wool add function is incorrect\n";
        }

        // Test wool take
        int amountToTake = 2;
        if (inventory.woolTake(amountToTake) && inventory.getWool() == (initialWool + amountToAdd - amountToTake))
        {
            std::cout << "Pass: Wool take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Wool take function is incorrect\n";
        }
    }

    void testEggsAddTake()
    {
        int initialEggs = inventory.getEggs();

        // Test eggs add and take
        int amountToAdd = 10;
        inventory.eggsAdd(amountToAdd);
        if (inventory.getEggs() == initialEggs + amountToAdd)
        {
            std::cout << "Pass: Eggs add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Eggs add function is incorrect\n";
        }

        // Test eggs take
        int amountToTake = 3;
        if (inventory.eggsTake(amountToTake) && inventory.getEggs() == (initialEggs + amountToAdd - amountToTake))
        {
            std::cout << "Pass: Eggs take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Eggs take function is incorrect\n";
        }
    }

    void testAnimalAddTake()
    {
        int initialChickens = inventory.getChickens();
        int initialSheep = inventory.getSheep();

        // Test animal add and take for chickens
        int amountToAddChickens = 5;
        inventory.ChickenAdd(amountToAddChickens);
        if (inventory.getChickens() == initialChickens + amountToAddChickens)
        {
            std::cout << "Pass: Chicken add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Chicken add function is incorrect\n";
        }

        // Test animal take for chickens
        int amountToTakeChickens = 2;
        if (inventory.ChickenTake(amountToTakeChickens) && inventory.getChickens() == (initialChickens + amountToAddChickens - amountToTakeChickens))
        {
            std::cout << "Pass: Chicken take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Chicken take function is incorrect\n";
        }

        // Test animal add and take for sheep
        int amountToAddSheep = 3;
        inventory.SheepAdd(amountToAddSheep);
        if (inventory.getSheep() == initialSheep + amountToAddSheep)
        {
            std::cout << "Pass: Sheep add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Sheep add function is incorrect\n";
        }

        // Test animal take for sheep
        int amountToTakeSheep = 1;
        if (inventory.SheepTake(amountToTakeSheep) && inventory.getSheep() == (initialSheep + amountToAddSheep - amountToTakeSheep))
        {
            std::cout << "Pass: Sheep take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Sheep take function is incorrect\n";
        }
    }

    void testMeatAddTake()
    {
        int initialMeat = inventory.getMeat();

        // Test meat add and take
        int amountToAdd = 8;
        inventory.meatAdd(amountToAdd);
        if (inventory.getMeat() == initialMeat + amountToAdd)
        {
            std::cout << "Pass: Meat add function is correct\n";
        }
        else
        {
            std::cout << "Fail: Meat add function is incorrect\n";
        }

        // Test meat take
        int amountToTake = 3;
        if (inventory.meatTake(amountToTake) && inventory.getMeat() == (initialMeat + amountToAdd - amountToTake))
        {
            std::cout << "Pass: Meat take function is correct\n";
        }
        else
        {
            std::cout << "Fail: Meat take function is incorrect\n";
        }
    }

public:
    void runAllTests()
    {
        // Run all individual test functions
        testMoneyAddTake();
        testFertiliserAddTake();
        testGrainAddTake();
        testSeedAddTake();
        testWoolAddTake();
        testEggsAddTake();
        testAnimalAddTake();
        testMeatAddTake();
    }
};

#endif