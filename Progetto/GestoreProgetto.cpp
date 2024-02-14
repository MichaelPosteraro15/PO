#include "GestoreProgetto.h"

GestoreProgetto::GestoreProgetto(){}

bool GestoreProgetto::aggiungi_autore(string id, string no, string co, const list<string>& af){ 
	return GestoreAutori::aggiungi_autore(id, no, co, af); 
}

bool GestoreProgetto::aggiungi_conferenza(string no, string ac, Data da, string lu, const list<string>& og, unsigned pa){
    if(!GestoreRiviste::esistenza_rivista(no, ac, da)){
		return GestoreConferenze::aggiungi_conferenza(no, ac, da, lu, og, pa);
	}
	return false;
}

bool GestoreProgetto::aggiungi_rivista(string no, string ac, Data da, string ed, unsigned vo){
	if(!GestoreConferenze::esistenza_conferenza(no, ac, da)){
		return GestoreRiviste::aggiungi_rivista(no, ac, da, ed, vo);
	}
	return false;
}

bool GestoreProgetto::aggiungi_articolo(string id, string ti, unsigned np, const list<string>& au, const list<string>& kw, float pr, const list<string>& ar, MezzoDivulgativo* pu){
	list<Autore> nuovi_autori;

	for(auto autore: au){
		if(GestoreAutori::esistenza_autore(autore)){ 
		    Autore* nuovo_autore = get_autore(autore);
            nuovi_autori.push_back(*nuovo_autore);
        }
	}

    if(GestoreRiviste::esistenza_rivista(pu->get_nome(), pu->get_acronimo(), pu->get_data()) == true || GestoreConferenze::esistenza_conferenza(pu->get_nome(), pu->get_acronimo(), pu->get_data()) == true){
        return GestoreArticoli::aggiungi_articolo(id, ti, np, nuovi_autori, kw, pr, ar, pu);
    }

	return false;
}

list<Articolo> GestoreProgetto::articoli_autore(string id) const{
	list<Articolo> nuovi_articoli;
    if(GestoreAutori::esistenza_autore(id)){ return GestoreArticoli::articoli_autore(id); }

	return nuovi_articoli;
}

list<Articolo> GestoreProgetto::articoli_conferenza(string no, string ac, const Data& da){
    list<Articolo> nuovi_articoli;

	if(GestoreConferenze::esistenza_conferenza(no, ac, da)){ 
		return GestoreArticoli::articoli_mezzodivulgativo(no, ac, da);
	}

	return nuovi_articoli;
}

list<Articolo> GestoreProgetto::articoli_rivista(string no, string ac, const Data& da){
	list<Articolo> nuovi_articoli;

	if(GestoreRiviste::esistenza_rivista(no, ac, da)){ 
		return GestoreArticoli::articoli_mezzodivulgativo(no, ac, da);
	}

	return nuovi_articoli;
}

const list<Articolo> GestoreProgetto::articoli_prezzobasso_autore(string id) const{
    list<Articolo> nuovi_articoli;

	if(GestoreAutori::esistenza_autore(id)){
       nuovi_articoli = GestoreArticoli::articoli_prezzobasso_autore(id);
	}

	return nuovi_articoli;
}

const list<Articolo> GestoreProgetto::articoli_prezzoalto_autore(string id) const{
	list<Articolo> nuovi_articoli;

	if(GestoreAutori::esistenza_autore(id)){
       nuovi_articoli = GestoreArticoli::articoli_prezzoalto_autore(id);
	}
   
    return nuovi_articoli;
}

double GestoreProgetto::media_articoli_autore(string id) const{
	if(GestoreAutori::esistenza_autore(id)){
       return GestoreArticoli::media_articoli_autore(id);
	}

	return 0;
}

const list<Articolo> GestoreProgetto::articoli_conferenza_prezzo(string no, string ac, const Data& da) const{
    list<Articolo>  nuovi_articoli;

	if(GestoreConferenze::esistenza_conferenza(no, ac, da)){
       nuovi_articoli = GestoreArticoli::articoli_mezzodivulgativo_prezzo(no, ac, da);
	}

	return nuovi_articoli;
}

const list<Articolo> GestoreProgetto::articoli_rivista_prezzo(string no, string ac, const Data& da) const{
    list<Articolo>  nuovi_articoli;

	if(GestoreRiviste::esistenza_rivista(no, ac, da)){
       nuovi_articoli = GestoreArticoli::articoli_mezzodivulgativo_prezzo(no, ac, da);
	}

	return nuovi_articoli;
}

//SEZIONE E

bool rivista_presente(const list<MezzoDivulgativo*> riviste, string nome){
    for(auto rivista: riviste){
        if(rivista->get_nome() == nome){ return true; }
    }

    return false;
}

const list<MezzoDivulgativo*> GestoreProgetto::riviste_pubblicate_autore(string identificativo) const{
    list<MezzoDivulgativo*> riviste;

    for(auto articolo: GestoreArticoli::lista_articoli()){
        if(articolo.autore_presente(identificativo)){
            MezzoDivulgativo* rivista = articolo.get_pubblicato();
            if(GestoreRiviste::esistenza_rivista(rivista->get_nome(), rivista->get_acronimo(),rivista->get_data())){
                if(!rivista_presente(riviste, rivista->get_nome())){ riviste.push_back(rivista); }
            }
        }
    }

    return riviste;
}

const list<MezzoDivulgativo*> GestoreProgetto::riviste_nonpubblicate_autore(string identificativo) const{
    list<MezzoDivulgativo*> non_pubblicate;

    for(auto articolo: GestoreArticoli::lista_articoli()){
        MezzoDivulgativo* mezzo = articolo.get_pubblicato();
        if(!GestoreConferenze::esistenza_conferenza(mezzo->get_nome(), mezzo->get_acronimo(), mezzo->get_data())){
           if(!rivista_presente(riviste_pubblicate_autore(identificativo), mezzo->get_nome())){
              if(!rivista_presente(non_pubblicate, mezzo->get_nome())) { non_pubblicate.push_back(mezzo); }
           }
        }
    }

    return non_pubblicate;
}
