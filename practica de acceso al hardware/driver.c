#include"driver.h"
#include"mock.h"
#include<stdio.h>
#define PRUEBA



info_driver_t leer_info(void)
{
    info_driver_t acceder;
    unsigned int puerto0,puerto1;

    unsigned short int puertos_unidos;


    do
    {
        puerto0= inb(PUERTO_0);
        puerto1= inb(PUERTO_1);

        #ifdef PRUEBA
        printf("\n\n [driver][do while 0] puerto 1: 0x%02hhx    puerto0: 0x%02hhx",puerto1,puerto0);
        #endif


    }while((puerto1 & 0x80)); //invalido


    do
    {
        puerto0= inb(PUERTO_0);
        puerto1= inb(PUERTO_1);

        #ifdef PRUEBA
        printf("\n\n [driver][do while 1] puerto 1: 0x%02hhx    puerto0: 0x%02hhx",puerto1,puerto0);
        #endif

    }while((!(puerto1 & 0x80)) && (puerto0 & 0xfe));//valido


        #ifdef PRUEBA
        printf("\n\n [driver][VALIDO] puerto 1: 0x%02hhx    puerto0: 0x%02hhx",puerto1,puerto0);
        #endif

    puertos_unidos=puerto1;
    puertos_unidos=(puerto1 << 8) | puerto0;

    acceder.temperatura= (puertos_unidos>> 5) & 0x1ff;
    acceder.numero_incubadora=(puertos_unidos >> 1) & 0xf;
    //acceder.finaliza=(puertos_unidos)& 0xfffe;


    return acceder;

}
