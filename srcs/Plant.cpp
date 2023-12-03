#include "Plant.h"

// Constructor for Plant class
Plant::Plant(){
    growthStage = 0; // Initialize growth stage to 0
    wateringLevel = 0; // Initialize watering level to 0
    isFertilised = false; // Initialize fertilization status to false
    isPlant = true; // Set the flag for being a plant
    isAnimal = false; // Set the flag for not being an animal
}

// Function to fertilize the plant
void Plant::fertilise(Inventory *Inventory){
    if(isFertilised == true){
        std::cout<< "Plant was already fertilised."<<std::endl;
        Inventory->fertiliserAdd(1); // Add fertiliser to inventory
        return;
    }
    isFertilised = true; // Mark the plant as fertilized
    std::cout << "Plant has been fertilised." << std::endl;
}

// Function to simulate the growth of the plant
bool Plant::grow(){
    if(wateringLevel == 5 && isFertilised){
        growthStage++; // Increment growth stage
        wateringLevel--; // Decrease watering level
        return true; // Return true to indicate successful growth
    }
    wateringLevel--; // Decrease watering level
    return false; // Return false if growth conditions are not met
}

// Function to check if the plant has died due to lack of water
bool Plant::checkDeath(){
    if(this->get_isWatered() == 0){
        std::cout << "Oh no! A plant has died." << std::endl;
        return true; // Return true to indicate the plant has died
    }
    else{
        return false; // Return false if the plant is still alive
    }
}

//returns the correct texture filename found in the texture filenames member of the class according to the growth stage
