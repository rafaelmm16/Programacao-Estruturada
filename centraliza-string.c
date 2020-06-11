#include <stdio.h>
#include <stdlib.h>

int int main()
{
	char str[64];
	int tam, esp, i;

	printf("Escreva alguma coisa:\n");
	fgets(str, 64, stdin);

	tam = strlen(str);
	esp = (80-tam)/2;

	for (i = 0; i < esp; i++)
	{
		printf(" ");
	}
	for (i = 0; i < tam; i++)
	{
		printf("%c", str[i]);
	}
	
	return 0;
}