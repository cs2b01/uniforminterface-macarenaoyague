//
// Created by Macarena Oyague on 2019-04-28.
//

#include "funciones.h"

int mostrar_serie_fibonacci (int n){
    if (n==1)
        return 1;
    if (n==2)
        return 1;
    else
        return (mostrar_serie_fibonacci(n-1)+mostrar_serie_fibonacci(n-2));
}

bool es_narcisista(int n);

void mostrar_narcisistas(int limite_inferior, int limite_superior);

int siguiente_primo(int num);