#ifndef Menu_H_
#define Menu_H_
#include "game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include<fstream>

class Menu{
public:

//add menu attributes here
Menu()
{
	//display menu screen here

// add functionality of all the menu options here
    sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	// error...
	}

    Sprite background; // Game background sprite
    Texture bg_texture;
    bg_texture.loadFromFile("img/background1.jpg");
    background.setTexture(bg_texture);
    background.setScale(0.7,1);
	// sf::Texture obj5;
    // 	obj5.loadFromFile("img/background.png");
	// sf::Sprite background(obj5);
    // sf::obj5.setScale(1.5, 1);
	
	
	sf::RenderWindow window(sf::VideoMode(780, 780), title);
	window.clear(sf::Color::Black);
    	
    sf::Clock clock;
    while (window.isOpen())
    {
    	bool f=0;
    	float time = clock.getElapsedTime().asSeconds();
    	//clock.restart();
    	window.draw(background);
    	//timer+=time;
   		sf::Event e;
    	while (window.pollEvent(e))
   		{                       //Event is occurring - until the game is in running state
    		if (e.type == sf::Event::Closed || f==1)//||end==1)
        	{ 
                window.close();
            }
        //   Opened window disposes
        	if (e.type == sf::Event::KeyPressed) 
        	{	
        		if (e.key.code == sf::Keyboard::S)
            	{  
                    window.close();
                    display_menu(); 
            	    // f=1;        								//Check if the other key pressed is UP key  
            	}
            
            	else if (e.key.code == sf::Keyboard::H)
            	{  
            	    Heighest_score();         								//Check if the other key pressed is UP key  
            	}
            	else if (e.key.code == sf::Keyboard::Q)
            	{  
            	    Instrustions();         								//Check if the other key pressed is UP key  
            	}
            	else if (e.key.code == sf::Keyboard::R)
            	{  
            	    f=1;         								//Check if the other key pressed is UP key  
            	}                      								//If any other key (not cross) is pressed
            
			}
		}
     	sf::Text text;
		text.setFont(font); 
		text.setPosition(55,110);	
		text.setString("PRESS 'S' TO START NEW GAME");
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(20,240);	
		text1.setString("PRESS 'H' TO SEE HEIGHEST SCORE");
		text1.setCharacterSize(40);
		text1.setFillColor(sf::Color::White);
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text2;
		text2.setFont(font); 
		text2.setPosition(80,370);	
		text2.setString("PRESS 'Q' For INSTRUCTIONS");
		text2.setCharacterSize(40);
		text2.setFillColor(sf::Color::White);
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(180,500);	
		text3.setString("PRESS 'R' TO EXIT");
		text3.setCharacterSize(40);
		text3.setFillColor(sf::Color::White);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		window.draw(text3);
		window.draw(text2);
		window.draw(text1);
		window.draw(text);
		//window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
  		 window.display();
	}
	


//constructors body
}
void Instrustions(){
    sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    // error...
	}
	 Sprite background; // Game background sprite
    Texture bg_texture;
    bg_texture.loadFromFile("img/background1.jpg");
    background.setTexture(bg_texture);
    background.setScale(0.7,1);
	
	sf::RenderWindow window(sf::VideoMode(780, 780), title);
	window.clear(sf::Color::Black);
    	
    sf::Clock clock;
    while (window.isOpen())
    {
    	bool f=0; 
    	float time = clock.getElapsedTime().asSeconds();
        //clock.restart();
        window.draw(background);
        //timer+=time;
    	sf::Event e;
        while (window.pollEvent(e))			//Event is occurring - until the game is in running state
        {                       
            if (e.type == sf::Event::Closed ||f==1)
            { 
				window.close();
            }                               				  //Opened window disposes
            if (e.type == sf::Event::KeyPressed) 
            {
            	if (e.key.code == sf::Keyboard::B)
                {  
                	f=1;        								//Check if the other key pressed is UP key  
                }
            }
		}	
     	sf::Text text;
		text.setFont(font); 
		text.setPosition(5,50);	
		text.setString("Fire to distroy enemy and defend moster and dragon");
		text.setCharacterSize(30);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(5,180);	
		text1.setString("YOUR GAME IS OVER WHEN yor lives are finished");
		text1.setCharacterSize(30);
		text1.setFillColor(sf::Color::White);
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text2;
		text2.setFont(font); 
		text2.setPosition(5,310);	
		text2.setString("WHEN all enemys are distroyed next level is called");
		text2.setCharacterSize(30);
		text2.setFillColor(sf::Color::White);
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(5,440);	
		text3.setString("PLAY AND ENJOY THE GAME AND SCORE HEIGH");
		text3.setCharacterSize(30);
		text3.setFillColor(sf::Color::White);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text4;
		text4.setFont(font); 
		text4.setPosition(5,570);	
		text4.setString("BEST OF LUCK!!!!!");
		text4.setCharacterSize(30);
		text4.setFillColor(sf::Color::White);
		text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text5;
		text5.setFont(font); 
		text5.setPosition(5,700);	
		text5.setString("PRESS 'B' FOR BACK");
		text5.setCharacterSize(30);
		text5.setFillColor(sf::Color::White);
		text5.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		window.draw(text5);
		window.draw(text4);
		window.draw(text3);
		window.draw(text2);
		window.draw(text1);
		window.draw(text);
		
        //---The Window that now Contains the Frame is Displayed---//
  		window.display();
	}
}

