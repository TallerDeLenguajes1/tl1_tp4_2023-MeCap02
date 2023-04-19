#include<stdio.h>
#include<stdlib.h>
#include"funciones_tarea.h"

int main(){
	NodoTarea *Laburo=crearLista();
	NodoTarea *trabajoComp=crearLista();
	NodoTarea **Laburo=&Laburo;
	NodoTarea **LaburosComp=&trabajoComp;
	cargarTareas(Laburo,n);
	BuscarTareaPorPC(Laburo,n);
	BuscarTareaPorID(Laburo,n);
	preguntarTareas(Laburo,LaburosComp,n);
	mostrarTareas(Laburo,LaburosComp,n);
	liberar(Laburo);
	liberar(LaburosComp);
	return 0;
}
