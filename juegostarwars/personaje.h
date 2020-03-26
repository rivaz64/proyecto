#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include<vector>
#include"animator_manager.h"
#include"deltaim.h"
#include"objeto.h"
#include"suelo.h"
#include<fstream>
#include <iostream>
using namespace std;
class personaje :public objeto
{
protected:
	sf::IntRect inrec(ifstream&);
	void llenar(ifstream&, vector<sf::IntRect>&);
public:
	int vida = 100, dir=1;
	float t = 2;
	virtual void update();
	virtual void morir() {}
	void dying();
	personaje(string,string);
	sf::IntRect normal;
	animator_manager muerto;
	bool vivo=true;
	~personaje();
	//friend std::istream &operator>> (std::istream&,vector<sf::IntRect>&);
};
std::istream & operator>>(std::istream &x, vector<sf::IntRect>&v);


