#include <SFML/Graphics.hpp>
#include <string.h>
#ifndef Player_H_
#define Player_H_
#include "G_Laser.h"
#include "Enemy.h"

using namespace sf;
class Player
{
public:
	G_Laser *b1;
	int lives;
	Texture tex;
	Sprite sprite;
	float speed = 1;
	int x, y;
	Player()
	{
		tex.loadFromFile("img/player_ship.png");
		sprite.setTexture(tex);
		lives = 300;
		x = 340;
		y = 700;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
	}
	void fire()
	{
		b1 = new G_Laser();
		b1->Position(sprite.getPosition().x, sprite.getPosition().y);
	}

	void moveBullet()
	{
		b1->move();
	}
	void moveBullet(string &s)
	{
		b1->move(s);
	}
	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			delta_x = -1;
		// move the player left
		else if (s == "r")
			delta_x = 1;
		// move the player right
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;
		double boundryx = sprite.getPosition().x;
		double boundryy = sprite.getPosition().y;

		if (sprite.getPosition().x < -34)
			sprite.setPosition(734, sprite.getPosition().y);
		if (sprite.getPosition().y >= 700)
			sprite.setPosition(sprite.getPosition().x, 700);
		if (sprite.getPosition().x > 734)
			sprite.setPosition(-34, sprite.getPosition().y);
		if (sprite.getPosition().y <= 0)
			sprite.setPosition(sprite.getPosition().x, 0);

