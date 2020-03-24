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
	personaje(string,string);
	sf::IntRect normal;
	~personaje();
	//friend std::istream &operator>> (std::istream&,vector<sf::IntRect>&);
};


