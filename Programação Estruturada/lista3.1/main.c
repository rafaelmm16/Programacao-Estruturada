/*CABEÇALHO
    Objetivo: Ler um números e verificar se ele é par ou ímpar.
    Autor:Rafael Merlo Mendes
    Data:12/05/2017
    Versão:1.0 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    /*Variaveis*/
    int numero;
    setlocale(LC_ALL, "Portuguese");
    printf("Digite o número:");
    scanf("%d", &numero);
    /*Condicional*/
    if (numero%2==0){
          printf ("%d Par", numero);
    }
    if (numero%2==1)
    {
          printf ("%d Impar", numero);
    }
    return (0);
}
