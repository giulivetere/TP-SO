#include "socketsKernel.h"

void* crearServidorHilo(){
    while((cliente = accept(servidorKernel, (struct sockaddr *)&dirMemoria, &dirMemoriaLen))){
        log_info(loggerKernel,"Cliente aceptado");
        if(damSafa==0){
        	recibirHandShakeSAFA(cliente,DAM);
        	damSafa=cliente;
        	sem_post(&semHayDam);
        }
        else{
        	recibirHandShakeSAFA(cliente,CPU);
        	list_add(CPUSAFA,&cliente);
        	sem_post(&semHayCpu);

        }
        hiloConSocket* nuevoHilo = malloc(sizeof(hiloConSocket));
        nuevoHilo->socket = cliente;
        pthread_create(&nuevoHilo->hilo,NULL,servidor,&cliente);
    }
    close(cliente);
    close(servidorSAFA);
    return NULL;
}
