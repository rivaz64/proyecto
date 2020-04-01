#include "texto.h"



texto::texto():objeto("letras.png")
{
	setFillColor(sf::Color(255, 255, 255));
}

void texto::draw(sf::RenderWindow &window)
{
	//dibuja cada letra
	for (int a = 0; a<kedice.size();a++) {
		if (kedice[a] != ' ') {
			setPosition({ (float)((float)posi.x + a * getSize().x),(float)posi.y });
			setTextureRect({ (int)((int(kedice[a]) - 97)*15.9f ),0,16,18 });
			window.draw(*this);
		}
		
	}
}


texto::~texto()
{
}
