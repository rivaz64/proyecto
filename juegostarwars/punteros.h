#pragma once
#include <vector>
#include"suelo.h"
class punteros
{
	
public:
	static std::vector<objeto*> po;
	static std::vector<suelo*> ps;
	punteros();
	void push(objeto*);
	void push(suelo*);
	~punteros();
};

