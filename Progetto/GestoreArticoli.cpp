#include "GestoreArticoli.h"
#include "Autore.h"
#include <climits>

GestoreArticoli::GestoreArticoli(){}

GestoreArticoli::GestoreArticoli(const GestoreArticoli& g){
    for(auto articolo: g.articoli){
		Articolo* nuovo_articolo = new Articolo(articolo->get_identificativo(), articolo->get_titolo(),
		                                        articolo->get_pagine(), articolo->get_autori(),
			                                    articolo->get_keywords(), articolo->get_prezzo(), 
			                                    articolo->get_articoli_correlati(), articolo->get_pubblicato());
        articoli.push_back(nuovo_articolo);
	}
}

GestoreArticoli::~GestoreArticoli(){ elimina_articoli(); }

GestoreArticoli& GestoreArticoli::operator=(const GestoreArticoli& g){
	if(this == &g){
        elimina_articoli();

		for(auto articolo: articoli){
		    Articolo* nuovo_articolo = new Articolo(articolo->get_identificativo(), articolo->get_titolo(), 
		    	                                    articolo->get_pagine(), articolo->get_autori(),
			                                        articolo->get_keywords(), articolo->get_prezzo(), 
			                                        articolo->get_articoli_correlati(), articolo->get_pubblicato());
            articoli.push_back(nuovo_articolo);
	    }
	}
    return *this;
}

bool GestoreArticoli::esistenza_articolo(string id) const{
	for(auto articolo: articoli){
		if(articolo->get_identificativo() == id){ return true; }
	}
    return false;
}

Articolo* GestoreArticoli::get_articolo(string id) const{
	for(auto articolo: articoli){
        if(articolo->get_identificativo() == id){ return articolo; }
	} 
    return nullptr;
}

list<Articolo> GestoreArticoli::lista_articoli() const{ 
	list<Articolo> nuovi_articoli;
    for(auto articolo: articoli){ nuovi_articoli.push_back(*articolo); }

	return nuovi_articoli; 
}

void GestoreArticoli::elimina_articoli(){
    for(auto articolo: articoli){ delete articolo->get_pubblicato(); delete articolo; }
	articoli.clear();
}

bool GestoreArticoli::aggiungi_articolo(string id, string ti, unsigned np, const list<Autore>& au, const list<string>& kw, float pr, const list<string>& ar, MezzoDivulgativo* me){
	if(!esistenza_articolo(id)){ 
	    list<string> nuovi_articoli;

	    for(auto a: ar){ 
	        Articolo* nuovo_articolo = get_articolo(a);
	        if(nuovo_articolo != nullptr){ nuovi_articoli.push_back(nuovo_articolo->get_identificativo()); }
	    }

        MezzoDivulgativo* pu = new MezzoDivulgativo(me->get_nome(), me->get_acronimo(), me->get_data());

	    articoli.push_back(new Articolo(id, ti, np, au, kw, pr, nuovi_articoli, pu)); 
	    return true;
	}

	return false;
}

void GestoreArticoli::visualizza_articoli() const{
    for(auto articolo: articoli){
    	cout << *articolo << endl;
    }
}

const list<Articolo> GestoreArticoli::articoli_autore(string id) const{
    list<Articolo> nuovi_articoli;

	for(auto articolo: articoli){
        if(articolo->autore_presente(id)){ nuovi_articoli.push_back(*articolo); }
	}

	return nuovi_articoli; 
}

const list<Articolo> GestoreArticoli::articoli_mezzodivulgativo(string no, string ac, const Data& da) const{
	list<Articolo> nuovi_articoli;

	for(auto articolo: articoli){
        if(articolo->mezzodivulgativo_presente(no, ac, da)){ nuovi_articoli.push_back(*articolo); }
	}

	return nuovi_articoli;
}

double GestoreArticoli::prezzobasso_autore(string id) const{
	double prezzo_basso = INT_MAX;

	for(auto articolo: articoli){
		if(articolo->autore_presente(id)){
		   if(articolo->get_prezzo() < prezzo_basso){ prezzo_basso = articolo->get_prezzo(); }
	    }
	}

    return prezzo_basso;
}

const list<Articolo> GestoreArticoli::articoli_prezzobasso_autore(string id) const{
    list<Articolo> nuovi_articoli;
    double prezzo_basso = prezzobasso_autore(id);
    
    for(auto articolo: articoli){
    	if(articolo->autore_presente(id)){
	    	if(articolo->get_prezzo() == prezzo_basso){ nuovi_articoli.push_back(*articolo); }
        }
    }

    return nuovi_articoli;
}

double GestoreArticoli::prezzoalto_autore(string id) const{
	double prezzo_alto = INT_MIN;

	for(auto articolo: articoli){
		if(articolo->autore_presente(id)){
		   if(articolo->get_prezzo() > prezzo_alto){ prezzo_alto = articolo->get_prezzo(); }
		}
	}

    return prezzo_alto;
}

const list<Articolo> GestoreArticoli::articoli_prezzoalto_autore(string id) const{
    list<Articolo> nuovi_articoli;
    double prezzo_alto = prezzoalto_autore(id);
    
    for(auto articolo: articoli){
    	if(articolo->autore_presente(id)){
	    	if(articolo->get_prezzo() == prezzo_alto){ nuovi_articoli.push_back(*articolo); }
        }
    }

    return nuovi_articoli;
}

double GestoreArticoli::media_articoli_autore(string id) const{
	double somma = 0;
	unsigned quanti = 0;

    for(auto articolo: articoli){
    	if(articolo->autore_presente(id)){ somma += articolo->get_prezzo(); quanti++; }
    }

    return (somma/quanti);
}

bool ordina_prezzo(Articolo& a1, Articolo& a2){ return a1.get_prezzo() < a2.get_prezzo(); }

const list<Articolo> GestoreArticoli::articoli_mezzodivulgativo_prezzo(string no, string ac, const Data& da) const{
 	list<Articolo> nuovi_articoli = articoli_mezzodivulgativo(no, ac, da);
 	nuovi_articoli.sort(ordina_prezzo);

 	return nuovi_articoli;
}

