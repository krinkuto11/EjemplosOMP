#include <stdio.h>
#include <time.h>

                long fibonacci(long numero){
                if(numero == 1 || numero == 2){
                    return 1;
                }
                else{
                    return fibonacci(numero - 1) + fibonacci(numero - 2);
                }
                }

                int main(){

                struct timespec begin, end;


                long numero;
                printf("Ingresar un numero: ");
                scanf("%ld", &numero);
                clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
                printf("El numero %ld de la sucesion de Fibonacci es %ld\n", numero, fibonacci(numero));

                clock_gettime(CLOCK_MONOTONIC_RAW, &end);
                printf ("Ha tardado = %f segundos\n", (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +(end.tv_sec  - begin.tv_sec));

                return 0;
                }
