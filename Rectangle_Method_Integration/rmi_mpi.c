#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <mpi.h>
main(int argc, char** argv)
{
        // Definiciones
        double a = 0, b = 1, w, sum = 0,mysum, x_i,a_proc,b_proc,w_proc,part;
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
                        sum = 0;
                        // Para cada proceso recibira la suma parcial y las sumará
                        for (proc=1; proc < size; proc++) {
                         MPI_Recv(&mysum,1,MPI_DOUBLE,proc,1,MPI_COMM_WORLD,&status);
                         sum +=mysum;
                        }
                        // Imprimir en pantalla
                        printf("VALOR APROXIMADO FINAL DE LA INTEGRAL DESDE 0 A 1 DE x ELEVADO A LA 3 = %g\n",sum);
        }
        // Si no es el proceso 0 entonces realizara particiones dependiendo de la cantidad de procesos (exceptuando el 0) y a cada particion le calculara la suma por el metodo de rectangulo
        else {
                        // La suma parcial inicial de cada particion es 0
                        mysum = 0;
                        // Longitud de particiones
                        part = (b-a)/(size-1);
                        // Cantidad de rectangulos por particion
                        n = 100000;
                        // Valor inicial de la particion
                        a_proc = part*rank - part;
                        // Valor final de la particion
                        b_proc = part*rank;
                        // Ancho de la particion
                        w_proc = (b_proc - a_proc)/n;
                        // Inicio de algoritmo del rectangulo
                        for(i = 1;i <= n;i++){
                                // Valor que toma x_i
                                x_i = a_proc + (i-1)*w_proc;
                                // Calculo de la sumatoria del rectangulo: ancho x largo
                                // Funcion: x^3
                                mysum = mysum + ( w_proc * (x_i * x_i * x_i) );
                        }
                        // Imprimir en pantalla
						printf("Valor aproximado de la integral desde %g a %g de x elevado a la 3 = %g en el proceso %d\n",a_proc,b_proc,mysum,rank);
                        // Enviar suma parcial al proceso 0
                        MPI_Send(&mysum,1,MPI_DOUBLE,0,1,MPI_COMM_WORLD);
        }
        // Finalizar MPI
        MPI_Finalize();
        // Finalizar
        return 0;
}