#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Farm.h"
#include "GameTile.h"

/*ninchompoop2*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(320, 320), "FarmVille!");
    Farm farm = Farm();
    int showInv = -1;
    int showShop = -1;
    int showHelp = -1;
    sf::Vector2f relevantWindowSize;
    sf::Vector2f mousePressPos;
    sf::Vector2f selectedGametile;
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
            { // handles the mouse positioning scales in the event of a resize in window
                relevantWindowSize = sf::Vector2f(event.size.width, event.size.height);
            }
            if (event.type == sf::Event::MouseButtonPressed)
            { // records the position of the mouse when the button is pressed
                mousePressPos.x = sf::Mouse::getPosition(window).x * (window.getDefaultView().getSize().x / relevantWindowSize.x);
                mousePressPos.y = sf::Mouse::getPosition(window).y * (window.getDefaultView().getSize().y / relevantWindowSize.y);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
            { // handles inventory open and close
                showInv *= -1;
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B){
                //handles the shop open and close 
                showShop *= -1;
            }
            //shop options
            if(showShop == 1 && event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Num1){
                    if(farm.inventory->moneyTake(2) == true){
                        farm.inventory->wheatSeedAdd(1);
                        std::cout<<"Successfully purchased 1 Wheat Seed"<<std::endl;
                    }
                    else{
                        std::cout<<"Cannot buy Wheat Seed, insufficient funds"<<std::endl;
                    }
                }
                if(event.key.code == sf::Keyboard::Num2){
                   if(farm.inventory->moneyTake(3) == true){
                        farm.inventory->barleySeedAdd(1);
                        std::cout<<"Successfully purchased 1 Barley Seed"<<std::endl;
                    }
                    else{
                        std::cout<<"Cannot buy Barley Seed, insufficient funds"<<std::endl;
                    } 
                }
                if(event.key.code == sf::Keyboard::Num3){
                    if(farm.inventory->moneyTake(15) == true){
                        farm.inventory->ChickenAdd(1);
                        std::cout<<"Successfully purchased Chicken"<<std::endl;
                    }
                    else{
                        std::cout<<"Cannot buy Chicken, insufficient funds"<<std::endl;
                    }
                }
                if(event.key.code == sf::Keyboard::Num4){
                    if(farm.inventory->moneyTake(20) == true){
                        farm.inventory->SheepAdd(1);
                        std::cout<<"Successfully purchased 1 Sheep"<<std::endl;
                    }
                    else{
                        std::cout<<"Cannot buy Sheep, insufficient funds"<<std::endl;
                    }
                }
                if(event.key.code == sf::Keyboard::Num5){
                    if(farm.inventory->moneyTake(1) == true){
                        farm.inventory->animalFeedAdd(1);
                        std::cout<<"Successfully purchased 1 animal feed"<<std::endl;
                    }
                    else{
                        std::cout<<"Cannot buy animal feed, insufficient funds"<<std::endl;
                    }

                }
                if(event.key.code == sf::Keyboard::Num6){
                    if(farm.inventory->moneyTake(2) == true){
                        farm.inventory->fertiliserAdd(1);
                        std::cout<<"Successfully purchased 1 fertiliser"<<std::endl;
                    }
                    else{
                        std::cout<<"Cannot buy fertiliser, insufficient funds"<<std::endl;
                    }

                }
                if(event.key.code == sf::Keyboard::Num7){
                    if(farm.shop->sellGoods(farm.inventory) == true){
                        std::cout<<"Successfully sold all sellable items"<<std::endl;
                    }
                    else{
                        std::cout<<"Error in selling items"<<std::endl;
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1 && showShop == -1)
            { // handles when key num1 is pressed
                if (farm.selectedTileIsPlot(selectedGametile))
                {
                    if (farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->isEmpty() == true)
                    {
                      if(farm.inventory->wheatSeedTake(1) == true){
                        Wheat *newWheat = new Wheat;
                        farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->placeEntity(newWheat);
                      }
                      else{
                        std::cout<<"Cannot plant, no wheat seeds."<<std::endl;                      
                        }
                    }
                    else if (farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->isEmpty() == false)
                    {
                        farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->water();
                    }
                    else if (farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->get_isAnimal() == true)
                    {
                        farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->water();
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2 && showShop == -1)
            { // handles when key num2 is pressed
                if (farm.selectedTileIsPlot(selectedGametile)) {
                    if(farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->isEmpty() == true) {
                      if(farm.inventory->barleySeedTake(1) == true){
                        Barley *newBarley = new Barley;
                        farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->placeEntity(newBarley);
                      }
                      else{
                        std::cout<<"Cannot plant, no Barley seeds"<<std::endl;
                      }
                    }
                    else if (farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->get_isPlant() == true) {
                        if(farm.inventory->fertiliserTake(1) == true){
                            farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->fertilise(farm.inventory);
                        }
                        else{
                            std::cout<<"Cannot fertilise, no fertiliser available."<<std::endl;
                        }
                    }
                    else if (farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->get_isAnimal() == true) {
                        if(farm.inventory->animalFeedTake(1) == true){
                            farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->feed(farm.inventory);
                        }
                        else{
                            std::cout<<"Cannot feed, no animal feed available."<<std::endl;
                        }
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3 && showShop == -1)
            { // handles when key num3 is pressed
                if (farm.selectedTileIsPlot(selectedGametile) && farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->isEmpty() == false)
                {
                    farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->harvest(farm.inventory);
                }
                else if (farm.selectedTileIsPlot(selectedGametile) && farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->isEmpty() == true)
                {
                    if(farm.inventory->ChickenTake(1) == true){
                    Chicken *newChicken = new Chicken;
                    farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->placeEntity(newChicken);
                    }
                    else{
                        std::cout<<"Cannot place chicken, no chickens in inventory"<<std::endl;
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4 && showShop == -1)
            { // handles when key num4 is pressed
                if(farm.selectedTileIsPlot(selectedGametile) && farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->get_isAnimal() == true) {
                    farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->Slaughter(farm.inventory);
                }
                else if (farm.selectedTileIsPlot(selectedGametile) && farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->isEmpty() == true)
                {   
                    if(farm.inventory->SheepTake(1) == true){
                        Sheep *newSheep = new Sheep;
                        farm.plots[(int)selectedGametile.x - 2][(int)selectedGametile.y - 3]->placeEntity(newSheep);
                    }
                    else{
                        std::cout<<"Cannot place sheep, no sheep in inventory"<<std::endl;
                    }
                }
            }

            if(event.type == sf::Event::KeyPressed &&event.key.code == sf::Keyboard::H){
                //handles the help menu
                showHelp *= -1;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
            { // handles when the user wants to pass time
                farm.passTime(&window);
            }
            // Saving inventory data to a file
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
            {
                if (farm.inventory->saveDataToFile("InventoryData.txt"))
                {
                    std::cout << "Inventory data saved successfully." << std::endl;
                }
                else
                {
                    std::cerr << "Error saving inventory data." << std::endl;
                }
            }
            // Loading inventory data from a file
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::L)
            {
                if (farm.inventory->loadDataFromFile("InventoryData.txt"))
                {
                    std::cout << "Inventory data loaded successfully." << std::endl;
                }
                else
                {
                    std::cerr << "Error loading inventory data." << std::endl;
                }
            }
        }
        // just gets the mouse position when pressed
        selectedGametile.x = (int)mousePressPos.x / 32;
        selectedGametile.y = (int)mousePressPos.y / 32;

        window.clear();

        /*draws background*/
        sf::Texture backgroundTexture; // setting background image as main.png
        backgroundTexture.loadFromFile("sprites/main.png");
        sf::Sprite background(backgroundTexture);
        background.setPosition(0, 0);
        window.draw(background);
        //prints a message letting the user know how to access the help menu
        farm.displayFarmText(&window,"Press H to access Help menu!",0,0);
        // draws all plots
        farm.drawPlots(&window);
        
        // handles options
        if (farm.selectedTileIsPlot(selectedGametile))
        {
            farm.getPlotOptions(&window, (int)selectedGametile.x, (int)selectedGametile.y);
            farm.tiles[(int)selectedGametile.x][(int)selectedGametile.y]->drawSelectionBox(&window);
        }

        // handles inventory
        if (showInv == 1)
            farm.inventory->show(&window);
        // handles shop
        if (showShop == 1)
            farm.shop->shopOpen(&window, farm.inventory->getMoney());
        if(showHelp == 1){
            farm.get_Help(&window);
        }
        window.display();

    }
}