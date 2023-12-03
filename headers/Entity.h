#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

/*The entity class represents anything that can be placed on a gametile, this includes all the plants
and all the animals. Other feature entities may be added later too.*/
class Entity
{
protected:
    // Growth stage of the entity
    int growthStage;

    // Level of watering for the entity
    int wateringLevel;

    // Flag indicating if the entity is an animal
    bool isAnimal;

    // Flag indicating if the entity is a plant
    bool isPlant;

public:
    // Filenames for the textures associated with the entity
    std::vector<std::string> textureFilenames;

    // Constructor to initialize an entity object
    Entity();

    // Getter for the flag indicating if the entity is a plant
    // Output: True if the entity is a plant, false otherwise
    bool get_isPlant();

    // Getter for the flag indicating if the entity is an animal
    // Output: True if the entity is an animal, false otherwise
    bool get_isAnimal();

    // Setter for the flag indicating if the entity is a plant
    // Input: _isPlant - Boolean value to set if the entity is a plant
    void set_isPlant(bool _isPlant);

    // Setter for the flag indicating if the entity is an animal
    // Input: _isAnimal - Boolean value to set if the entity is an animal
    void set_isAnimal(bool _isAnimal);

    // Getter for the growth stage of the entity
    // Output: The growth stage of the entity
    int get_growthStage();

    // Getter for the watering level of the entity
    // Output: The watering level of the entity
    int get_isWatered();

    // Setter for the growth stage of the entity
    // Input: _growthStage - The growth stage to set for the entity
    void set_growthStage(int _growthStage);

    // Setter for the watering level of the entity
    // Input: _wateringLevel - The watering level to set for the entity
    void set_isWatered(int _wateringLevel);

    // Virtual function to water the entity (to be implemented by derived classes)
    virtual void water() = 0;

    // Virtual function to check if the entity has died (to be implemented by derived classes)
    // Output: True if the entity has died, false otherwise
    virtual bool checkDeath() = 0;

    // Virtual function to get the type of the entity (to be implemented by derived classes)
    // Output: The type of the entity
    virtual int get_type() = 0;

    // Virtual function to simulate growth of the entity (to be implemented by derived classes)
    // Output: True if the entity has grown, false otherwise
    virtual bool grow() = 0;

    // Virtual function to get the maximum watered level of entity
    // Output: returns the max watering level of the entity wheat:5 barley:4 ...
    virtual int get_maxWateringLevel() = 0;

    // Virtual function to fertilize the entity (to be implemented by derived classes)
    virtual void fertilise(Inventory *Inventory);

    virtual bool eatGrain(Inventory *inventory); // implemented in animal classes

    // Virtual destructor for the entity class
    virtual ~Entity(){};

    // Function to get the correct filename for the entity's texture
    // Output: The correct filename for the entity's texture
    std::string getCorrectFilename();
    
    //virtual getters and setters for the animal subclasses
    virtual int getEggs();
    virtual void setEggs(int _Eggs);
    virtual bool getWool();
    virtual void setWool(bool _Wool);
};

#endif