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
	tarea Laburo;
	struct Nodo *next;
};

typedef struct Nodo NodoTarea;

NodoTarea *crearLista(){
	return NULL;
}

NodoTarea *crearNodo(tarea Laburo){
	NodoTarea *nodo=(NodoTarea*)malloc(sizeof(*nodo));
	nodo->Laburo=Laburo;
	nodo->next=NULL;
	return nodo;
}

void anadirNodo(NodoTarea **iniciarNodo, tarea Laburo){
	NodoTarea *nodo=crearNodo(Laburo);
	nodo->next=*iniciarNodo;
	*iniciarNodo=nodo;
}

void removerNodo(NodoTarea **iniciarNodo, tarea Laburo){
	NodoTarea *NodoTemp=*iniciarNodo;
	NodoTarea *NodoPrev=*iniciarNodo;
	while(NodoTemp!=NULL && NodoTemp->Laburo.tareaID!=Laburo.tareaID && strcmp(NodoTemp->Laburo.desc,Laburo.desc)!=0 && NodoTemp->Laburo.durac!=Laburo.durac){
		NodoPrev=NodoTemp;
		NodoTemp=NodoTemp->next;
	}
	if(NodoTemp!=NULL){
		if(NodoTemp==*iniciarNodo){
			NodoPrev=NodoTemp->next;
			*iniciarNodo=NodoPrev;
		}else{
			NodoPrev->next=NodoTemp->next;
		}
		free(NodoTemp);
	}
}
