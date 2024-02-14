#ifndef ARTICOLO_H
#define ARTICOLO_H

#include "Autore.h"
#include "MezzoDivulgativo.h"

class Articolo{

private:

	string identificativo;
	string titolo;
	unsigned pagine;
	list<Autore> autori;
	list<string> keywords;
	float prezzo;
	list<string> articoli_correlati;
	MezzoDivulgativo* pubblicato;//non so se é una conferenza o una rivista quindi vado ad allocare dinamicamente

public:

	Articolo();
	Articolo(string, string, unsigned, const list<Autore>&, const list<string>& , float, MezzoDivulgativo*);
	Articolo(string, string, unsigned, const list<Autore>&, const list<string>& , float, const list<string>&, MezzoDivulgativo*);

    string get_identificativo() const;
    string get_titolo() const;
    unsigned get_pagine() const;
    const list<Autore>& get_autori() const;
    const list<string>& get_keywords() const;
    float get_prezzo() const;
    const list<string>& get_articoli_correlati() const;
    MezzoDivulgativo* get_pubblicato() const;

    bool autore_presente(string);
    bool mezzodivulgativo_presente(string, string, const Data&);
   
    bool operator==(const Articolo&);
    friend ostream& operator<<(ostream&, const Articolo&);
};

#endif
