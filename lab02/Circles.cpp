#include "pch.h"
#include "Circles.h"
#include <cmath>
#include <iostream>
#define M_PI 3.141592

void draw_to_color_pixels(sf::Uint8 *colors_pixels, unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
{
	colors_pixels[4 * (y * 200 + x) + 0] = r;
	colors_pixels[4 * (y * 200 + x) + 1] = g;
	colors_pixels[4 * (y * 200 + x) + 2] = b;
	colors_pixels[4 * (y * 200 + x) + 3] = 255;
}

void Circles::initialize() {
	_background = new sf::Texture;
	_sprite = new sf::Sprite;
	_spriteRGB = new sf::Sprite;
	_colorsRGB = new sf::Uint8[200 * 200 * 4];
	_RGB = new sf::Texture;
	_spriteHSL = new sf::Sprite;
	_colorsHSL = new sf::Uint8[200 * 200 * 4];
	_HSL = new sf::Texture;
	_spriteHSV = new sf::Sprite;
	_colorsHSV = new sf::Uint8[200 * 200 * 4];
	_HSV = new sf::Texture;
	_spriteCMY = new sf::Sprite;
	_colorsCMY = new sf::Uint8[200 * 200 * 4];
	_CMY = new sf::Texture;
	_line = new sf::RectangleShape;
	_colors = new sf::Uint8[_sizeX*_sizeY * 4];
	_sliderPosition = 175;
}

void Circles::initRGB() {
	const double R = 100;
	double alfa;
	double r, xFixed, yFixed;
	for (int x = 0; x < 200; x++) {
		for (int y = 0; y < 200; y++) {
			xFixed = x - R;
			yFixed = R - y;
			r = sqrt(pow(xFixed, 2) + pow(yFixed, 2));
			alfa = acos(xFixed / r);
			if (y > R) alfa = 2 * M_PI - alfa;
			if (r < R) draw_to_color_pixels(_colorsRGB, x, y, 255 * r / R, 255 * alfa / (2. * M_PI), _sliderPosition);
			else draw_to_color_pixels(_colorsRGB, x, y, 255, 255, 255);
		}
	}
	_RGB->create(200, 200);
	_RGB->update(_colorsRGB);
	_spriteRGB->setTexture(*_RGB);
	_spriteRGB->setPosition(80, 80);
}

void Circles::initHSL() {
	const double R = 100;
	double alfa;
	double rad, xFixed, yFixed, p;
	float r=0, g=0, b=0;
	for (int x = 0; x < 200; x++) {
		for (int y = 0; y < 200; y++) {
			xFixed = x - R;
			yFixed = R - y;
			rad = sqrt(pow(xFixed, 2) + pow(yFixed, 2));
			p = rad / R;
			alfa = acos(xFixed / rad);
			if (y > R) alfa = 2 * M_PI - alfa;

			float c = (1 - fabs(2 * (255. - _sliderPosition)/255. - 1)) * p;
			float tmp = c * (1 - fabs(fmod(alfa * 3 / M_PI, 2.) - 1));
			float m = (255. - _sliderPosition) / 255. - c / 2;
			if (alfa >= 0. && alfa < M_PI / 3.) {
				r = c;
				g = tmp;
				b = 0;
			}
			else if (alfa>= M_PI / 3. && alfa <2.*M_PI/3.) {
				r = tmp;
				g = c;
				b = 0;
			}
			else if (alfa >= 2.* M_PI / 3. && alfa < M_PI) {
				r = 0;
				g = c;
				b = tmp;
			}
			else if (alfa >= M_PI  && alfa < M_PI * 4. / 3.) {
				r = 0;
				g = tmp;
				b = c;
			}
			else if (alfa >= M_PI * 4. / 3. && alfa < M_PI * 5. / 3.) {
				r = tmp;
				g = 0;
				b = c;
			}
			else if (alfa >= 5. * M_PI / 3. && alfa < 2.* M_PI) {
				r = c;
				g = 0;
				b = tmp;
			}
			r = (r + m) * 255;
			g = (g + m) * 255;
			b = (b + m) * 255;
			if (rad < R) {
				draw_to_color_pixels(_colorsHSL, x, y, r, g, b);
			}
			else draw_to_color_pixels(_colorsHSL, x, y, 255, 255, 255);
		}
	}
	_HSL->create(200, 200);
	_HSL->update(_colorsHSL);
	_spriteHSL->setTexture(*_HSL);
	_spriteHSL->setPosition(400, 80);
}

void Circles::initHSV() {
	const double R = 100;
	double alfa;
	double rad, xFixed, yFixed, p;
	for (int x = 0; x < 200; x++) {
		for (int y = 0; y < 200; y++) {
			xFixed = x - R;
			yFixed = R - y;
			rad = sqrt(pow(xFixed, 2) + pow(yFixed, 2));
			p = rad / R;
			alfa = acos(xFixed / rad);
			if (y > R) alfa = 2. * M_PI - alfa;

			float c = _sliderPosition/255. * p;
			float tmp = c * (1. - fabs(fmod(alfa * 3. / M_PI, 2.) - 1.));
			float m =  _sliderPosition/255 - c;
			float r=0, g=0, b=0;
			if (alfa >= 0. && alfa < M_PI / 3.) {
				r = c;
				g = tmp;
				b = 0;
			}
			else if (alfa >= M_PI / 3. && alfa < 2.*M_PI / 3.) {
				r = tmp;
				g = c;
				b = 0;
			}
			else if (alfa >= 2.* M_PI / 3. && alfa < M_PI) {
				r = 0;
				g = c;
				b = tmp;
			}
			else if (alfa >= M_PI && alfa < M_PI * 4. / 3.) {
				r = 0;
				g = tmp;
				b = c;
			}
			else if (alfa >= M_PI * 4. / 3. && alfa < M_PI * 5. / 3.) {
				r = tmp;
				g = 0;
				b = c;
			}
			else if (alfa >= 5. * M_PI / 3. && alfa < 2.* M_PI) {
				r = c;
				g = 0;
				b = tmp;
			}
			r = (r + m) * 255.;
			g = (g + m) * 255.;
			b = (b + m) * 255.;
			if (rad < R) {
				draw_to_color_pixels(_colorsHSV, x, y, r, g, b);
			}
			else draw_to_color_pixels(_colorsHSV, x, y, 255, 255, 255);
		}
	}
	_HSV->create(200, 200);
	_HSV->update(_colorsHSV);
	_spriteHSV->setTexture(*_HSV);
	_spriteHSV->setPosition(80, 360);
}

void Circles::initCMY() {
	const double R = 100;
	double alfa;
	double r, xFixed, yFixed;
	for (int x = 0; x < 200; x++) {
		for (int y = 0; y < 200; y++) {
			xFixed = x - R;
			yFixed = R - y;
			r = sqrt(pow(xFixed, 2) + pow(yFixed, 2));
			alfa = acos(xFixed / r);
			if (y > R) alfa = 2 * M_PI - alfa;
			if (r < R) draw_to_color_pixels(_colorsCMY, x, y, 255 -255 * r / R, 255 - 255 * alfa / (2. * M_PI), _sliderPosition - 255);
			else draw_to_color_pixels(_colorsCMY, x, y, 255, 255, 255);
		}
	}
	_CMY->create(200, 200);
	_CMY->update(_colorsCMY);
	_spriteCMY->setTexture(*_CMY);
	_spriteCMY->setPosition(400, 360);
}

Circles::Circles() {
	initialize();
	_background->create(_sizeX, _sizeY);
	int x, y;
	for (x = 0; x < _sizeX; x++) {
		for (y = 0; y < _sizeY; y++) {
			_colors[4 * (y * 40 + x) + 0] = y;
			_colors[4 * (y * 40 + x) + 1] = y;
			_colors[4 * (y * 40 + x) + 2] = y;
			_colors[4 * (y * 40 + x) + 3] = 255;
		}
	}
	_background->update(_colors);
	_sprite->setTexture(*_background);
	_sprite->setPosition(700, 50);

	_line->setSize(sf::Vector2f(40, 3));
	_line->setFillColor(sf::Color::Red);
	_line->setPosition(sf::Vector2f(700, 175));


	initRGB();

	initHSL();

	initCMY();

	initHSV();
}

void Circles::draw(sf::RenderTarget& target, sf::RenderStates states) {

	target.draw(*_sprite);
	target.draw(*_line);
	target.draw(*_spriteRGB);
	target.draw(*_spriteHSL);
	target.draw(*_spriteCMY);
	target.draw(*_spriteHSV);
}

void Circles::setLine(int y) {
	if (y > 50 && y < 305) {
		_line->setPosition(sf::Vector2f(700, y));
		_sliderPosition = y - 50;
		initRGB();

		initHSL();

		initCMY();

		initHSV();
	}
}