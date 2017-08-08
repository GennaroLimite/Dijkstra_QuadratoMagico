#ifndef CELLA_H_INCLUDED
#define CELLA_H_INCLUDED
class Cella
{
    private:
        int  Valore;
        bool Bloccato;

    public:
        Cella();
        ~Cella();

        int getValore();
        bool getBloccato();
        void setValore(int Elem);
        void setBloccato(bool Bloccato);

};


#endif // CELLA_H_INCLUDED
