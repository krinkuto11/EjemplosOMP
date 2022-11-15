#include <stdio.h>
#include <math.h>
#include <time.h>

                double numeroAureo = (1.0 + sqrt(5.0)) / 2.0;

                double fibonacci(long numero){
                return (pow(numeroAureo, numero) - pow(1 - numeroAureo, numero)) / sqrt(5.0);
                }

                int main(){



                struct timespec begin, end;
                long numero;
                printf("Ingresar un numero: ");
                scanf("%ld", &numero);

                clock_gettime(CLOCK_MONOTONIC_RAW, &begin);
                printf("El numero %ld de la sucesion de Fibonacci es %.0f\n", numero, fibonacci(numero));

                clock_gettime(CLOCK_MONOTONIC_RAW, &end);
                printf ("Ha tardado = %f segundos\n", (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +(end.tv_sec  - begin.tv_sec));
                return 0;
                }
