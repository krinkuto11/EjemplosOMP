#include <stdio.h>
#include <stdbool.h>
#include <time.h>



                        int main(){
                        double respuesta = 0.0;
                        long numeroIteraciones;
                        printf("Ingresar el numero de iteraciones: ");
                        scanf("%ld", &numeroIteraciones);
                        struct timespec begin, end;
                        clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

                        bool esIndicePar = true;
                        for(long indice = 0; indice <= numeroIteraciones; indice++){
                            if(esIndicePar == true){
                            respuesta += 4.0 / (2.0 * indice + 1.0);
                            }else{
                            respuesta -= 4.0 / (2.0 * indice + 1.0);
                            }
                            esIndicePar = !esIndicePar;
                        }
                        clock_gettime(CLOCK_MONOTONIC_RAW, &end);
                        printf("La respuesta es: %f\n", respuesta);
                        printf ("Ha tardado = %f segundos\n",
                            (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
                            (end.tv_sec  - begin.tv_sec));
                        return 0;
                        }
