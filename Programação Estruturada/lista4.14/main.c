#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, cont=1,soma;
    printf("Digite o numero:");
    scanf("%d",&numero);
    while (cont<=numero){
        printf("%d ", cont);
        cont++;}
    soma=(cont*numero)/2;
    printf("%d ",soma);
}
