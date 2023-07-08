#include <stdio.h>

int main(){

	int num;
	int x;

	printf("Digite um numero de 3 dig.: ");
	scanf("%d", &num);

	x = num%10 * 100;
	num= num/10;
	x = x + num%10 * 10;
	num = num/10;
	x = x + num;

	printf("Invertido: %d", x);

	return 0;
}