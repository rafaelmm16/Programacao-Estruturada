#include <stdio.h>
#include <math.h>

int main (){

	double x1, x2, y1, y2;
	float distancia;

	printf("Informe as coodernadas de x: \n");
	scanf("%lf %lf", &x1, &x2);
	printf("Informe as coodernadas de y: \n");
	scanf("%lf %lf", &y1, &y2);

	distancia = sqrt(pow((x2-x1),2) + pow((y2-y1),2));

	printf("Distancia: %lf ", distancia);

	return 0;
}