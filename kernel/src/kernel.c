#include "kernel.h"


int main(void){
	configurarLoggerKernel();
	configKernel =leerConfigKernel();
	mostrarDatosArchivoConfig();
	crearConsolaKERNEL();
	exit_gracefully(EXIT_SUCCESS);
	return 0;
}
