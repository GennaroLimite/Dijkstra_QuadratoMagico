#include "../Include/Soluzione.h"

//Soluzione(int Id, vector<int> MatRisolta, int Cicli)
Soluzione::Soluzione(int Id, vector<int> MatRisolta, int Cicli)
{
    this->IdSoluzione = Id;
    this->SoluzQuadrato = MatRisolta;
    this->CicliBack = Cicli;
}

//Costruttore per default
Soluzione::Soluzione(){}

//Distruttore
Soluzione::~Soluzione()
{
    this->SoluzQuadrato.clear();
}

//getIdSoluzione()
int Soluzione::getIdSoluzione()
{
    return this->IdSoluzione;
}

//getValoreCella(int i)
int Soluzione::getValoreCella(int i)
{
    return this->SoluzQuadrato[i];
}

//getCicliBack()
int Soluzione::getCicliBack()
{
    return this->CicliBack;
}
