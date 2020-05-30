#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont1=100,cont2=200;
    do{
            if(cont1%2==1)
               printf("%d ",cont1);
               cont1++;}
    while (cont1<=cont2);
    return 0;
}
