#include"funciones_lista.h"

/*------------------------------Cargar Tareas------------------------------*/

void cargarTareas(NodoTarea **Laburo,int n){
	char* buff = (char*)malloc(sizeof(buff)*MAX);
	int *aux=(int*)malloc(sizeof(int));
	n=1;
	
	puts("\n=============CARGAR TAREAS=============");
	for(i=0;n;i++){
		fflush(stdin);
		printf("------------CARGAR TAREA %d------------",i+1);
		Laburo.tareaID=i+1;
		puts("\nIngrese una descripcion de la tarea:");
		gets(buff);
		fflush(stdin);
		Laburo.desc=(char *)malloc(strlen(buff)+1);
		strcpy(Laburo.desc,buff);
		puts("Ingrese la duracion de la tarea (entre 10 a 100 minutos):");
		scanf("%d",&Laburo.durac);
		while(Laburo.durac<10 || Laburo.durac>100){
			puts("Ingrese un valor correcto:");
			scanf("%d",&Laburo.durac);
		}
		fflush(stdin);
		anadirNodo(NodoTarea,Laburo);
		puts("Desea seguir agregando tareas? (1=SI, 0=NO):");
		scanf("%d",&aux);
		while(*aux!=1 && *aux!=0){
			puts("Ingrese un valor correcto:");
			scanf("%d",&aux);
		}
		if(*aux==1){
			n=n+1;
		}
		fflush(stdin);
	}
	free(buff);
}

/*------------------------------Preguntar por Tareas------------------------------*/

void preguntarTareas(NodoTarea **Laburo,NodoTarea **LaburosComp,int n){
	int aux;
	NodoTarea *NodoTemp=*Laburo;
	for(i=0;NodoTemp!=NULL;i++){
		printf("\n\nLa tarea numero %d fue completada? (1=SI o 0=NO):",i+1);
		scanf("%d",&aux);
		while(aux!=1 && aux!=0){
			puts("\nIngrese un valor correcto:");
			scanf("%d",&aux);
		}
		switch(aux){
			case 1:aux==1;
				anadirNodo(LaburosComp,NodoTemp->Laburo);
				removerNodo(Laburo,NodoTemp->Laburo);
				break;
			case 2:aux==0;
				break;
		}
		fflush(stdin);
	}
}

/*-----------------------------Mostrar Tareas------------------------------*/

void mostrarTareas(NodoTarea **Laburo,NodoTarea **LaburosComp,int n){
	puts("\n\n------------TAREAS COMPLETAS------------");
		if(LaburosComp!=NULL){
			NodoTarea *NodoTemp=LaburosComp;
			for(i=0;NodoTemp;i++){
			printf("------------TAREA %d------------",i+1);
			printf("\nID: %d",NodoTemp->LaburosComp.tareaID);
			puts("\nDescripcion de la tarea:");
			puts(NodoTemp->LaburosComp.desc);
			printf("\nDuracion de la tarea: %d",NodoTemp->LaburosComp.durac);
			NodoTemp=NodoTemp->next;
	        }
	    }
	puts("------------TAREAS PENDIENTES------------");
		if(Laburo!=NULL){
			NodoTarea *NodoTemp=Laburo;
			for(i=0;NodoTemp;i++){
			    printf("------------TAREA %d------------",i+1);
			    printf("ID: %d",NodoTemp->Laburo.tareaID);
			    puts("Descripcion de la tarea:");
			    puts(NodoTemp->Laburo.desc);
			    printf("Duracion de la tarea: %d",NodoTemp->Laburo.durac);
			    NodoTemp=NodoTemp->next;
	        }
		}
}

/*----------------------------Liberar Memoria----------------------------*/

void liberar(NodoTarea **Laburo){
	NodoTarea *NodoTemp=*Laburo;
	NodoTarea *borrarNodo=*Laburo;
	while(NodoTemp!=NULL){
		borrarNodo=NodoTemp;
		NodoTemp=NodoTemp->next;
		free(borrarNodo);
	}
	free(Laburo);
}

/*----------------------------Buscar Tarea Palabra Clave----------------------------*/

void BuscarTareaPorPC(NodoTarea **Laburo,int n){
	char *aux;
	aux=(char*)malloc(sizeof(char)*MAX);
	puts("Ingrese una palabra clave para la busqueda:");
	gets(aux);
	NodoTarea *NodoTemp=*Laburo;
	for(i=0;NodoTemp!=NULL;i++){
		if(strstr(NodoTemp->Laburo.desc,aux)){
			printf("\n\n------------TAREA CON PALABRA CLAVE %s ENCONTRADA------------",aux);
			printf("\nID: %d",NodoTemp->Laburo.tareaID);
			puts("\nDescripcion de la tarea:");
			puts(NodoTemp->Laburo.desc);
			printf("\nDuracion de la tarea: %d",NodoTemp->Laburo.durac);
		}
	}
	fflush(stdin);
	free(aux);
}

/*----------------------------Buscar Tarea ID----------------------------*/

void BuscarTareaPorID(NodoTarea **Laburo,int n){
	int *aux;
	aux=(int *)malloc(sizeof(int));
	puts("Ingrese la ID del Laburo que desea buscar:");
	scanf("%d",&aux);
	fflush(stdin);
	NodoTarea *NodoTemp=*Laburo;
	for(i=0;NodoTemp!=NULL;i++){
		if(NodoTemp->Laburo.tareaID==*aux){
			printf("------------TAREA %d------------",i+1);
			printf("ID: %d",NodoTemp->Laburo.tareaID);
			puts("Descripcion de la tarea:");
			puts(NodoTemp->Laburo.desc);
			printf("Duracion de la tarea: %d",NodoTemp->Laburo.durac);
		}
	}
	fflush(stdin);
	free(aux);
}
