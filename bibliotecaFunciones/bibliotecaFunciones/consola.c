#include "consola.h"


int chequearValoresNULL(char** valor, int cantElementos){
	int i= 0;
	for(i=0;i<cantElementos;i++){
		if (valor[i]==NULL){
			return 1;
		}
	}
	return 0;

}

char* obtenerParametros(char* linea, int cantElementos){
	char** parametros = string_n_split(linea,cantElementos," ");
	if(chequearValoresNULL(parametros, cantElementos)!=0){
		return NULL;
	}
	else{
		char** p = string_n_split(linea,2," ");
		return p[1];
	}
}

int verificarCantidadParametrosPasados(char* linea){
	char** parametros = string_split(linea, " ");
	return tamanioArray(parametros);
}


int tamanioArray(char** array){
	int i = 0;
	while(array[i]!=NULL){
		i++;
	}
	return i;
}
int verificarQueDigaPalabraEspecifica(char* linea, char* palabra, int posicion){
	char** parametros = string_split(linea, " ");
	if(strcmp(parametros[posicion],palabra)!=0){
		return 1;
	}
	return 0;
}

