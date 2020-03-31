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
	/*p->d = new suelo();
	p->d->solid = false;
	p->d->i = p;
	p->i = new suelo();
	p->i->solid = false;
	p->i->d = p;
	p->a = new suelo();
	p->a->solid = false;
	p->a->v = p;
	p->v = new suelo();
	p->v->solid = false;
	p->v->a = p;*/
}
//une un suelo con otro que esta arriva a la izquierda
void suelo::arribaizquierda(suelo *otro)
{
	/*if (a->d)
	otro->d->d= a->d;*/
	if (otro->v->i&&otro->v->i->abajo < abajo) {
		otro->v->i->arribaderecha(this);
		otro = new suelo(otro->izquierda, otro->derecha);
		arribaizquierda(otro);
		return;
	}
	a = otro->d;
	a->v = this;
	if (otro->v->abajo > v->abajo || otro->v->abajo > i->abajo) {
		i = otro->v;
		i->d = this;
	}
	if (d->a) {
		a->d = d->a;
	}
	otro->v->d = this;
	i = otro->v;
	if (i->v) {
		v->i = i->v;
		v->i->d = v;
	}

	
	arriva = otro->abajo;
	a->abajo = arriva;
	i->arriva = arriva;
	a->d = d;
	/*otro->v = i;
	i->i = otro->i->v;
	i->d = v;
	arriva = otro->abajo;
	a->abajo = arriva;
	i->arriva = arriva;
	a->i = otro;*/
}
//une un suelo con otro que esta arriva a la derecha
void suelo::arribaderecha(suelo *otro)
{
	/*if (a->i) {
		otro->i->i = a->i;
		otro->i->i->d = a;
	}*/
	if (a->i&& a->i->solid&&a->i->abajo > otro->abajo) {
		a->i->arribaderecha(otro);
		//a->i->d = a;
		return;
	}
	otro->i = a;
	a->d = otro;
	if (d->v) {
		otro->v = d;
		otro->v->a = otro;
	}
	else {
		otro->v->i = this;
		d = otro->v;
	}
	
	arriva = otro->abajo;
	a->abajo = arriva;
	d->arriva = arriva;
	a->i = i;
	/*a->i = d->a;
	a->i->solid = false;*/
	/*
	a = otro->i;
	a->v = this;
	otro->v->i = this;
	//otro->i->v = this;
	otro->v = d;
	//d->i = v;
	arriva = otro->abajo;
	a->abajo = arriva;
	d->arriva = arriva;
	otro->v->a = otro;
	//d = otro->v;*/
}
//une un suelo con otro que esta abajo a la izquierda
void suelo::abajoizquierda(suelo *otro)
{
	otro->arribaderecha(this);
}
//une un suelo con otro que esta abajo a la derecha
void suelo::abajoderecha(suelo *otro)
{
	otro->arribaizquierda(this);
}

void suelo::subir(suelo *& x)
{
	/*lis[a]->arriva = p->abajo;
	lis[a] = lis[a]->a;
	lis[a]->a = new suelo();
	lis[a]->a->abajo = p->abajo;
	lis[a]->a->derecha = lis[a]->derecha;
	lis[a]->a->izquierda = lis[a]->izquierda;*/
}

suelo::~suelo()
{
}