void display_menu()

{
    Game g; 
//if Start game option is chosen 
    
    g.start_game();
}
void Heighest_score(){
    int size=0,score2;	
	string s;								//data is read from file
	ifstream infile1("score.txt");				
	while(infile1>>s>>score2)
	{
		size++;									//lines calculated till end of file
	}
	infile1.close();
 	//how to read in arrays
 
	int score1[size];							//delaration of array
	string Name[size];							//delaration of array
 
	ifstream infile("score.txt");
	int index=0;
	while(infile>>Name[index]>>score1[index])				//scores are stored in array
	{
		//infile>>str>>score2;
		index++;
	}
	infile.close();
    int max=0,max1=0,max2=0,index1,index2,index3;
	for(int i=0;i<size;i++)
	{
		if(score1[i]>max){
			max=score1[i];
			index1=i;
        }
    }
    for(int i=0;i<size;i++)
	{
        if(score1[i]>max1 && score1[i]<max){
			max1=score1[i];
			index2=i;
        }
    }
    for(int i=0;i<size;i++)
	{
        if(score1[i]>max2 && score1[i]<max1){
			max2=score1[i];
			index3=i;
        }
	}
    // cout<<max<<endl;
	int a=0;
	a=max;
	string Name1=Name[index1],Name2=Name[index2],Name3=Name[index3];
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    // error...
	}
	sf::Texture obj4, obj5, obj6;
    	// obj4.loadFromFile("img/tiles.png");
    	obj5.loadFromFile("img/background.png");
    	// obj6.loadFromFile("img/frame.png");
	sf::Sprite sprite(obj4), background(obj5), frame(obj6);
	
	sf::RenderWindow window(sf::VideoMode(320, 480), title);
	window.clear(sf::Color::Black);
    	
    sf::Clock clock;
    while (window.isOpen())
    {
    	bool f=0; 
    	float time = clock.getElapsedTime().asSeconds();
        //clock.restart();
        window.draw(background);
        //timer+=time;
    	sf::Event e;
        while (window.pollEvent(e))			//Event is occurring - until the game is in running state
        {                       
            if (e.type == sf::Event::Closed ||f==1)
            { 
				window.close();
            }                               				  //Opened window disposes
            if (e.type == sf::Event::KeyPressed) 
            {
            	if (e.key.code == sf::Keyboard::B)
                {  
                	f=1;        								//Check if the other key pressed is UP key  
                }
            }
		}	
     	sf::Text text;
		text.setFont(font); 
		text.setPosition(180,180);	
		text.setString(std::to_string(a));
		text.setCharacterSize(25);
		text.setFillColor(sf::Color::Yellow);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);

		sf::Text tex6;
		tex6.setFont(font); 
		tex6.setPosition(80,180);	
		tex6.setString(Name1);
		tex6.setCharacterSize(25);
		tex6.setFillColor(sf::Color::Yellow);
		tex6.setStyle(sf::Text::Bold | sf::Text::Underlined);

		sf::Text tex7;
		tex7.setFont(font); 
		tex7.setPosition(80,230);	
		tex7.setString(Name2);
		tex7.setCharacterSize(25);
		tex7.setFillColor(sf::Color::Green);
		tex7.setStyle(sf::Text::Bold | sf::Text::Underlined);

		sf::Text tex8;
		tex8.setFont(font); 
		tex8.setPosition(80,280);	
		tex8.setString(Name3);
		tex8.setCharacterSize(25);
		tex8.setFillColor(sf::Color::Red);
		tex8.setStyle(sf::Text::Bold | sf::Text::Underlined);

        sf::Text text4;
		text4.setFont(font); 
		text4.setPosition(180,230);	
		text4.setString(std::to_string(max1));
		text4.setCharacterSize(25);
		text4.setFillColor(sf::Color::Green);
		text4.setStyle(sf::Text::Bold | sf::Text::Underlined);

        sf::Text text5;
		text5.setFont(font); 
		text5.setPosition(180,280);	
		text5.setString(std::to_string(max2));
		text5.setCharacterSize(25);
		text5.setFillColor(sf::Color::Red);
		text5.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text2;
		text2.setFont(font); 
		text2.setPosition(10,350);	
		text2.setString("PRESS B TO RETURN");
		text2.setCharacterSize(20);
		text2.setFillColor(sf::Color::White);
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(5,100);	
		text3.setString("HEIGHEST SCORE");
		text3.setCharacterSize(30);
		text3.setFillColor(sf::Color::White);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);

		sf::Text text9;
		text9.setFont(font); 
		text9.setPosition(5,180);	
		text9.setString("1st");
		text9.setCharacterSize(25);
		text9.setFillColor(sf::Color::Yellow);
		text9.setStyle(sf::Text::Bold | sf::Text::Underlined);

		sf::Text text10;
		text10.setFont(font); 
		text10.setPosition(5,230);	
		text10.setString("2nd");
		text10.setCharacterSize(25);
		text10.setFillColor(sf::Color::Green);
		text10.setStyle(sf::Text::Bold | sf::Text::Underlined);

		sf::Text text11;
		text11.setFont(font); 
		text11.setPosition(5,280);	
		text11.setString("3rd");
		text11.setCharacterSize(25);
		text11.setFillColor(sf::Color::Red);
		text11.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
        window.draw(text4);
		window.draw(text5);
		window.draw(text3);
		window.draw(text2);
		window.draw(text9);
		window.draw(text10);
		window.draw(text11);
		// window.draw(text1);
		window.draw(text);
		window.draw(tex6);
		window.draw(tex7);
		window.draw(tex8);
		
        //---The Window that now Contains the Frame is Displayed---//
  		window.display();
	}
}
// void display_pausemenu()
// {
//     sf::Font font;
// 		if (!font.loadFromFile("arial.ttf"))
// 		{
//     	// error...
// 		}
// 	sf::Texture obj4, obj5, obj6;
//     	// obj4.loadFromFile("img/tiles.png");
//     	obj5.loadFromFile("img/background.png");
//     	// obj6.loadFromFile("img/frame.png");
// 	sf::Sprite sprite(obj4), background(obj5), frame(obj6);
	
	
// 	sf::RenderWindow window(sf::VideoMode(320, 480), title);
// 	window.clear(sf::Color::Black);
    	
