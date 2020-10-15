#include <stdio.h>

int main (){
	int ancho = 30, alto = 15, i, j;
	for (i=1;i<=alto;i++){
		if(i==1 || i==alto){
		else{
		for(j=1;j<ancho-1;j++){
			if(i==1 || i==alto){
				printf("-");
			}
			else{
				printf(" ");
			}
		}
		if(i==1 || i==alto){
			printf("+");
		}
		else{
			printf("|");
		}
		printf("\n");
			}
		}
	}
}
	
	

