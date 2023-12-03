#ifndef FARM_H
#define FARM_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "GameTile.h"
#include "Inventory.h"
#include "Plot.h"
#include "Shop.h"

/*The Farm class represents the virtual farm. 
It serves as a central entity that encapsulates various functionalities related to the farm
-> inventory
-> gametiles
-> landplots
*/
class Farm
{ 
  private:
    //* Helper function to set the background tiles for the farm.
    void setBackTiles();

    //* Helper function to set the initial plots on the farm.
    void setPlots();

    //* Number of grid cells along one side of the farm (assuming a square farm).
    int gridLength;

    //* Counter to keep track of days.
    int dayCounter;

    //textures and sprites for the help menu
    sf::Texture Help_texture;
    sf::Sprite Help_sprite;
    //coordinates of the help menu
    int help_x;
    int help_y;

  public:
    //* Pointer to the player's inventory in the game.
    Inventory *inventory;

    //* Pointer to the in-game shop for purchasing items.
    Shop *shop;

    //* 2D vector to store the grid tiles for the farm.
    std::vector<std::vector<GameTile*> > tiles;

    //* 2D vector to store the plots on the farm.
    std::vector<std::vector<Plot*> > plots;

    //* Constructor to initialize a farm object.
    Farm();

    //* Displays available actions for a selected plot on the farm.
    //* Input: window - SFML window to render the plot options.
    //*        pos_x - x-coordinate of the selected plot.
    //*        pos_y - y-coordinate of the selected plot.
    void getPlotOptions(sf::RenderWindow *window, int pos_x, int pos_y);

    //* Renders the grid tiles and plots on the game window.
    //* Input: window - SFML window to render the farm layout.
    void drawPlots(sf::RenderWindow *window);

    //* Advances the game time, simulating the passage of time in the game.
    //* Input: window - SFML window to display the time passing effect.
    void passTime(sf::RenderWindow *window);

    //* Pauses the game for num_seconds. -> it freezes the game basically
    //* Input: num_seconds - Number of seconds to pause the game.
    void pause(int num_seconds);

    //* Changes the background sprite of a specific grid tile on the farm.
    //* Input: x - x-coordinate of the tile to change.
    //*        y - y-coordinate of the tile to change.
    //*        textureFilename - Filename of the new texture for the tile.
    //* Output: True if the sprite was successfully changed, false otherwise.
    bool changeBackSprite(int x, int y, std::string textureFilename);

    //* Displays farm-related text on the game window.
    //* Input: window - SFML window to display the text.
    //*        displayString - Text to display.
    //*        x - x-coordinate for text positioning.
    //*        y - y-coordinate for text positioning.
    void displayFarmText(sf::RenderWindow *window, std::string displayString, int x, int y);

    //* Checks if the selected game tile is a plot (for interaction).
    //* Input: selectedGametile - Position of the selected game tile.
    //* Output: True if the selected tile is a plot, false otherwise.
    bool selectedTileIsPlot(sf::Vector2f selectedGametile);

    //* Getter for the grid length (number of cells along one side of the farm).
    //* Output: The grid length.
    int get_GridLength() { return gridLength; };

    //* Brings up a menu that gives the user information about the game when they press h.
    bool get_Help(sf::RenderWindow *window);
};

#endif