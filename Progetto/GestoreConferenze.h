#ifndef GESTORECONFERENZE_H
#define GESTORECONFERENZE_H

#include "Conferenza.h"

class GestoreConferenze{
	
private:

	list<Conferenza*> conferenze;

public:

	GestoreConferenze();
    GestoreConferenze(const GestoreConferenze&);
    ~GestoreConferenze();
    GestoreConferenze& operator=(const GestoreConferenze&);

    bool esistenza_conferenza(string, string, const Data&) const;
    Conferenza* get_conferenza(string, string, const Data&) const;
    list<Conferenza> lista_conferenze() const;
    void elimina_conferenze();

    bool aggiungi_conferenza(string, string, const Data&, string, const list<string>&, unsigned);
    void visualizza_conferenze() const;

};

#endif
