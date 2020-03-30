#pragma once
#include "pch.h"

class Circles {
public:
	Circles();
	void draw(sf::RenderTarget&, sf::RenderStates);
	void setLine(int);
	void initialize();
	void initRGB();
	void initHSL();
	void initCMY();
	void initHSV();
private:
	sf::Texture *_background;
	sf::Sprite *_sprite;
	sf::RectangleShape *_line;
	sf::Uint8 *_colors;
	sf::Uint8 *_colorsRGB;
	sf::Texture *_RGB;
	sf::Sprite *_spriteRGB;
	sf::Uint8 *_colorsHSL;
	sf::Texture *_HSL;
	sf::Sprite *_spriteHSL;
	sf::Uint8 *_colorsHSV;
	sf::Texture *_HSV;
	sf::Sprite *_spriteHSV;
	sf::Uint8 *_colorsCMY;
	sf::Texture *_CMY;
	sf::Sprite *_spriteCMY;
	int _sizeX = 40;
	int _sizeY = 255;
	float _sliderPosition;
};

void draw_to_color_pixels(sf::Uint8 *, unsigned int, unsigned int, unsigned char, unsigned char, unsigned char);

