#include "lfs.h"

int main(void) {

	leerConfigLFS();
	mostrarValoresDeConfig();

	consolaAPI();

	exitLFS(0);

	return EXIT_SUCCESS;
}

void leerConfigLFS()
{
	archivoConfig = config_create("../../lfs.conf");
	logger = log_create("lfs.log", "lfs", 1,LOG_LEVEL_INFO);

	log_info(logger,"\n\nINICIANDO PROCESO LFS...");
	log_info(logger, "Leyendo archivo de configuracion...");


	if (config_has_property(archivoConfig, "PUERTO_ESCUCHA"))
		configLFS.puertoEscucha = config_get_int_value(archivoConfig,"PUERTO_ESCUCHA");
	else
	{
		log_error(logger,"No se encontro la key PUERTO_ESCUCHA en el archivo de configuracion");
		exitLFS(EXIT_FAILURE);
	}

	if (config_has_property(archivoConfig, "PUNTO_MONTAJE"))
		configLFS.puntoMontaje = config_get_string_value(archivoConfig,"PUNTO_MONTAJE");
	else
	{
		log_error(logger,"No se encontro la key PUNTO_MONTAJE en el archivo de configuracion");
		exitLFS(EXIT_FAILURE);
	}

	if (config_has_property(archivoConfig, "RETARDO"))
		configLFS.retardo = config_get_int_value(archivoConfig,"RETARDO");
	else
	{
		log_error(logger,"No se encontro la key RETARDO en el archivo de configuracion");
		exitLFS(EXIT_FAILURE);
	}

	if (config_has_property(archivoConfig, "TAMAÑO_VALUE"))
		configLFS.tamanioValue = config_get_int_value(archivoConfig,"TAMAÑO_VALUE");
	else
	{
		log_error(logger,"No se encontro la key TAMAÑO_VALUE en el archivo de configuracion");
		exitLFS(EXIT_FAILURE);
	}

	if (config_has_property(archivoConfig, "TIEMPO_DUMP"))
		configLFS.tiempoDump = config_get_int_value(archivoConfig,"TIEMPO_DUMP");
	else
	{
		log_error(logger,"No se encontro la key TIEMPO_DUMP en el archivo de configuracion");
		exitLFS(EXIT_FAILURE);
	}
}

void mostrarValoresDeConfig(void)
{
	printf("\nPUERTO_ESCUCHA: %d\n",configLFS.puertoEscucha);
	printf("PUNTO_MONTAJE: %s\n",configLFS.puntoMontaje);
	printf("RETARDO: %d\n",configLFS.retardo);
	printf("TAMAÑO_VALUE: %d\n",configLFS.tamanioValue);
	printf("TIEMPO_DUMP: %d\n\n",configLFS.tiempoDump);
}

void exitLFS(int return_nr)
{
	config_destroy(archivoConfig);
	//config_destroy(archivoMetadata);
	log_destroy(logger);

	//close(socketLFS);
	exit(return_nr);
}

void consolaAPI()
{
	char *linea;
	char **operacion;
	int cantArgumentos;

	while(1)
	{
	    linea = readline(">");

	    if(linea)
	    	add_history(linea);

	    operacion = string_split(linea," ");
	    free(linea);
	    cantArgumentos = longitudArrayDePunteros(operacion) - 1; //XQ LA OPERACION CUENTA

	    if(!strcmp(operacion[0], "exit")) //###
	    {
	    	if(cantArgumentos == 0)
	    	{
	    		log_info(logger,"Finalizo LFS");
	    		break;
	    	}
	    	else
	    		printf("Esta operacion no admite parametros\n");

	    }
	    else if(!strcmp(operacion[0], "select")) //###
	    {
	    	if(cantArgumentos == 2)
	    	{
	    		log_info(logger,"Operacion SELECT");
	    		printf("Parametros: [%s][%s]\n",operacion[1],operacion[2]);
	    		//IMPRIMO POR PANTALLA EL RESULTADO DE LA OPERACION
	    	}
	    	else
	    		printf("Falta, o hay exceso, de parametros de SELECT\n");

	    }
	    else if(!strcmp(operacion[0], "insert")) //###
	    {
	    	if(cantArgumentos == 3)
	    	{
	    		log_info(logger,"Operacion INSERT");
	    		printf("Parametros: [%s][%s][%s]\n",operacion[1],operacion[2],operacion[3]);
	    		//IMPRIMO POR PANTALLA EL RESULTADO DE LA OPERACION
	    	}
	    	else if(cantArgumentos == 4)
	    	{
	    		log_info(logger,"Operacion INSERT");
	    		printf("Parametros: [%s][%s][%s][%s]\n",operacion[1],operacion[2],operacion[3],operacion[4]);
	    		//IMPRIMO POR PANTALLA EL RESULTADO DE LA OPERACION
	    	}
	    	else
	    		printf("Falta, o hay exceso, de paramentros de INSERT\n");

	    }
	    else if(!strcmp(operacion[0], "create")) //###
	    {
	    	if(cantArgumentos == 4)
	    	{
	    		log_info(logger,"Operacion CREATE");
	    		printf("Parametros: [%s][%s][%s][%s]\n",operacion[1],operacion[2],operacion[3],operacion[4]);
	    		//IMPRIMO POR PANTALLA EL RESULTADO DE LA OPERACION
	    	}
	    	else
	    		printf("Falta, o hay exceso, de parametros de CREATE\n");
	    }
	    else if(!strcmp(operacion[0], "describe")) //###
	    {
	    	//EL UNICO ARGUMENTO PUEDE SER OPCIONAL
	    	if(cantArgumentos == 0)
	    	{
	    		log_info(logger,"Operacion DESCRIBE");
	    		printf("Parametros: [sin Parametros]\n");
	    		//IMPRIMO POR PANTALLA EL RESULTADO DE LA OPERACION (TODAS LAS TABLAS)
	    	}
	    	else if(cantArgumentos == 1)
	    	{
	    		log_info(logger,"Operacion DESCRIBE");
	    		printf("Parametros: [%s]\n",operacion[1]);
	    		//IMPRIMO POR PANTALLA EL RESULTADO DE LA OPERACION (TODAS LAS TABLAS)
	    	}
	    	else
	    		printf("Exceso de parametros de DESCRIBE\n");
	    }
	    else if(!strcmp(operacion[0], "drop")) //###
	    {
	    	if(cantArgumentos == 1)
	    	{
	    		log_info(logger,"Operacion DROP");
	    		printf("[%s]\n",operacion[1]);
	    	}
	    	else
	    		printf("Falta, o hay exceso, de parametros de DROP\n");
	    }
	    else
	    {
	    	log_info(logger,"Operacion no valida por la API");
	    }
	}
}
