#include "../Include/Vertice.h"
//Costruttore di default
Vertice::Vertice()
{
        this->NomeVertice = "";
        this->Nadiacenti = 0;
        this->Stima = INFINITO;
        this->i_Padre = -1;
}
//Costruttore per argomenti
Vertice::Vertice(string NomeVertice, int Nadiacenti, vector<Arco> Adiacenti)
{
        this->NomeVertice = NomeVertice;
        this->Nadiacenti = Nadiacenti;
        this->Adiacenti = Adiacenti;
        this->Stima = INFINITO;
        this->i_Padre = -1;
}
//Distruttore
Vertice::~Vertice()
{
    this->Adiacenti.clear();
}
//getNomeVertice()
string Vertice::getNomeVertice()
{
    return NomeVertice;
}
//getStima()
float Vertice::getStima()
{
    return Stima;
}
//setStima()
void Vertice::setStima(float Stima)
{
    this->Stima = Stima;
}
//getNadj()
int Vertice::getNadj()
{
    return Nadiacenti;
}
//getAdj()
Arco Vertice::getAdj(int i)
{
    return Adiacenti[i];
}
//setAdj()
void Vertice::setAdj(Arco Archetto)
{
    this->Adiacenti.push_back(Archetto);
}
//getIndicePadre()
int Vertice::getIndicePadre()
{
    return this->i_Padre;
}
//setIndicePadre()
void Vertice::setIndicePadre(int Indice)
{
    this->i_Padre = Indice;
}
