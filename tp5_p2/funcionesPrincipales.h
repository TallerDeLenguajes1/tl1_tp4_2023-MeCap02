#include"funcionesLista.h"

/*------------------------------Cargar Tareas------------------------------*/

void cargarTareas(NodoOri** nodoInicial,int n){
	char* buff = malloc(sizeof(*buff)*MAX);
	tarea Trab;
	puts("\n=============CARGAR TAREAS=============");
	for(i=0;i<n;i++){
		fflush(stdin);
		printf("\n------------CARGAR TAREA %d------------",i+1);
		Trab.tareaID=i+1;
		
		puts("\nIngrese una descripcion de la tarea:");
		gets(buff);
		fflush(stdin);
		Trab.desc=(char*)malloc(sizeof(char)*strlen(buff)+1);
		strcpy(Trab.desc,buff);
		
		puts("Ingrese la duracion de la tarea (entre 10 a 100 minutos):");
		scanf("%d",&Trab.durac);
		while(Trab.durac<10 || Trab.durac>100){
			puts("Ingrese un valor correcto:");
			scanf("%d",&Trab.durac);
		}
		fflush(stdin);
		anadirNodo(nodoInicial,Trab);
	}
	free(buff);
}

/*-----------------------------Verificar-----------------------------*/

int verificarCont(NodoOri** nodoInicial,int id){
	NodoOri* nodoTemp=*nodoInicial;
	while(nodoTemp!=NULL){
		if(nodoTemp->Trab.tareaID==id){
			return 1;
		}
		nodoTemp=nodoTemp->next;
	}
	return 0;
}

/*------------------------------Preguntar por Tareas------------------------------*/

void preguntarTareas(NodoOri** tareasPendientes,NodoOri** tareasCompletas,NodoOri** tareasEnProceso){
	int aux;
	int id;
	int moveAux;
	while(aux!=2){
		puts("\n\n------------TAREAS COMPLETAS------------");
	    mostrarTareas(tareasCompletas); //x
	    puts("\n\n------------TAREAS PENDIENTES------------");
	    mostrarTareas(tareasPendientes); //x
	    puts("\n\n------------TAREAS EN PROCESO------------");
	    mostrarTareas(tareasEnProceso);
	    puts("\n\nIngrese la id de la tarea a seleccionar:");
	    scanf("%d",&id);
	    fflush(stdin);
	    switch(aux){
	    	case 1:
	    		puts("\nMover tarea a: 1=Tareas Completadas, 2=Tareas en proceso:");
	    		scanf("%d",&moveAux);
	    		fflush(stdin);
	    		while(moveAux!=1 && moveAux!=2){
	    			puts("Ingrese un valor valido:");
	    			scanf("%d",&moveAux);
	    			fflush(stdin);
				}
				if(moveAux==1){
					if(verificarCont(tareasCompletas,id)){
						puts("\nTarea ya completada");
					}else{
						if(verificarCont(tareasPendientes,id)){
							anadirNodo(tareasCompletas,BuscarTareaPorID(tareasPendientes,id));
							removerNodo(tareasPendientes,BuscarTareaPorPC(tareasPendientes,id));
						}else{
							anadirNodo(tareasCompletas,BuscarTareaPorID(tareasEnProceso,id));
							removerNodo(tareasPendientes,BuscarTareaPorPC(tareasEnProceso,id));
						}
					}
					break;
				}
				if(moveAux==2){
					if(verificarCont(tareasEnProceso,id)){
						puts("\nTarea ya en proceso");
					}else{
						if(verificarCont(tareasCompletas,id)){
							puts("\nLa tarea ya fue completada");
						}else{
							anadirNodo(tareasEnProceso,BuscarTareaPorID(tareasPendientes,id));
							removerNodo(tareasPendientes,BuscarTareaPorID(tareasPendientes,id));
						}
					}
					break;
				}
				break;
			case 2:
				if(verificarCont(tareasPendientes,id)){
					removerNodo(tareasPendientes,BuscarTareaPorID(tareasPendientes,id));
					break;
				}
				if(verificarCont(tareasCompletas,id)){
					removerNodo(tareasCompletas,BuscarTareaPorID(tareasEnProceso,id));
					break;
				}
				if(verificarCont(tareasEnProceso,id)){
					removerNodo(tareasEnProceso,BuscarTareaPorID(tareasEnProceso,id));
					break;
				}
				break;
			case 3:
				break;
		}
		puts("\n\nModificar otra tarea? 1=SI, 2=NO");
		scanf("%d",&aux);
		switch(aux){
			case 1:
				break;
			case 2:
				puts("\n---DATOS DE CADA LISTA---");
				puts("\nTareas pendientes");
				mostrarDatos(tareasPendientes);
				puts("\nTareas completas");
				mostrarDatos(tareasCompletas);
				puts("\nTareas en proceso");
				mostrarDatos(tareasEnProceso);
				break;
		}
	}
}

