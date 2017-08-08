#include "../Include/Cella.h"
//Costruttore di default
Cella::Cella()
{
    this->Valore=0;
    this->Bloccato=false;
}
//Distruttore
Cella::~Cella(){}
//getValore()
int  Cella::getValore()
{
    return this->Valore;
}
//getBloccato()
bool Cella::getBloccato()
{
    return this->Bloccato;
}
//setValore(int Elem)
void Cella::setValore(int Elem)
{
    this->Valore=Elem;
}
//setBloccato(bool Bloccato)
void Cella::setBloccato(bool Bloccato)
{
    this->Bloccato=Bloccato;
}
