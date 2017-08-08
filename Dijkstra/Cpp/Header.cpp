#include "../Include/Header.h"
//CreaGrafo(int Nvertici)
vector<Vertice> CreaGrafo(int Nvertici)
{
    int N_adj, Peso, IndiceAdj;
    string Nome, NomeAdj;
    vector<Vertice> Nodo;
    Nodo.resize(Nvertici);
    vector< vector<Arco> > Adj;
    Adj.resize(Nvertici);
    vector<Vertice> VetGrafo;
    for(int i=0; i<Nvertici;)
    {
        cout<<"Inserisci nome del "<<i+1<<"' Vertice"<<endl;
        fflush(stdin); getline(cin, Nome);
        if(ControlloVertice(Nodo, Nome, Nvertici))
        {
            cout<<"Inserisci Il numero di adiacenze di "<<Nome<<endl;
            cin>>N_adj;
            Nodo[i] = Vertice(Nome, N_adj, Adj[i]);
            i++;
        }
        else cout<<"Vertice non corretto!! Reinserire..."<<endl;
    }
    for(int i=0; i< Nvertici; i++)
    {
       cout<<endl<<"Inserimento nodo adiacente di ["<<Nodo[i].getNomeVertice()<<"]"<<endl;
       for(int j=0; j< Nodo[i].getNadj(); )
       {
           cout<<"Inserire nome del "<<j+1<<"' nodo adiacente "<<endl;
           fflush(stdin); getline(cin, NomeAdj);
           IndiceAdj = ControlloVertice(Nodo, NomeAdj, Nvertici);
           if( IndiceAdj>=0 && AdjGiaInserito(Nodo, Adj[i], NomeAdj) )
           {
                do
                {
                    cout<<"Inserire il peso di collegamento dei due nodi"<<endl;
                    cin>>Peso;
                }while(Peso<0);
                Arco Archetto( Peso, IndiceAdj );
                Nodo[i].setAdj(Archetto);
                j++;
           }
           else cout<<"Vertice adiacente non esistente!! Reinserire..."<<endl;
       }
       VetGrafo.push_back( Nodo[i] );
    }
    Nodo.clear();
    for(int i=0; i<Nvertici;i++)
        Adj[i].clear();
    Adj.clear();
    return VetGrafo;
}
//ControlloVertice(vector<Vertice> Vertici, string NomeAdj)
int ControlloVertice(vector<Vertice> A, string NomeAdj, int Nvertici)
{
    for(int i=0; i<Nvertici; i++)
        if(A[i].getNomeVertice() == NomeAdj) return i;

    return -1;
}
//(vector<Vertice> Vertici, vector<Arco> Adj, string NomeAdj)
bool AdjGiaInserito(vector<Vertice> A, vector<Arco> Adj, string NomeAdj)
{
    for(unsigned int i=0; i < Adj.size(); i++)
        if( A[ Adj[i].getIndiceNodoAdj() ].getNomeVertice() == NomeAdj) return false;
    return true;
}
