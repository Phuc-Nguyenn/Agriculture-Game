#ifndef GT_TEST_H
#define GT_TEST_H

#include "GameTile.h"
#include <iostream>

class GameTileTest
{
private:
    GameTile *gametile;

    void BackSpriteTest()
    {
        if (!gametile->setUpBackSprite("sprites/Transparent.png"))
            std::cout << "failed: setUpBackSprite" << std::endl;
        else if (!gametile->setUpBackSprite("sprites/wheatSprite/wheat0.png"))
            std::cout << "failed: setUpBackSprite" << std::endl;
        else
            std::cout << "pass: back sprite tests" << std::endl;
    }

    void FrontSpriteTest()
    {
        if (!gametile->setUpFrontSprite("sprites/Transparent.png"))
            std::cout << "failed: setUpFrontSprite" << std::endl;
        else if (!gametile->setUpFrontSprite("sprites/wheatSprite/wheat0.png"))
            std::cout << "failed: setUpFrontSprite" << std::endl;
        else
            std::cout << "pass: front sprite tests" << std::endl;
    }

    void positionTest()
    {
        sf::Vector2f vct = gametile->get_pos();
        if (vct.x == 1 && vct.y == 2)
        {
            std::cout << "Pass: Correct initial position (1, 2)\n";
        }
        else
        {
            std::cout << "Fail: Incorrect initial position\n";
        }

        gametile->set_pos(3, 4);
        sf::Vector2f vct2 = gametile->get_pos();
        if (vct2.x == 3 && vct2.y == 4)
        {
            std::cout << "Pass: Correct updated position (3, 4)\n";
        }
        else
        {
            std::cout << "Fail: Incorrect updated position\n";
        }
    }

public:
    GameTileTest()
    {
        gametile = new GameTile("sprites/Transparent.png", 1, 2);
    }

    void runAllTests()
    {
        // Run all individual test functions
        BackSpriteTest();
        FrontSpriteTest();
        positionTest();
    }
};

#endif