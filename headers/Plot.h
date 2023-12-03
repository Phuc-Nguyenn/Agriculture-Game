#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "GameTile.h"
#include "Plant.h"
#include "Wheat.h"
#include "Sheep.h"
#include "Chicken.h"
#include "Barley.h"
#include "Animal.h"
#include "Inventory.h"
#include "Entity.h"

#ifndef PLOT_H
#define PLOT_H


/*the plot is a gametile that can hold an entity eg. plants and animals, 
it has specific functions that are able to access and alter the entity.*/
class Plot : public GameTile
{
  protected:
    // Pointer to the entity (plant or animal) placed on the plot
    Entity* entity;

  public:
    // Constructor to initialize a Plot object
    // Input: texture_filename - Filename of the texture for the plot
    //        pos_x - X-coordinate of the position
    //        pos_y - Y-coordinate of the position
    Plot(std::string texture_filename, float pos_x, float pos_y);

    // Place a plant on the plot
    // Input: _entity - Pointer to the plant entity
    // Output: True if the plant is successfully placed, false otherwise
    bool placeEntity(Entity *_entity);
    // Place an entity on the plot
    // Input: _entity - Pointer to the animal entity
    // Output: True if the animal is successfully placed, false otherwise
    // bool placeAnimal(Entity *_entity);

    // Clear the plot (remove the entity from the plot)
    // Output: True if the plot is successfully cleared, false otherwise
    bool clear();

    // Harvest the entity from the plot and add it to the inventory
    // Input: inventory - Pointer to the player's inventory
    // Output: True if the entity is successfully harvested and added to the inventory, false otherwise
    bool harvest(Inventory *inventory);

    // Check if the plot is empty (no entity placed)
    // Output: True if the plot is empty, false otherwise
    bool isEmpty();

    // Check if the entity on the plot has died
    // Output: True if the entity has died, false otherwise
    bool checkDeath();

    // Water the entity on the plot
    void water();

    // Fertilize the entity on the plot
    void fertilise(Inventory *Inventory);

    //feeds the animal on the plot
    void feed(Inventory *Inventory);

    // Getter for the flag indicating if the plot contains a plant
    // Output: True if the plot contains a plant, false otherwise
    bool get_isPlant();

    // Getter for the flag indicating if the plot contains an animal
    // Output: True if the plot contains an animal, false otherwise
    bool get_isAnimal();

    // Update the sprite of the plot based on the entity type
    // Output: True if the sprite is successfully updated, false otherwise
    bool updateSprite();

    // Simulate growth of the entity on the plot
    // Output: True if the entity has grown, false otherwise
    bool growEntity();

    // Reset the plot (clear entity and reset sprite)
    void plotReset();
    //function for slaughtering animals
    void Slaughter(Inventory *Inventory);
};

#endif