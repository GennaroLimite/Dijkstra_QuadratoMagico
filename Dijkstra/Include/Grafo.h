#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include "Vertice.h"
#include <map>
#include <iostream>
#include <fstream>
#include <list>

class Grafo
{
    private:
        vector<Vertice> VetGrafo;
        int Nvertici;
        string VerticeSorgente;
        int ControlloVertice(vector<Vertice> Vertici, string NomeAdj);
        void Dijkstra(int IndiceSorgente);
        void DefinisciSingolaSorgente(multimap<float, int> &Map, int IndiceSorgente);
        void Relax(int i_u, int i_v, float w, multimap<float, int > &Map);
        list<Vertice> RicavaUnCammino(string Arrivo);
        int getIndiceVertice(string VerticeDaCercare);

    public:
        Grafo(int Nvertici, vector<Vertice> VetGrafo);
        Grafo(string NomeFile);
        Grafo();
        ~Grafo();

        int CalcolaCamminoMinimo(string Sorgente);
        void StampaGrafo();
        void StampaUnCammino(string Arrivo);
        void StampaTuttiCammini();
        int getNvertici();
};
#endif // GRAFO_H_INCLUDED
