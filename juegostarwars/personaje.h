#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include<vector>
#include"animator_manager.h"
#include"deltaim.h"
#include"objeto.h"
#include"suelo.h"
using namespace std;
class personaje :public objeto
{
public:
	suelo* piso;
	bool r=false, l=false, semueve=false,run= false,jump=false;
	int corre = 0, cor = 1;
	animator_manager caminar, correr,saltar;
	float ya = 1, vel = 100,next=0,vely=0;
	int textnum = 0;
	int uw;
	deltaim time;
	personaje(string);
	void update();
	void render();
	void salta();
	void stop();
	~personaje();
};

