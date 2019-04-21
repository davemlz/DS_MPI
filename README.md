# DS_MPI

## Creadores

- David Montero Loaiza. email: david.montero@correounivalle.edu.co
- Juan Manuel Valencia Correa. email: juan.valencia@correounivalle.edu.co

## Contenido

### Montecarlo Pi

- `mcpi.c`. Implementación secuencial del algoritmo de estimación de pi por el método de Montecarlo.
- `mcpi_mpi.c`. Implementación distribuida del algoritmo de estimación de pi por el método de Montecarlo. En esta implementación, por cada proceso (exceptuando el proceso 0) se generarán un total de n puntos aleatorios y cada uno enviará al proceso 0 el conteo de los puntos que sí cumplen la condición del método de Montecarlo para que este estime el valor de pi.
- `mcpi_mpig.c`. Implementación distribuida con MPI y funciones grupales del algoritmo de estimación de pi por el método de Montecarlo. En esta implementación, por cada proceso (esta vez incluyendo el proceso 0) se generarán un total de n puntos aleatorios y cada uno generará un conteo de los puntos que sí cumplen la condición del método de Montecarlo. Todos los conteos se sumarán haciendo uso de la función `MPI_Reduce` con la operación `MPI_SUM` para que el proceso 0 se encargue finalmente de estimar el valor de pi.

### Integral por el Método del Rectángulo

#### Implementación Secuencial
La implementación secuencial del algoritmo de estimación del valor de una integral definida por el método del rectángulo se encuentra en  `rmi.c`.

#### Implementación Distribuida con MPI
La implementación distribuida del algoritmo de estimación de pi por el método de Montecarlo se encuentra en `mcpi_mpi.c`. En esta implementación, por cada proceso (exceptuando el proceso 0) se generarán un total de n puntos aleatorios y cada uno enviará al proceso 0 el conteo de los puntos que sí cumplen la condición del método de Montecarlo para que este estime el valor de pi.

#### Implementación Distribuida con MPI y Funciones Grupales
La implementación distribuida con MPI y funciones grupales del algoritmo de estimación de pi por el método de Montecarlo se encuentra en `mcpi_mpig.c`. En esta implementación, por cada proceso (esta vez incluyendo el proceso 0) se generarán un total de n puntos aleatorios y cada uno generará un conteo de los puntos que sí cumplen la condición del método de Montecarlo.

Todos los conteos se sumarán haciendo uso de la función `MPI_Reduce` con la operación `MPI_SUM` para que el proceso 0 se encargue finalmente de estimar el valor de pi.

### Integral por la Regla del Trapezoide
