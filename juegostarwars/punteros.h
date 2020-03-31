#pragma once
#include <vector>
#include"suelo.h"
class punteros
{
	
public:
	static std::vector<enemy*> po;
	static std::vector<suelo*> ps;
	punteros();
	void push(enemy*);
	void push(suelo*);
	static void deletear();
	~punteros();
};

