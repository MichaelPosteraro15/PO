#include "Articolo.h"

Articolo::Articolo(): identificativo(""), titolo(""), pagine(0),
                      prezzo(0), pubblicato(nullptr){}

Articolo::Articolo(string id, string ti, unsigned pa, const list<Autore>& au, 
	               const list<string>& kw, float pr, MezzoDivulgativo* pu){
	identificativo = id;
	titolo = ti;
	pagine = pa;
	autori = au;
	keywords = kw;
	prezzo = pr;
	pubblicato = pu;
}

Articolo::Articolo(string id, string ti, unsigned pa, const list<Autore>& au, 
	               const list<string>& kw, float pr, const list<string>& ar, MezzoDivulgativo* pu){
	identificativo = id;
	titolo = ti;
	pagine = pa;
	autori = au;
	keywords = kw;
	prezzo = pr;
	articoli_correlati = ar;
	pubblicato = pu;
}

string Articolo::get_identificativo() const{ return identificativo; }

string Articolo::get_titolo() const{ return titolo; }

unsigned Articolo::get_pagine() const{ return pagine; }

const list<Autore>& Articolo::get_autori() const{ return autori; }

const list<string>& Articolo::get_keywords() const{ return keywords; }

float Articolo::get_prezzo() const{ return prezzo; }

const list<string>& Articolo::get_articoli_correlati() const{ return articoli_correlati; }

MezzoDivulgativo* Articolo::get_pubblicato() const{ return pubblicato; }

bool Articolo::autore_presente(string id){
	for(auto autore: autori){
		if(autore.get_identificativo() == id){ return true; }
	}

	return false;
}

bool Articolo::mezzodivulgativo_presente(string no, string ac, const Data& da){
	MezzoDivulgativo nuovo_mezzo(no, ac, da);
	return nuovo_mezzo == *pubblicato;
}

bool Articolo::operator==(const Articolo& a){ return identificativo == a.identificativo; }

ostream& operator<<(ostream& o, const Articolo& a){
	o << "Identificativo: " << a.identificativo << endl;
	o << "Titolo: " << a.titolo << endl;
	o << "Pagine: " << a.pagine << endl;

	o << "Autori: " << endl;
    for(auto autore: a.autori){ o << autore.get_identificativo() << endl; }
 
    o << "Keywords: " << endl;
    for(auto keyword: a.keywords){ o << keyword << endl; }

    o << "Prezzo: " << a.prezzo << endl;

    o << "Articoli correlati: " << endl;
    for(auto articolo: a.articoli_correlati){ o << articolo << endl; }

    o << "Pubblicato per: "<< endl;
    o << (a.pubblicato)->get_nome() << endl;

    return o;
}



