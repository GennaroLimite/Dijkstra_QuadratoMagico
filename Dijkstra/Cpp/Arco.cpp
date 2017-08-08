#include "../Include/Arco.h"

//Costruttore per default
Arco::Arco(){}

//Costruttore per argomenti
Arco::Arco(float Peso, int i_NodoAdiacente)
{
        this->Peso = Peso;
        this->i_NodoAdiacente = i_NodoAdiacente;
}

//Distruttore
Arco::~Arco(){}

//getIndiceNodoAdj()
int Arco::getIndiceNodoAdj()
{
    return this->i_NodoAdiacente;
}

//getPeso()
float Arco::getPeso()
{
    return this->Peso;
}
