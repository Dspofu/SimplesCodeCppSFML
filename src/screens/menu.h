#ifndef MENU_H
#define MENU_H

#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../modules/controller.h"

class Menu {
  private:
    sf::RenderWindow &window;
    sf::Text detailsTextM, exibDevM;
    sf::Texture personTexture;
    sf::Sprite personM;
    Controller movePerson;
  public:
    Menu(sf::RenderWindow& window, const sf::Font& font);
    void load();
};

#endif