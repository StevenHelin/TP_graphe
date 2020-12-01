//
// Created by HELIN Steven & DEWAGHE Guillaume  24/11/2020.
//



#ifndef TP_GRAPHE_HEADER_H
#define TP_GRAPHE_HEADER_H

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int id;
    int distance;
} Arc;

typedef struct
{
    int n; //Nombre de sommets
    Arc **M;
} MATRICE;

typedef int* Sommet;


#endif //TP_GRAPHE_HEADER_H
