#pragma once
#include"SFML/Graphics.hpp"
#include<vector>
#include"deltaim.h"
#include<string>
#include<fstream>
#include"algoritmo.h"
#include"suelo.h"
#include"punteros.h"
#include"jugador.h"
#include "enemy.h"
#include<iostream>
using namespace std;
class nivel
{
public:
	jugador* player;
	enemy* t;
	std::vector < sf::Vector2f > map, enemys;
	deltaim time;
	suelo *p, *an;
	punteros pointers;
	sf::RenderWindow * window;
	objeto* fondo;
	//objeto *fondo0;
	int num;
	void acomodapiso();
	void guardado();
	objeto* piso;
	objeto* cual;
	sf::Vector2f posipiso;
	void init(int);
	nivel();
	void loadata(string, vector < sf::Vector2f >&);
	void update();
	void edit();
	void render();
	void savedata(string, vector < sf::Vector2f >&);
	~nivel();
};

