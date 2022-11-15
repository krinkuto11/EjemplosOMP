#include <stdio.h>
#include <math.h>
#include "omp.h"

                double numeroAureo = (1.0 + sqrt(5.0)) / 2.0;

                int main(){
                int numeroHilos = 12;
                omp_set_num_threads(numeroHilos);
                double respuesta = 0;
                long numero;
                printf("Ingresar un numero: ");
                scanf("%ld", &numero);

                double itime, ftime, exec_time;
                itime = omp_get_wtime();

                #pragma omp parallel sections
                {
                    #pragma omp section
                    {
                    double subrespuesta = pow(numeroAureo, numero) / sqrt(5.0);
                    printf("El hilo %d descubrio que el primer valor numerico es %.10f\n", omp_get_thread_num(), subrespuesta);
                    #pragma omp atomic
                        respuesta += subrespuesta;
                    }
                    #pragma omp section
                    {
                    double subrespuesta = pow(1 - numeroAureo, numero) / sqrt(5.0);
                    printf("El hilo %d descubrio que el segundo valor numerico es %.10f\n", omp_get_thread_num(), subrespuesta);
                    #pragma omp atomic
                        respuesta -= subrespuesta;
                    }
                }

                printf("El numero %ld de la sucesion de Fibonacci es %.0f\n", numero, respuesta);
                ftime = omp_get_wtime();
                exec_time = ftime - itime;
                printf("\n Ha tardado %f segundos", exec_time);


                return 0;
                }
