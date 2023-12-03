
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Farm.h"
#include <vector>

// Constructor for Farm class
Farm::Farm()
{
    gridLength = 10; // Set the grid length
    dayCounter = 0; // Initialize day counter
    setBackTiles(); // Set the background tiles
    setPlots(); // Set the farm plots
    shop = new Shop(); // Initialize the shop
    inventory = new Inventory(); // Initialize the inventory
    help_x = 20; // Set help x-coordinate
    help_y = 0; // Set help y-coordinate
}

// Function to set the farm plots
void Farm::setPlots()
{
    plots.clear(); // Clear existing plots
    sf::Vector2f start(2, 3); // Set the starting position for plots
    sf::Vector2f end(7, 6); // Set the ending position for plots

    int x_size = end.x - start.x; // Calculate x size of plots
    int y_size = end.y - start.y; // Calculate y size of plots
    for (int x = 0; x <= x_size; x++)
    {
        std::vector<Plot *> pRow;
        for (int y = 0; y <= y_size; y++)
        {
            Plot *plotToAdd = new Plot("sprites/Transparent.png", 32 * (start.x + x), 32 * (start.y + y));
            plotToAdd->setUpFrontSprite("sprites/Transparent.png");
            pRow.push_back(plotToAdd);
        }
        plots.push_back(pRow);
    }
}

// Function to set the background tiles
void Farm::setBackTiles()
{
    tiles.clear();
    for (int i = 0; i < gridLength; i++)
    {
        std::vector<GameTile *> row;
        for (int j = 0; j < gridLength; j++)
        {
            row.push_back(new GameTile("sprites/Transparent.png", 32 * i, 32 * j));
        }
        tiles.push_back(row);
    }
    std::cout << "completed Farm.setUpTiles() " << std::endl;
}

// Function to pass time and simulate a day on the farm
void Farm::passTime(sf::RenderWindow *window)
{
    dayCounter++;
    std::cout << "the farm is now on day " << dayCounter << ". Congratulations!" << std::endl;
    for (int i = 0; i < (int)plots.size(); i++)
    {
        for (int j = 0; j < (int)plots[i].size(); j++)
        {
            if (plots[i][j]->isEmpty() == false)
            {
                if (plots[i][j]->checkDeath() == false)
                {                              // if the plant has not died on this day yet:
                    plots[i][j]->growEntity(); // entity may only grow when certain conditions are met
                    plots[i][j]->updateSprite();
                    
                }
            }
        }
    }
    sf::RectangleShape blackScreen;
    blackScreen.setFillColor(sf::Color::White);
    blackScreen.setSize(sf::Vector2f(350, 350));
    window->draw(blackScreen);
    displayFarmText(window, "day: ", 140, 150);
    displayFarmText(window, std::to_string(dayCounter), 175, 150);
    window->display();
    pause(2);
}

/*pauses the game for a set amount of seconds*/
void Farm::pause(int num_seconds)
{
    sf::Clock clock;
    sf::Time time = sf::seconds(0);
    while (num_seconds > time.asSeconds())
        time = clock.getElapsedTime();
}

