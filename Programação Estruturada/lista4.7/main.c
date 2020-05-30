#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros,cont=50;
    printf("Escreva o numero: ");
    scanf("%d", &numeros);

    do{
          if (cont<=50){
              printf("%d",cont);
              cont++;}}

    while (cont>numeros);
    return 0;
}
