#include <SFML/Graphics.hpp>
#include <string.h>
// #include"Bullet.h"
#ifndef Powerup_H_
#define Powerup_H_
using namespace sf;

class Powerup
{

public:
	Texture tex;
	Sprite sprite;
	float speed = 1;
	int x, y;
	Powerup(std::string png_path)
	{
		srand(time(0));

		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		sprite.setScale(1, 1);
		sprite.setPosition(rand() % 760, 0);
	}
	void Position(double a, double b)
	{
		a += 35;
		b -= 40;
		sprite.setPosition(a, b);
	}

	float delta_y = 0;
	float delta_x = 0;
	void move(int a)
	{
		delta_y = -1;
		sprite.move(0, delta_y);
	}
	void move()
	{
		delta_x = 0;
		delta_y = +0.5;
		sprite.move(delta_x, delta_y);
	}

	float get_posy()
	{
		return sprite.getPosition().y;
	}
	float get_posx()
	{
		return sprite.getPosition().x;
	}
};

#endif
