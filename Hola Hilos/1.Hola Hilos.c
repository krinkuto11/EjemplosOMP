#include <stdio.h>
                        #include "omp.h"

                        int main(){
                            int numeroHilos;
                            printf("Ingresar el numero de hilos: ");
                            scanf("%d", &numeroHilos);

                            int numeroProcesadores = omp_get_num_procs();
                            omp_set_num_threads(numeroHilos);
                            printf("Este computador usa %d procesador(es)\n", numeroProcesadores);
                            printf("En este ejemplo se desea usar %d hilo(s)\n", omp_get_max_threads());
                            printf("En este momento se esta(n) ejecutando %d hilo(s)\n", omp_get_num_threads());

                            printf("\nAcabo de entrar a la seccion paralela\n");
                            #pragma omp parallel
                            {
                                int idHilo = omp_get_thread_num();
                                printf("Hola, soy el hilo %d, en este momento se esta(n) ejecutando %d hilo(s)\n", idHilo, omp_get_num_threads());
                            }
                            printf("Acabo de salir de la seccion paralela\n");

                            printf("\nEn este momento se esta(n) ejecutando %d hilo(s)\n", omp_get_num_threads());
                            return 0;
                        }
