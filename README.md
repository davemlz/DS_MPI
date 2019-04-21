# DS_MPI

## Creadores

- David Montero Loaiza. email: david.montero@correounivalle.edu.co
- Juan Manuel Valencia Correa. email: juan.valencia@correounivalle.edu.co

## Contenido

### Montecarlo Pi `Montecarlo_pi`

- `mcpi.c`. Implementación secuencial del algoritmo de estimación de pi por el método de Montecarlo.
- `mcpi_mpi.c`. Implementación distribuida del algoritmo de estimación de pi por el método de Montecarlo. En esta implementación, por cada proceso (exceptuando el proceso 0) se generarán un total de n puntos aleatorios y cada uno enviará al proceso 0 el conteo de los puntos que sí cumplen la condición del método de Montecarlo para que este estime el valor de pi.
- `mcpi_mpig.c`. Implementación distribuida con MPI y funciones grupales del algoritmo de estimación de pi por el método de Montecarlo. En esta implementación, por cada proceso (esta vez incluyendo el proceso 0) se generarán un total de n puntos aleatorios y cada uno generará un conteo de los puntos que sí cumplen la condición del método de Montecarlo. Todos los conteos se sumarán haciendo uso de la función `MPI_Reduce` con la operación `MPI_SUM` para que el proceso 0 se encargue finalmente de estimar el valor de pi.

### Integral por el Método del Rectángulo `Rectangle_Method_Integration`

- `rmi.c`. Implementación secuencial del algoritmo de estimación de una integral definida por el método del rectángulo.
- `rmi_mpi.c`. Implementación distribuida del algoritmo de estimación de una integral definida por el método del rectángulo. En esta implementación, cada proceso (exceptuando el proceso 0) se encargará de estimar el valor de la integral en un subrango definido dentro del rango definido de la función a integrar y de enviar esta estimación al proceso 0 para que se encargue de sumarlas y dar el valor total estimado de la integral definida.
- `rmi_mpig.c`. Implementación distribuida con MPI y funciones grupales del algoritmo de estimación de una integral definida por el método del rectángulo. En esta implementación, cada proceso (exceptuando de nuevo el proceso 0) se encargará de estimar el valor de la integral en un subrango definido dentro del rango definido de la función a integrar. Todas las estimaciones parciales se sumarán haciendo uso de la función `MPI_Reduce` con la operación `MPI_SUM` para que el proceso 0 se encargue finalmente de imprimir el valor total estimado de la integral definida.

### Integral por la Regla del Trapezoide `Trapezoidal_Rule_Integration`

- `tri.c`. Implementación secuencial del algoritmo de estimación de una integral definida por la regla del trapezoide.
- `tri_mpi.c`. Implementación distribuida del algoritmo de estimación de una integral definida por la regla del trapezoide. En esta implementación, cada proceso (exceptuando el proceso 0) se encargará de estimar el valor de la integral en un subrango definido dentro del rango definido de la función a integrar y de enviar esta estimación al proceso 0 para que se encargue de sumarlas y dar el valor total estimado de la integral definida.
- `tri_mpig.c`. Implementación distribuida con MPI y funciones grupales del algoritmo de estimación de una integral definida por la regla del trapezoide. En esta implementación, cada proceso (exceptuando de nuevo el proceso 0) se encargará de estimar el valor de la integral en un subrango definido dentro del rango definido de la función a integrar. Todas las estimaciones parciales se sumarán haciendo uso de la función `MPI_Reduce` con la operación `MPI_SUM` para que el proceso 0 se encargue finalmente de imprimir el valor total estimado de la integral definida.
