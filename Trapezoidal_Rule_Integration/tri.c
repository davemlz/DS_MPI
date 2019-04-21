#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
// Definicion de la funcion a integrar
float f(float x)
{
    // f(x) = 1/(1+x*x) 
    return 1/(1+x*x);
}
main(int argc, char* argv)
{
   // Definiciones
    float a = 0;
    float b = 1;
    float result;
    
    // Cantidad de divisiones 
    int n = 6;
  
    // Ancho del trapezoide 
    float h = (b-a)/n;
    // Suma del primero y ultimo valor de la integral definida 
    float s = f(a)+f(b);
    // Suma de los valores intermedios
    for(int i = 1; i < n; i++){
        s += 2*f(a+i*h);
    }
    
    // Valor final 
    result = (h/2)*s;
    // Imprimir en pantalla    
    printf("Valor aproximado de la integral = %g\n",result);
    // Finalizar
    return 0;
}