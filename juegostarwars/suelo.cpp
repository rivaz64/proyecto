#include "suelo.h"
#include"punteros.h"
//inizializa un suelo sin fondo
suelo::suelo() {
	solid = false;
}
//inicialisa un suelo con fondo
suelo::suelo(int iz,int de)
{
	izquierda = iz;
	derecha = de;
	d = new suelo();
	punteros::ps.push_back(d);
	d->i = this;
	d->izquierda = derecha;
	i = new suelo();
	punteros::ps.push_back(i);
	i->d = this;
	i->derecha = izquierda;
	a = new suelo();
	punteros::ps.push_back(a);
	a->v = this;
	a->derecha = derecha;
	a->izquierda = izquierda;
	v = new suelo();
	punteros::ps.push_back(v);
	v->a = this;
	v->derecha = derecha;
	v->izquierda = izquierda;
	
}



suelo::~suelo()
{
}
