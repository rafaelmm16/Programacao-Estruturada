#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[4];
    int i=1, ord=0, aux=1;

    for (i=1; i<=4; i++){
    printf("Digite um numero:");
    scanf("%d",&num[i]);}

    while(ord<1){
        for(i=1; i<=4; i++){
            if(num[i]>aux){
                aux=num[i+1];
                num[i+1]=num[i+1];
                num[i+1]=aux;}}
    	ord=ord+1;}
    for(i=1; i<=4; i++){
    printf("\nOrdem crescente:");
    printf(" %d\t", num[i]);}
    return 0;}
