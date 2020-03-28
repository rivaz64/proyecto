#pragma once
#include"jugador.h"
#include"deltaim.h"
#include<fstream>
#include"suelo.h"
#include"punteros.h"
#include"enemy.h"
#include"shoot.h"
#include"nivel.h"
#include "texto.h"
class game
{
public:
	nivel *level;
	texto nuevo;
	texto carga;
	//enemy* t;
	deltaim time;
	void setear(int);
	sf::RectangleShape prueba;
	fstream file;
	bool charge = false;
	//vector < sf::Vector2f > map,enemys;
	//sf::Vector2f posipiso;
	bool Left=false, Right=false,Up=false,Down=false,shift = false,space=false,enter=false, cntrlz =false, enterp = false, cntrlzp = false,A=false;
	//deltaim time;
	sf::RenderWindow window;
	jugador player;
	objeto final;
	int nnivel = 1;
	//enemy troop;
	//objeto* cual;
	sf::Time tiempo;
	objeto fondo;
	//objeto fondo0;
	objeto piso;
	//suelo *p, *an;
	punteros pointers;
	objeto ini;
	game();
	void setea();
	void edit();
	void run();
	void events();
	void input(sf::Keyboard::Key key, bool isPressed);
	void menu();
	void update();
	void render();
	void loadata(string,vector < sf::Vector2f >&);
	void savedata(string, vector < sf::Vector2f >&);
	~game();
};

