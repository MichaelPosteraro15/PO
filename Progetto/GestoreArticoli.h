#ifndef GESTOREARTICOLI_H
#define GESTOREARTICOLI_H

#include "Articolo.h"

class GestoreArticoli{

private:

	list<Articolo*> articoli;

public:
    
	GestoreArticoli();
    GestoreArticoli(const GestoreArticoli&);
    ~GestoreArticoli();
    GestoreArticoli& operator=(const GestoreArticoli&);

    bool esistenza_articolo(string) const;
    Articolo* get_articolo(string) const;
    list<Articolo> lista_articoli() const;
    void elimina_articoli();

    double prezzobasso_autore(string) const;
    double prezzoalto_autore(string) const;

    bool aggiungi_articolo(string, string, unsigned, const list<Autore>&, const list<string>&, float, const list<string>&, MezzoDivulgativo*);
    void visualizza_articoli() const;

    const list<Articolo> articoli_autore(string) const;
    const list<Articolo> articoli_mezzodivulgativo(string, string, const Data&) const;

    const list<Articolo> articoli_prezzobasso_autore(string) const;
	const list<Articolo> articoli_prezzoalto_autore(string) const;
    double media_articoli_autore(string) const;

    const list<Articolo> articoli_mezzodivulgativo_prezzo(string, string, const Data&) const;

};

#endif
