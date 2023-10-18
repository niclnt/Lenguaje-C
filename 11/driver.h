#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED

typedef struct
{
    unsigned int corriente;
    unsigned int numero_lampara;

}datos_t;

datos_t leer_datos(void);

#endif // DRIVER_H_INCLUDED
