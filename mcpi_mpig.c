#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <mpi.h>
main(int argc, char** argv)
{
        // Definiciones 
        double x,y,z,pi;
        int i,count = 0,mycount,iterations = 100000;
        int rank,size,proc;
        MPI_Status status;
        // Iniciar MPI
        MPI_Init(&argc,&argv);
        // Numero de procesos
        MPI_Comm_size(MPI_COMM_WORLD,&size);
        // Rango del proceso
        MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        // Semilla por rango
        srand(rank);
        // Conteo parcial en 0
        mycount = 0;
        // Iniciar conteo
        for(i = 0;i < iterations;i++){
                // Coordenada X
                x = (double) rand()/RAND_MAX;
                // Coordenada Y
                y = (double) rand()/RAND_MAX;
                // Distancia al centro
                z = x*x+y*y;
                // Verifica si esta en el circulo
                if(z <= 1) mycount++;
        }
        // Imprimir en pantalla
        printf("Proceso %d tiene un conteo total de = %d\n",rank,mycount);
        // Reductor que sumara todas las sumatorias parciales de coordenadas que caen en el circulo
        MPI_Reduce(&mycount,&count,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
        // El proceso 0 se encarga de estimar pi cuando se hayan sumado todos los conteos parciales
        if (rank == 0) {
                // Estimacion de pi, el tamaño de puntos generados sera igual al numero de procesos por el numero de iteraciones
                pi = (double) 4*count/(size*iterations);
                // Imprimir en pantalla
                printf("Cantidad de Iteraciones = %d, Pi estimado: %g \n",size*iterations,pi);
        }
        // Finalizar MPI
        MPI_Finalize();
        // Finalizar
        return 0;
}