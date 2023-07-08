#include <stdio.h>

int main(){

	int dia;
	float diaria = 30.0, desconto = 8;
	float sub_total, total, resul;

	printf("Dias trabalhados: \n");
	scanf("%d", &dia);

	total = (dia*diaria);
	sub_total = (desconto/100) * total;

	resul = total - sub_total;

	printf("Total: %f", resul);

	return 0;
}