#include "Sheep.h"

// Constructor for Sheep class
Sheep::Sheep(){
    wool = false; // Initialize wool production to false
    growthStage = 0; // Initialize growth stage to 0
    lifespan = 20; // Set the lifespan of the sheep
    textureFilenames.push_back("./sprites/sheepSprite/sheepShornSprite.png"); // Load shorn sheep texture
    textureFilenames.push_back("./sprites/sheepSprite/sheepSprite.png"); // Load full wool sheep texture
    isAnimal = true; // Set the flag for being an animal
    hungryStatus = 0; // Initialize hungry status to 0
    wateringLevel = 0; // Initialize watering level to 0
}

// Function to simulate wool production by the sheep
void Sheep::produceWool(){
    wool = true; // Set wool production to true
}

// Function to check if the sheep has wool
bool Sheep::getWool(){
    return wool;
}

// Function to set the wool production of the sheep
void Sheep::setWool(bool _wool){
    wool = _wool;
}

// Function to get the type of the entity (sheep)
int Sheep::get_type(){
    return 4;
}

// Function to simulate the growth of the sheep
bool Sheep::grow(){
    if(wateringLevel == 3 && hungryStatus == 3){
        produceWool(); // Simulate wool production if well-watered and fed
        std::cout<<"A sheep is ready for shearing"<<std::endl;
    }
    wateringLevel--;
    if(wateringLevel < 0) wateringLevel = 0;
    hungryStatus--;
    if(hungryStatus < 0) hungryStatus = 0;
    growthStage++;
    std::cout<<"A sheep has grown to age:"<<growthStage<<std::endl;
    return true;
}

// Function to water the sheep
void Sheep::water(){
    if(wateringLevel < 3){
        wateringLevel++;
        std::cout << "Sheep watered to hydration level: " << wateringLevel << std::endl;
        return;
    } else {
        std::cout << "Watering level ="<< wateringLevel <<" (sheep has been watered)" << std::endl;
    }
}