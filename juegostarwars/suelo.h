#pragma once
#include "objeto.h"
#include<string>
#include<iostream>
//#include"punteros.h"
using namespace std;
class punteros;
class suelo 
{
public:
	suelo();
	suelo(int,int);
	int abajo = 10000;
	int derecha= 10000;
	int izquierda= -100;
	int arriva= -100;
	bool solid = true,salida=false;
	suelo *a, *d, *i,*v;
	~suelo();
};

