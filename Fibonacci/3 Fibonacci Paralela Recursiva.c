#include <stdio.h>
#include "omp.h"

                long fibonacci(long numero){
                if(numero == 1 || numero == 2){
                    return 1;
                }else{
                    return fibonacci(numero - 1) + fibonacci(numero - 2);
                }
                }

                int main(){
                int numeroHilos = 12;
                omp_set_num_threads(numeroHilos);
                long respuesta = 0, numero;
                printf("Ingresar un numero: ");
                scanf("%ld", &numero);

                double itime, ftime, exec_time;
                itime = omp_get_wtime();

                #pragma omp parallel sections
                {
                    #pragma omp section
                    {
                    long subrespuesta = fibonacci(numero - 2);
                    printf("El hilo %d descubrio que fibonacci(%ld) = %ld\n", omp_get_thread_num(), numero - 2, subrespuesta);
                    #pragma omp atomic
                        respuesta += subrespuesta;
                    }
                    #pragma omp section
                    {
                    long subrespuesta = fibonacci(numero - 1);
                    printf("El hilo %d descubrio que fibonacci(%ld) = %ld\n", omp_get_thread_num(), numero - 1, subrespuesta);
                    #pragma omp atomic
                        respuesta += subrespuesta;
                    }
                }

                printf("El numero %ld de la sucesion de Fibonacci es %ld\n", numero, respuesta);

                ftime = omp_get_wtime();
                exec_time = ftime - itime;
                printf("\n Ha tardado %f segundos", exec_time);

                return 0;
                }
