#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
main(int argc, char* argv)
{
	// Definiciones
	double a = 0, b = 1, w, sum = 0, x_i;
	int i, n;
	
	// Cantidad de rectangulos
	n = 100000;
	
	// Ancho de rectangulos
	w = (b-a)/n;	

	// Inicio de algoritmo del rectangulo
	for(i = 1;i <= n;i++){
		
		// Valor que toma x_i
		x_i = a + (i-1)*w;

		// Calculo de la sumatoria del rectangulo: ancho x largo
		// Funcion: x^3
		sum = sum + ( w * (x_i * x_i * x_i) );
		
	}
	
	// Imprimir en pantalla
	printf("Valor aproximado de la integral desde 0 a 1 de x elevado a la 3 = %g\n",sum);
	
	// Finalizar
	return 0;
}
