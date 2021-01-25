#ifndef BIBLIOTECAFUNCIONES_SOCKETS_H_
#define BIBLIOTECAFUNCIONES_SOCKETS_H_
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sockets.h>


int crearServidor();
void escuchar(int ,struct sockaddr_in);
int conectarAlServidor( char*, int );
#endif /* BIBLIOTECAFUNCIONES_SOCKETS_H_ */
