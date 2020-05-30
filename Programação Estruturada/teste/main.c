#include <stdio.h>

int main( ){

  int linha, coluna;

  printf("\n");
  linha = 1;
  while (linha < 20)
  {
    printf( "\t" );
    coluna = 1;
    while (coluna < linha)
    {
      printf( " gado d+ " );
      coluna += 1;
    }
    printf( "\n" );
    linha += 1;
  }
}
