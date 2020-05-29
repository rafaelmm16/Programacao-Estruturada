#include <stdio.h>

int main(){

	float lado;

	printf("Informe um lado do quadrado: \n");
	scanf("%f", &lado);

	lado *= lado;

	printf("Area: %f", lado);

	return 0;
}