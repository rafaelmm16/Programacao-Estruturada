#include <stdio.h>

int main(){

	float valor_despesa, gorjeta;
	int num_pessoas;
	float valor_pago;

	printf("Informe o valor de despesa: \n");
	scanf("%f", &valor_despesa);

	printf("Informe o valor da gorjeta (em porcentagem): \n");
	scanf("%f", &gorjeta);

	printf("Informe o numero de pessoas: \n");
	scanf("%d", &num_pessoas);

	valor_despesa += gorjeta;

	valor_pago = valor_despesa / num_pessoas;

	printf("Valor para cada: %f.000\n", valor_pago);

	return 0;
}