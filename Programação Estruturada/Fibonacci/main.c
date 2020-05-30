/*CABEÇALHO
    Objetivo: Fibonacci otimizado
    Autor: Rafael Merlo Mendes
    Versão: 1.0
    Data: 19/05/17 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Digite um valor:");
    scanf("%d", &x);
    if (x==0){
    printf 0;
    }
    if (x==1 or x==2){
    printf 1;
    }
    else{
    printf fibonacci(x-1)+ fibonacci(x-2);
    }
    return 0;
}
