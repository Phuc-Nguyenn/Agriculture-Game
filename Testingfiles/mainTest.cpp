#include <iostream>
#include "Farm.h"
#include "EntityTest.h"
#include "AnimalTest.h"
#include "PlantTest.h"
#include "InventoryTest.h"
#include "GameTileTest.h"

int main() {
    // Run the tests for Entity class functions
    std::cout << "Running Entity Class Tests...\n";
    EntityTest entityTest;
    entityTest.runAllTests();
    
    // Run the tests for Animal class functions -> with child class Chicken
    std::cout << "\n\nRunning Animal Class Tests...\n";
    AnimalTest animalTest;
    animalTest.runAllTests();

    // Run the tests for Plant class functions -> with child class Wheat
    std::cout << "\n\nRunning Plant Class Tests...\n";
    PlantTest plantTest;
    plantTest.runAllTests();

    // Run the tests for Inventory class functions
    std::cout << "\n\nRunning Inventory Class Tests...\n";
    InventoryTest invTest;
    invTest.runAllTests();

    // Run the tests for GameTile class functions
    std::cout << "\n\nRunning GameTile Class Tests...\n";
    GameTileTest gametileTest;
    gametileTest.runAllTests();

    return 0;
}