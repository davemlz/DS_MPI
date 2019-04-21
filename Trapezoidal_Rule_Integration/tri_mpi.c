#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <mpi.h>
// Definicion de la funcion a integrar
float f(float x)
{
    // f(x) = 1/(1+x*x) 
    return 1/(1+x*x);
}
main(int argc, char** argv)
{
        // Definiciones
        double a = 0, b = 1, h, result = 0,myresult, x_i,a_proc,b_proc,h_proc,part,s_proc;
        int i, n, rank, size, proc;
        MPI_Status status;
        // Iniciar MPI
        MPI_Init(&argc,&argv);
        // Numero de procesos
        MPI_Comm_size(MPI_COMM_WORLD,&size);
        // Rango del proceso
        MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        // El proceso 0 se encarga de recibir las sumas parciales de los otros procesos y sumarlas
        if (rank == 0) {
                // La suma es 0 inicialmente
                result = 0;
                // Para cada proceso recibira la suma parcial y las sumará
                for (proc=1; proc < size; proc++) {
                 MPI_Recv(&myresult,1,MPI_DOUBLE,proc,1,MPI_COMM_WORLD,&status);
                 result +=myresult;
                }
                // Imprimir en pantalla
                printf("VALOR APROXIMADO FINAL DE LA INTEGRAL DESDE 0 A 1 DE 1/(1+x^2) = %g\n",result);
        }
        // Si no es el proceso 0 entonces realizara particiones dependiendo de la cantidad de procesos (exceptuando el 0) y a cada particion le calculara la suma por el metodo de rectangulo
        else {
                // La suma parcial inicial de cada particion es 0
                myresult = 0;
                // Longitud de particiones
                part = (b-a)/(size-1);
                // Cantidad de rectangulos por particion
                n = 6;
                // Valor inicial de la particion
                a_proc = part*rank - part;
                // Valor final de la particion
                b_proc = part*rank;
                // Ancho de la particion
                h_proc = (b_proc - a_proc)/n;
                // Suma del primero y ultimo valor de la integral definida 
                s_proc = f(a_proc)+f(b_proc);
                // Inicio de algoritmo del trapezoide
                for(i = 1;i < n;i++){
                    s_proc += 2*f(a_proc+i*h_proc);
                }
                // Valor final 
                myresult = (h_proc/2)*s_proc;
                // Imprimir en pantalla
                printf("Valor aproximado de la integral desde %g a %g de 1/(1+x^2) = %g en el proceso %d\n",a_proc,b_proc,myresult,rank);
                // Enviar suma parcial al proceso 0
                MPI_Send(&myresult,1,MPI_DOUBLE,0,1,MPI_COMM_WORLD);
        }
        // Finalizar MPI
        MPI_Finalize();
        // Finalizar		
        return 0;
}
