#ifndef GESTORERIVISTE_H
#define GESTORERIVISTE_H

#include "Rivista.h"
#include <list>

class GestoreRiviste{
	
private:

	list<Rivista*> riviste;

public:

	GestoreRiviste();
    GestoreRiviste(const GestoreRiviste&);
    ~GestoreRiviste();
    GestoreRiviste& operator=(const GestoreRiviste&);

    bool esistenza_rivista(string, string, const Data&) const;
    Rivista* get_rivista(string, string, const Data&) const;
    Rivista* get_rivista(string) const;
    list<Rivista> lista_riviste() const;
    void elimina_riviste();

    bool aggiungi_rivista(string, string, const Data&, string, unsigned);
    void visualizza_riviste() const;

};

#endif