// Function to change the background sprite for a given tile
bool Farm::changeBackSprite(int x, int y, std::string textureFilename)
{
    if (tiles[y][x]->setUpBackSprite(textureFilename))
        return (1);
    return (0);
}
//the help menu
bool Farm::get_Help(sf::RenderWindow *window)
{
    std::string texture_filename = "sprites/Shop_background.png";
    if (!Help_texture.loadFromFile(texture_filename))
    {
        std::cout << "error loading from file" << texture_filename << std::endl;
        return false;
    }
    Help_sprite.setTexture(Help_texture);
    Help_sprite.setPosition(sf::Vector2f(20, 0));
    window->draw(Help_sprite);
    displayFarmText(window, "HELP MENU", help_x+110, help_y+20);
    displayFarmText(window, "Press 'B' to access the shop menu.", help_x+25, help_y+40);
    displayFarmText(window, "Press 'I' to access the inventory.", help_x+25, help_y+60);
    displayFarmText(window, "Press 'P' to pass a day.", help_x+25, help_y+80);
    displayFarmText(window, "Plants must be watered each day, and ", help_x+25, help_y+100);
    displayFarmText(window, "fertilised only once in their lifetime.", help_x+25, help_y+120);
    displayFarmText(window, "Animals must be watered and fed daily.", help_x+25, help_y+140);
    displayFarmText(window, "To collect eggs or wool,", help_x+25, help_y+160);
    displayFarmText(window, "use the harvest option.", help_x+25, help_y+180);
    displayFarmText(window, "If a plant or animal has either its", help_x+25, help_y+200);
    displayFarmText(window, "wateringlevel or hunger fall to zero", help_x+25, help_y+220);
    displayFarmText(window, "it will perish.", help_x+25, help_y+240);
    displayFarmText(window, "Chickens die after 10 days and Sheep", help_x+25, help_y+260);
    displayFarmText(window, "die after 15. Good Luck!", help_x+25, help_y+280);
    return true;
}

// Function to display options for a selected plot
void Farm::getPlotOptions(sf::RenderWindow *window, int pos_x, int pos_y)
{
    pos_x -= 2;
    pos_y -= 3;
    // std::cout<< pos_x << ", " << pos_y << std::endl;
    if (plots[pos_x][pos_y]->isEmpty() == true)
    {
        displayFarmText(window, "This Farmplot is empty.", pos_x * 32, pos_y * 32);
        displayFarmText(window, "Press 1 to plant wheat(Uses wheat seeds).", pos_x * 32, pos_y * 32 + 15);
        displayFarmText(window, "Press 2 to plant barley(Uses barley seeds).", pos_x * 32, pos_y * 32 + 30);
        displayFarmText(window, "Press 3 to place a chicken(Uses 1 chicken).", pos_x * 32, pos_y * 32 + 45);
        displayFarmText(window, "Press 4 to place a sheep(Uses 1 sheep).", pos_x * 32, pos_y * 32 + 60);
        return;
    }
    if (plots[pos_x][pos_y]->get_isAnimal() == true)
    {
        displayFarmText(window, "Press 1 to give Water.", pos_x * 32, pos_y * 32);
        displayFarmText(window, "Press 2 to Feed.", pos_x * 32, pos_y * 32 + 15);
        displayFarmText(window, "Press 3 to Harvest.", pos_x * 32, pos_y * 32 + 30);
        displayFarmText(window, "Press 4 to Slaughter.", pos_x * 32, pos_y * 32 + 45);
        return;
    }
    if (plots[pos_x][pos_y]->get_isPlant() == true)
    {
        displayFarmText(window, "Press 1 to Water.", pos_x * 32, pos_y * 32);
        displayFarmText(window, "Press 2 to Fertilise.", pos_x * 32, pos_y * 32 + 15);
        displayFarmText(window, "Press 3 to Harvest.", pos_x * 32, pos_y * 32 + 30);
        return;
    }
}

// Function to check if the selected tile is a plot
bool Farm::selectedTileIsPlot(sf::Vector2f selectedGametile)
{
    int tile_x = (int)selectedGametile.x;
    int tile_y = (int)selectedGametile.y;
    if ((tile_x <= 7 && tile_x >= 2) && (tile_y <= 6 && tile_y >= 3))
        return true;
    return false;
}

// Function to display text on the farm
void Farm::displayFarmText(sf::RenderWindow *window, std::string displayString, int x, int y)
{
    sf::Font font;
    font.loadFromFile("Silkscreen/slkscr.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString(displayString);
    text.setCharacterSize(10);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x, y);
    window->draw(text);
}

// Function to draw the farm plots on the window
void Farm::drawPlots(sf::RenderWindow *window)
{
    int ySize = plots.size();
    int xSize = plots[0].size();
    for (int i = 0; i < ySize; i++)
    {
        for (int j = 0; j < xSize; j++)
        {
            window->draw(plots[i][j]->get_backSprite());
            window->draw(plots[i][j]->get_frontSprite());
        }
    }
}
