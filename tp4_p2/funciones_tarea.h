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

/*------------------------------Preguntar por Tareas------------------------------*/

void preguntarTareas(tarea **Laburo,tarea **LaburosComp,int n){
	int aux;
	for(i=0;i<n;i++){
		printf("\n\nLa tarea numero %d fue completada? (1=SI o 0=NO):",i+1);
		scanf("%d",&aux);
		while(aux!=1 || aux!=0){
			puts("\nIngrese un valor correcto:");
			scanf("%d",&aux);
		}
		switch(aux){
			case 1:aux==1;
				LaburosComp[i]=malloc(sizeof(*(LaburosComp[i])));
				LaburosComp[i]=Laburo[i];
				Laburo[i]=NULL;
				break;
			case 2:aux==0;
				break;
		}
		fflush(stdin);
	}
}

/*-----------------------------Mostrar Tareas------------------------------*/

void mostrarTareas(tarea **Laburo,tarea **LaburosComp,int n){
	puts("------------TAREAS COMPLETAS------------");
	for(i=0;i<n;i++){
		if(LaburosComp[i]!=NULL){
			printf("------------TAREA %d------------",i+1);
			printf("ID: %d",LaburosComp[i]->tareaID);
			puts("Descripcion de la tarea:");
			puts(LaburosComp[i]->desc);
			printf("Duracion de la tarea: %d",LaburosComp[i]->durac);
		}
	}
	puts("------------TAREAS PENDIENTES------------");
	for(i=0;i<n;i++){
		if(Laburo[i]!=NULL){
			printf("------------TAREA %d------------",i+1);
			printf("ID: %d",Laburo[i]->tareaID);
			puts("Descripcion de la tarea:");
			puts(Laburo[i]->desc);
			printf("Duracion de la tarea: %d",Laburo[i]->durac);
		}
	}
}

/*----------------------------Liberar Memoria----------------------------*/

void liberar(tarea **Laburo,int n){
	for(i=0;i<n;i++){
		free(Laburo[i]);
	}
	free(Laburo);
}

/*----------------------------Buscar Tarea Palabra Clave----------------------------*/

void BuscarTareaPorPC(tarea **Laburo,int n){
	char *aux;
	aux=malloc(sizeof(char)*MAX);
	puts("Ingrese una palabra clave para la busqueda:");
	gets(aux);
	for(i=0;i<n;i++){
		if(strstr(Laburo[i]->desc,aux)){
			printf("------------TAREA CON PALABRA CLAVE %s ENCONTRADA------------",aux);
			printf("ID: %d",Laburo[i]->tareaID);
			puts("Descripcion de la tarea:");
			puts(Laburo[i]->desc);
			printf("Duracion de la tarea: %d",Laburo[i]->durac);
		}
	}
	fflush(stdin);
}

/*----------------------------Buscar Tarea ID----------------------------*/

void BuscarTareaPorID(tarea **Laburo,int n){
	int aux;
	puts("Ingrese la ID del trabajo que desea buscar:");
	scanf("%d",&aux);
	for(i=0;i<n;i++){
		if(Laburo[i]->tareaID==aux){
			printf("------------TAREA %d------------",i+1);
			printf("ID: %d",Laburo[i]->tareaID);
			puts("Descripcion de la tarea:");
			puts(Laburo[i]->desc);
			printf("Duracion de la tarea: %d",Laburo[i]->durac);
		}
	}
	fflush(stdin);
}
