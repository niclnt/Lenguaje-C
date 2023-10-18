#include "driver.h"
#include "Mock.h"
#include<stdio.h>

//#define DEBUG

datos_t leer_datos(void)
{
    datos_t acceso_datos;
    unsigned char puerto1, puerto2; //puerto 2 es 0x601, puerto1 es 0x600

    unsigned short int puertos_unidos;

    do{

            puerto1= Mock(PUERTO_1);
            puerto2= Mock(PUERTO_2);

            #ifdef DEBUG
            printf("\n [DRIVER][DO WHILE 0] puerto_2: 0x%02hhx  puerto1: 0x%02hhx",puerto2,puerto1);
            #endif

    }while(!(puerto2 & 0x80)); //si no cumple, sale, mientras tanto es verdadero y pasa de 0 a 1(invalido)


    do{

            puerto1= Mock(PUERTO_1);
            puerto2= Mock(PUERTO_2);


            #ifdef DEBUG
            printf("\n [DRIVER][DO WHILE 1] puerto_2: 0x%02hhx  puerto1: 0x%02hhx",puerto2,puerto1);
            #endif

    }while((puerto2 & 0x80));


    #ifdef DEBUG
    printf("\n [DRIVER][VALIDO] puerto_2: 0x%02hhx  puerto1: 0x%02hhx",puerto2,puerto1);
    #endif

    //aca el dato ya  es valido, por lo tanto extraigo los datos
    //primero que nada lo que hago es unir los puertos para que sea mas facil trabajar


    puertos_unidos= puerto2;
    puertos_unidos= (puerto2 << 8) | puerto1;


    acceso_datos.corriente = (puertos_unidos) & 0x3ff;
    acceso_datos.numero_lampara= (puertos_unidos >> 10) & 0x1f;


    return acceso_datos;
}

