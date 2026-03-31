#include "menu.h"

Menu::Menu(sf::RenderWindow &window, const sf::Font &font) : window(window), movePerson(window.getSize().x, window.getSize().y) {
  if (!personTexture.loadFromFile("src/assets/image/cogu.png")) {
    if (personTexture.getSize().x >= sf::Texture::getMaximumSize() || personTexture.getSize().y >= sf::Texture::getMaximumSize()) {
      MessageBoxW(NULL, L"video memory limit exceeded", L"Error video memory", MB_OK | MB_ICONERROR);
      exit(1);
    } else {
      MessageBoxW(NULL, L"Image is not found.", L"Error loading image", MB_OK | MB_ICONERROR);
      exit(1);
    }
  }

  // AjustPerson
  personM.setTexture(personTexture);
  personM.setScale(0.02f, 0.02f);
  personM.setPosition(window.getSize().x / 2, window.getSize().y / 2);

  // DetailsText
  detailsTextM.setFont(font);
  detailsTextM.setCharacterSize(10);
  detailsTextM.setFillColor(sf::Color::Yellow);
  detailsTextM.setPosition(260, 570);
  detailsTextM.setString("Keys from Movimented: W = Up, S = Down, D = Right, A = Left");

  // DetailsText2
  exibDevM.setFont(font);
  exibDevM.setCharacterSize(10);
  exibDevM.setFillColor(sf::Color::Yellow);
  exibDevM.setPosition(260, 580);
  exibDevM.setString("Shift = FPS, Ctrol = GPU Device, T = Testing advanced 'Song'");
}

void Menu::load() {
  if (personM.getGlobalBounds().intersects(detailsTextM.getGlobalBounds())) personM.setColor(sf::Color::Red);
  else personM.setColor(sf::Color::White);

  sf::Vector2f position = personM.getPosition();

  movePerson.moveUp(personM, 4, position.y);
  movePerson.moveDown(personM, 4, position.y);
  movePerson.moveLeft(personM, 4, position.x);
  movePerson.moveRight(personM, 4, position.x);

  window.draw(detailsTextM);
  window.draw(exibDevM);
  window.draw(personM);
}