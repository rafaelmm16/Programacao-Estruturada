#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,cont, aux, aux2;
    printf("Digite os valores:");
    scanf("%d %d", &a, &b);
    if (a<=b){
        cont=a;
        aux=a;
        aux2=a;
        while (cont<=b){
            printf("%d", cont);
            cont++;
        if (aux%2==1){
            printf("%d", aux);
            aux++;}
        if (aux2%3==0){
            printf("%d", aux);
            aux2++;}}}

    return 0;
}
