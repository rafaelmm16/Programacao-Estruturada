#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    float pi=3.14, raio,cont=0, area, letra;
    printf("Digite o valor do raio: ");
    scanf("%f",&raio);
    area=pi*(raio*raio);
    printf("\n%f", area);

    do
    {
        printf("\nDeseja calcular mais areas? Sim (S) ou nao (N) ");
        fflush(stdin);
        letra=getchar();

        if(letra=='S'){
        printf("Digite o valor do raio: ");
        scanf("%f",&raio);
        area=pi*(raio*raio);
        printf("\n%f", area);}


    }while (letra == 'S');


    return 0;
}
