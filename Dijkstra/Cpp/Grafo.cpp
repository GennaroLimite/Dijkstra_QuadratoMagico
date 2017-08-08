#include "../Include/Grafo.h"
//Costruttore di default
Grafo::Grafo()
{
    this->Nvertici = 0;
    this->VerticeSorgente = "";
}
//Primo costruttore per argomenti
Grafo::Grafo(int Nvertici, vector<Vertice> VetGrafo)
{
    this->VerticeSorgente = "";
    this->Nvertici = Nvertici;
    this->VetGrafo = VetGrafo;
}
//Secondo costruttore per argomenti
Grafo::Grafo(string NomeFile)
{
    this->VerticeSorgente = "";
    int N_adj, IndiceAdj;
    float Peso;
    string Nome, NomeAdj, Testo;
    ifstream  Qf;
    Qf.open(NomeFile.c_str(), ios::in);
    if(!Qf.eof())
    {
        int Estratto;
        Qf>>Estratto;
        this->Nvertici = Estratto;
        vector<Vertice> Nodo;
        Nodo.resize(this->Nvertici);
        vector< vector<Arco> > Adj;
        Adj.resize(this->Nvertici);
        for(int i=0; i<Nvertici && !Qf.eof(); i++)
        {
            Qf>>Nome;
            Qf>>N_adj;
            Nodo[i] = Vertice(Nome, N_adj, Adj[i]);
        }
        for(int i=0; i<Nvertici; i++)
        {
            for(int j=0; j< Nodo[i].getNadj(); j++)
            {
                Qf>>NomeAdj;
                Qf>>Peso;
                IndiceAdj = ControlloVertice(Nodo , NomeAdj);
                Arco Archetto( Peso, IndiceAdj );
                Nodo[i].setAdj(Archetto);
            }
            VetGrafo.push_back( Nodo[i] );
        }
        Nodo.clear();
        for(int i=0; i<this->Nvertici;i++)
            Adj[i].clear();
        Adj.clear();
    }
    else
    { cout<<"APERTURA DEL FILE FALLITA!!"<<endl; this->Nvertici = 0;}
}
//Distruttore
Grafo::~Grafo()
{
    this->VetGrafo.clear();
}
//ControlloVertice(vector<Vertice> Vertici, string NomeAdj)
int Grafo::ControlloVertice(vector<Vertice> Vertici, string NomeAdj)
{
    for(int i=0; i<this->Nvertici; i++)
        if(Vertici[i].getNomeVertice() == NomeAdj) return i;

    return -1;
}
//getNvertici
int Grafo::getNvertici()
{
    return this->Nvertici;
}
//getIndiceVertice
int Grafo::getIndiceVertice(string VerticeDaCercare)
{
    for(int i=0; i<this->Nvertici; i++)
        if( VetGrafo[i].getNomeVertice() == VerticeDaCercare) return i;
    return -1;
}
//StampaGrafo
void Grafo::StampaGrafo()
{
    for(int i=0; i< this->Nvertici; i++)
    {
         cout<<"NOME VERTICE: '"<< VetGrafo[i].getNomeVertice()
         <<"'\npresenta i seguenti nodi adiacenti"<<endl;
         int Nadj = VetGrafo[i].getNadj();
         if(Nadj==0) cout<<" Nessun nodo adiacente!"<<endl;
         for(int j=0; j<Nadj; j++)
         {
            cout<<" '"<<VetGrafo[ VetGrafo[i].getAdj(j).getIndiceNodoAdj() ].getNomeVertice();
            cout<<"' [PesoArco = "<< VetGrafo[i].getAdj(j).getPeso() <<"] ";
            cout<<endl;
         }
         cout<<endl;
    }
    cout<<endl;
}
//Dijkstra(int IndiceSorgente)
void Grafo::Dijkstra(int IndiceSorgente)
{
    int i_u, i_v;
    float w, CostoEstrattoU;
    multimap<float, int> MapDijkstra;
    multimap<float, int>::iterator it;
    this->DefinisciSingolaSorgente(MapDijkstra, IndiceSorgente);
    while(!MapDijkstra.empty())
    {
        it = MapDijkstra.begin();
        i_u = it->second;
        CostoEstrattoU = it->first;
        MapDijkstra.erase(it);
        if(CostoEstrattoU <= VetGrafo[i_u].getStima())
        {
            for(int j=0; j< VetGrafo[i_u].getNadj(); j++)
            {
                i_v = VetGrafo[i_u].getAdj(j).getIndiceNodoAdj();
                w = VetGrafo[i_u].getAdj(j).getPeso();
                Relax(i_u, i_v, w, MapDijkstra);
            }
        }
    }
}
//Relax(int i_u, int i_v, float w, multimap<float, int> &Map)
void Grafo::Relax(int i_u, int i_v, float w, multimap<float, int> &Map)
{
    float Stimato = VetGrafo[i_u].getStima() + w;
    if( VetGrafo[i_v].getStima() > Stimato )
    {
        VetGrafo[i_v].setStima(Stimato);
        VetGrafo[i_v].setIndicePadre(i_u);
        Map.insert(make_pair( VetGrafo[i_v].getStima(), i_v ));
    }
}
//(multimap<float, int> &Map, int IndiceSorgente)
void Grafo::DefinisciSingolaSorgente(multimap<float, int> &Map, int IndiceSorgente)
{
    for(int i=0; i<this->Nvertici; i++)
    {
        VetGrafo[i].setStima(INFINITO);
        VetGrafo[i].setIndicePadre(-1);
    }
    VetGrafo[IndiceSorgente].setStima(0);
    Map.insert(make_pair(0, IndiceSorgente));
}
//RicavaUnCammino(string Arrivo)
list<Vertice> Grafo::RicavaUnCammino(string Arrivo)
{
    list<Vertice> Cammino;
    map<string, Vertice>::iterator it;
    int i_Padre;
    int i_Arrivo = getIndiceVertice(Arrivo);
    if(i_Arrivo != -1) i_Padre = i_Arrivo;
    else{cout<<"Destinazione non esitente!!! "; return Cammino;}
    while(i_Padre != -1)
    {
        Cammino.push_front( VetGrafo[i_Padre] );
        if(this->VerticeSorgente == VetGrafo[i_Padre].getNomeVertice()) return Cammino;
        i_Padre = VetGrafo[i_Padre].getIndicePadre();
    }
    Cammino.clear();
    return Cammino;
}
//StampaTuttiCammini()
void Grafo::StampaTuttiCammini()
{
    if(this->VerticeSorgente!="")
    {
        for(int i=0; i<this->Nvertici; i++)
        {
            cout<<"Percorso minimo ["<<this->VerticeSorgente<<"..."<< VetGrafo[i].getNomeVertice();
            cout<<"] presenta un costo di: ";
            if(VetGrafo[i].getStima()!=INFINITO) cout<<VetGrafo[i].getStima()<<endl;
            else cout<<"COSTO NON ESISTENTE!!!"<<endl;
            StampaUnCammino( VetGrafo[i].getNomeVertice() );
            cout<<endl<<endl;
        }
    }
    else cout<<"Il cammino minimo non e' stato ancora calcolato!"<<endl;
}
//StampaUnCammino(string Arrivo)
void Grafo::StampaUnCammino(string Arrivo)
{
    if(this->VerticeSorgente!="")
    {
        list<Vertice> Cammino = RicavaUnCammino(Arrivo);
        if(Cammino.size() == 0) cout<<"Cammino non esistente!";
        for(list<Vertice>::iterator it = Cammino.begin(); it!= Cammino.end(); it++)
            cout<<" => "<<it->getNomeVertice() <<"["<<it->getStima()<<"]";
        Cammino.clear();
    }
    else cout<<"Il cammino minimo non e' stato ancora calcolato!"<<endl;
}
//CalcolaCamminoMinimo(string Sorgente)
int Grafo::CalcolaCamminoMinimo(string Sorgente)
{
    int IndiceSorgente = this->getIndiceVertice(Sorgente);

    if(IndiceSorgente>=0)
    {
      this->VerticeSorgente = Sorgente;
      Dijkstra(IndiceSorgente);
      return 1;
    }
    else
    {
        cout<<"Sorgente non trovata e quindi non calcolo cammino minimo!!"<<endl<<endl;
        return -1;
    }
}
