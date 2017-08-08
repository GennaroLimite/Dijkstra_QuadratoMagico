#ifndef QUADRATO_H_INCLUDED
#define QUADRATO_H_INCLUDED
#include "Cella.h"
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Quadrato
{
    private:
        vector<Cella> Mat;
        vector <bool> Doppione;
        int N;
        int NxN;
    public:
        Quadrato(int Lato, string NomeFile);
        Quadrato(int Lato);
        Quadrato();
        ~Quadrato();

        int getN();
        int getNxN();
        Cella getCella(int i);
        void setCellaVal(int i, int Elemento);
        bool getDoppioneVal(int Val);
        void setDoppioneVal(int Val, bool Booleano);

        void StampaMatriceCaricata();
};
#endif // QUADRATO_H_INCLUDED
