#ifndef VERTICE_H_INCLUDED
#define VERTICE_H_INCLUDED
#include "Arco.h"
#include <vector>
#include <string>
#include <limits>

#define INFINITO std::numeric_limits<float>::max()

using namespace std;

class Vertice
{
    private:
        string NomeVertice;
        int Nadiacenti;
        float Stima;
        int i_Padre;
        vector<Arco> Adiacenti;

    public:
        Vertice(string NomeVertice, int Nadiacenti, vector<Arco> Adiacenti);
        Vertice();
        ~Vertice();

        string getNomeVertice();
        float getStima();
        void setStima(float Stima);
        int getNadj();
        Arco getAdj(int i);
        void setAdj(Arco Archetto);
        int getIndicePadre();
        void setIndicePadre(int Indice);
};
#endif // VERTICE_H_INCLUDED
