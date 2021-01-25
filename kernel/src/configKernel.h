#ifndef CONFIGKERNEL_H_
#define CONFIGKERNEL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <commons/log.h>
#include <commons/collections/list.h>
#include <commons/config.h>

#define configKernelDir "/home/utnso/Documentos/tp-2019-1c-Non-lol/kernel.conf"
t_log * loggerKernel;
t_config *archivoConfigKernel;
typedef struct
{
	char *ipDeMemoria;
	int puertoDeMemoria;
	int quantum;
	int multiprocesamiento;
	int refreshMetaData;
	int retardoCicloDeEjecucion;

}t_ConfigKernel;

t_ConfigKernel configKernel;


t_ConfigKernel leerConfigKernel(void);
void mostrarDatosArchivoConfig();
void configurarLoggerKernel();
void exit_gracefully(int exitInfo);

#endif /* CONFIGKERNEL_H_ */
