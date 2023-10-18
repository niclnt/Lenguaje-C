#include <stdio.h>
#include <stdlib.h>
#include"driver.h"


void main(void)
{
    int i;
    info_driver_t datos;


    for(i=0;i<10;i++)
    {
       datos= leer_info();

       printf("\n\n [app]  temperatura: %u | numero de incubadora: %u",datos.temperatura,datos.numero_incubadora);
    }




    return 0;
}
