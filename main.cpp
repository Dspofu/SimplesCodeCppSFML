#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "modules/controller.h"

int main() {
  int width = 800;
  int height = 600;
  int impact = 20;
  bool XboolL = false;
  bool XboolR = false;
  bool YboolU = false;
  bool YboolD = false;
  sf::RenderWindow window(sf::VideoMode(width, height), "Circle that moves");

  sf::CircleShape person(10.f);
  person.setFillColor(sf::Color::Green);
  person.setPosition(window.getSize().x / 2, window.getSize().y / 2);

  // float speed = 0.05f;
  float speed = 0.2f;
  sf::Clock clock;
  sf::Text exibFPS;
  sf::Text exibOrient;
  sf::Font font;
  Controller moveAll = Controller(width, height);
  if (font.loadFromFile("fonts/retro_gaming.ttf")) {
    exibFPS.setFont(font);
    exibFPS.setCharacterSize(18);
    exibFPS.setFillColor(sf::Color::Yellow);
    exibOrient.setFont(font);
    exibOrient.setCharacterSize(10);
    exibOrient.setFillColor(sf::Color::Yellow);
    exibOrient.setPosition(260, 570);
  }

  while (window.isOpen()) {
    sf::Event event;
    sf::Time elapsed = clock.restart();
    float fps = 1.0f / elapsed.asSeconds();

    exibFPS.setString("FPS: " + std::to_string((int)fps));
    exibOrient.setString("Keys from Movimented: W = Up, S = Down, D = Right, A = Left;\nFrom Speed: Shift = Fast, Ctrol = Slow");
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) { speed = speed+0.05f; }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) { if(speed >= 0) speed = speed-0.05f; }
    }
    sf::Vector2f position = person.getPosition();

    if (speed < 0) { speed = 0.05f; }

    moveAll.moveUp(person, speed, position.y);
    moveAll.moveDown(person, speed, position.y);
    moveAll.moveLeft(person, speed, position.x);
    moveAll.moveRight(person, speed, position.x);


    window.clear();
    window.draw(exibFPS);
    window.draw(exibOrient);
    window.draw(person);
    window.display();
  }
  return 0;
}

// void controller(std::string key, sf::CircleShape &personagem) {
//   sf::Keyboard::isKeyPressed(key);
// }
// std::string what = "\033[32mTecla pressionada: \033[34m";


// void setTimeout(std::string text = "Your text.", int time = 1000) {
//   auto start = std::chrono::high_resolution_clock::now();

//   for (char write: text) {
//     while (true) {
//       auto end = std::chrono::high_resolution_clock::now();
//       std::chrono::duration<double, std::milli> elapsed = end - start;

//       if (elapsed.count() >= time) {
//         std::cout << write;
//         start = std::chrono::high_resolution_clock::now();
//         break;
//       }
//       std::this_thread::sleep_for(std::chrono::milliseconds(100));
//     }
//   }
//   std::cout << "\n";
// }