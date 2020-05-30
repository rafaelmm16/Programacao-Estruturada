#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int qtcasas(int num);
long int somadig(long int num);

int main(){
	
	printf("q casas %d\n", qtcasas(10));
	printf("soma %ld\n", somadig((long int)1730));
	return 0;
}

int qtcasas(int num){
	int quant=1;
	while((num = num/10)>0){
		quant++;
	}
	return quant;
}

long int somadig(long int num){
	int casas=0;
	long int soma=0;
	
	casas=qtcasas(num);
	
	while(casas>0){
		soma += (num%(int)pow(10,casas)/(int)( pow(10,casas-1))); 
		casas--;
	}
	return soma;
}