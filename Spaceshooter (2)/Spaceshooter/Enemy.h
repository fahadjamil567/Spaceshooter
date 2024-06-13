#include <SFML/Graphics.hpp>
#include<string.h>
// #include"Dragon.h"
#include"B-laser.h"
#ifndef Enemy_H_
#define Enemy_H_

using namespace sf;

class Enemy{

	
public:
	// Dragon d1;
	B_Laser *b1;
	float t;
int b_counter;
Sprite spriteFire;
Texture texFire;
Texture tex;
Sprite sprite;
float speed=1;
int points;
int l;
int x,y;
Enemy(){
	
}
virtual void fire(float x,float y)=0;
virtual void move()=0;

Enemy(std::string png_path,float a,float b)
{
    tex.loadFromFile(png_path);
    sprite.setTexture(tex);
    sprite.setScale(a,b);
}
void fireDragon()//string s)
    {
        b1= new B_Laser();
        texFire.loadFromFile("img/PNG/Lasers/dragFire.png");
		spriteFire.setTexture(texFire);
        spriteFire.setScale(0.6,2);        
        spriteFire.setPosition(sprite.getPosition().x+145, sprite.getPosition().y+375);
		
        
    }
void fireMonster()
    {
        b1= new B_Laser();
        texFire.loadFromFile("img/PNG/Lasers/monsterfire.png");
        spriteFire.setTexture(texFire);
        spriteFire.setScale(0.6,3.5);        
        spriteFire.setPosition(sprite.getPosition().x+110, sprite.getPosition().y+85);
    }

void pos(float x, float y){
    sprite.setPosition(x,y);
}

};
#endif
