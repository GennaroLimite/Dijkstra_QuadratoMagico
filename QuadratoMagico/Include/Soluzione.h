#ifndef SOLUZIONE_H_INCLUDED
#define SOLUZIONE_H_INCLUDED
#include "Quadrato.h"
class Soluzione
{
    private:
        int  IdSoluzione;
        vector<int> SoluzQuadrato;
        int CicliBack;

    public:
        Soluzione(int Id, vector<int> MatRisolta, int Cicli);
        Soluzione();
        ~Soluzione();

        int getIdSoluzione();
        int getValoreCella(int i);
        int getCicliBack();
};


#endif // SOLUZIONE_H_INCLUDED
