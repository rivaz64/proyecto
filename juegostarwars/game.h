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
	texto ganaste;
	//enemy* t;
	deltaim time;
	void setear(int);
	sf::RectangleShape prueba;
	fstream file;
	bool charge = false;
	sf::RenderWindow window;
	jugador player;
	objeto final;
	int nnivel = 1;
	//enemy troop;
	sf::Time tiempo;
	objeto fondo;
	objeto piso;
	objeto ini;
	game();
	void run();
	void events();
	void input(sf::Keyboard::Key key, bool isPressed);
	void update();
	void render();
	~game();
};

