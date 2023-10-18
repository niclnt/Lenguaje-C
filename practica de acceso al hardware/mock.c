#include <stdio.h>
#include <stdlib.h>

#define PUERTO_0 0x400
#define PUERTO_1 0x401
#define CANT_INCUBADORAS 10
#define CANT_MEDICIONES 200

#define finalizar(x) ((x)|0x01)
#define armar_trama(temp,num) (((temp)&0x1FF)<<5)|(((num)&0x0F)<<1)
#define hacer_invalido(x) ((x)&0x7FFF)
#define hacer_valido(x) ((x)|0x8000)
#define obtener_byte0(x) ((x)&0xFF)
#define obtener_byte1(x) ((x)>>8)

unsigned short int genDato(void)
{
	static int incubadora = 0, temp, numMedicion = 0, fin = 0;
	static unsigned short int retVal=0;
	if(fin){
		retVal = finalizar(retVal);
		return retVal;
	}
	else{
		switch(incubadora){
			case 0: temp = 460;
					break;
			case 1: temp = 462;
					break;
			case 2: temp = 470;
					break;
			case 3: temp = 475;
					break;
			case 4: temp = 464;
					break;
			case 5: temp = 465;
					break;
			case 6: temp = 448;
					break;
			case 7: temp = 465;
					break;
			case 8: temp = 460;
					break;
			case 9: temp = 485;
					break;
		}
		temp += (numMedicion%5)*5;
		if(!(numMedicion%2)){
			retVal = armar_trama(temp,incubadora);
			if( incubadora == CANT_INCUBADORAS - 1 )
				numMedicion++;
			else
				incubadora++;
		}
		else{
			retVal = armar_trama(temp,incubadora);
			if( incubadora == 0 )
				numMedicion++;
			else
				incubadora--;
		}
		if( numMedicion == CANT_MEDICIONES )
			fin=1;
	}
	return retVal;
}

unsigned char inb(unsigned int puerto)
{
	static unsigned short int retVal=0;
	static unsigned char byte0=0,byte1=0;
	static int validez=0;
	if( puerto != PUERTO_0 && puerto != PUERTO_1 ){
		printf("\nERROR. Número de puerto incorrecto.\n");
		exit(1);
	}
	if ( puerto == PUERTO_0 )
	{
		if(validez == 4)
		{
			retVal = genDato();
			retVal = hacer_invalido(retVal);
			validez = 0;
		}
		else{
			validez++;
			retVal = hacer_valido(retVal);
		}
		byte1 = obtener_byte1(retVal);
		byte0 = obtener_byte0(retVal);
		return byte0;
	}
	if ( puerto == PUERTO_1 )
	{
		return byte1;
	}
	return 0;
}
