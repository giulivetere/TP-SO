#ifndef TEMPORAL_H_
#define TEMPORAL_H_
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <string.h>

char* obtenerParametros(char*, int);
int chequearValoresNULL(char** , int );
int verificarQueDigaPalabraEspecifica(char*, char*, int);
int tamanioArray(char** );

#endif /* TEMPORAL_H_ */
