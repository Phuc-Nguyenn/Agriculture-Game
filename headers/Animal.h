#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include "Entity.h"
#include "Inventory.h"
// #include "Chicken.h"
// #include "Sheep.h"

class Animal : public Entity
{
    protected:
        // Type of the animal
        std::string type;

        // Lifespan of the animal
        int lifespan;

        // Hungry status is a measure of how full an animal is, decreases daily
        int hungryStatus;

        // Textures associated with the animal
        std::vector<std::string> textures;

public:
        // Constructor to initialize an Animal object
        Animal();
        // Check if the animal has died
        // Output: True if the animal has died, false otherwise
        bool checkDeath();

        // Feed the animal with grain, incrementing hungry status
        // Input: Animal - Pointer to the animal to feed
        // Output: True if the animal is successfully fed, false otherwise
        bool eatGrain(Inventory *Inventory);

        // Getter for the age of the animal
        // Output: The age of the animal
        int get_age();

        // Setter for the age of the animal
        // Input: _age - The age to set for the animal
        void set_age(int _age);

        // Virtual function to get the type of the animal (to be implemented by derived classes)
        // Output: The type of the animal (e.g., specific animal type)
        virtual int get_type() = 0;

        // Getter for the lifespan of the animal
        // Output: The lifespan of the animal
        int get_lifespan();

        // Setter for the lifespan of the animal
        // Input: _lifespan - The lifespan to set for the animal
        void set_lifespan(int _lifespan);

        // Getter for the hungry status of the animal
        // Output: The hungry status of the animal
        int get_hungryStatus();

        // Setter for the hungry status of the animal
        // Input: _hungryStatus - The hungry status to set for the animal
        void set_hungryStatus(int _hungryStatus);

        bool grow() = 0;
        // Destructor for the Animal class
        ~Animal();
};



#endif