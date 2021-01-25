#include "sockets.h"
int crearServidor(){
	int servidor,aceptar = 1;
	if((servidor= socket(AF_INET, SOCK_STREAM, 0))==-1){
		salir_con_error(servidor,"Error al asignar socket");
		//perror("Error al asignar socket");
			//exit(1);
		}
	//si socket ya esta siendo utilizado tira error
	if (setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &aceptar, sizeof(aceptar))){
		salir_con_error(servidor,"Socket utilizado");
		//perror("Socket utilizado");
		//exit(EXIT_FAILURE);
	}
	return servidor;
}

void escuchar(int servidor,struct sockaddr_in dirSocket){
	if(bind(servidor,(struct sockaddr *)&dirSocket,sizeof(dirSocket))<0){
		salir_con_error(servidor,"Error al esperar conexion");
		//perror("Error al esperar conexion");
		//exit(1);
	}
	if(listen(servidor,100)==-1){
		salir_con_error(servidor,"Error al escuchar");
		//perror("Error al escuchar");
		//exit(1);
	}
}

int conectarAlServidor( char* ip, int puerto){
	char* ipSinComillas=string_substring(ip,1,(string_length(ip)-2));
	struct sockaddr_in dirSocket;
	int cliente;
	cliente= socket(AF_INET, SOCK_STREAM, 0);
	if(cliente==-1){
		salir_con_error(cliente,"Error al crear el socket");
		printf("\n Error al crear socket");
		return -1;
	}
	memset(&dirSocket,'0',sizeof(dirSocket));
	dirSocket.sin_family = AF_INET;
	//dirSocket.sin_addr.s_addr = inet_addr(ipConst);
	dirSocket.sin_port = htons(puerto);

	if(inet_pton(AF_INET, ipSinComillas, &dirSocket.sin_addr)<=0)
	    {
	    salir_con_error(cliente,"Direccion invalida/no soportada");
	printf("\nDireccion invalida/ Direccion no soportada\n");
	       return -1;
	    }

	if(connect(cliente,(struct sockaddr*)&dirSocket,sizeof(dirSocket))<0){
	    //salir_con_error(cliente,"Error al conectar el socket");
		perror("No se pudo realizar la conexion");
		return 1;
	}
	return cliente;
}


