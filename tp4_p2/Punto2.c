#include<stdio.h>
#include<stdlib.h>
#include"funciones_tarea.h"

int main(){
	tarea **Laburo;
	tarea **LaburosComp;
	int n;
	srand(time(NULL));
	puts("================TAREAS================");
	puts("\nCuantas tareas desea ingresear?:");
	scanf("%d",&n);
	if(n<1){
		puts("Ingrese un valor valido");
		scanf("%d",&n);
	}
	puts("\n======================================");
	Laburo=(tarea **)malloc(sizeof(tarea)*n);
	LaburosComp=(tarea **)malloc(sizeof(tarea)*n);
	for(i=0;i<n;i++){
		Laburo[i]=NULL;
		LaburosComp[i]=NULL;
	}
	cargarTareas(Laburo,n);
	BuscarTareaPorPC(Laburo,n);
	BuscarTareaPorID(Laburo,n);
	preguntarTareas(Laburo,LaburosComp,n);
	mostrarTareas(Laburo,LaburosComp,n);
	liberar(Laburo,n);
	liberar(LaburosComp,n);
	return 0;
}
