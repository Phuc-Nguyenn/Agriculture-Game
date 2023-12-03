#ifndef AT_H
#define AT_H

#include <iostream>
#include "Farm.h"

class AnimalTest {
private:
    Chicken chicken;
    Animal* animal;

    void testAnimalType() {
        std::cout << "\ntesting Animal type retrieval \n";
        int AnimalType = animal->get_type();
        if (AnimalType == 3) {
            std::cout << "Pass: Correct Animal type for Chicken\n";
        } else {
            std::cout << "Fail: Incorrect Animal type for Chicken\n";
        }
    }

    void testIsAnimalAndPlant() {
        std::cout << "\ntesting Animal isPlant/isAnimal flags\n";
        bool isAnimal =animal->get_isAnimal();
        bool isPlant = animal->get_isPlant();
        if (isAnimal == true && isPlant == false) {
            std::cout << "Pass: Correct Animal isAnimal/isPlant bool values for Chicken\n";
        } else {
            std::cout << "Fail: Incorrect Animal types for Chicken\n";
        }
    }

    void testGrowFunction() {
        std::cout << "\ntesting Animal grow function\n";
        int initial = animal->get_growthStage();
        animal->grow();
        int after = animal->get_growthStage();
        if (after == initial + 1) {
            std::cout << "Pass: Grow function is correct\n";
        } else {
            std::cout << "Fail: Grow function is incorrect\n";
        }
    }

    void testMaxWateringLevelFunction() {
        std::cout << "\ntesting get_maxWateringLevel function\n";
        int m = animal->get_maxWateringLevel();
        if (m >= 0) {
            std::cout << "Pass: maxwatering is a valid number\n";
        } else {
            std::cout << "Fail: invalid result from maxwatering function\n";
        }
    }

    void testWaterFunction() {
        std::cout << "\ntesting water function\n";
        int a = animal->get_isWatered();
        animal->water();
        int b = animal->get_isWatered();
        if (b == a + 1) {
            std::cout << "Pass: watering functions are correct\n";
        } else {
            std::cout << "Fail: watering functions are incorrect\n";
        }
    }

    void testCheckDeathFunction() {
        std::cout << "\ntesting checkdeath function\n";
        int ded = animal->checkDeath(); //will die coz things are zero
        if (ded == 1) {
            std::cout << "Pass: checkdeath functions are correct\n";
        } else {
            std::cout << "Fail: checkdeath functions are incorrect\n";
        }
    }

    void testLifeSpanFunction() {
        std::cout << "\ntesting lifespan functions\n";
        animal->set_lifespan(5);
        int l = animal->get_lifespan(); //will die coz things are zero
        if (l== 5) {
            std::cout << "Pass: checkdeath functions are correct\n";
        } else {
            std::cout << "Fail: checkdeath functions are incorrect\n";
        }
    }

    void testHungryFunction() {
        std::cout << "\ntesting hungry functions\n";
        animal->set_hungryStatus(5);
        int l = animal->get_hungryStatus(); //will die coz things are zero
        if (l== 5) {
            std::cout << "Pass: checkdeath functions are correct\n";
        } else {
            std::cout << "Fail: checkdeath functions are incorrect\n";
        }
    }

public:
    AnimalTest() {
        animal = &chicken;
    }

    void runAllTests() {
        testAnimalType();
        testIsAnimalAndPlant();
        testGrowFunction();
        testMaxWateringLevelFunction();
        testWaterFunction();
        testCheckDeathFunction();
        testLifeSpanFunction();
        testHungryFunction();
    }
};

#endif