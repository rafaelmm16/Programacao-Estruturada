#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    do{

    printf("Digite os numeros:");
    scanf("%d", &numero);
    if(numero<0){
        printf ("%d\n", numero);
    }
    }
    while (numero!=0);
    printf("fim");
    return 0;
}
