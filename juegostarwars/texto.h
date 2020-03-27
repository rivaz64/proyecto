#pragma once
#include "objeto.h"
class texto :
	public objeto
{
public:
	string kedice ;
	sf::Vector2i posi;
	texto();
	void draw(sf::RenderWindow&);
	~texto();
};

