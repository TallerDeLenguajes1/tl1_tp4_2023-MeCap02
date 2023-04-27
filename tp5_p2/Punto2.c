#include"funcionesPrincipales.h"

/*----------------------------Funcion Principal----------------------------*/

int main(int argc,char** argv){
	int n;
	NodoOri* Laburo=crearLista();
	NodoOri* LaburosComp=crearLista();
	NodoOri* LaburoEnp=crearLista();
	NodoOri** punTar=&Laburo;
	NodoOri** punCom=&LaburosComp;
	NodoOri** punEnp=&LaburoEnp
	srand(time(NULL));
	puts("================TAREAS================");
	puts("\nCuantas tareas desea ingresear?:");
	scanf("%d",&n);
	if(n<1){
		puts("Ingrese un valor valido");
		scanf("%d",&n);
	}
	cargarTareas(punTar,n); //x
	preguntarTareas(punTar,punCom,punEnp); //x
	liberar(punTar); //x
	liberar(punCom); //x
	liberar(punEnp); //x
	return 0;
}
