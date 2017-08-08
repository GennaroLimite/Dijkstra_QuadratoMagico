#include "../Include/Quadrato.h"
//Costruttori per paramenti
//Quadrato(int Lato, string NomeFile)
Quadrato::Quadrato(int Lato, string NomeFile)
{
    this->N = Lato;
    this->NxN = Lato*Lato;
    this->Mat.resize(NxN);
    for(int i=0; i<NxN; i++)
        Doppione.push_back(false);
    ifstream  Qf;
    string Testo;
    Qf.open(NomeFile.c_str(), ios::in);
    if(Qf)
    {
        int Estratto;
        for(int i=0; getline(Qf, Testo, ';'); i++)
        {
            if(Testo == "_") Estratto = 0;
            else istringstream(Testo)>>Estratto;
            if(Estratto>=1 && Estratto<=getNxN())
            {
                this->Mat[i].setValore(Estratto);
                this->Mat[i].setBloccato(true);
                this->Doppione[Estratto-1] = true;
            }
        }
    }
    else cout<<"Errore nell'apertura del file!"<<endl;
    Qf.close();
}
//Quadrato(int Lato)
Quadrato::Quadrato(int Lato)
{
    this->N = Lato;
    this->NxN = Lato*Lato;
    this->Mat.resize(NxN);
    for(int i=0; i<NxN; i++)
        this->Doppione.push_back(false);
}
//Costruttore per default
Quadrato::Quadrato()
{
    this->N = 0;
    this->NxN = 0;
}
//Distruttore
Quadrato::~Quadrato()
{
   this->Doppione.clear();
   this->Mat.clear();
}
//StampaMatriceCaricata()
void Quadrato::StampaMatriceCaricata()
{
    for(int i=0; i<N; i++)
    {   for(int j=0; j<N; j++)
            cout<<setw(5)<<this->Mat[i*N+j].getValore();
        cout<<endl;
    }
}
//getDoppioneVal(int Val)
bool Quadrato::getDoppioneVal(int Val)
{
    return this->Doppione[Val-1];
}
//setDoppioneVal(int Val, bool Boolean)
void Quadrato::setDoppioneVal(int Val, bool Boolean)
{
    this->Doppione[Val-1] = Boolean;
}
//getCella(int i)
Cella Quadrato::getCella(int i)
{
    return this->Mat[i];
}
//setCellaVal(int i, int Elemento)
void Quadrato::setCellaVal(int i, int Elemento)
{
    this->Mat[i].setValore(Elemento);
}
//getN()
int Quadrato::getN()
{
    return this->N;
}
//getN()
int Quadrato::getNxN()
{
    return this->NxN;
}
