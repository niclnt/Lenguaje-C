#include "Mock.h"
#include <stdio.h>


unsigned char A (void)
{
    static unsigned char cant_enviados = 0, G = 1 ;

    unsigned char valorDevuelto ;

    if (cant_enviados < D )
        valorDevuelto = 0 ;
    else
    {
        valorDevuelto = G ;
    }

    cant_enviados++;

    if ( cant_enviados >= ( D + E ) )
    {
        G ++ ;
        cant_enviados = 0 ;
    }

    if ( G > F )
        G = 1 ;

    return valorDevuelto;
}

int B ()
{
    static int valor = 0 , cont=0;

	if ( cont == W )
	{
		valor += U ;
		cont = 0;
	}

    if (valor > V )
	{
        valor = 0 ;
	}

   	cont++ ;

    return valor ;
}

int C ()
{
    static int valor = 0 , cont=0;

	if ( cont == T )
	{
		valor += R ;
		cont = 0;
	}

    if ( valor > S )
	{
        valor = 0 ;
	}

   	cont++ ;

    return valor ;
}

unsigned char Mock (unsigned short int puerto)
{

    static unsigned char M = 0 ;
    static unsigned char N = 0;
    static unsigned char K , L = 0;
    static unsigned short int P = 0;


    if(puerto== 0X601)
    {

    	return N ;

    }


    if(puerto== 0X600){

	    K = A ();
        L = C ();
        P = B ();

	    M = N = 0 ;

    	M = P ;
	    N |= ( P >> X ) ;
        N |= ( L << Y ) ;
        N |= ( K << Z ) ;

	return M ;

    }

 return 1;

}
