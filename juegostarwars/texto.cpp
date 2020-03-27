#include "texto.h"



texto::texto():objeto("letras.png")
{
	setFillColor(sf::Color(255, 255, 255));
}

void texto::draw(sf::RenderWindow &window)
{
	for (int a = 0; a<kedice.size();a++) {
		if (kedice[a] != ' ') {
			//cout << a * 25 << " " << ((int(kedice[a]) - 97) * 25) << endl;
			setPosition({ (float)((float)posi.x + a * getSize().x),(float)posi.y });
			setTextureRect({ (int)((int(kedice[a]) - 97)*15.9f ),0,16,18 });
			window.draw(*this);
		}
		
	}
}


texto::~texto()
{
}
