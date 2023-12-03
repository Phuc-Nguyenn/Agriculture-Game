#ifndef PT_H
#define PT_H

#include <iostream>
#include "Farm.h"

#include <iostream>

class PlantTest {
private:
    Wheat wheat;
    Plant* plant;

    void testPlantType() {
        std::cout << "\ntesting Plant type retrieval \n";
        int PlantType = plant->get_type();
        if (PlantType == 1) {
            std::cout << "Pass: Correct Plant type for Wheat\n";
        } else {
            std::cout << "Fail: Incorrect Plant type for Wheat\n";
        }
    }

    void testIsAnimalAndPlant() {
        std::cout << "\ntesting Plant isPlant/isAnimal flags\n";
        bool isAnimal = plant->get_isAnimal();
        bool isPlant = plant->get_isPlant();
        if (isAnimal == false && isPlant == true) {
            std::cout << "Pass: Correct Plant isAnimal/isPlant bool values for Wheat\n";
        } else {
            std::cout << "Fail: Incorrect Plant types for Wheat\n";
        }
    }

    void testGrowFunction() {
        std::cout << "\ntesting Plant grow function\n";
        int initial = plant->get_growthStage();
        Inventory inventory;
        inventory.fertiliserAdd(5);
        plant->fertilise(&inventory);
        plant->water();
        plant->water();
        plant->water();
        plant->water();
        plant->water();
        plant->grow();
        int after = plant->get_growthStage();
        if (after == initial + 1) {
            std::cout << "Pass: Grow function is correct\n";
        } else {
            std::cout << "Fail: Grow function is incorrect\n";
        }
    }

    void testMaxWateringLevelFunction() {
        std::cout << "\ntesting get_maxWateringLevel function\n";
        int m = plant->get_maxWateringLevel();
        if (m >= 0) {
            std::cout << "Pass: maxwatering is a valid number\n";
        } else {
            std::cout << "Fail: invalid result from maxwatering function\n";
        }
    }

    void testWaterFunction() {
        std::cout << "\ntesting water function\n";
        int a = plant->get_isWatered();
        plant->water();
        int b = plant->get_isWatered();
        if (b == a + 1) {
            std::cout << "Pass: watering functions are correct\n";
        } else {
            std::cout << "Fail: watering functions are incorrect\n";
        }
    }

    void testCheckDeathFunction() {
        std::cout << "\ntesting checkdeath function\n";
        int ded = plant->checkDeath(); //wont die coz it is watered
        if (ded == 0) {
            std::cout << "Pass: checkdeath functions are correct\n";
        } else {
            std::cout << "Fail: checkdeath functions are incorrect\n";
        }
    }

public:
    PlantTest() {
        plant = &wheat;
    }

    void runAllTests() {
        testPlantType();
        testIsAnimalAndPlant();
        testGrowFunction();
        testMaxWateringLevelFunction();
        testWaterFunction();
        testCheckDeathFunction();
    }
};

#endif