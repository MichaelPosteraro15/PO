#include "MezzoDivulgativo.h"

MezzoDivulgativo::MezzoDivulgativo(): nome(""), acronimo(""), data(0, 0, 0){}

MezzoDivulgativo::MezzoDivulgativo(string no, string ac, const Data& da){
	nome = no;
	acronimo = ac;
	data = da;
}

MezzoDivulgativo::~MezzoDivulgativo(){}

string MezzoDivulgativo::get_nome() const{ return nome; }

string MezzoDivulgativo::get_acronimo() const{ return acronimo; }

Data MezzoDivulgativo::get_data() const{ return data; }

bool MezzoDivulgativo::operator==(const MezzoDivulgativo& m){
	return (nome == m.nome) && (acronimo == m.acronimo) && (data == m.data);
}

ostream& MezzoDivulgativo::stampa(ostream& o) const{
	o << "Nome: " << nome << endl;
	o << "Acronimo: " << acronimo << endl;
    o << "Data: " << data << endl;

    return o;
}

ostream& operator<<(ostream& o, const MezzoDivulgativo& m){ return m.stampa(o); }