		sprite.move(delta_x, delta_y);
	}
	bool enemydistroy(Enemy *E, bool &fired, bool p, int &score)
	{
		if (fired == true)
		{
			if (E->sprite.getPosition().y+50 >= b1->sprite.getPosition().y && E->sprite.getPosition().y <= b1->sprite.getPosition().y + 20 && b1->sprite.getPosition().x >= E->sprite.getPosition().x && b1->sprite.getPosition().x <= E->sprite.getPosition().x + 83 && p == true)
			{
				fired = false;
				score += E->points * E->l;
				return 0;
			}
			else
				return p;
		}
		else
			return p;
	}
	bool playercollide(Enemy *E, bool p,bool pow)
	{
		if (E->sprite.getPosition().y >= sprite.getPosition().y - 70 && E->sprite.getPosition().y <= sprite.getPosition().y + 70 && sprite.getPosition().x >= E->sprite.getPosition().x - 83 && sprite.getPosition().x <= E->sprite.getPosition().x + 83 && p == true &&pow==false)
		{
			x = 340;
			y = 700;
			sprite.setPosition(x, y);
			lives--;

			return p;
		}
		else
			return p;
	}
	bool MonsterFireCollision(B_Laser *b1)
	{
		return true;
	}
	void playerdistroy(B_Laser *E, bool p, bool &b,bool pow)
	{
		if (E->sprite.getPosition().y >= sprite.getPosition().y && E->sprite.getPosition().y <= sprite.getPosition().y + 70 && E->sprite.getPosition().x >= sprite.getPosition().x && E->sprite.getPosition().x <= sprite.getPosition().x + 73 && b == true &&pow==false)
		{
			x = 340;
			y = 700;
			sprite.setPosition(x, y);
			lives--;
			b = false;
		}
	}
	void setTiltedpng(int n)
	{

		if (n == 1)
		{
			tex.loadFromFile("img/player_ship_R.png");
			sprite.setScale(1, 1);
		}
		if (n == 2)
		{
			tex.loadFromFile("img/player_ship_L.png");
			sprite.setScale(1, 1);
		}
	}
	void setorignal()
	{
		tex.loadFromFile("img/player_ship.png");
		sprite.setScale(0.75, 0.75);
	}
	void display_pausemenu(bool &end)
	{
		char title[] = "OOP-Project, Spring-2023";
		sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
		{
			// error...
		}
		Sprite background; // Game background sprite
		Texture bg_texture;
		bg_texture.loadFromFile("img/background1.jpg");
		background.setTexture(bg_texture);
		background.setScale(0.7, 1);

		sf::RenderWindow window(sf::VideoMode(400, 400), title);
		window.clear(sf::Color::Black);

		sf::Clock clock;
		while (window.isOpen())
		{
			bool a = 0, b = 0, c = 0, d = 0, f = 0;
			float time = clock.getElapsedTime().asSeconds();
			// clock.restart();
			window.draw(background);
			// timer+=time;
			sf::Event e;
			while (window.pollEvent(e))
			{ // Event is occurring - until the game is in running state
				if (e.type == sf::Event::Closed || f == 1 || end == 1)
				{
					window.close();
				}
				// Opened window disposes
				if (e.type == sf::Event::KeyPressed)
				{
					if (e.key.code == sf::Keyboard::C)
					{
						f = 1; // Check if the other key pressed is UP key
					}

					else if (e.key.code == sf::Keyboard::R)
					{
						end = 1;
						// Check if the other key pressed is UP key
					} // If any other key (not cross) is pressed
				}
			}

			sf::Text text2;
			text2.setFont(font);
			text2.setPosition(100, 80);
			text2.setString("Game Paused!! :)");
			text2.setCharacterSize(30);
			text2.setFillColor(sf::Color::White);
			text2.setStyle(sf::Text::Bold);

			sf::Text text3;
			text3.setFont(font);
			text3.setPosition(100, 180);
			text3.setString("PRESS 'R' TO EXIT");
			text3.setCharacterSize(20);
			text3.setFillColor(sf::Color::White);
			text3.setStyle(sf::Text::Bold | sf::Text::Underlined);

			sf::Text text4;
			text4.setFont(font);
			text4.setPosition(80, 250);
			text4.setString("PRESS 'C' TO CONTINUE");
			text4.setCharacterSize(20);
			text4.setFillColor(sf::Color::White);
			text4.setStyle(sf::Text::Bold | sf::Text::Underlined);

			window.draw(text4);
			window.draw(text3);
			window.draw(text2);

			//---The Window that now Contains the Frame is Displayed---//
			window.display();
		}
	}
	void gameover(int score)
	{
		char title[] = "OOP-Project, Spring-2023";
		sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
		{
			// error...
		}
		Sprite background; // Game background sprite
		Texture bg_texture;
		bg_texture.loadFromFile("img/background1.jpg");
		background.setTexture(bg_texture);
		background.setScale(0.7, 1);

		sf::RenderWindow window(sf::VideoMode(400, 400), title);
		window.clear(sf::Color::Black);

		sf::Clock clock;
		while (window.isOpen())
		{
			bool a = 0, b = 0, c = 0, d = 0, f = 0;
			float time = clock.getElapsedTime().asSeconds();
			// clock.restart();
			window.draw(background);
			// timer+=time;
			sf::Event e;
			while (window.pollEvent(e))
			{ // Event is occurring - until the game is in running state
				if (e.type == sf::Event::Closed || f == 1)
				{
					window.close();
				}
				// Opened window disposes
				if (e.type == sf::Event::KeyPressed)
				{
					if (e.key.code == sf::Keyboard::B)
					{
						f = 1; // Check if the other key pressed is UP key
					}		   // If any other key (not cross) is pressed
				}
			}

			sf::Text text2;
			text2.setFont(font);
			text2.setPosition(100, 120);
			text2.setString("Game Over !! :)");
			text2.setCharacterSize(30);
			text2.setFillColor(sf::Color::White);
			text2.setStyle(sf::Text::Bold);

			sf::Text text3;
			text3.setFont(font);
			text3.setPosition(100, 240);
			text3.setString("Your Score is");
			text3.setCharacterSize(20);
			text3.setFillColor(sf::Color::White);
			text3.setStyle(sf::Text::Bold | sf::Text::Underlined);

			sf::Text text1;
			text1.setFont(font);
			text1.setPosition(100, 350);
			text1.setString("Press B to Return");
			text1.setCharacterSize(20);
			text1.setFillColor(sf::Color::White);
			text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

			sf::Text text;
			text.setFont(font);
			text.setPosition(250, 235);
			text.setString(std::to_string(score));
			text.setCharacterSize(25);
			text.setFillColor(sf::Color::Red);
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);

			window.draw(text);
			window.draw(text1);
			window.draw(text3);
			window.draw(text2);

			//---The Window that now Contains the Frame is Displayed---//
			window.display();
		}
	}
};
#endif
