//
// Created by HELIN Steven & DEWAGHE Guillaume  24/11/2020.
//

#include "header.h"


void reservation_en_memoire_sommet(int n,Sommet *s){
    s = (int*)calloc(n,sizeof(int));
}

void liberation_memoire_sommet(int n,Sommet *s){
    for(int i=0;i<n;i++){
        free(s[i]);
    }
}

void reservation_en_memoire_matrice(int n, MATRICE g)
{
    g.n = n;
    g.M = (Arc**)calloc(n, sizeof(Arc*) );
    if(g.M)
    {
        for(int i = 0; i < n; i++)
        {
            g.M[i] = (Arc*)calloc(n, sizeof(Arc));
        }
    }
}

void liberation_memoire_matrice(MATRICE *g)
{
    if(g->M)
    {
        for(int i = 0; i <= g->n-1; i++)
        {
            free(g->M[i]);
        }
        free(g->M);
    }
}
void ajouter_arc(MATRICE g, int i, int j)
{
    if(g.M[i][j].distance == 0)
    {
        //printf("Ajout de l'arc i = %d, j = %d\n", i, j);
        g.M[i][j].distance = 1;
    }
}
void retirer_arc(MATRICE g, int i, int j)
{
    if(g.M[i][j].distance == 1)
    {
        //printf("Retrait de l'arc i = %d, j = %d", i, j);
        g.M[i][j].distance= 0;
    }
}


int est_successeur(MATRICE g, int  i, int j)
{
    if(g.M[i][j].distance == 1)
    {
        return 1;
    }
    return 0;
}

int compteur_arc (MATRICE g){
    int i,j;
    int cpt=0;
    for (i=0;i<g.n;i++){
        for(j=0;j<g.n;j++){
            if(est_successeur(g,i,j)==1){
                cpt++;
            }
        }
    }
    return cpt;
}

int idSommet(Sommet s,int j){
    for(int i=0;i<s-1;i++){
        if(s[i]==j){
            return i;
        }
    }
}

void lire_graphe_matrice(char *nom, MATRICE g)
{
    char temp[64];
    int n, i, j, temp2;
    FILE *f = NULL;
    f = fopen(nom,"r");
    if (f)
    {
        fgets(temp,64,f);
        sscanf(temp,"%d",&n);
        reservation_en_memoire_matrice(n, g);
        while (fgets(temp,64,f) != NULL)
        {
            sscanf(temp,"%d %d",&i,&j);
            if(est_successeur(g, i, j)==1)
            {
                ajouter_poids(g, i, j);
            }
            else
            {
                ajouter_arc(g, i, j);
            }
        }
        fclose(f);
    }
    else{
        printf("Impossible d'ouvrir le fichier %s",nom);
    }
}

void ecrit_graphe_matrice(MATRICE g, char *nom)
{
    int i, j;
    FILE *f;
    f = fopen(nom, "w");
    if(f)
    {
        fprintf(f, "%d %d", g.n, compteur_arc(g) );
        for(i = 0; i < g.n; i++)
        {
            for(j = 0; j < g.n; j++)
            {
                fprintf(f, "%d\n", g.M[i][j].id);
            }
        }
        for(i = 0; i < g.n; i++)
        {
            for(j = 0; j < g.n; j++)
            {
                fprintf(f, "%d %d %d", g.M[i][j].id, g.M[i][j+1].id, g.M[i][j].distance);
            }
        }
        fclose(f);
    }
    else printf("Erreur sauvegarde");
}