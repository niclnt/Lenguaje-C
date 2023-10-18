#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED


typedef struct
{
    unsigned int temperatura;
    unsigned int numero_incubadora;
    unsigned int finaliza;

}info_driver_t;


info_driver_t leer_info(void);

#endif // DRIVER_H_INCLUDED
