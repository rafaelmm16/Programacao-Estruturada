#include <stdio.h>

int main(){

	float nota1, nota2;
	float media_p;

	printf("Informe suas 2 notas: \n");
	scanf("%f %f", &nota1, &nota2);

	media_p = ((3*nota1) + (7*nota2)/(3+7));

	printf("Media Ponderada: %f", media_p);

	return 0;
}