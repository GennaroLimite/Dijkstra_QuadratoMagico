#ifndef QUADRATOMAGICO_H_INCLUDED
#define QUADRATOMAGICO_H_INCLUDED
#include "Quadrato.h"
#include "Soluzione.h"
#define FALSO     -1
#define OVERFLOW   0
#define VERO       1

class QuadratoMagico: public Quadrato
{
    private:
        vector<Soluzione> InsiemeSoluzioni;
        int SoluzioniContate;
        int CicliBack;
        int CostanteMagica;

        void Risolvi(int Indice);
        int ControlloMagico(int Indice);
        int ControllaVincoli(int i, int Fine, int Incremento);
        void AggiungiSoluzione();

    public:
        QuadratoMagico(int Lato, string NomeFile);
        QuadratoMagico(int Lato);
        QuadratoMagico();
        ~QuadratoMagico();

        void AvviaQuadratoMagico();
        void StampaSoluzioni();
        int getSoluzioniContate();
};


#endif // QUADRATOMAGICO_H_INCLUDED
