#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include"driver.h"
typedef struct
{
    unsigned int maximo;
    unsigned int acumulador;
    unsigned int cant_mediciones;
    unsigned int alertas;
    unsigned int num_lampara;

}info_lamparas;

void inicializar_vectores(info_lamparas * reporte, int cant);

void hallar_resultados (datos_t datos_driver, info_lamparas*reporte, int cant);
int medir_suficiencia(info_lamparas* reporte, int cant);

void imprimir_reporte(info_lamparas * datos, int cant);

void ordenar_reporte(info_lamparas * datos, int cant);
#endif // FUNCIONES_H_INCLUDED
