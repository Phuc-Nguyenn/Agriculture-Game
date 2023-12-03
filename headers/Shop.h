
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Inventory.h"
#ifndef SHOP_H
#define SHOP_H


/*the shop is where the player can buy and sell their resources.
Progression is made in the game as the player gains money and is able
to trade more expensive items like sheep.*/
class Shop
{
private:
    // Texture and sprite for the shop backdrop
    sf::Texture Backdrop_texture;
    sf::Sprite Backdrop_sprite;

    // Flag indicating if the shop is open
    bool shopIsOpen;

    // Position of the shop
    int shop_pos_x;
    int shop_pos_y;

public:
    // Constructor to initialize a Shop object
    Shop();

    // Getter for the flag indicating if the shop is open
    // Output: True if the shop is open, false otherwise
    bool get_shopIsOpen();

    // Display shop-related text on the window
    // Input: window - Pointer to the SFML render window.
    //        display_string - Text to display.
    //        x - X-coordinate for text positioning.
    //        y - Y-coordinate for text positioning.
    void displayShopText(sf::RenderWindow *window, std::string display_string, int x, int y);

    // Setter for the flag indicating if the shop is open
    // Input: _shopIsOpen - Boolean value to set if the shop is open
    void set_shopIsOpen(bool _shopIsOpen);

    // Open the shop and allow the player to interact with it
    // Input: window - Pointer to the SFML render window.
    //        money - Amount of money the player has
    // Output: True if the shop is open and the player interacted, false otherwise
    bool shopOpen(sf::RenderWindow *window, int money);
    
    //function that sells all sellable items in the inventory
    bool sellGoods(Inventory *Inventory);
};


#endif