#include <SFML/Graphics.hpp>
#include <string.h>
#include "B-laser.h"
#include "Enemy.h"

using namespace sf;

class Dragon : public Enemy
{

public:
// Texture tex;
// Sprite sprite;
float speed=1;
    Dragon()
    {
        tex.loadFromFile("img/dragon1.png");
        sprite.setTexture(tex);
        sprite.setScale(1.7, 1.7);
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
    void move(){}

    // void pos(float x, float y)
    // {
    //     sprite.setPosition(x, y);
    // }
    float get_pos()
    {
        return sprite.getPosition().y;
    }
    
};