//     	sf::Clock clock;
//     while (window.isOpen()){
//     	bool a=0,b=0,c=0,d=0,f=0; 
//     	  float time = clock.getElapsedTime().asSeconds();
//         //clock.restart();
//         window.draw(background);
//         //timer+=time;
//     	  sf::Event e;
//         while (window.pollEvent(e)){                       //Event is occurring - until the game is in running state
//             if (e.type == sf::Event::Closed || f==1)// end==1)
//                 { 
//                 	window.close();
//                 }
//                                            				  //Opened window disposes
//             if (e.type == sf::Event::KeyPressed) {
//             	if (e.key.code == sf::Keyboard::C)
//                 {  
//                 	f=1;         								//Check if the other key pressed is UP key  
//                 }
                
//                 // else if (e.key.code == sf::Keyboard::H)
//                 // {  
//                 // 	Heighest_score(score2,size);        								//Check if the other key pressed is UP key  
//                 // }
//                 // else if (e.key.code == sf::Keyboard::Q)
//                 // {  
//                 // 	Help();         								//Check if the other key pressed is UP key  
//                 // }
//                 // else if (e.key.code == sf::Keyboard::R)
//                 // {  
//                 // 	end=1;
//                 //       								//Check if the other key pressed is UP key  
//                 // }                      								//If any other key (not cross) is pressed
            
//             }
//             }
		
// 		sf::Text text1;
// 		text1.setFont(font); 
// 		text1.setPosition(5,140);	
// 		text1.setString("PRESS 'H' TO SEE HEIGHEST SCORE");
// 		text1.setCharacterSize(15);
// 		text1.setFillColor(sf::Color::White);
// 		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
// 		sf::Text text2;
// 		text2.setFont(font); 
// 		text2.setPosition(5,170);	
// 		text2.setString("PRESS 'Q' TO HELP");
// 		text2.setCharacterSize(15);
// 		text2.setFillColor(sf::Color::White);
// 		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		
// 		sf::Text text3;
// 		text3.setFont(font); 
// 		text3.setPosition(5,200);	
// 		text3.setString("PRESS 'R' TO EXIT");
// 		text3.setCharacterSize(15);
// 		text3.setFillColor(sf::Color::White);
// 		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
// 		sf::Text text4;
// 		text4.setFont(font); 
// 		text4.setPosition(5,230);	
// 		text4.setString("PRESS 'C' TO CONTINUE");
// 		text4.setCharacterSize(15);
// 		text4.setFillColor(sf::Color::White);
// 		text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
// 		window.draw(text4);
// 		window.draw(text3);
// 		window.draw(text2);
// 		window.draw(text1);
		
		
//         //---The Window that now Contains the Frame is Displayed---//
//   	window.display();
// 	}
// }


};
#endif