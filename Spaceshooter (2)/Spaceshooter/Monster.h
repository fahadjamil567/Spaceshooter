#include <SFML/Graphics.hpp>
#include <string.h>
#include "B-laser.h"
#include "Enemy.h"
// #include "game.h"
#ifndef Monster_H_
#define Monster_H_

using namespace sf;

class Monster : public Enemy
{

public:
// Texture tex;
// Sprite sprite;
// float speed=1;
bool colide=false;
float speed=0.5;
    Monster()
    {
        tex.loadFromFile("img/monster.png");
        sprite.setTexture(tex);
        sprite.setScale(0.25, 0.25);
        sprite.setPosition(180, 0);   
    }
    // void fire()
    // {
        // b1= new B_Laser();
    //     texFire.loadFromFile("img/PNG/Lasers/dragonfire.png");
    //     spriteFire.setTexture(texFire);
    //     spriteFire.setScale(0.6,2);        
    //     spriteFire.setPosition(sprite.getPosition().x+145, sprite.getPosition().y+375);
    // }
    void pos(float x, float y){
    sprite.setPosition(x,y);
}

    void fire(float a, float b)
    {
        // b1 = new B_Laser("img/PNG/Lasers/laserBlue07.png");
        // b1->Position(a, b);
        // b_counter += 1;
        // // b1->move("u");
    }
    void move(){
        
		sprite.setPosition(sprite.getPosition().x+speed,sprite.getPosition().y);
		spriteFire.setPosition(spriteFire.getPosition().x+speed,spriteFire.getPosition().y);
        if(sprite.getPosition().x>450 && colide==false ){
        speed=-0.5;
        colide=true;
        }
        else if(sprite.getPosition().x<0 && colide==true ){
        speed=0.5;
        colide=false;
        }
	}
    
    // void move(float n){
	// 	sprite.setPosition(sprite.getPosition().x-n,sprite.getPosition().y);
	// 	spriteFire.setPosition(spriteFire.getPosition().x-n,spriteFire.getPosition().y);
	// }

    // void pos(float x, float y)
    // {
    //     sprite.setPosition(x, y);
    // }
    float get_pos()
    {
        return sprite.getPosition().y;
    }
    
};
#endif
