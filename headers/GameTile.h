#ifndef GAMETILE_H
#define GAMETILE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

/*The farm/game is divided into a 10x10 grid. each tile is represented by an object called a gametile.
The gametile is the base graphics section that everything is built upon whether that be plots or something else.*/
class GameTile
{
  protected:
    // Texture and sprite for the selection box associated with the game tile
    sf::Texture selectionBoxTexture;
    sf::Sprite selectionBoxSprite;

    // Position of the game tile
    sf::Vector2f pos;

    // Texture and sprite for the background of the game tile
    sf::Texture backTexture;
    sf::Sprite backSprite;

    // Texture and sprite for the front (foreground) of the game tile
    sf::Texture frontTexture;
    sf::Sprite frontSprite;

  public:
    // Default constructor to initialize a GameTile object
    GameTile();

    // Constructor to initialize a GameTile object with a specified background texture and position
    // Input: backTextureFilename - Filename of the background texture.
    //        pos_x - X-coordinate of the position.
    //        pos_y - Y-coordinate of the position.
    GameTile(std::string backTextureFilename, float pos_x, float pos_y);

    // Set up the background sprite of the game tile using the given texture filename
    // Input: backTextureFilename - Filename of the background texture.
    // Output: True if the background sprite is set up successfully, false otherwise.
    bool setUpBackSprite(std::string backTextureFilename);

    // Set up the background sprite of the game tile using the given texture filename and position
    // Input: backTextureFilename - Filename of the background texture.
    //        pos_x - X-coordinate of the position.
    //        pos_y - Y-coordinate of the position.
    // Output: True if the background sprite is set up successfully, false otherwise.
    bool setUpBackSprite(std::string backTextureFilename, int pos_x, int pos_y);

    // Set up the front sprite of the game tile using the given texture filename
    // Input: frontTextureFilename - Filename of the front texture.
    // Output: True if the front sprite is set up successfully, false otherwise.
    bool setUpFrontSprite(std::string frontTextureFilename);

    // Set up the front sprite of the game tile using the given texture filename and position
    // Input: frontTextureFilename - Filename of the front texture.
    //        pos_x - X-coordinate of the position.
    //        pos_y - Y-coordinate of the position.
    // Output: True if the front sprite is set up successfully, false otherwise.
    bool setUpFrontSprite(std::string frontTextureFilename, int pos_x, int pos_y);

    // Draw the selection box on the game tile using the provided window
    // Input: window - Pointer to the SFML render window.
    void drawSelectionBox(sf::RenderWindow *window);

    // Set the position of the game tile
    // Input: pos_x - X-coordinate of the new position.
    //        pos_y - Y-coordinate of the new position.
    void set_pos(float pos_x, float pos_y);
    
    // Get the position of the game tile
    // Output: The position of the game tile as a 2D vector.
    sf::Vector2f get_pos();

    // Getter for the background texture of the game tile
    // Output: The background texture of the game tile.
    sf::Texture get_backTexture() { return backTexture; };

    // Getter for the background sprite of the game tile
    // Output: The background sprite of the game tile.
    sf::Sprite get_backSprite() { return backSprite; };

    // Getter for the front texture of the game tile
    // Output: The front texture of the game tile.
    sf::Texture get_frontTexture() { return frontTexture; };

    // Getter for the front sprite of the game tile
    // Output: The front sprite of the game tile.
    sf::Sprite get_frontSprite() { return frontSprite; };
};
#endif