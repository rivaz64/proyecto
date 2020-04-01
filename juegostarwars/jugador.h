#pragma once
#include "personaje.h"
//class accion;
class shoot;
class jugador :
	public personaje
{
public:
	bool next;
	void salir();
	sf::RenderWindow* window;
	static vector<shoot*> balas;
	suelo* piso;
	void morir();
	//accion* actual;
	bool r = false, l = false, semueve = false, run = false, jump = false, fast = false,atakando = false,doubejump=true,rebote=false,perdio = false,restart = false;
	int corre = 0, cor = 1;
	animator_manager caminar, correr, saltar,atacar;
	float ya = 1, vel = 110, vely = 0;
	int textnum = 0;
	int uw;
	jugador(string,string);
	void update();
	void render();
	void salta();
	std::vector < sf::Vector2f >* map;
	//void set(accion*);
	bool atack;
	~jugador();
};

