#include "Chicken.h"

// Constructor for Chicken class
Chicken::Chicken(){
    eggs = 0; // Initialize egg count to 0
    growthStage = 0; // Initialize growth stage to 0
    lifespan = 10; // Set the lifespan of the chicken
    for(int i = 0; i < 11; i++){
        textureFilenames.push_back("sprites/chickenSprite/chickenSprite1.png"); // Add chicken sprite filenames
    }
    isAnimal = true; // Set isAnimal to true
    isPlant = false; // Set isPlant to false
    hungryStatus = 0; // Initialize hungry status to 0
    wateringLevel = 0; // Initialize watering level to 0
}

// Function to get the type of the animal (inherited from Animal class)
int Chicken::get_type(){
    return 3; // Return the type for Chicken
}

// Function to simulate the chicken laying eggs
bool Chicken::layEgg(){
    if(eggs >= 3){
        return false; // Return false if maximum egg count reached
    }
    else{
        eggs++; // Increment egg count
        return true; // Return true after laying an egg
    }
}

// Function to get the number of eggs the chicken has
int Chicken::getEggs(){
    return eggs; // Return the egg count
}

// Function to set the number of eggs for the chicken
void Chicken::setEggs(int _eggs){
    eggs = _eggs; // Set the egg count
}

// Function to simulate the growth of the chicken
bool Chicken::grow(){
    // For animals, the grow function does not change sprite

    // Check conditions for laying eggs
    if(wateringLevel == 3 && hungryStatus == 3){
        layEgg();
        std::cout << "A chicken has laid an egg" << std::endl;
    }

    wateringLevel--; // Decrease watering level
    if(wateringLevel < 0) wateringLevel = 0;

    hungryStatus--; // Decrease hungry status
    if(hungryStatus < 0) hungryStatus = 0;

    growthStage++; // Increment growth stage
    std::cout << "A chicken has grown to age: " << growthStage << std::endl;
    return true; // Return true to indicate growth
}

// Function to simulate providing water to the chicken
void Chicken::water(){
    if(wateringLevel < 3){
        wateringLevel++; // Increment watering level
        std::cout << "Chicken watered to hydration level: " << wateringLevel << std::endl;
        return;
    } else {
        std::cout << "Watering level = " << wateringLevel << " (chicken has been watered)" << std::endl;
    }
}