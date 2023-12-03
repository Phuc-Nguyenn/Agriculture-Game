#include "Animal.h"

// Constructor for Animal class
Animal::Animal()
{
    growthStage = 0;   // Initialize growth stage to 0
    type = "";         // Initialize type to empty string
    hungryStatus = 0;  // Initialize hungry status to 0
    wateringLevel = 0; // Initialize watering level to 0
    isAnimal = true;   // Set isAnimal to true
    isPlant = false;   // Set isPlant to false
}

// Function to feed the animal with grain
bool Animal::eatGrain(Inventory *Inventory)
{
    if (hungryStatus >= 3)
    {
        std::cout << "Animal is already full" << std::endl;
        // Display message to the user that the animal has not been fed
        Inventory->animalFeedAdd(1); // Add animal feed to inventory
        return false;                // Return false as the animal is already full
    }
    else
    {
        set_hungryStatus(get_hungryStatus() + 1); // Increment hungry status
        std::cout << "Animal fed, " << 3 - (get_hungryStatus()) << " feed from full" << std::endl;
        return true; // Return true after feeding the animal
    }
}

// Function to check if the animal has died
bool Animal::checkDeath()
{
    if (this->get_growthStage() >= this->get_lifespan() || this->get_hungryStatus() == 0 || this->get_isWatered() == 0)
    {
        isAnimal = false; // Set isAnimal to false as the animal has died
        std::cout << "An animal has died." << std::endl;
        return true; // Return true to indicate the animal has died
    }
    else
    {
        return false; // Return false if the animal is still alive
    }
}

// Destructor for Animal class
Animal::~Animal()
{
}

// Function to get the lifespan of the animal
int Animal::get_lifespan()
{
    return lifespan; // Return the lifespan of the animal
}

// Function to set the lifespan of the animal
void Animal::set_lifespan(int _lifespan)
{
    lifespan = _lifespan; // Set the lifespan of the animal
}

// Function to get the hungry status of the animal
int Animal::get_hungryStatus()
{
    return hungryStatus; // Return the hungry status of the animal
}

// Function to set the hungry status of the animal
void Animal::set_hungryStatus(int _hungryStatus)
{
    hungryStatus = _hungryStatus; // Set the hungry status of the animal
}