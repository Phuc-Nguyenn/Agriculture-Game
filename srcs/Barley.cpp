#include "Barley.h"
#include <iostream>

#define BARLEYWATER 4

// Function to get the type of the plant (inherited from Plant class)
int Barley::get_type()
{
    return 2; // Return the type for Barley
}

// Constructor for Barley class
Barley::Barley()
{
    growthStage = 0;      // Initialize growth stage to 0
    wateringLevel = 0;    // Initialize watering level to 0
    isFertilised = false; // Initialize isFertilised to false

    // Initialize texture filenames for different growth stages and watering levels
    textureFilenames.push_back("sprites/barleySprite/barley0.png");
    textureFilenames.push_back("sprites/barleySprite/barley1.png");
    textureFilenames.push_back("sprites/barleySprite/barley2.png");
    textureFilenames.push_back("sprites/barleySprite/barley3.png");
    textureFilenames.push_back("sprites/barleySprite/barley0watered.png");
    textureFilenames.push_back("sprites/barleySprite/barley1watered.png");
    textureFilenames.push_back("sprites/barleySprite/barley2watered.png");
    textureFilenames.push_back("sprites/barleySprite/barley3watered.png");

    std::cout << "Barley plant created." << std::endl; // Display creation message
}

// Function to simulate the growth of Barley
bool Barley::grow()
{
    /* Conditions for growth */
    if (growthStage < 3 && wateringLevel == BARLEYWATER && isFertilised)
    {
        growthStage++;
        wateringLevel--;
        std::cout << "A barley plant grew to the next stage!" << std::endl;
        return true; // Return true to indicate successful growth
    }
    else if (growthStage == 3)
        std::cout << "A barley plant is at max growth stage!" << std::endl;

    return false; // Return false if growth conditions are not met
}

// Function to simulate watering the Barley plant
void Barley::water()
{
    if (wateringLevel < BARLEYWATER)
    {
        wateringLevel++;
        std::cout << "Barley plant watered to hydration level: " << wateringLevel << std::endl;
        return;
    }
    else
    {
        std::cout << "Watering level =" << wateringLevel << " (Barley has been watered)" << std::endl;
        return;
    }
}