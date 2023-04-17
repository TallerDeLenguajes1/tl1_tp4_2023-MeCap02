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

/*------------------------------Cargar Tareas------------------------------*/

void cargarTareas(tarea **Laburo,int n){
	char* buff = malloc(sizeof(*buff)*MAX);
	puts("\n=============CARGAR TAREAS=============");
	for(i=0;i<n;i++){
		fflush(stdin);
		printf("------------CARGAR TAREA %d------------",i+1);
		Laburo[i]=malloc(sizeof(tarea));
		Laburo[i]->tareaID=i+1;
		
		puts("\nIngrese una descripcion de la tarea:");
		gets(buff);
		fflush(stdin);
		Laburo[i]->desc=malloc(sizeof(char)*strlen(buff)+1);
		strcpy(Laburo[i]->desc,buff);
		
		puts("Ingrese la duracion de la tarea (entre 10 a 100 minutos):");
		scanf("%d",&Laburo[i]->durac);
		while(Laburo[i]->durac<10 || Laburo[i]->durac>100){
			puts("Ingrese un valor correcto:");
			scanf("%d",&Laburo[i]->durac);
		}
		fflush(stdin);
	}
}

/*-----------------------------Mostrar Tareas------------------------------*/



/*----------------------------Funcion Principal----------------------------*/

int main(){
	tarea **Laburo;
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
	for(i=0;i<n;i++){
		Laburo[i]=NULL;
	}
	cargarTareas(Laburo,n);
	free(Laburo);
	for(i=0;i<n;i++){
		free(Laburo[i]->desc);
		free(Laburo[i]);
	}
	return 0;
}
