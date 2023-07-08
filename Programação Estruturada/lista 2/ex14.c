#include <stdio.h>

int main () {
	
	float km, ms;
	
	printf("Digite uma velocidade em Km/h: ");
	scanf("%f", &km);
	
	ms = km/3.6;
	
	printf("%2.f Km/h convertido para %2.fm/s", km, ms); 
			
	return 0;
}