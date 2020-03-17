#pragma once
#include "objeto.h"
#include<string>
#include<iostream>
using namespace std;
class suelo 
{
public:
	suelo();
	suelo(int,int);
	suelo(const suelo&);
	int abajo = 10000;
	int derecha= 10000;
	int izquierda= -100;
	int arriva= -100;
	bool solid = true;
	suelo *a, *d, *i,*v;
	void arribaizquierda(suelo*);
	void arribaderecha(suelo*);
	void abajoizquierda(suelo*);
	void abajoderecha(suelo*);
	~suelo();
};

