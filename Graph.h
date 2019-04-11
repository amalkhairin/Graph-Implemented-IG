#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define Start(G)  G.Start
#define nextCh(p)  p->nextCh
#define nextPr(p)  p->nextPr
#define nama(p)  p->nama
#define jenis(p)  p->jenis
#define id(p)  p->id
#define idCh(p)  p->idCh
using namespace std;

typedef struct elmPr *adrPr;
typedef struct elmCh *adrCh;
struct elmPr {
    string nama,jenis,id;
    adrCh nextCh;
    adrPr nextPr;
};
struct elmCh {
    string idCh;
    adrCh nextCh;
};
struct Graph {
    adrPr Start;
};

void createGraph (Graph &G);
adrPr AlokasiPr (string name,string type,string username);
adrCh AlokasiCh(string username);
void inserPr (Graph &G, adrPr p);
void insertCh(Graph &G, adrCh p, adrPr q);
void connecting(string id1,string id2, Graph &G);
adrPr searchId1(Graph G,string id1);
void disconnecting(Graph &G, string u1, string u2);
void deleteNode(Graph &G, adrPr &p);
void jmlhFollowersnFollowing(Graph G);

#endif // GRAPH_H_INCLUDED
