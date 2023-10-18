#include <stdio.h>
#include <stdlib.h>
#define CANT 30
#include"funciones.h"
#include "driver.h"


int main(void)
{
    datos_t lampara;
    info_lamparas datos[CANT];

    inicializar_vectores(datos,CANT);

    do{
        lampara = leer_datos();
        hallar_resultados(lampara,datos,CANT);

    } while(medir_suficiencia(datos,CANT));

    ordenar_reporte(datos, CANT);

    imprimir_reporte(datos, CANT);







}

