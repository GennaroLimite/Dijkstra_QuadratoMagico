#ifndef ARCO_H_INCLUDED
#define ARCO_H_INCLUDED
class Arco
{
    private:
        float Peso;
        int i_NodoAdiacente;

    public:
        Arco(float Peso, int i_NodoAdiacente);
        Arco();
        ~Arco();

        int getIndiceNodoAdj();
        float getPeso();
};
#endif // ARCO_H_INCLUDED

