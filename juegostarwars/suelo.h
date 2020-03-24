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
	bool solid = true;
	suelo *a, *d, *i,*v;
	//punteros pointers;
	void arribaizquierda(suelo*);
	void arribaderecha(suelo*);
	void abajoizquierda(suelo*);
	void abajoderecha(suelo*);
	~suelo();
};

