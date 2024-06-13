#include <SFML/Graphics.hpp>
#include<string.h>
// #include"Dragon.h"
#include "B-laser.h"
//#include "G_Laser.h"

#include "Invader.h"

#ifndef Beta_H_
#define Beta_H_

using namespace sf;

class Beta:public Invader{

	
public:
	// Dragon d1;
	
int x,y;
// Beta(){}
Beta(float x,float y,int a) : Invader("img/enemy_2.png",0.75,0.75){
	sprite.setPosition(x,y);
	t=3;
	l=a;
	points=20;
}

void move(){
	b1->moveBeta(l);
}

void fire(float x,float y)
{
	b1=new B_Laser();
	b1->Position(x,y);
	b_counter+=1;
	//b1->move("u");
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
