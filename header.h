//
// Created by HELIN Steven & DEWAGHE Guillaume  24/11/2020.
//



#ifndef TP_GRAPHE_HEADER_H
#define TP_GRAPHE_HEADER_H


typedef struct sommet {
int id;
};

typedef struct arcs {
int id;
int distance;
struct sommet i;
struct sommet j;
};

//modif
#endif //TP_GRAPHE_HEADER_H
