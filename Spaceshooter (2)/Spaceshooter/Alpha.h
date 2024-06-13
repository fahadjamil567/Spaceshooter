#include <SFML/Graphics.hpp>
#include<string.h>
// #include"Dragon.h"
// #include "B-laser.h"
#include "Invader.h"

#ifndef Alpha_H_
#define Alpha_H_

using namespace sf;

class Alpha:public Invader{

	
public:
	// Dragon d1;
	

Alpha(float x,float y,int a) : Invader("img/enemy_1.png",0.75,0.75)
{
	sprite.setPosition(x,y);
	t=5;
	points=10;
	l=a;
}

void move(){
	b1->moveAlpha(l);
}

void fire(float x,float y){
	// cout<<"jdwjk"<<endl;
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
