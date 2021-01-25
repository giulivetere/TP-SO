#ifndef LFS_H_
#define LFS_H_

#include <stdio.h> // Por dependencia de readline en algunas distros de linux :)
#include <openssl/md5.h> // Para calcular el MD5
#include <string.h>
#include <stdlib.h> // Para malloc
#include <sys/socket.h> // Para crear sockets, enviar, recibir, etc
#include <netdb.h> // Para getaddrinfo
#include <unistd.h> // Para close
#include <readline/readline.h> // Para usar readline
#include <readline/history.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <libgen.h>

#include <commons/log.h>
#include <commons/collections/list.h>
#include <commons/config.h>
#include <commons/bitarray.h>
#include <commons/string.h>
#include <commons/collections/dictionary.h>
#include <commons/txt.h>

#include "varios.h"


//## CONFIG #################
t_config *archivoConfig;

typedef struct
{
	int puertoEscucha;
	char *puntoMontaje;
	int retardo;
	int tamanioValue;
	int tiempoDump;
}t_ConfigLFS;

//VARIABLES GLOBALES
t_ConfigLFS configLFS;
t_log *logger;

//PROTOTIPOS DE FUNCIONES
void leerConfigLFS(void);
void mostrarValoresDeConfig(void);
void exitLFS(int);

void consolaAPI(void);

#endif /* LFS_H_ */
