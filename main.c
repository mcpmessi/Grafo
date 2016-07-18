
#include <stdio.h>
#include <stdlib.h>

/**
 * --------------------------------------------
 * Estrutura de dados para armazenar o grafo
 * --------------------------------------------
 **/
typedef struct No
{
	//Aponta para o próximo no.
    struct No * next;
    int vertice;
    int cor;
}nGrafo;

//Constants
#define MAX_VERTICES 20

#define TRUE	1
#define FALSE 	0

//cores
#define BRANCO  0
#define CONZA	1
#define PRETO	2


/**
 * Global variables
 **/
nGrafo * G[MAX_VERTICES];

//Visitados --> n representa o numero de vértices
int visitados[MAX_VERTICES], n_vertices;



/**
 * Algoritmo DFS
 * Recursivo
 * insert an edge (vi,vj) in te adjacency list
 **/

void DFS(int i)
{
    nGrafo * p;

    printf("\n%d",i);
    p=G[i];

    visitados[i] = TRUE;
    printf("\nVerice %d visitado", i);

    while(p!=NULL)
    {
       i=p->vertice;

       if(!visitados[i]){
            DFS(i);
       }
       //proximo
       p = p->next;
    }
}



/**
 * Metodo para adicionar a lista de adjascência
 * @param vi int
 * @param vj int
 **/
void insert(int vi,int vj)
{
    nGrafo *p,*q;

    //alocar memória para um Nó
    q=(nGrafo*)malloc(sizeof(nGrafo));
    q->vertice=vj;
    q->next=NULL;


    //insert the node in the linked list number vi
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        //p auxiliar
        p=G[vi];

        //ir até o final da lista
        while(p->next!=NULL){
            p=p->next;
        }

        p->next=q;
    }
}

/**
 * Preencher o grafo
 **/

void preencherGrafo()
{
    int i, num_adja;

    //obter o numero de vertices do grafo
    printf("Informe o numero de vertices::");
    scanf("%d",&n_vertices);


    for(i=0;i<n_vertices;i++)
    {
    	int vi, vj;
        G[i]=NULL;
        //read edges and insert them in G[]

        printf("Numero de ligações para o vertice %d:", i);
        scanf("%d",&num_adja);

        for(i=0;i<num_adja;i++)
        {
            printf("Defina as arestas(u,v):");
            scanf("%d",&vi);
            scanf("%d", &vj);
            insert(vi,vj);
        }
    }
}



/**
 * Main - Metodo principal
 * @return void
 **/
int main()
{
    int i;
    preencherGrafo();
    //initialised visited to 0

    for(i=0;i<n_vertices;i++)
        visitados[i]=FALSE;

    DFS(0);

    int c;
    scanf("%d", &c);

    return 0;
}
