#ifndef GESTOREPROGETTO_H
#define GESTOREPROGETTO_H

#include "GestoreAutori.h"
#include "GestoreConferenze.h"
#include "GestoreRiviste.h"
#include "GestoreArticoli.h"

class GestoreProgetto: public GestoreAutori, public GestoreConferenze, public GestoreRiviste, public GestoreArticoli{

public:

	GestoreProgetto();

	//SEZIONE A
    
    bool aggiungi_autore(string, string, string, const list<string>&);
    bool aggiungi_conferenza(string, string, Data, string, const list<string>&, unsigned);
    bool aggiungi_rivista(string, string, Data, string, unsigned);
    bool aggiungi_articolo(string, string, unsigned, const list<string>&, const list<string>&, float, const list<string>&, MezzoDivulgativo*);

    //per la visualizzazione uso i getter list dei gestori
 
    //SEZIONE B

    list<Articolo> articoli_autore(string) const;
    list<Articolo> articoli_conferenza(string, string, const Data&);
    list<Articolo> articoli_rivista(string, string, const Data&);

    //SEZIONE C
    
    const list<Articolo> articoli_prezzobasso_autore(string) const;
    const list<Articolo> articoli_prezzoalto_autore(string) const;
    double media_articoli_autore(string) const;

    //SEZIONE D
    const list<Articolo> articoli_conferenza_prezzo(string, string, const Data&) const;
    const list<Articolo> articoli_rivista_prezzo(string, string, const Data&) const;

    //SEZIONE E
    const list<MezzoDivulgativo*> riviste_pubblicate_autore(string) const; //metodo ausiliare
    const list<MezzoDivulgativo*> riviste_nonpubblicate_autore(string) const;
    
};

#endif
