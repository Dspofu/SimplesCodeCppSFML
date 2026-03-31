#include <windows.h>
#include <iostream>
#include <d3d9.h>
#include <conio.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "src/screens/menu.h"

#pragma comment(lib, "d3d9.lib")

int main() {
  // char buffer[MAX_PATH];
  // GetCurrentDirectoryA(MAX_PATH, buffer);
  // std::cout << buffer << std::endl;
  // SetConsoleOutputCP(CP_UTF8);
  // SetConsoleCP(CP_UTF8);

  IDirect3D9 *d3d = Direct3DCreate9(D3D_SDK_VERSION);
  if (d3d) {
    D3DADAPTER_IDENTIFIER9 adapterIdentifier;
    if (SUCCEEDED(d3d->GetAdapterIdentifier(D3DADAPTER_DEFAULT, 0, &adapterIdentifier))) {
      // std::wcout << L"GPU: " << adapterIdentifier.Description << L"\nDriver: " << adapterIdentifier.Driver << L"\nDevice Name: " << adapterIdentifier.DeviceName << L"\nVendor ID: " << std::hex << adapterIdentifier.VendorId << L"\nDevice ID: " << std::hex << adapterIdentifier.DeviceId << L"\nSubSystem ID: " << std::hex << adapterIdentifier.SubSysId << std::endl;

      // getch();
      int width = 800;
      int height = 600;
      int impact = 20;
      bool XboolL = false;
      bool XboolR = false;
      bool YboolU = false;
      bool YboolD = false;
      bool isFPS = true;
      bool isGPU = true;
      bool isPlay = false;

      sf::RenderWindow window(sf::VideoMode(width, height), "DemoGame");
      window.setFramerateLimit(120);

      float speed = 4;
      sf::Event event;
      sf::Clock clock;
      sf::Text exibFPS;
      sf::Text deviceGPU;
      sf::Font font;
      sf::SoundBuffer bufferEntry;
      sf::Sound sound;
      sound.setBuffer(bufferEntry);
      if (!bufferEntry.loadFromFile("src/assets/sounds/entry.mp3")) return MessageBoxW(NULL, L"Audio is not found.", L"Error loading audio", MB_OK | MB_ICONERROR);
      if (!font.loadFromFile("src/assets/fonts/retro_gaming.ttf")) return MessageBoxW(NULL, L"Text font is not found.", L"Error loading text font", MB_OK | MB_ICONERROR);
      Controller moveAll = Controller(width, height);

      // FPS
      exibFPS.setFont(font);
      exibFPS.setCharacterSize(18);
      exibFPS.setFillColor(sf::Color::Yellow);

      // GPU
      deviceGPU.setFont(font);
      deviceGPU.setCharacterSize(10);
      deviceGPU.setFillColor(sf::Color::Yellow);
      deviceGPU.setPosition(0, 20);

      Menu startScreen = Menu(window, font);
      while (window.isOpen()) {
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed) window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) isFPS = !isFPS;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) isGPU = !isGPU;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) isPlay = !isPlay;

        sf::Time elapsed = clock.restart();
        float fps = 1.0f / elapsed.asSeconds();
        
        if (isGPU) deviceGPU.setString("GPU: " + std::string(adapterIdentifier.Description));
        else deviceGPU.setString("");
        if (isFPS) exibFPS.setString("FPS: " + std::to_string((int)fps));
        else exibFPS.setString("");
        if (isPlay) sound.play();

        window.clear();
        startScreen.load();
        window.draw(exibFPS);
        window.draw(deviceGPU);
        window.display();
      }
    }
    d3d->Release();
  }
  else MessageBoxW(NULL, L"Support for \"DirectX\" was not identified.", L"Error GPU detect", MB_OK | MB_ICONERROR);

  return 0;
}