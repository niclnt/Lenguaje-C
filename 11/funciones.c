#include"funciones.h"

#include<stdio.h>

void inicializar_vectores(info_lamparas * reporte, int cant)
{
    int i;

    for(i=0;i<cant;i++)
    {
        reporte[i].maximo=0;
        reporte[i].acumulador=0;
        reporte[i].cant_mediciones=0;
        reporte[i].alertas=0;
        reporte[i].num_lampara=i;
    }

}

void hallar_resultados (datos_t datos_driver, info_lamparas*reporte, int cant)
{
    int i = datos_driver.numero_lampara;



    if(datos_driver.corriente > reporte[i].maximo)
    {
        reporte[i].maximo=datos_driver.corriente;

        reporte[i].cant_mediciones++;
        reporte[i].acumulador+=datos_driver.corriente;
    }


    if(datos_driver.corriente < 5)
    {
        reporte[i].alertas++;
    }


}

int medir_suficiencia(info_lamparas* reporte, int cant)
{
    int i;

    for(i=0;i<cant;i++)
        if(reporte[i].cant_mediciones< 100)
              {
                  return 1;
              }

    return 0;


}

void imprimir_reporte(info_lamparas * datos, int cant)
{
    int i;
    printf("\n\n---------REPORTE--------\n");

    for(i=0;i<cant;i++)
    {
        printf("\n\n lampara: %2u | maximo: %5u | promedio: %.2f | mediciones:  %3u | Alertas: %3u ", datos[i].num_lampara,datos[i].maximo,(float)datos[i].acumulador/datos[i].cant_mediciones,datos[i].cant_mediciones,datos[i].alertas );
    }

    printf("\n\n----- FIN REPORTE -----\n");
}


void ordenar_reporte(info_lamparas * datos, int cant)
{
    info_lamparas auxiliar;
    int i,j;

    for(i=0;i<cant-1;i++)
        for(j=0;j<cant-1-i;j++)
    if(datos[i].alertas< datos[j+1].alertas)
    {
        auxiliar=datos[j];
        datos[j]=datos[j+1];
        datos[j+1]=auxiliar;
    }
}

