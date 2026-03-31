#include "config.h"

ConfigInit::ConfigInit(sf::RenderWindow& window): window(window) {
  for (auto shape : shapes) {
    window.draw(*shape);
  }
}

void ConfigInit::addShape(sf::Shape* shape) {
  shapes.push_back(shape);
}