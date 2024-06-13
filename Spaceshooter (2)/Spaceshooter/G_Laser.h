#include <SFML/Graphics.hpp>
#include<string.h>
//#include"Bullet.h"
#ifndef G_Laser_H_
#define G_Laser_H_
using namespace sf;

class G_Laser{
	
public:
Texture tex;
Sprite sprite;
float speed=1;
int x,y;
G_Laser()
{


tex.loadFromFile("img/PNG/Lasers/laserBlue08.png");
sprite.setTexture(tex);
x=sprite.getPosition().x; y=sprite.getPosition().y;
// x=200;y=400;

sprite.setScale(0.5,0.5);
}
void Position(double a, double b){
	a+=35;
	b-=40;
	sprite.setPosition(a,b);
}

float delta_y=0;
float delta_x=0;

//////////player Bullet move///////////
void move(){	
	delta_y=-3;
	sprite.move(0, delta_y);

}
//////////player tilted bullet move////
void move(string &s){
	// cout<<s<<endl;
	if(s=="R"){
		if(sprite.getPosition().x>780){
		s="L";
		}
		delta_x=1*speed;
	}
	if(s=="L"){
		if(sprite.getPosition().x<0){
		s="R";
		}
		delta_x=-1*speed;
	
	}
	delta_y=-1*speed;
	sprite.move(delta_x, delta_y);

}



float get_posy(){
	return sprite.getPosition().y;
	
}
float get_posx(){
	return sprite.getPosition().x;
	
}

};

#endif
