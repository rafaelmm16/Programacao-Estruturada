/* CABEÇALHO
   Programa: Cálculo da Série de Fibonacci
   Arquivo: fibonacci.c
   Objetivo: Fornecida a quantidade de termos (n), calcular a série
             de fibonacci para os n primeiros termos
   Autor(a): Maria das Graças
   Versão: 1.0

   OBS.: Notar falhas nesse código. Atribuição de valores desnecessariamente
         em dois momentos. Vale a pena manter ou algo deve ser feito
         para retirar?
 */

/* Importação de Bibliotecas */
#include <stdio.h>

/* Programa Principal */
int main(){

   /* Dicionário de Dados */
   int n, termoAtual, penultimoTermo, antePenultimoTermo, i;

   /* Solicitar quantidade de termos */
   printf("Informe a quantidade de termos: ");
   scanf("%d",&n);

   printf("\n\nSerie de Fibonacci\n");

   /* Os dois primeiros termos da Série de Fibonacci (0 e 1) são constantes
      e podem ser impressos na tela diretamente, sem cálculos */
   if(n >= 1){
      printf("0  ");
   }

   if(n >= 2){
      printf("1  ");
   }

   /* Iniciar os três primeiros termos da série */
   antePenultimoTermo = 0;
   penultimoTermo = 1;
   termoAtual = antePenultimoTermo + penultimoTermo;

   /* LOOP: Calcular os n primeiros termos da série,
      exibindo a partir do 3o. */
   for(i = 3; i <= n; i++){
      printf("%d  ",termoAtual);

      /* Providenciar quebra de linha a cada 5 termos impressos
         Instrução apenas para facilitar a visualização na tela */
       if ((i % 5) == 0) {
         printf("\n");
      }

      /* calcular os novos termos */
      antePenultimoTermo = penultimoTermo;
      penultimoTermo = termoAtual;
      termoAtual = penultimoTermo + antePenultimoTermo;
   }

   return 1;
}
