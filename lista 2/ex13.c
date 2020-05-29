#include <stdio.h>

int main(){

	float aposta1, aposta2, aposta3, premio;
	float ganho1, ganho2, ganho3, total;
	float recebe1, recebe2, recebe3;

	printf("Informe o Valor do premio: \n");
	scanf("%f", &premio);

	printf("Informe o Valor da aposta1: \n");
	scanf("%f", &aposta1);
	printf("Informe o Valor da aposta2: \n");
	scanf("%f", &aposta2);
	printf("Informe o Valor da aposta3: \n");
	scanf("%f", &aposta3);

	total = aposta1+aposta2+aposta3;

	ganho1 = aposta1/total;
	ganho2 = aposta2/total;
	ganho3 = aposta3/total;

	recebe1 = premio*ganho1;
	recebe2 = premio*ganho2;
	recebe3 = premio*ganho3;

	printf("Jogador 1: %f\n", recebe1);
	printf("Jogador 2: %f\n", recebe2);
	printf("Jogador 3: %f\n", recebe3);

	return 0;
}