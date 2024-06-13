#ifndef Game_H_
#define Game_H_
#include <SFML/Graphics.hpp>
#include <fstream>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "Alpha.h"
#include "Beta.h"
#include "Gama.h"
#include "Dragon.h"
#include "Monster.h"
#include "powerup.h"
#include "menu.h"

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
    int level = 1;
    Sprite background; // Game background sprite
    Texture bg_texture;
    Player *p; // player
    // add other game attributes
    // Menu *m;
    Enemy *E1[15];
    Enemy *D, *M;
    Powerup *Fire, *life, *Danger,*Pow;
    string tilt;
    bool Epresent[15] = {true};
    bool Epresent_temp[15] = {true};
    bool present[15] = {false};
    float Enemy_timer[15] = {0, 1.2, 3.5, 2.34, 0.4, 5.6, 4.45, 2.3, 1.9, 1.3, 2.2, 1.09, 4.5, 3.1, 0.7}, t_timer = 0, F_timer = 0, PF_timer = 0, PL_timer = 0, PD_timer = 0,P_timer = 0, MonsFiretime = 0, dragtime = 0,P_T=0;
    ;
    bool dragon_present = false, Monster_present = false, tiltedfireR = false, tiltedfireL = false, FireP = false, PowerFire = false, PowerLife = false, PowerDanger = false,Power = false,PowerTaken = false, MonsFire = false;
    ;
    int lev = 1, score = 0;

    bool fired = false, change = false, end = false;
    bool player = true;
    // bool s=true;

    Game()
    {
        p = new Player();
        bg_texture.loadFromFile("img/background_1.png");
        background.setTexture(bg_texture);
        background.setScale(1.5, 1);
    }
    void start_game()
    {
        E1[0] = new Alpha(100, 100,level);
        E1[1] = new Beta(250, 100,level);
        E1[2] = new Gama(400, 100,level);
        E1[3] = new Alpha(550, 100,level);
        E1[4] = new Beta(100, 200,level);
        E1[5] = new Gama(550, 200,level);
        E1[6] = new Alpha(100, 300,level);
        E1[7] = new Beta(250, 300,level);
        E1[8] = new Alpha(400, 300,level);
        E1[9] = new Alpha(550, 300,level);
        E1[10] = new Alpha(550, 300,level);
        E1[11] = new Alpha(550, 300,level);
        Fire = new Powerup("img/PNG/Power-ups/bold_silver.png");
        life = new Powerup("img/PNG/Power-ups/pill_blue.png");
        Danger = new Powerup("img/PNG/Power-ups/powerupRed_bolt.png");
        Pow = new Powerup("img/PNG/Power-ups/shield_gold.png");

        for (int i = 0; i < 10; i++)
        {
            Epresent[i] = true;
        }
        srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);
        Clock clock;
        float timer = 0, Monster_timer = 0, MTime = rand() % 10, DTime = rand() % 10;
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            bool img = true;
            // cout<<time<<endl;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed || end == 1 || p->lives<1)
                {                                        // If cross/close is clicked/pressed
                    fstream file("score.txt", ios::app); // appanding data in file
                    int score2 = score;
                    string s="Fahad";
                    cin>>s;
                    file << s<<" "<<score2 << endl;
                    file.close();
                    window.close(); // close the game
                    p->gameover(score);
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::P))
            { // If left key is pressed

                p->display_pausemenu(end);
            }
            if (Keyboard::isKeyPressed(Keyboard::Left))  // If left key is pressed
                p->move("l");                            // Player will move to left&&p==true ){
                                                         // fired=false;
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
                p->move("r");                            // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up))    // If up key is pressed
            {
                p->move("u");
                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    img = false;
                    if (!img)
                        p->setTiltedpng(1);
                    if (fired == false)
                    {
                        if (Keyboard::isKeyPressed(Keyboard::Space)) // If left key is pressed
                        {
                            p->fire();
                            fired = true;
                            tiltedfireR = true;
                            tilt = "R";
                        }
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    img = false;
                    if (!img)
                        p->setTiltedpng(2);
                    if (fired == false)
                    {
                        if (Keyboard::isKeyPressed(Keyboard::Space)) // If left key is pressed
                        {
                            p->fire();
                            fired = true;
                            tiltedfireL = true;
                            tilt = "L";
                        }
                    }
                }
                // img = true;
            }
            if (img)
                p->setorignal();

            // playet will move upwards
            if (Keyboard::isKeyPressed(Keyboard::Down))
            {                 // If down key is pressed
                p->move("d"); // player will move downwards
                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    img = false;
                    if (!img)
                    {
                        p->setTiltedpng(2);
                        if (fired == false)
                        {
                            if (Keyboard::isKeyPressed(Keyboard::Space)) // If left key is pressed
                            {
                                //  cout<<"XD"<<endl;
                                p->fire();
                                fired = true;
                                tiltedfireL = true;
                                tilt = "L";
                            }
                        }
                    }
                }
                else if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    img = false;
                    if (!img)
                        p->setTiltedpng(1);
                    if (fired == false)
                    {
                        //  cout<<"XD"<<endl;
                        if (Keyboard::isKeyPressed(Keyboard::C)) // If left key is pressed
                        {
                            // cout<<"XD"<<endl;
                            p->fire();
                            fired = true;
                            tiltedfireR = true;
                            tilt = "R";
                        }
                    }
                }
                // img = true;
            }
            if (img)
            {
                p->setorignal();
                if (fired == false)
                {
                    tiltedfireR = 0;
                    tiltedfireL = 0;
                }
            }
            if (fired == false)
            {
                if (Keyboard::isKeyPressed(Keyboard::Space)) // If left key is pressed
                {
                    p->fire();
                    fired = true;
                }
            }

            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            //////////////////////////////////////////////

            ////////////////PowerUps////////////////////
            ///////////////////////////////////////////

            ////////////////FIre/////////////////////
            if (timer - PF_timer > 20)
            {
                delete Fire;
                Fire = new Powerup("img/PNG/Power-ups/bold_silver.png");
                PF_timer = rand() % 10 + timer + 20;
                // cout<<PF_timer<<endl;
                PowerFire = true;
                F_timer = 0;
            }
            F_timer += time;
            if (PowerFire)
            {
                // cout<<F_timer <<endl;
                Fire->move();
                if (p->sprite.getPosition().x >= Fire->sprite.getPosition().x - 70 && p->sprite.getPosition().x <= Fire->sprite.getPosition().x + 10 && p->sprite.getPosition().y >= Fire->sprite.getPosition().y && p->sprite.getPosition().y <= Fire->sprite.getPosition().y + 20)
                {
                    FireP = true;
                    F_timer = 0;
                    fired = true;
                    PowerFire = false;
                    // cout<<"jhdw\n";
                }
            }
            if (F_timer >= 5)
            {
                FireP = false;
            }
            //////////////////Lives///////////////////////////
            if (timer - PL_timer > 10)
            {
                delete life;
                life = new Powerup("img/PNG/Power-ups/pill_blue.png");
                PL_timer = rand() % 10 + timer + 20;
                // cout<<PF_timer<<endl;
                PowerLife = true;
            }
            if (PowerLife)
            {
                life->move();
                if (p->sprite.getPosition().x >= life->sprite.getPosition().x - 70 && p->sprite.getPosition().x <= life->sprite.getPosition().x + 10 && p->sprite.getPosition().y >= life->sprite.getPosition().y && p->sprite.getPosition().y <= life->sprite.getPosition().y + 20)
                {
                    p->lives++;
                    PowerLife = false;
                }
                if (life->sprite.getPosition().y > 778)
                    PowerLife = false;
            }
            ////////////////////Danger///////////////////////
            if (timer - PD_timer > 11)
            {
                delete Danger;
                Danger = new Powerup("img/PNG/Power-ups/powerupRed_bolt.png");
                PD_timer = rand() % 10 + timer + 20;
                // cout<<PF_timer<<endl;
                PowerDanger = true;
            }
            if (PowerDanger)
            {
                Danger->move();
                if (p->sprite.getPosition().x >= Danger->sprite.getPosition().x - 70 && p->sprite.getPosition().x <= Danger->sprite.getPosition().x + 10 && p->sprite.getPosition().y >= Danger->sprite.getPosition().y && p->sprite.getPosition().y <= Danger->sprite.getPosition().y + 20)
                {
                    p->lives--;
                    PowerDanger = false;
                }
                if (Danger->sprite.getPosition().y > 778)
                {
                    PowerDanger = false;
                    score += 5;
                }
            }
            ////////////////////PowerUp///////////////////////
            if (timer - P_timer > 30)
            {
                delete Pow;
                Pow = new Powerup("img/PNG/Power-ups/shield_gold.png");
                P_timer = rand() % 10 + timer + 20;
                // cout<<PF_timer<<endl;
                Power = true;
                P_T = 0;
            }
            P_T += time;
            
            if (Power)
            {
                Pow->move();
                if (p->sprite.getPosition().x >= Pow->sprite.getPosition().x - 70 && p->sprite.getPosition().x <= Pow->sprite.getPosition().x + 10 && p->sprite.getPosition().y >= Pow->sprite.getPosition().y && p->sprite.getPosition().y <= Pow->sprite.getPosition().y + 20)
                {
                    // p->lives--;
                    Power = false;
                    PowerTaken = true;
                    P_T = 0;
                }
                // if (Pow->sprite.getPosition().y > 778)
                // {
                //     Power = false;
                // }
            }
            if (P_T >= 5)
            {
                PowerTaken = false;
            }

            ///////////////Dragon////////////////////////

            if (timer - DTime >= 100 && dragon_present == false && Monster_present == false)
            {
                 for (int i = 0; i < 15; i++)
                {
                    Epresent_temp[i] = Epresent[i];
                    Epresent[i] = false;
                    present[i]=false;
                }
                t_timer += time;
                cout<<t_timer<<endl;
                if (t_timer > 1.7)
                {
                    t_timer = 0;
                DTime = rand() % 10 + timer + 40;
                dragon_present = true;
                D = new Dragon();
                D->fireDragon(); //"C");

               
                }
            }

            if (dragon_present)
            {
                dragtime += time;
                if (p->sprite.getPosition().x < 180)
                {
                    D->texFire.loadFromFile("img/PNG/Lasers/dragFireL.png");
                    D->spriteFire.setScale(3.2, 3.2);
                    D->spriteFire.setPosition(D->sprite.getPosition().x - 230, D->sprite.getPosition().y + 355);
                    if (p->sprite.getPosition().x >= D->spriteFire.getPosition().x  && p->sprite.getPosition().x <= D->spriteFire.getPosition().x + 120)
                    {
                        p->lives--;
                        p->sprite.setPosition(210, 700);
                    }

                    // D->fireDragon();//"L");
                }
                else if (p->sprite.getPosition().x < 500)
                {
                    D->texFire.loadFromFile("img/PNG/Lasers/dragFire1.png");
                    D->spriteFire.setScale(2, 2);
                    D->spriteFire.setPosition(D->sprite.getPosition().x + 130, D->sprite.getPosition().y + 375);
                    // D->fireDragon();//"C");
                    if (p->sprite.getPosition().x >= D->spriteFire.getPosition().x - 78 && p->sprite.getPosition().x <= D->spriteFire.getPosition().x + 120)
                    {
                        // cout<<"JKd\n";
                        p->lives--;
                        p->sprite.setPosition(210, 700);
                    }
                }
                else if (p->sprite.getPosition().x > 500)
                {
                    D->texFire.loadFromFile("img/PNG/Lasers/dragFireR.png");
                    D->spriteFire.setScale(3.3, 3.3);
                    D->spriteFire.setPosition(D->sprite.getPosition().x + 150, D->sprite.getPosition().y + 340);
                    // D->fireDragon();//"R");
                    if (p->sprite.getPosition().x >= 600 && p->sprite.getPosition().x <=780)
                    {
                        p->lives--;
                        p->sprite.setPosition(500, 700);
                    }
                }
            }
            if (dragtime >= 5)
            {
                score += 50;
                dragon_present = false;
                dragtime = 0;

                for (int i = 0; i < 15; i++)
                {
                    Epresent[i] = Epresent_temp[i];
                }
            }

            //////////////Monster//////////////////////
            if (timer - MTime >= 40 && Monster_present == false && dragon_present == false)
            {
                for (int i = 0; i < 15; i++)
                {
                    Epresent_temp[i] = Epresent[i];
                    present[i] = false;
                    Epresent[i] = false;
                }
                t_timer += time;
                if (t_timer > 1.7)
                {
                    t_timer = 0;
                MonsFiretime = Monster_timer;
                MTime = rand() % 10 + timer + 30;
                // cout<<MTime<<endl;90
                Monster_present = true;
                M = new Monster();
                M->fireMonster();
                }
            }
            if (Monster_present)
            {

                Monster_timer += time;
                // MonsFiretime+=time;
                M->move();
                if (Monster_timer - MonsFiretime > 2)
                {
                    MonsFire = true;
                    // MonsFiretime+=time;
                }
                if (Monster_timer - MonsFiretime > 3)
                {
                    MonsFire = false;
                    MonsFiretime = Monster_timer;
                }
                if (M->spriteFire.getPosition().x + 30 >= p->sprite.getPosition().x - 50 && M->spriteFire.getPosition().x + 30 <= p->sprite.getPosition().x + 70 && MonsFire == true)
                {
                    p->lives--;
                    p->sprite.setPosition(680, 700);
                }
                if (p->sprite.getPosition().x >= M->sprite.getPosition().x - 70 && p->sprite.getPosition().x <= M->sprite.getPosition().x + 330 && p->sprite.getPosition().y >= M->sprite.getPosition().y && p->sprite.getPosition().y + 50 <= M->sprite.getPosition().y + 400)
                {
                    p->lives--;
                    p->sprite.setPosition(680, 700);
                }
            }
            if (Monster_timer >= 20)
            {
                score += 40;
                Monster_present = false;
                Monster_timer = 0;

                for (int i = 0; i < 15; i++)
                {
                    // cout<<endl<<Epresent_temp[i];
                    Epresent[i] = Epresent_temp[i];
                }
            }
            // cout<<Monster_timer<<endl;

            //////////////////////functions/////////////
            for (int i = 0; i < 12; i++)
            {
                Epresent[i] = p->playercollide(E1[i], Epresent[i],PowerTaken);

                if (present[i] == true)
                {
                    p->playerdistroy(E1[i]->b1, Epresent[i], present[i],PowerTaken);
                }

                if (fired == true)
                {
                    Epresent[i] = p->enemydistroy(E1[i], fired, Epresent[i], score);
                    if (FireP == true)
                        fired = true;
                }

                if (Epresent[i])
                {
                    if (timer - Enemy_timer[i] >= E1[i]->t)
                    {
                        Enemy_timer[i] = timer;
                        E1[i]->fire(E1[i]->sprite.getPosition().x + 8, E1[i]->sprite.getPosition().y + 88);
                        present[i] = true;
                    }
                }
                if (present[i] == true)
                {
                    E1[i]->move();
                }
            }
            if (fired == true)
            {
                if (tiltedfireR)
                {
                    p->moveBullet(tilt);
                }
                else if (tiltedfireL)
                {
                    p->moveBullet(tilt);
                }
                else
                    p->moveBullet();
                if (p->b1->sprite.getPosition().y <= -5)
                    fired = false;
            }

            //////////////////////////////////////////////////////
            /////////////////////////////////////////////////////
            bool found = false;
            for (int i = 0; i < 15; i++)
            {
                if (Epresent[i] == true)
                {
                    found = true;
                }
            }
            ////////////////////////////////////////////////////////
            //////////////////////level 1///////////////////////////
            ////////////////////////////////////////////////////////

            /////////////////////Phase 2////////////////////////////
            if (found == false && lev == 1 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    t_timer = 0;

                    E1[0]->pos(75, 100);
                    E1[1]->pos(250, 100);
                    E1[2]->pos(425, 100);
                    E1[3]->pos(600, 100);
                    E1[4]->pos(164, 200);
                    E1[5]->pos(337, 200);
                    E1[6]->pos(512, 200);
                    E1[7]->pos(250, 300);
                    E1[8]->pos(337, 400);
                    E1[9]->pos(424, 300);

                    for (int i = 0; i < 10; i++)
                    {
                        Epresent[i] = true;
                    }
                    Epresent[5] = false;
                    lev = 2;
                    found = true;
                    for (int i = 0; i < 15; i++)
                    {
                        Enemy_timer[i] = Enemy_timer[i] += time;
                    }
                }
            }
            /////////////////////Phase 3////////////////////////////
            if (found == false && lev == 2 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    t_timer = 0;
                    E1[0]->pos(150, 00);
                    E1[1]->pos(250, 100);
                    E1[2]->pos(350, 200);
                    E1[3]->pos(450, 300);
                    E1[4]->pos(550, 400);
                    E1[5]->pos(550, 00);
                    E1[6]->pos(450, 100);
                    E1[7]->pos(250, 300);
                    E1[8]->pos(150, 400);

                    for (int i = 0; i < 9; i++)
                    {
                        Epresent[i] = true;
                    }
                    lev = 3;
                    found = true;
                    for (int i = 0; i < 15; i++)
                    {
                        Enemy_timer[i] = Enemy_timer[i] += time;
                    }
                }
            }
            
            ////////////////////////////////////////////////////////
            //////////////////////level 2///////////////////////////
            ////////////////////////////////////////////////////////

            if (found == false && lev == 3 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    level=2;
                    t_timer = 0;
                    for (int i = 0; i < 12; i++)
                    {
                        delete E1[i];
                        E1[i] = NULL;
                    }
                    lev = 4;
                    // if(lev==3){
                    E1[0] = new Alpha(285, 30,level);
                    E1[1] = new Beta(445, 30,level);
                    E1[2] = new Gama(155, 140,level);
                    E1[3] = new Alpha(575, 140,level);
                    E1[4] = new Beta(155, 310,level);
                    E1[5] = new Gama(285, 440,level);
                    E1[6] = new Alpha(445, 440,level);
                    E1[7] = new Beta(575, 310,level);
                    E1[8] = new Gama(125, 225,level);
                    E1[9] = new Alpha(605, 225,level);
                    E1[10] = new Gama(125, 225,level);
                    E1[11] = new Alpha(605, 225,level);

                    for (int i = 0; i < 10; i++)
                    {
                        Epresent[i] = true;
                        present[i] = false;
                    }
                    present[11]=false;
                    present[12]=false;
                    fired = false;
                    found = true;
                }
                for (int i = 0; i < 15; i++)
                {
                    Enemy_timer[i] = Enemy_timer[i] += time;
                }
            }
            /////////////////////Phase 2////////////////////////////

            if (found == false && lev == 4 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    t_timer = 0;
                    E1[0]->pos(350, 20);
                    E1[1]->pos(245, 90);
                    E1[2]->pos(450, 100);
                    E1[3]->pos(160, 180);
                    E1[4]->pos(560, 180);
                    E1[5]->pos(220, 290);
                    E1[6]->pos(500, 290);
                    E1[7]->pos(360, 500);
                    E1[8]->pos(300, 400);
                    E1[9]->pos(420, 400);
                    E1[10]->pos(15, 300);
                    E1[11]->pos(15, 600);

                    for (int i = 0; i < 10; i++)
                    {
                        Epresent[i] = true;
                    }
                    lev = 5;
                    found = true;
                }
                for (int i = 0; i < 15; i++)
                {
                    Enemy_timer[i] = Enemy_timer[i] += time;
                }
            }
            /////////////////////Phase 3////////////////////////////
            if (found == false && lev == 5 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    t_timer = 0;
                    E1[0]->pos(360, 120);
                    E1[1]->pos(460, 50);
                    E1[2]->pos(560, 100);
                    E1[3]->pos(500, 200);
                    E1[4]->pos(360, 430);
                    E1[5]->pos(260, 50);
                    E1[6]->pos(160, 100);
                    E1[7]->pos(220, 200);
                    E1[8]->pos(300, 300);
                    E1[9]->pos(420, 300);

                    for (int i = 0; i < 10; i++)
                    {
                        Epresent[i] = true;
                    }
                    lev = 6;
                    found = true;
                }
                for (int i = 0; i < 15; i++)
                {
                    Enemy_timer[i] = Enemy_timer[i] += time;
                }
            }
            ////////////////////////////////////////////////////////
            /////////////////////level 3///////////////////////////
            //////////////////////////////////////////////////////
             if (found == false && lev == 6 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    level=3;
                    t_timer = 0;
                    for (int i = 0; i < 12; i++)
                    {
                        delete E1[i];
                        E1[i] = NULL;
                    }
                    lev ++;
                    // if(lev==3){
                    E1[0] = new Gama(351, 30,level);
                    E1[1] = new Beta(101, 270,level);
                    E1[2] = new Gama(620, 270,level);
                    E1[3] = new Alpha(151, 100,level);
                    E1[4] = new Beta(571, 100,level);
                    E1[5] = new Gama(381, 480,level);
                    E1[6] = new Alpha(151, 400,level);
                    E1[7] = new Beta(551, 400,level);
                    E1[8] = new Gama(371, 140,level);
                    E1[9] = new Alpha(241, 260,level);
                    E1[10] = new Gama(491, 260,level);
                    E1[11] = new Gama(351, 360,level);

                    for (int i = 0; i < 12; i++)
                    {
                        Epresent[i] = true;
                        present[i] = false;
                    }
                    fired = false;
                    found = true;
                }
                for (int i = 0; i < 15; i++)
                {
                    Enemy_timer[i] = Enemy_timer[i] += time;
                }
            }


            //////////////Phase2/////////////////////////////
            if (found == false && lev == 7 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    t_timer = 0;

                    E1[0]->pos(350, 30);
                    E1[1]->pos(380, 500);
                    E1[2]->pos(101, 270);
                    E1[3]->pos(620, 270);
                    E1[4]->pos(240, 270);
                    E1[5]->pos(490, 270);
                    E1[6]->pos(240, 140);
                    E1[7]->pos(490, 140);
                    E1[8]->pos(490, 375);
                    E1[9]->pos(240, 375);
                    E1[10]->pos(350, 375);
                    E1[11]->pos(350, 140);

                    for (int i = 0; i < 12; i++)
                    {
                        Epresent[i] = true;
                    }
                    lev = 8;
                    found = true;
                    for (int i = 0; i < 15; i++)
                    {
                        Enemy_timer[i] = Enemy_timer[i] += time;
                    }
                }
            }

            //////////////Phase3/////////////////////////////
            if (found == false && lev == 8 && dragon_present == false && Monster_present == false && dragon_present == false)
            {
                t_timer += time;
                if (t_timer > 1.7)
                {
                    t_timer = 0;

                    E1[0]->pos(100, 220);
                    E1[1]->pos(140, 50);
                    E1[2]->pos(170, 350);
                    E1[3]->pos(360, 100);
                    E1[4]->pos(370, 450);
                    E1[5]->pos(630, 220);
                    E1[6]->pos(600, 50);
                    E1[7]->pos(550, 350);
                    E1[8]->pos(240, 180);
                    E1[9]->pos(490, 180);
                    E1[10]->pos(370, 330);
                    E1[11]->pos(370, 240);

                    for (int i = 0; i < 11; i++)
                    {
                        Epresent[i] = true;
                        present[i]=false;
                    }
                    lev = 9;
                    found = true;
                    for (int i = 0; i < 15; i++)
                    {
                        Enemy_timer[i] = Enemy_timer[i] += time;
                    }
                }
            }
            ///////////////////////////////////

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background
            if (p->lives > 0)
            {
                // s=false;
                window.draw(p->sprite); // setting player on screen
            }
            // if (lev==1){
            if (fired == true)
            {
                window.draw(p->b1->sprite);
            }
            for (int i = 0; i < 12; i++)
            {
                if (Epresent[i] == true)
                {
                    window.draw(E1[i]->sprite);
                }
                if (present[i] == true)
                {
                    window.draw(E1[i]->b1->sprite);
                }
            }
            if (dragon_present == true)
            {
                window.draw(D->spriteFire);
                window.draw(D->sprite);
            }
            if (Monster_present == true)
            {
                if (MonsFire)
                {
                    window.draw(M->spriteFire);
                }
                window.draw(M->sprite);
            }
            if (PowerFire)
                window.draw(Fire->sprite);
            if (PowerLife)
                window.draw(life->sprite);
            if (PowerDanger)
                window.draw(Danger->sprite);
            if (Power)
                window.draw(Pow->sprite);
            ////////////////////////////////////////////////
            sf::Font font;
            if (!font.loadFromFile("arial.ttf"))
            {
                // error...
            }
            sf::Text text;
            text.setFont(font);
            text.setPosition(110, 720);
            text.setString(std::to_string(score));
            text.setCharacterSize(25);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);

            sf::Text text4;
            text4.setFont(font);
            text4.setPosition(700, 20);
            text4.setString(std::to_string(p->lives));
            text4.setCharacterSize(25);
            text4.setFillColor(sf::Color::Red);
            text4.setStyle(sf::Text::Bold | sf::Text::Underlined);

            sf::Text text3;
            text3.setFont(font);
            text3.setPosition(700, 720);
            text3.setString(std::to_string(level));
            text3.setCharacterSize(25);
            text3.setFillColor(sf::Color::Red);
            text3.setStyle(sf::Text::Bold | sf::Text::Underlined);

            sf::Text text5;
            text5.setFont(font);
            text5.setPosition(600, 20);
            text5.setString("Lives");
            text5.setCharacterSize(25);
            text5.setFillColor(sf::Color::White);
            text5.setStyle(sf::Text::Bold | sf::Text::Underlined);

            sf::Text text2;
            text2.setFont(font);
            text2.setPosition(20, 720);
            text2.setString("Score:");
            text2.setCharacterSize(25);
            text2.setFillColor(sf::Color::White);
            text2.setStyle(sf::Text::Bold | sf::Text::Underlined);

            sf::Text text1;
            text1.setFont(font);
            text1.setPosition(620, 720);
            text1.setString("Level:");
            text1.setCharacterSize(25);
            text1.setFillColor(sf::Color::White);
            text1.setStyle(sf::Text::Bold | sf::Text::Underlined);

            window.draw(text);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(text4);
            window.draw(text5);

            window.display(); // Displying all the sprites
        }
    }
};
#endif
