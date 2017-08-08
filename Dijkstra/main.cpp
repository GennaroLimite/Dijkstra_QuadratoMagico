#include "Include/Vertice.h"
#include "Include/Arco.h"
#include "Include/Grafo.h"
#include "Include/header.h"
using namespace std;
int main()
{
    char Scelta;
    Grafo OggettoGrafo;
    cout<<"  1] - Carica da Input                             "<<endl;
    cout<<"  2] - Carica da file un esempio didattico         "<<endl;
    cout<<"  3] - Carica da file l'esempio del problema reale "<<endl;
    do
    {
         cout<<endl<<"Inserire scelta:"<<endl;
         fflush(stdin);Scelta = getchar();fflush(stdin);
         switch(Scelta)
         {
            case '1':   int Nvertici;
                        do
                        {
                            cout<<"Inserire il numero di nodi del grafo"<<endl;
                            cin>>Nvertici;
                            fflush(stdin);
                        }while(Nvertici<0);
                        OggettoGrafo = Grafo(Nvertici, CreaGrafo(Nvertici) );
                        break;
            case '2':   OggettoGrafo = Grafo("ExDidattico.dij");
                        break;
            case '3':   OggettoGrafo = Grafo("ExUnderground.dij");
                        break;
            default: cout<<"La scelta non e' valida."<<endl;
                        break;
         }
     }while(Scelta!='1'&&Scelta!='2'&&Scelta!='3');
    cout<<endl<<"Stampa del grafo"<<endl<<endl;
    OggettoGrafo.StampaGrafo();
    cout<<"Inserire la sorgente da cui partire"<<endl;
    string Sorgente;
    cin>>Sorgente;
    int SorgenteEsistente = OggettoGrafo.CalcolaCamminoMinimo(Sorgente);
    if(OggettoGrafo.getNvertici()>0 && SorgenteEsistente==1)
    {
        cout<<endl<<"Stampa dei percorsi minimi"<<endl<<endl;
        OggettoGrafo.StampaTuttiCammini();
    }
    return 0;
}
