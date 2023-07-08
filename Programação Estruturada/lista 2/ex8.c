#include <stdio.h>

int main(){

	float real, cotacao_dia, dolar;

	printf("Valor em Real:\n");
	scanf("%f", &real);

	printf("Cotacao do dolar:\n");
	scanf("%f", &cotacao_dia);

	dolar = real*cotacao_dia;

	printf("Dolar: %f", dolar); 

	return 0;
}