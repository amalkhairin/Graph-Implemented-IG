#include "Graph.h"

void createGraph (Graph &G){
    Start(G) = NULL;
}
adrPr AlokasiPr (string name,string type,string username){
    adrPr p = new elmPr;
    nama(p) = name;
    jenis(p) = type;
    id(p) = username;
    nextCh(p) = NULL;
    nextPr(p) = NULL;
    return p;
}
adrCh AlokasiCh(string username){
    adrCh p = new elmCh;
    idCh(p) = username;
    nextCh(p) = NULL;
    return p;
}
void inserPr (Graph &G, adrPr p){
    if (Start(G) == NULL){
        Start(G) = p;
    } else {
        adrPr q = Start(G);
        while (nextPr(q) != NULL){
            q = nextPr(q);
        }
        nextPr(q) = p;
    }
}
void insertCh(Graph &G, adrCh p, adrPr q){
    if (nextCh(adrPr(q)) == NULL){
        nextCh(adrPr(q)) = p;
    } else {
        adrCh i = nextCh(adrPr(q));
        while (nextCh(i) != NULL){
            i = nextCh(i);
        }
        nextCh(i) = p;
    }
}
void connecting(string id1,string id2, Graph &G){
    adrPr pr = searchId1(G,id1);
    adrCh ch = AlokasiCh(id2);
    insertCh(G,ch,pr);
}
adrPr searchId1(Graph G,string id1){
    adrPr p = Start(G);
    while ((p != NULL) && (id(p) != id1)) {
        p = nextPr(p);
    }
    if (id(p) == id1){
        return p;
    } else {
        return NULL;
    }
}
void disconnecting(Graph &G, string u1, string u2){
    adrPr p = searchId1(G,u1);
    adrCh q = nextCh(p);
    while ((q != NULL) && (idCh(q) != u2)){
        q = nextCh(q);
    }
    if ((nextCh(p) == q) && (nextCh(q) == NULL)){
        nextCh(p) = NULL;
    } else if (nextCh(q) == NULL){
        adrCh i = nextCh(p);
        while (nextCh(nextCh(i)) != NULL){
            i = nextCh(i);
        }
        nextCh(i) = NULL;
    } else {
        adrCh s = nextCh(p);
        while (nextCh(s) != q){
            s = nextCh(s);
        }
        nextCh(s) = nextCh(q);
        nextCh(q) = NULL;
    }
}
void deleteNode(Graph &G, adrPr &p){
    if (p != NULL){
        if ((p == Start(G)) && (nextPr(nextPr(p)) == NULL)){
            Start(G) = nextPr(p);
            nextPr(p) = NULL;
        } else if (nextPr(p) == NULL){
            adrPr i = Start(G);
            while (nextPr(nextPr(i)) != NULL){
                i = nextPr(i);
            }
            nextPr(i) = NULL;
        } else {
            adrPr i = Start(G);
            while (nextPr(i) != p){
                i = nextPr(i);
            }
            nextPr(i) = nextPr(p);
            nextPr(p) = NULL;
        }
    } else {
        cout << "node tidak ditemukan"<<endl;
    }
}
void jmlhFollowersnFollowing(Graph G){
    if (Start(G) != NULL){
        int folls = 0;
        int follw = 0;
        adrPr i = Start(G);
        while (i != NULL){
            adrCh j = nextCh(i);
            while (j != NULL){
                j = nextCh(j);
                follw++;
            }
            i = nextPr(i);
            folls++;
        }
        cout << "Followers: " << folls <<endl;
        cout << "Following: " << follw <<endl;
    } else {
        cout << "Graph empty"<<endl;
    }
}
