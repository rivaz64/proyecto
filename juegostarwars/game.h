#pragma once
#include"personaje.h"
#include"deltaim.h"
#include<fstream>
#include"suelo.h"
class game
{
public:
	fstream mapa;
	vector < sf::Vector2f > map;
	sf::Vector2f posipiso;
	bool Left=false, Right=false,Up=false,Down=false,shift = false,space=false,enter=false, cntrlz =false, enterp = false, cntrlzp = false;
	deltaim time;
	sf::RenderWindow window;
	personaje player;
	sf::Time tiempo;
	objeto fondo;
	objeto piso;
	suelo *p, *an;
	game();
	void editinit();
	void edit();
	void run();
	void events();
	void input(sf::Keyboard::Key key, bool isPressed);
	void update();
	void render();
	~game();
};

