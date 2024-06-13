#include <SFML/Graphics.hpp>
#include <string.h>
// #include"Bullet.h"
#ifndef B_Laser_H_
#define B_Laser_H_
#include "game.h"
using namespace sf;

class B_Laser
{

public:
	Texture tex;
	Sprite sprite;
	float speed = 2;
	Texture texD;
	Sprite spriteD;
	int x, y;
	B_Laser()
	{
		tex.loadFromFile("img/PNG/Lasers/laserRed13.png");
		sprite.setTexture(tex);
		x = sprite.getPosition().x;
		y = sprite.getPosition().y;
		// x=200;y=400;

		sprite.setScale(0.75, 0.7);
	}
	void Position(double a, double b)
	{
		a += 35;
		b -= 40;
		sprite.setPosition(a, b);
	}

	float delta_y = 0;
	void move()
	{
		delta_y = -1;
		sprite.move(0, delta_y);
	}
	void moveAlpha(int l)
	{

		delta_y = 0.4*l;

		sprite.move(0, delta_y);
	}
	void moveBeta(int l)
	{

		delta_y = 0.7*l;

		sprite.move(0, delta_y);
	}

	void moveGama(int l)
	{

		delta_y = 1.3*l;

		sprite.move(0, delta_y);
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
