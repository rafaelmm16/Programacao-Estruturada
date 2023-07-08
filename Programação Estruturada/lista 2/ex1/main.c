#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, produto;

    printf("Informe 2 numeros: \n");
    scanf("%d %d", &num1, &num2);

    produto=num1*num2;

    printf("Resultado: %d", produto);

    return 0;
}
