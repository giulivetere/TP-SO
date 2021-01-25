#include "configKernel.h"


t_ConfigKernel leerConfigKernel(){
	archivoConfigKernel = config_create(configKernelDir);

	log_info(loggerKernel, "Leyendo archivo de configuracion...");

	if (config_has_property(archivoConfigKernel, "IP_DE_MEMORIA")) {
		configKernel.ipDeMemoria = config_get_string_value(archivoConfigKernel,"IP_DE_MEMORIA");
	} else {
		log_error(loggerKernel,"No se encontro la key IP_DE_MEMORIA en el archivo de configuracion");
		exit(EXIT_FAILURE);
	}
	if (config_has_property(archivoConfigKernel, "PUERTO_DE_MEMORIA")) {
		configKernel.puertoDeMemoria = config_get_int_value(archivoConfigKernel,"PUERTO_DE_MEMORIA");
	} else {
		log_error(loggerKernel,"No se encontro la key PUERTO_DE_MEMORIA en el archivo de configuracion");
		exit(EXIT_FAILURE);
	}
	if (config_has_property(archivoConfigKernel, "QUANTUM")) {
		configKernel.quantum = config_get_int_value(archivoConfigKernel,"QUANTUM");
	} else {
		log_error(loggerKernel,"No se encontro la key QUANTUM en el archivo de configuracion");
		exit(EXIT_FAILURE);
		}
	if (config_has_property(archivoConfigKernel, "MULTIPROCESAMIENTO")) {
		configKernel.multiprocesamiento = config_get_int_value(archivoConfigKernel,"MULTIPROCESAMIENTO");
	} else {
		log_error(loggerKernel,"No se encontro la key MULTIPROCESAMIENTO en el archivo de configuracion");
		exit(EXIT_FAILURE);
	}
	if (config_has_property(archivoConfigKernel, "REFRESH_METADATA")) {
		configKernel.refreshMetaData = config_get_int_value(archivoConfigKernel,"REFRESH_METADATA");
	} else {
		log_error(loggerKernel,"No se encontro la key REFRESH_METADATA en el archivo de configuracion");
		exit(EXIT_FAILURE);
	}
	if (config_has_property(archivoConfigKernel, "RETARDO_CICLO_DE_EJECUCION")) {
		configKernel.retardoCicloDeEjecucion = config_get_int_value(archivoConfigKernel,"RETARDO_CICLO_DE_EJECUCION");
	} else {
		log_error(loggerKernel,"No se encontro la key RETARDO_CICLO_DE_EJECUCION en el archivo de configuracion");
		exit(EXIT_FAILURE);
	}

	return configKernel;

}
void mostrarDatosArchivoConfig(){
	printf("\n%s %s\n","IP_DE_MEMORIA: ",configKernel.ipDeMemoria);
	printf("%s %d\n","PUERTO_DE_MEMORIA: ",configKernel.puertoDeMemoria);
	printf("%s %d\n","QUANTUM: ",configKernel.quantum);
	printf("%s %d\n","MULTIPROCESAMIENTO: ",configKernel.multiprocesamiento);
	printf("%s %d\n","REFRESH_METADATA: ",configKernel.refreshMetaData);
	printf("%s %d\n","RETARDO_CICLO_DE_EJECUCION: ",configKernel.retardoCicloDeEjecucion);
	return;
}
void configurarLoggerKernel(){
	loggerKernel = log_create("kernel.log","kernel",1,LOG_LEVEL_INFO);
}

void exit_gracefully(int exitInfo){
	log_destroy(loggerKernel);
	exit(exitInfo);
}
