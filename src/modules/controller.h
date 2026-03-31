#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SFML/Graphics.hpp>

// Classe Controller para controlar movimentação
class Controller {
  private:
    int width, height;
  public:
    Controller(int width, int height);
    void moveUp(sf::Sprite& person, float speed, float y);
    void moveDown(sf::Sprite& person, float speed, float y);
    void moveLeft(sf::Sprite& person, float speed, float x);
    void moveRight(sf::Sprite& person, float speed, float x);
};

#endif