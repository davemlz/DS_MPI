#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
main(int argc, char* argv)
{
   // Definiciones
   int iterations = 10000;
   double x,y,z,pi;
   int i,count = 0;
   // Iniciar iteraciones
   for(i = 0;i < iterations;i++){
      // Coordenada x
      x = (double) rand()/RAND_MAX;
      // Coordenada y
      y = (double) rand()/RAND_MAX;
      // Distancia al centro
      z = x*x+y*y;
      // Verificar si la coordenada esta dentro del circulo
      if(z <= 1) count++;
      }
   // Estimacion de pi
   pi = (double) 4*count/iterations;
   // Imprimir en pantalla
   printf("Cantidad de Iteraciones = %d, Pi estimado: %g \n",iterations,pi);
   // Finalizar
   return 0;
}