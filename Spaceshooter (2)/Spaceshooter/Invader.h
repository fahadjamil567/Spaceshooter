#include <SFML/Graphics.hpp>
#include<string.h>
// #include"Dragon.h"
#include "B-laser.h"
#include "Enemy.h"

#ifndef Invader_H_
#define Invader_H_

using namespace sf;

class Invader:public Enemy{

	
public:
	// Dragon d1;
	
Invader(){}
Invader(string s,float a,float b) : Enemy(s,a,b) {}
void fire(){}
void move(){}


virtual void pos(float x, float){}
virtual float get_pos()=0;
virtual float get_posx()=0;



};
#endif
