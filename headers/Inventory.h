#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>

/*the inventory class holds all the farm's resources and determines what
the player is allowed to plant and what the player cannot plant. The inventory
can be saved when the player exits the game.*/
class Inventory
{
  private:
    /*resources*/
    int money;
    int fertiliser;
    int animalFeed;

    /*Sellable items*/
    int wheatGrain;
    int barleyGrain;
    int wool;
    int eggs;
    int meat;

    /*seeds*/
    int wheatSeed;
    int barleySeed;

    /*animals*/
    int sheep;
    int chickens;

    /*specific to inventory class*/
    sf::Texture backdrop_texture;
    sf::Sprite  backdrop_sprite;
    int inventoryPos_x;
    int inventoryPos_y;

  public:
    /*constructor*/
    Inventory();

    /*saving and loading from a file*/
    bool saveDataToFile(const std::string& filename);
    bool loadDataFromFile(const std::string& filename);

    /*functions to access and change private inventory members*/
    void moneyAdd(int amount);
    bool moneyTake(int amount);
    void fertiliserAdd(int amount);
    bool fertiliserTake(int amount);
    void wheatGrainAdd(int amount);
    bool wheatGrainTake(int amount);
    void barleyGrainAdd(int amount);
    bool barleyGrainTake(int amount);
    void wheatSeedAdd(int amount);
    bool wheatSeedTake(int amount);
    void barleySeedAdd(int amount);
    bool barleySeedTake(int amount);
    void woolAdd(int amount);
    bool woolTake(int amount);
    void eggsAdd(int amount);
    bool eggsTake(int amount);
    void ChickenAdd(int amount);
    bool ChickenTake(int amount);
    void SheepAdd(int amount);
    bool SheepTake(int amount);
    void animalFeedAdd(int amount);
    bool animalFeedTake(int amount);
    void meatAdd(int amount);
    bool meatTake(int amount);
    //getters for sellable objects + money
    int getMoney();
    int getWool();
    int getEggs();
    int getWheatGrain();
    int getBarleyGrain();
    int getMeat();
    int getFertiliser() {return(fertiliser);};
    int getWheatSeed() {return(wheatSeed);};
    int getBarleySeed() {return(barleySeed);};
    int getSheep() {return(sheep);};
    int getChickens() {return(chickens);};
    /*functions to show the inventory*/
    bool show(sf::RenderWindow *window);
    void displayInvText(sf::RenderWindow *window, std::string displayString, int x, int y);
};

#endif