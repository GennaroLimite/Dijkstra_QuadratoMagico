#include "../Include/QuadratoMagico.h"
//QuadratoMagico(int Lato, string NomeFile):Quadrato(Lato, NomeFile)
QuadratoMagico::QuadratoMagico(int Lato, string NomeFile):Quadrato(Lato, NomeFile)
{
    this->CicliBack = 0;
    this->SoluzioniContate = 0;
    this->CostanteMagica = (Lato*(Lato*Lato+1))/2;
}
//QuadratoMagico(int Lato):Quadrato(Lato)
QuadratoMagico::QuadratoMagico(int Lato):Quadrato(Lato)
{
    this->CicliBack = 0;
    this->SoluzioniContate = 0;
    this->CostanteMagica = (Lato*(Lato*Lato+1))/2;
}
//Costruttore di default
QuadratoMagico::QuadratoMagico():Quadrato()
{
    this->CicliBack = 0;
    this->SoluzioniContate = 0;
    this->CostanteMagica = 0;
}
//Distruttore
QuadratoMagico::~QuadratoMagico()
{
    this->InsiemeSoluzioni.clear();
}
//Risolvi(int Pos)
void QuadratoMagico::Risolvi(int Pos)
{
    int RispettoVincolo = VERO;
    if( getCella(Pos).getBloccato() == false)
    {
        for(int Val=1; Val<= getNxN() && RispettoVincolo != OVERFLOW; Val++)
        {
            if( getDoppioneVal(Val) == false )
            {
                setCellaVal(Pos, Val);
                setDoppioneVal(Val, true);
                RispettoVincolo = ControlloMagico(Pos);
                if(RispettoVincolo == VERO)
                {
                    if(Pos == getNxN()-1) AggiungiSoluzione();
                    else Risolvi(Pos+1);
                }
                setCellaVal(Pos, 0);
                setDoppioneVal(Val, false);
                this->CicliBack++;
            }
        }
    }

     else
    {
        if(Pos == getNxN()-1)  AggiungiSoluzione();
        else Risolvi(Pos+1);
    }
}
//ControllaVincoli(int i, int Fine, int Incremento)
int QuadratoMagico::ControllaVincoli(int i, int Fine, int Incremento)
{
    int Sum=0, Valore;
    bool FlagZero = false;
    for(; i<=Fine; i+=Incremento)
    {
        Valore = getCella(i).getValore();
        if(Valore == 0) FlagZero = true;
        Sum += Valore;
        if(Sum>this->CostanteMagica) return OVERFLOW;
    }
    if(Sum != this->CostanteMagica && FlagZero == false) return FALSO;
    return VERO;
}
//ControlloMagico(int Indice)
int QuadratoMagico::ControlloMagico(int Indice)
{
    int RispettoVincolo=VERO;
    int N=getN();
    int i=Indice/N;
    int j=Indice%N;
    int RigaInizio = i*N;
    int ColInizio  = j;
    int RigaFine   = RigaInizio+N-1;
    int ColFine    = ColInizio+N*(N-1);
    int DPInizio = 0;
    int DPFine   = N*N-1;
    int DSInizio = N-1;
    int DSFine   = N*(N-1);
    RispettoVincolo = ControllaVincoli(RigaInizio, RigaFine, 1);
    if( RispettoVincolo <= 0 ) return RispettoVincolo;
    RispettoVincolo = ControllaVincoli(ColInizio, ColFine, N);
    if( RispettoVincolo <= 0 ) return RispettoVincolo;
    if(i == j)
    {
        RispettoVincolo = ControllaVincoli(DPInizio, DPFine, N+1);
        if( RispettoVincolo <= 0 ) return RispettoVincolo;
    }
    if(i == N-1-j)
    {
        RispettoVincolo = ControllaVincoli(DSInizio, DSFine, N-1);
        if( RispettoVincolo <= 0 ) return RispettoVincolo;
    }
     return VERO;
}
//AvviaQuadratoMagico()
void QuadratoMagico::AvviaQuadratoMagico()
{
    this->Risolvi(0);
}
//AggiungiSoluzione()
void QuadratoMagico::AggiungiSoluzione()
{
    SoluzioniContate++;
    vector<int> Vect;
    for(int i=0; i<getNxN(); i++) Vect.push_back( getCella(i).getValore() );
    Soluzione OggettoSoluzione(SoluzioniContate, Vect, CicliBack);
    InsiemeSoluzioni.push_back(OggettoSoluzione);
    Vect.clear();
}
//StampaSoluzioni()
void QuadratoMagico::StampaSoluzioni()
{
    int N = getN();
    for(int k=0; k<getSoluzioniContate(); k++)
    {
        cout << "SOLUZIONE: "<<this->InsiemeSoluzioni[k].getIdSoluzione()<<endl;
        for(int i=0; i<N; i++)
        {   for(int j=0; j<N; j++)
                cout<<setw(4)<< this->InsiemeSoluzioni[k].getValoreCella(i*N+j);
            cout<<endl;
        }
        cout<<"Soluzione effettuata con "<< this->InsiemeSoluzioni[k].getCicliBack();
        cout<<" cicli di backtracking"<< endl<<endl;
    }
}
//getSoluzioniContate()
int QuadratoMagico::getSoluzioniContate()
{
    return SoluzioniContate;
}
