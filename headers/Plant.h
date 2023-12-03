
#ifndef PLANT_H
#define PLANT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Entity.h"
#include "Inventory.h"

class Plant : public Entity
{
protected:
    // Flag indicating if the plant has been fertilized
    bool isFertilised;

public:
    // Constructor to initialize a Plant object
    Plant();

    // Function to fertilize the plant
    void fertilise(Inventory *Inventory);

    // Function to check if the plant has died
    // Output: True if the plant has died, false otherwise
    bool checkDeath();

    // Function to get the correct filename for the plant's texture
    // Output: The correct filename for the plant's texture
    std::string getCorrectFilename();

    // Virtual function to get the type of the plant (to be implemented by derived classes)
    // Output: The type of the plant (e.g., 1 for Wheat, 2 for Barley, etc.)
    virtual int get_type() = 0;

    // Virtual function to simulate growth of the plant (to be implemented by derived classes)
    // Output: True if the plant has grown, false otherwise
    virtual bool grow() = 0;
};

#endif