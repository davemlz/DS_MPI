# DS_MPI

## Creadores

- David Montero Loaiza. email: david.montero@correounivalle.edu.co
- Juan Manuel Valencia Correa. email: juan.valencia@correounivalle.edu.co

## Contenido

### Montecarlo Pi

#### Implementación Secuencial
La implementación secuencial del algoritmo de estimación de pi por el método de Montecarlo se encuentra en `mcpi.c`.

#### Implementación Distribuida con MPI
La implementación distribuida del algoritmo de estimación de pi por el método de Montecarlo se encuentra en `mcpi_mpi.c`. En esta implementación, por cada proceso -exceptuando el proceso 0- se generarán un total de n puntos aleatorios y cada uno enviará al proceso 0 el conteo de los puntos que sí cumplen la condición del método de Montecarlo para que este estime el valor de pi.

### Integral por el Método del Rectángulo

### Integral por la Regla del Trapezoide
