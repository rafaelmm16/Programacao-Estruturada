#include <stdio.h>
#include <stdlib.h>

int main(){
	int Vetor[5], i;
	for (i=0; i<5; i++){
		printf("digite qq: [%d]", i);
		scanf("%d", &Vetor[i]);
		Vetor[i]=i+1;
	}
	printf("%d [%d]", Vetor[i], i);
	
	return 0;}