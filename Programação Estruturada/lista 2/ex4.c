#include <stdio.h>

int main(){

	int num1, num2, num3;
	int media;

	printf("Informe 3 numeros: \n");
	scanf("%d %d %d", &num1, &num2, &num3);

	media = (num1+num2+num3)/3;

	printf("Media: %d.000", media);

return 0;

}