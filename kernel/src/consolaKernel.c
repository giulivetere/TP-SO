#include "consolaKernel.h"

void* crearConsolaKERNEL(){
	char* linea;
	while(1){
		linea = readline(">");

		if(linea){
			add_history(linea);
		}
		if(!strncmp(linea,"SELECT",6)){
			char* parametros = obtenerParametros(linea,3);
			if(parametros == NULL || string_is_empty(parametros)){
				log_error(loggerKernel,"No se ha especificado nombre de tabla o key");
				free(parametros);
			} else if (verificarCantidadParametrosPasados(linea)>3){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else{
				puts("SI, MANDASTE TODO (SELECT)"); // aca haria lo que hace el select
				free(parametros);
			}
		}
		else if(!strncmp(linea,"INSERT",6)){
			char* parametros = obtenerParametros(linea,5);
			if(parametros==NULL || string_is_empty(parametros)){
				log_error(loggerKernel,"No se ha especificado nombre de tabla, key, value o timestamp");
				free(parametros);
			} else if (verificarCantidadParametrosPasados(linea)>5){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else {
				puts("SI, MANDASTE TODO (INSERT)"); //aca haria lo que hace el insert
				free(parametros);
			}
		}

		else if(!strncmp(linea,"CREATE",6)){
			char* parametros = obtenerParametros(linea,5);
			if(parametros == NULL || string_is_empty(parametros)){
				log_error(loggerKernel,"No se ha especificado nombre de tabla, tipo de consistencia, numero de particiones o compaction time");
				free(parametros);
			}else if (verificarCantidadParametrosPasados(linea)>5){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else{
				puts("SI, MANDASTE TODO (CREATE)"); //aca haria lo que hace el create
				free(parametros);
			}
		}

		else if(!strncmp(linea,"DESCRIBE",8)){
			char* parametros = obtenerParametros(linea,2);
			if(parametros == NULL || string_is_empty(parametros)){
				//retorna contenido de archivos de metadata
				puts ("SI, MANDASTE 0 PARAMETROS(DESCRIBE)");
				free(parametros);
			}
			else if(verificarCantidadParametrosPasados(linea)==2){
				//retorna contenido archivo tabla especifica
				puts("SI, MANDASTE TODO (DESCRIBE)"); //aca haria todo lo que hace el describe
				free(parametros);
			}
			else {
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
		}
		else if(!strncmp(linea,"DROP",4)){
			char* parametros = obtenerParametros(linea,2);
			if(parametros == NULL || string_is_empty(parametros)){
				log_error(loggerKernel,"No se ha especificado nombre de tabla");
				free(parametros);
			}else if (verificarCantidadParametrosPasados(linea)>2){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else{
				puts("SI, MANDASTE TODO (DROP)"); //aca haria lo que hace el drop
				free(parametros);
			}
		}
		else if(!strncmp(linea,"JOURNAL",7)){
			char* parametros = obtenerParametros(linea,1);
			if (verificarCantidadParametrosPasados(linea)>1){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else{
				puts("SI, MANDASTE TODO (JOURNAL)"); //aca haria lo que hace el journal
				free(parametros);
			}
		}
		else if(!strncmp(linea,"METRICS",7)){
			char* parametros = obtenerParametros(linea,1);
			if (verificarCantidadParametrosPasados(linea)>1){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else{
				puts("SI, MANDASTE TODO (METRICS)"); //aca haria lo que hace el metrics
				free(parametros);
			}
		}
		else if(!strncmp(linea,"ADD",3)){
			char* parametros = obtenerParametros(linea,5);
			if(parametros == NULL || string_is_empty(parametros)){
				log_error(loggerKernel,"No se ha especificado a quien darle memoria y con que criterio");
				free(parametros);
			}else if (verificarCantidadParametrosPasados(linea)>5){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else if(verificarQueDigaPalabraEspecifica(linea,"MEMORY",1)!=0 ||verificarQueDigaPalabraEspecifica(linea,"TO",3)!=0 ){
				log_error(loggerKernel,"La sintaxis no es correcta");
				free(parametros);
			}
			else{
				puts("SI, MANDASTE TODO (ADD)"); //aca haria lo que hace el add
				free(parametros);
			}
		}
		else if(!strncmp(linea,"RUN",3)){
			char* parametros = obtenerParametros(linea,2);
			if(parametros == NULL || string_is_empty(parametros)){
				log_error(loggerKernel,"No se ha especificado el path");
				free(parametros);
			}else if (verificarCantidadParametrosPasados(linea)>2){
				log_error(loggerKernel,"Se han pasado mas parametros de los requeridos");
				free(parametros);
			}
			else{
				puts("SI, MANDASTE TODO (RUN)"); //aca haria lo que hace el run
				free(parametros);
			}
		}
		else if(!strncmp(linea,"EXIT",4)){
			exit_gracefully(EXIT_SUCCESS);
			free(linea);
			break;
		}
		else{
			log_error(loggerKernel,"No se ingreso ningun comando valido");
		}
		free(linea);
	}
	return NULL;
}

