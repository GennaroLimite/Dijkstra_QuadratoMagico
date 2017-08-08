#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include "Vertice.h"
#include "Arco.h"
#include "Grafo.h"

vector<Vertice> CreaGrafo(int Nvertici);
int ControlloVertice(vector<Vertice> A, string NomeAdj, int Nvertici);
bool AdjGiaInserito(vector<Vertice> A, vector<Arco> Adj, string NomeAdj);


#endif // HEADER_H_INCLUDED
