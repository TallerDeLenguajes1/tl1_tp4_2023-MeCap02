#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int i=0,j=0;

struct{
	int tareaID;
	char *desc;
	int durac;
}typedef(tarea);

struct Nodo{
	tarea Trab;
	struct Nodo *next;
};

typedef struct Nodo NodoOri;

NodoOri* crearLista(){
	return NULL;
}

NodoOri* crearNodo(tarea Trab){
	NodoOri* nodo=(NodoOri*)malloc(sizeof(nodo));
	nodo->Trab=Trab;
	nodo->next=NULL;
	return nodo;
}

void anadirNodo(NodoOri** nodoInicial,tarea Trab){
	NodoOri* nodo=crearNodo(Trab);
	nodo->next=*nodoInicial;
	*nodoInicial=nodo;
}

void removerNodo(NodoOri** nodoInicial,tarea Trab){
	NodoOri* nodoTemp=*nodoInicial;
	NodoOri* nodoPrev=*nodoInicial;
	while(nodoTemp!=NULL && nodoTemp->Trab.tareaID!=Trab.tareaID && strcmp(nodoTemp->Trab.desc,Trab.desc)!=0 && nodoTemp->Trab.durac!=Trab.durac){
		nodoPrev=nodoTemp;
		nodoTemp=nodoTemp->next;
	}
	if(nodoTemp!=NULL){
		if(nodoTemp==nodoInicial){
			nodoPrev=nodoTemp->next;
			*nodoInicial=nodoPrev;
		}else{
			nodoPrev->next=nodoTemp->next;
		}
		free(nodoTemp);
	}
}