/*-----------------------------Mostrar Tareas------------------------------*/

void mostrarTareas(NodoOri* nodoInicial){
	NodoOri* nodoTemp=*nodoInicial;
	for(i=0;nodoTemp;i++){
		printf("\n------------TAREA %d------------",i+1);
		printf("\nID: %d",nodoTemp->Trab.tareaID);
		puts("\nDescripcion de la tarea:");
		puts(nodoTemp->Trab.desc);
		printf("Duracion de la tarea: %d",nodoTemp->Trab.durac);
		nodoTemp=nodoTemp->next;
	}
	fflush(stdin);
}

/*----------------------------Liberar Memoria----------------------------*/

void liberar(NodoOri** nodoInicial){
	NodoOri* nodoTemp=*nodoInicial;
	NodoOri* removerNodo=*nodoInicial;
	while(nodoTemp!=NULL){
		removerNodo=nodoTemp;
		nodoTemp=nodoTemp->next;
		free(removerNodo);
	}
	free(nodoInicial);
}

/*----------------------------Buscar Tarea Palabra Clave----------------------------*/

void BuscarTareaPorPC(NodoOri** nodoInicial){
	char *aux;
	aux=malloc(sizeof(char)*MAX);
	puts("\n======================================\n\n");
	puts("Ingrese una palabra clave para la busqueda:");
	gets(aux);
	NodoOri* nodoTemp=*nodoInicial;
	for(i=0;nodoTemp!=NULL;i++){
		if(strstr(nodoTemp->Trab.desc,aux)){
			printf("\n\n------------TAREA CON PALABRA CLAVE %s ENCONTRADA------------",aux);
			printf("\nID: %d",nodoTemp->Trab.tareaID);
			puts("\nDescripcion de la tarea:");
			puts(nodoTemp->Trab.desc);
			printf("Duracion de la tarea: %d\n",nodoTemp->Trab.durac);
		}
		nodoTemp=nodoTemp->next;
	}
	fflush(stdin);
}

/*----------------------------Buscar Tarea ID----------------------------*/

void BuscarTareaPorID(NodoOri** nodoInicial,int id){
	/*int aux;
	puts("\n======================================\n\n");
	puts("Ingrese la ID del trabajo que desea buscar:");
	fflush(stdin);
	scanf("%d",&aux);*/
	NodoOri* nodoTemp=*nodoInicial;
	for(i=0;nodoTemp!=NULL;i++){
		if(nodoTemp->Trab.tareaID==id){
			printf("\n\n------------TAREA %d------------",i+1);
			printf("\nID: %d",nodoTemp->Trab.tareaID);
			puts("\nDescripcion de la tarea:");
			puts(nodoTemp->Trab.desc);
			printf("Duracion de la tarea: %d",nodoTemp->Trab.durac);
		}
		nodoTemp=nodoTemp->next;
	}
	fflush(stdin);
}

/*----------------------------Mostrar Datos----------------------------*/

void mostrarDatos(NodoOri** nodoInicial){
	NodoOri** nodoTemp=*nodoInicial;
	int m=0,t=0;
	while(nodoTemp!=NULL){
		t+=nodoTemp->Trab.durac;
		m++;
		nodoTemp=nodoTemp->next;
	}
	printf("\nCantidad de tareas: %d",m);
	printf("\nTiempo asociado a la lista: %d",t);
}
