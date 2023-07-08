#include <stdio.h>
#include <stdlib.h>

int main (){

	int num;

	printf("Digite um numero: \n");
	scanf("%d", &num);

	printf("Antecessor: %d\n", num-1);
	printf("Sucessor: %d\n", num+1);

	return 0;
}