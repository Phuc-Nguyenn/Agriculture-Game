#include "Entity.h"

// Constructor for Entity class
Entity::Entity(){
    // Default constructor, no specific initialization needed for Entity
}

// Function to get the growth stage of the entity
int Entity::get_growthStage(){
    return growthStage; // Return the growth stage
}

// Function to get the watering level of the entity
int Entity::get_isWatered(){
    return wateringLevel; // Return the watering level
}

// Function to set the growth stage of the entity
void Entity::set_growthStage(int _growthStage){
    growthStage = _growthStage; // Set the growth stage
}

// Function to set the watering level of the entity
void Entity::set_isWatered(int _wateringLevel){
    wateringLevel = _wateringLevel; // Set the watering level
}

// Function to get the number of eggs (not applicable for all entities)
int Entity::getEggs(){
    std::cout<<"Cannot get eggs, entity is not a chicken"<<std::endl;
    return 0; // Return 0 as it's not a chicken
}

// Function to get the presence of wool (not applicable for all entities)
bool Entity::getWool(){
    std::cout<<"Cannot get wool, entity is not a sheep"<<std::endl;
    return 0; // Return false as it's not a sheep
}

// Function to set the number of eggs (not applicable for all entities)
void Entity::setEggs(int _Eggs){
    _Eggs = isPlant; // Incorrect assignment, likely meant to be isPlant = _Eggs;
    isPlant = _Eggs;
    std::cout<<"Cannot get eggs, entity is not a chicken"<<std::endl;
}

// Function to set the presence of wool (not applicable for all entities)
void Entity::setWool(bool _Wool){
    _Wool = isPlant; // Incorrect assignment, likely meant to be isPlant = _Wool;
    isPlant = _Wool;
    std::cout<<"Cannot set wool, entity is not a sheep"<<std::endl;
}

// Function to set whether the entity is a plant or not
void Entity::set_isPlant(bool _isPlant){
    isPlant = _isPlant; // Set the flag for being a plant
}

// Function to set whether the entity is an animal or not
void Entity::set_isAnimal(bool _isAnimal){
    isAnimal = _isAnimal; // Set the flag for being an animal
}

// Function to get whether the entity is a plant or not
bool Entity::get_isPlant(){
    return isPlant; // Return whether the entity is a plant
}

// Function to get whether the entity is an animal or not
bool Entity::get_isAnimal(){
    return isAnimal; // Return whether the entity is an animal
}

// Function to simulate eating grain (not applicable for all entities)
bool Entity::eatGrain(Inventory *){
    return false; // Return false as eating grain is not applicable
}

// Function to get the correct filename for the entity's texture
std::string Entity::getCorrectFilename()
{
    if(this->get_type() == 4) { // if it's a sheep, a special case for sheep
        if(this->getWool() == true) // has wool
            return(textureFilenames[1]); // Return wool texture filename
        else
            return(textureFilenames[0]); // Return regular texture filename
    }
    return(textureFilenames[growthStage]); // Return texture based on growth stage
}

// Function to simulate fertilizing (not applicable for all entities)
void Entity::fertilise(Inventory *Inventory){
    Inventory->eggsAdd(0); // Add eggs (incorrectly named function, should be wool or plant-related)
}