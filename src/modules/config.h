#ifndef CONFIG_H
#define CONFIG_H

#include <SFML/Graphics.hpp>
#include <vector>

class ConfigInit {
  private:
    sf::RenderWindow& window;
    std::vector<sf::Shape*> shapes;
  public:
    ConfigInit(sf::RenderWindow& window);
    void addShape(sf::Shape* shape);
};

#endif