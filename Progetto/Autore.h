#ifndef AUTORE_H
#define AUTORE_H

#include <iostream>
#include <list>

using namespace std;

class Autore{

private:

	string identificativo;
	string nome;
	string cognome;
	list<string> afferenze;

public:

	Autore();
	Autore(string, string, string);
	Autore(string, string, string, const list<string>&);

    string get_identificativo() const;
	string get_nome() const;
	string get_cognome() const;
    const list<string>& get_afferenze() const;

    bool operator==(const Autore&) const;
    friend ostream& operator<<(ostream&, const Autore&); 
};

#endif