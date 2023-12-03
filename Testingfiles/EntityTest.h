#ifndef ET_H
#define ET_H

#include <iostream>
#include "Farm.h"

#include <iostream>

class EntityTest {
private:
    Chicken chicken;
    Entity* entity;

    void testEntityType() {
        std::cout << "\ntesting entity type retrieval \n";
        int entityType = entity->get_type();
        if (entityType == 3) {
            std::cout << "Pass: Correct entity type for Chicken\n";
        } else {
            std::cout << "Fail: Incorrect entity type for Chicken\n";
        }
    }

    void testIsAnimalAndPlant() {
        std::cout << "\ntesting entity isPlant/isAnimal flags\n";
        bool isAnimal = entity->get_isAnimal();
        bool isPlant = entity->get_isPlant();
        if (isAnimal == true && isPlant == false) {
            std::cout << "Pass: Correct entity isAnimal/isPlant bool values for Chicken\n";
        } else {
            std::cout << "Fail: Incorrect entity types for Chicken\n";
        }
    }

    void testGrowFunction() {
        std::cout << "\ntesting entity grow function\n";
        int initial = entity->get_growthStage();
        entity->grow();
        int after = entity->get_growthStage();
        if (after == initial + 1) {
            std::cout << "Pass: Grow function is correct\n";
        } else {
            std::cout << "Fail: Grow function is incorrect\n";
        }
    }

    void testMaxWateringLevelFunction() {
        std::cout << "\ntesting get_maxWateringLevel function\n";
        int m = entity->get_maxWateringLevel();
        if (m >= 0) {
            std::cout << "Pass: maxwatering is a valid number\n";
        } else {
            std::cout << "Fail: invalid result from maxwatering function\n";
        }
    }

    void testWaterFunction() {
        std::cout << "\ntesting water function\n";
        int a = entity->get_isWatered();
        entity->water();
        int b = entity->get_isWatered();
        if (b == a + 1) {
            std::cout << "Pass: watering functions are correct\n";
        } else {
            std::cout << "Fail: watering functions are incorrect\n";
        }
    }

    void testCheckDeathFunction() {
        std::cout << "\ntesting checkdeath function\n";
        int ded = entity->checkDeath(); //will die coz things are zero
        if (ded == 1) {
            std::cout << "Pass: checkdeath functions are correct\n";
        } else {
            std::cout << "Fail: checkdeath functions are incorrect\n";
        }
    }

public:
    EntityTest() {
        entity = &chicken;
    }

    void runAllTests() {
        testEntityType();
        testIsAnimalAndPlant();
        testGrowFunction();
        testMaxWateringLevelFunction();
        testWaterFunction();
        testCheckDeathFunction();
    }
};

#endif