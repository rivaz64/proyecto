#pragma once
#include "personaje.h"
//class accion;
class shoot;
class jugador :
	public personaje
{
public:
	sf::RenderWindow* window;
	static vector<shoot*> balas;
	suelo* piso;
	//accion* actual;
	bool r = false, l = false, semueve = false, run = false, jump = false, fast = false,atakando = false,doubejump=true;
	int corre = 0, cor = 1;
	animator_manager caminar, correr, saltar,atacar;
	float ya = 1, vel = 110, next = 0, vely = 0;
	int textnum = 0;
	int uw;
	jugador(string,string);
	void update();
	void render();
	void salta();
	void cheka();
	//void set(accion*);
	bool atack;
	~jugador();
};

