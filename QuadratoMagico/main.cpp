#include "Include/QuadratoMagico.h"
#include <time.h>
using namespace std;
int main()
{
    int Lato;
    string NomeFile;
    ifstream  Cf;
    char Scelta = '1';
    QuadratoMagico *QuadratoOgg;
    do
    {
        cout<<"Inserire il lato del quadrato (max 10)"<<endl;
        cin>>Lato;
    }while(Lato<1 || Lato>10);
    do
    {
        cout<<endl;
        cout<<"1 - Carica il quadrato parziale di lato "<<Lato<<" da file "<<endl;
        cout<<"2 - Provare tutte le possibili disposizioni "<<endl;
        cout<<endl;
        cout<<"Seleziona una scelta: "<<endl;
        fflush(stdin);Scelta = getchar();fflush(stdin);
        if(Scelta == '1')
        {
            cout<<"\nInserire il nome del file di testo che contiene il quadrato parziale di lato "<<Lato<<endl;
            cin>>NomeFile;
            Cf.open(NomeFile.c_str(), ios::in);
            if(Cf)
            {
                Cf.close();
                cout<<endl<<"Il file e' stato trovato!!!"<<endl;
                QuadratoOgg = new QuadratoMagico(Lato, NomeFile);
            }
            else
            {
                cout<<endl<<"Il file NON e' stato trovato"<<endl;
                Scelta='0'; //Per far reiterare
            }
        }
        else if(Scelta == '2') QuadratoOgg = new QuadratoMagico(Lato);
        else cout<<endl<<"Scelta non valida, riprovare!!"<<endl;
    }while(Scelta!='1' && Scelta!='2');
    cout<<endl;
    cout<<"*Matrice Di Input*"<<endl<<endl;
    QuadratoOgg->StampaMatriceCaricata();
    cout<<endl<<"Attendere..."<<endl<<endl;
    clock_t T1, T2;
    T1 = clock();
        QuadratoOgg->AvviaQuadratoMagico();
    T2 = clock();
    double eTime = (double)(T2 - T1)/(double)CLOCKS_PER_SEC;
    QuadratoOgg->StampaSoluzioni();
    cout<<"Il tempo impiegato per costruire tutte le possibili soluzioni e' stato di "<<eTime<<" secondi"<<endl;
    delete QuadratoOgg;
    return 0;
}
