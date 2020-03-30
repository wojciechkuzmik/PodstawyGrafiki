#include "pch.h"
#include "Circles.h"
#include "font.h"

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 02", sf::Style::Titlebar | sf::Style::Close);
 sf::Clock clock;
 sf::Time time = sf::Time::Zero;
 unsigned int FPS = 0 , frame_counter = 0;
 Circles circles;
 sf::Text text;
 sf::Font font;
 font.loadFromMemory(font_data, font_data_size);
 text.setFont(font);
 text.setCharacterSize(20);
 text.setFillColor(sf::Color::Black);

 
 //inicjalizacja 
 clock.restart().asMilliseconds();
 while (window.isOpen())
 {
  sf::Event event;
  window.clear(sf::Color::White);

  while (window.pollEvent(event))
  {
	  if (event.type == sf::Event::Closed) window.close();
	  if (event.type == sf::Event::MouseMoved) {
		  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			  circles.setLine(event.mouseMove.y);
		  }
	  }
  }
  //tu wyrysować wszystko na ekran
  circles.draw(window, sf::RenderStates::Default);
  text.setPosition(30, 50);
  text.setString("RGB");
  window.draw(text);

  text.setPosition(400, 50);
  text.setString("HSL");
  window.draw(text);

  text.setPosition(30, 350);
  text.setString("HSV");
  window.draw(text);

  text.setPosition(400, 350);
  text.setString("CMY");
  window.draw(text);


  //tu wypisać na ekran wartość FPS
  if (clock.getElapsedTime().asSeconds() >= 1.0f)
  {
   FPS = (unsigned int)((float)frame_counter / clock.getElapsedTime().asSeconds());
   clock.restart();
   frame_counter = 0;
  }
  frame_counter++;
  text.setPosition(700, 20);
  text.setString("FPS: " + std::to_string(FPS));
  window.draw(text);
  window.display();
 }
}