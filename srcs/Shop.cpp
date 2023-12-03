#include "Shop.h"

bool Shop::shopOpen(sf::RenderWindow *window, int money)
{
    shopIsOpen = true;
    std::string texture_filename = "sprites/Shop_background.png";
    if (!Backdrop_texture.loadFromFile(texture_filename))
    {
        std::cout << "error loading from file" << texture_filename << std::endl;
        return false;
    }
    Backdrop_sprite.setTexture(Backdrop_texture);
    Backdrop_sprite.setPosition(sf::Vector2f(shop_pos_x, shop_pos_y));
    window->draw(Backdrop_sprite);
    displayShopText(window, "SHOP", shop_pos_x + 110, shop_pos_y + 20);
    displayShopText(window, "Money: ", shop_pos_x + 175, shop_pos_y + 20);
    displayShopText(window, std::to_string(money), shop_pos_x + 230, shop_pos_y + 20);
    displayShopText(window, "1.Buy Wheat Seeds $2", shop_pos_x + 50, shop_pos_y + 40);
    displayShopText(window, "2.Buy Barley Seeds $3", shop_pos_x + 50, shop_pos_y + 60);
    displayShopText(window, "3.Buy a Chicken $15", shop_pos_x + 50, shop_pos_y + 80);
    displayShopText(window, "4.Buy a Sheep $20", shop_pos_x + 50, shop_pos_y + 100);
    displayShopText(window, "5.Buy Animal Feed $1", shop_pos_x + 50, shop_pos_y + 120);
    displayShopText(window, "6.Buy Fertiliser $2", shop_pos_x + 50, shop_pos_y + 140);
    displayShopText(window, "7.Sell Goods", shop_pos_x + 50, shop_pos_y + 160);
    return true;
}
void Shop::set_shopIsOpen(bool _shopIsOpen)
{
    shopIsOpen = _shopIsOpen;
}
bool Shop::get_shopIsOpen()
{
    return shopIsOpen;
}
void Shop::displayShopText(sf::RenderWindow *window, std::string display_string, int x, int y)
{
    sf::Font font;
    font.loadFromFile("Silkscreen/slkscr.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString(display_string);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x, y);
    window->draw(text);
}
Shop::Shop()
{
    shopIsOpen = false;
    shop_pos_x = 20;
    shop_pos_y = 0;
}
bool Shop::sellGoods(Inventory *Inventory)
{
    /*Eggs sell for 5 money each*/
    int Eggs = Inventory->getEggs();
    Inventory->eggsTake(Eggs);
    Inventory->moneyAdd(Eggs * 5);
    /*Barley sells for 15 money each*/
    int BarleyGrain = Inventory->getBarleyGrain();
    Inventory->barleyGrainTake(BarleyGrain);
    Inventory->moneyAdd(BarleyGrain * 15);
    /*Wheat sells for 10 money each*/
    int WheatGrain = Inventory->getWheatGrain();
    Inventory->wheatGrainTake(WheatGrain);
    Inventory->moneyAdd(WheatGrain * 10);
    /*Wools sells for 10 money each*/
    int Wool = Inventory->getWool();
    Inventory->woolTake(Wool);
    Inventory->moneyAdd(Wool * 10);
    /*Meat sells for 5 money each*/
    int Meat = Inventory->getMeat();
    Inventory->meatTake(Meat);
    Inventory->moneyAdd(Meat * 5);
    return true;
}