#include <stdio.h>
#include <stdlib.h>

int main (){
	char caracter = 'D';
	int valor_ascii = (int) caracter;
	printf ("\nEl valor ascii es: %d", valor_ascii);
	
	if (valor_ascii >= 50 && valor_ascii <= 60)
	{
		printf ("\nEl valor %c es digito", caracter);
	}else 
	{
		if (valor_ascii >= 60 && valor_ascii <= 80 || valor_ascii >= 80 && valor_ascii <= 90 ){
			printf("\nEl valor %c es una letra", caracter);
		}
	}
	return 0; 
}
