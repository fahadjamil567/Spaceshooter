#include <SFML/Graphics.hpp>
#include<string.h>
#include"B-laser.h"
#include"Invader.h"
// #include"Dragon.h"
#ifndef Gama_H_
#define Gama_H_

using namespace sf;

class Gama:public Invader{

	
public:
	// Dragon d1;
	
Gama(float x,float y,int a):Invader("img/enemy_3.png",0.5,0.5){
	sprite.setPosition(x,y);
	t=2;
	l=a;
	points=30;
}

void fire(float x,float y)
{
	b1=new B_Laser();
	b1->Position(x,y);
	b_counter+=1;
	//b1->move("u");
}
void move(){
	b1->moveGama(l);
}

void pos(float x, float y){
    sprite.setPosition(x,y);
}
float get_pos(){
	return sprite.getPosition().y;
}
float get_posx(){
	return sprite.getPosition().x;
}

};
#endif
