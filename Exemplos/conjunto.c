#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declara variável de opções, e os três vetores para os conjuntos 1, 2, e 3.
  int i, x, enc, num, numConj, opt, cont1, cont2, cont3, cont4, cont5, i_R, j, k;
  int g, h, y, existe, moex, conjesco, conjesco2;
  int elemento, c1 = 0, c2 = 0, c3 = 0, l1 = 0, l2 = 0, l3 = 0;
  int conj1[100], conj2[100], conj3[100], conj4[200], conj5[200], conjR[100];
  char op1[2], op2[2];
  cont1 = -1;
  cont2 = -1;
  cont3 = -1;
  cont4 = -1;
  x     = -1;

  // Imprime uma descrição apresentando o programa e dá instruções
  //  simples sobre o uso do mesmo antes de rodar o laço principal.
  //  (colocado nessa parte para que rode apenas quando o programa for executado.)
  printf("PROGRAMA DE CONJUNTOS\n\n"
         "Instruções:\n"
         "- Para realizar alguma operação, digite o número entre colchetes referente\n"
         "   a operação que você deseja realizar. Exemplo: Digite \"1\" para inserir um\n"
         "   elemento em um conjunto, como explanado na lista abaixo.\n\n"
         "- Você poderá sair do programa a qualquer momento digitando o número 10 no menu\n"
         "    ou teclando ctrl+Z em seu teclado.\n\n");

  // Implementa o laço principal para operação do programa de conjuntos.  Este roda em loop
  //   infinito até que o programa faça com que o loop se encerre em decorrência de alguma
  //   instrução dentro do loop das operações.
  while (1) {
    // Mostra o menu e pede ao usuário para dizer qual operação realizar
    printf("Escolha uma das opções abaixo para realizar uma operação:\n"
           "+------------------------------------------------------+\n"
           "| [1]  Inserir elemento em um conjunto                 |\n"
           "| [2]  Remover um elemento de um conjunto              |\n"
           "| [3]  Verificar se um elemento pertence a um conjunto |\n"
           "| [4]  Verificar se um conjunto é subconjunto de outro |\n"
           "| [5]  Realizar a união de dois conjuntos              |\n"
           "| [6]  Realizar a interseção entre dois conjuntos      |\n"
           "| [7]  Realizar a diferença entre dois conjuntos       |\n"
           "| [8]  Realizar o produto cartesiano de dois conjuntos |\n"
           "| [9]  Imprimir os elementos de um conjunto            |\n"
           "| [10] Sair do programa                                |\n"
           "+------------------------------------------------------+\n"
           "Diga o número da operação [1-10]: ");
    scanf("%d", &opt);

    // Processa a operação escolhida de acordo com o número da operação
    switch (opt) {
      case 1:
        enc = 0;
        // Pede o conjunto para inserir o número.
        printf("Em qual conjunto você quer inserir? [A, B ou C]: ");
        scanf("%s", op1);

        // Pede o valor a ser inserido como novo elemento.
        printf("Qual valor você quer inserir?: ");
        scanf("%d", &num);

        // Processa caso do elemento A.
        if (strcmp("A", op1) == 0) {
          for (i = 0; i <= cont1; i++) {
            if (conj1[i] == num) {
              // Valor já existe nesse conjunto. Sinalizar.
              enc = 1;
            }
          }
          // O valor especificado é positivo? Se sim, parar o laço atual e avançar para o próximo,
          //  caso contrário, continuar a operação normalmente.
          if (enc == 1) {
            printf("\n\n%s = {", op1);
            for (i = 0; i <= cont1; i++) {
              if (i != 0 && i < cont1 + 1) {
                printf(", ");
              }
              printf("%d", conj1[i]);
            }
            printf("}\n\n\n");
            break;
          }

          // Adicione o novo valor do conjunto no vetor.
          cont1++;
          conj1[cont1] = num;

          // Mostre o resultado da operação.
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont1; i++) {
            if (i != 0 && i < cont1 + 1) {
              printf(", ");
            }
            printf("%d", conj1[i]);
          }
          printf("}\n\n\n");
          break;
        } else if (strcmp("B", op1) == 0) {
          // Funciona da mesma forma que o processo para A.
          for (i = 0; i <= cont2; i++) {
            if (conj2[i] == num) {
              enc = 1;
            }
          }
          if (enc == 1) {
            printf("\n\n%s = {", op1);
            for (i = 0; i <= cont2; i++) {
              if (i != 0 && i < cont2 + 1) {
                printf(", ");
              }
              printf("%d", conj2[i]);
            }
            printf("}\n\n\n");
            break;
          }
          cont2++;
          conj2[cont2] = num;
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont2; i++) {
            if (i != 0 && i < cont2 + 1) {
              printf(", ");
            }
            printf("%d", conj2[i]);
          }
          printf("}\n\n\n");
          break;
        } else if (strcmp("C", op1) == 0) {
          // Funciona da mesma forma que o processo para o elemento A.
          for (i = 0; i <= cont3; i++) {
            if (conj3[i] == num) {
              enc = 1;
            }
          }
          if (enc == 1) {
            printf("\n\n%s = {", op1);
            for (i = 0; i <= cont3; i++) {
              if (i != 0 && i < cont3 + 1) {
                printf(", ");
              }
              printf("%d", conj3[i]);
            }
            printf("}\n\n\n");
            break;
          }
          cont3++;
          conj3[cont3] = num;
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont3; i++) {
            if (i != 0 && i < cont3 + 1) {
              printf(", ");
            }
            printf("%d", conj3[i]);
          }
          printf("}\n\n\n");
          break;
        } else {
          printf("Conjunto não existe, tente novamente:\n");
          break;
        }
        break;

      case 2:
        // Pede o conjunto que vamos trabalhar.
        printf("De qual conjunto você quer remover um elemento? [1-3]: ");
        scanf("%s", op1);

        // Pede o valor a ser removido.
        printf("Qual valor você quer remover?: ");
        scanf("%d", &num);

        if (strcmp("A", op1) == 0) {
          // Verifica em qual indice do vetor está contido o número especificado.
          //  Caso não esteja contido no conjunto, x permanesce com seu valor de -1,
          //  sinalizando que o valor não foi encontrado, logo x não é alterada.
          for (i = 0; i <= cont1; i++) {
            if (conj1[i] == num) {
              x = i;
            }
          }

          // Valor inicial de x é -1, logo, como nenhum indice tem menos que 0,
          //  assume-se que não existe esse número no conjunto, uma vez que x
          //  permanesce inalterada.
          if (x < 0) {
            printf("Esse valor não existe nesse conjunto.\n\n");
            break;
          }

          // Remove o valor especificado do conjunto. Para isso, substitui-se o indice
          //  contendo o valor a ser removido pelo valor do ultimo indice e decresce o
          //  número de indices do vetor contido em cont1, forçando o programa a verificar só até esse.
          conj1[x] = conj1[cont1];
          cont1--;

          // Mostra o conjunto resultante após a remoção do valor especificado pelo usuário.
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont1; i++) {
            if (i != 0 && i < cont1 + 1) {
              printf(", ");
            }
            printf("%d", conj1[i]);
          }
          printf("}\n\n\n");
          break;
        } else if (strcmp("B", op1) == 0) {
          // Funciona da mesma forma que o elemento A.
          for (i = 0; i <= cont2; i++) {
            if (conj2[i] == num) {
              x = i;
            }
          }

          if (x < 0) {
            printf("Esse valor não existe nesse conjunto.\n\n");
            break;
          }

          conj2[x] = conj2[cont1];
          cont2--;

          // Mostra o conjunto resultante após a remoção do valor especificado pelo usuário.
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont2; i++) {
            if (i != 0 && i < cont2 + 1) {
              printf(", ");
            }
            printf("%d", conj2[i]);
          }
          printf("}\n\n\n");
          break;
        } else if (strcmp("C", op1) == 0) {
          // Funciona da mesma forma que op elemento A.
          for (i = 0; i <= cont3; i++) {
            if (conj3[i] == num) {
              x = i;
            }
          }

          if (x < 0) {
            printf("Esse valor não existe nesse conjunto.\n\n");
            break;
          }

          conj3[x] = conj3[cont1];
          cont3--;

          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont3; i++) {
            if (i != 0 && i < cont3 + 1) {
              printf(", ");
            }
            printf("%d", conj3[i]);
          }
          printf("}\n\n\n");
          break;
        } else {
          printf("Conjunto não existe.\n\n");
          break;
        }
        break;

      case 3:
      	l1=0;
      	c1=-1;
        printf("(1 representa A, 2 representa B, e 3 representa C)\n");
        printf("Digite o número que voce quer saber se é elemento dos conjuntos: ");
    		scanf("%d", &elemento); //ler o número a ser verificado
    		printf("Digite o conjunto que voce quer usar [1-3]: ");
    		scanf("%d", &conjesco);
    		if (conjesco == 1) {
    			while(l1 == 0 && c1 <= cont1) {  //verificação conjunto 1
    				if(conj1[c1] == elemento) {//analisar se o numero é igual ao elemento daquela posição, caso seja a variavel lógica mudara o valor
    					l1 = 1;
            }
    				c1++; //todo o vetor sera percorrido
    			}
    			if(l1 == 1) {//caso a modificação seja feita(o elemento era igual)
    				printf("O elemento %d pertence ao conjunto 1 \n", elemento);
    			} else { //caso a modificação nao seja feita(todos os elementos eram diferentes)
    				printf("O elemento %d  nao pertence ao conjunto 1 \n", elemento);
    			}
    		  break;
    		}

    		if (conjesco==2){
    			while(l1==0 && c1<=cont2){
    				if(conj2[c1] == elemento) {
    					l1 = 1;
            }
    				c1++;
    			}
    			if (l1 == 1) {
    				printf("O elemento %d pertence ao conjunto 1.\n", elemento);
    			} else {
    				printf("O elemento %d nao pertence ao conjunto 1.\n", elemento);
    			}
    		  break;
    		}
    		if (conjesco == 3) {
    			while (l1 == 0 && c1 <= cont3) {
    				if (conj3[c1] == elemento) {
              l1 = 1;
            }
    				c1++;
    			}
    			if (l1 == 1) {
    				printf("O elemento %d pertence ao conjunto 1 \n", elemento);
    			} else {
    				printf("O elemento %d  nao pertence ao conjunto 1 \n", elemento);
    			}
    		  break;
    		}
        break;

      case 4:
          y = 0;
          printf("(1 representa A, 2 representa B, e 3 representa C)\n");
          printf("Escolha os 2 conjuntos que serão analisados: "); // conjescos sao os conjuntos escolhidos
        	scanf("%d%d", &conjesco, &conjesco2);//pede para o usuario digitar os conjuntos
        	if (conjesco==1 && conjesco2==2) {
        		if (cont1 == -1) { //se o primeiro conjunto for vazio, ele é subconjunto(vazio pertence a todos os conjuntos)
        			printf("O conjunto 1 e subconjunto de 2.\n\n");
            	break;
            } else if (cont2 == -1) {//se o segundo conjunto for vazio, não é subconjunto
            		printf("O conjunto 1 não é subconjunto de 2.\n\n");
            		break;
            } else if (cont1 != -1 && cont2 != -1) {   //se nenhum for vazio, ele faz a comparação
        			for (g = 0; g < cont1; g++) {//trava no primeiro elemento, e percorre os elementos do segundo conjunto
        				for (h = 0; h < cont2; h++) {
        					if (conj1[g] == conj2[h]) { //se achar um elemento igual, ele adiciona 1 a "y"
        						y++;
        					}
        				}
        			}
        			if (y == cont1) { //se y for do tamanho do primeiro conjunto, significa que ele é subconjunto do segundo
        				printf("o conjunto 1 e subconjunto de 2.\n\n");
        				break;
        			} else { // se não, nao é subconjunto
        				printf("o conjunto 1 não é subconjunto de 2.\n\n");
        				break;
        			}
        		}
        	  break;
        	} else if (conjesco==1 && conjesco2==3) {
        		if (cont1 == -1) {
        			printf("O conjunto 1 e subconjunto de 3.\n\n");
            		break;
            	}
            	else if(cont3==-1){
            		printf("O conjunto 1 não é subconjunto de 3.\n\n");
            		break;
            	}
            	else if(cont1 != -1 && cont3 != -1){
        			for (g = 0; g < cont1; g++) {
        				for (h = 0; h < cont3; h++) {
        					if (conj1[g] == conj3[h]) {
        						y++;
        					}
        				}
        			}
        			if (y == cont1) {
        				printf("o conjunto 1 e subconjunto de 3.\n\n");
        				break;
        			} else {
        				printf("o conjunto 1 não é subconjunto de 3.\n\n");
        				break;
        			}
        		}
        	  break;
        	} else if (conjesco==2 && conjesco2==3) {
        		if (cont2 == -1) {
        			printf("O conjunto 2 e subconjunto de 3.\n\n");
              break;
            } else if(cont3==-1){
            		printf("O conjunto 2 não é subconjunto de 3.\n\n");
            		break;
            	} else if (cont2 !=-1 && cont3!= -1) {
        			     for (g = 0; g < cont2; g++) {
        				      for (h = 0; h < cont3; h++) {
        					       if (conj2[g] == conj3[h]) {
        						         y++;
        					        }
        			         }
        			      }
              			if (y == cont2) {
              				printf("o conjunto 2 e subconjunto de 3.\n\n");
              				break;
              			} else {
                				printf("o conjunto 2 não é subconjunto de 3.\n\n");
                				break;
                			}
        		   }
        	     break;
        	} else if (conjesco==2 && conjesco2==1) {
        		if (cont2 == -1) {
        			printf("O conjunto 2 e subconjunto de 1.\n\n");
            	break;
            } else if (cont1 == -1) {
            		printf("O conjunto 2 não é subconjunto de 1.\n\n");
            		break;
            } else if (cont2 != -1 && cont1 != -1) {
        			for (g = 0; g < cont2; g++) {
        				for (h = 0; h < cont1; h++) {
        					if (conj2[g] == conj1[h]) {
        						y++;
        					}
        				}
        			}
        			if (y == cont2) {
        				printf("o conjunto 2 e subconjunto de 1.\n\n");
        				break;
        			} else {
        				printf("o conjunto 2 não é subconjunto de 1.\n\n");
        				break;
        			}
        		}
        	  break;
        	}
        	else if (conjesco==3 && conjesco2==1) {
        		if (cont3 == -1) {
        			printf("O conjunto 3 e subconjunto de 1.\n\n");
            	break;
            }
            else if (cont1==-1){
            	printf("O conjunto 3 não é subconjunto de 1.\n\n");
            	break;
            } else if (cont3 != -1 && cont1 != -1) {
        			for (g = 0; g < cont3; g++) {
        				for (h = 0; h < cont1; h++) {
        					if (conj3[g] == conj1[h]) {
        						y++;
        					}
        				}
        			}
        			if (y == cont3) {
        				printf("o conjunto 3 e subconjunto de 1.\n\n");
        				break;
        			} else {
        				printf("o conjunto 3 não é subconjunto de 1.\n\n");
        				break;
        			}
        		}
        	  break;
        	} else if (conjesco == 3 && conjesco2 == 2) {
        		if (cont3 == -1) {
        			printf("O conjunto 3 e subconjunto de 2.\n\n");
            	break;
            } else if (cont2 == -1) {
            	printf("O conjunto 3 não é subconjunto de 2.\n\n");
            	break;
            } else if (cont3 != -1 && cont2 != -1) {
        			for (g = 0; g < cont3; g++) {
        				for (h = 0; h < cont2; h++) {
        					if (conj3[g] == conj2[h]) {
        						y++;
        					}
        				}
        			}
        			if (y == cont3) {
        				printf("o conjunto 3 e subconjunto de 2.\n\n");
        				break;
        			} else{
        				printf("o conjunto 3 não é subconjunto de 2.\n\n");
        				break;
        			}
        		}
        	  break;
        	}
        break;

      case 5:
        printf("Qual o primeiro conjunto [A, B ou C]: ");
        scanf("%s", op1);
        printf("Qual o segundo conjunto [A, B, ou C]: ");
        scanf("%s", op2);

        if (strcmp("A", op1) == 0) {
          if (strcmp("A", op2) == 0) {
            printf("\n\n%s ∩ %s = {", op1, op2);
            //Verificação dos elementos iguais nos conjuntos
            for (i = 0; i <= cont1; i++) {
              if (i != 0 && i < cont1 + 1) {
                printf(", ");
              }
              printf("%d", conj1[i]);
            }
            printf("}\n\n\n");
            break;
          }
          if (strcmp("B", op2) == 0) {
            //Verificação dos elementos iguais nos conjuntos
            cont4 = 0;
            moex = 0;
            //Aloca os conjuntos no conjunto vazio, verificando se tem elemntos iguais
            for (i = 0; i <= cont1; i++) {
              conj4[cont4] = conj1[i];
              cont4++;
            }
            for (i = 0; i <= cont2; i++) {
              conj4[cont4] = conj2[i];
              cont4++;
            }
            j = cont4;
            k = 0;
            cont5 = 0;
            for (i = 0; i < 200; i++) {
              conj5[i] = -1;
            }
            for (i = 0; i < j; i++) {
              for (g = 0; g < j; g++) {
                if (conj4[i] == conj4[g]) {
                  existe = 0;
                  for (y = 0; y < j; y++) {
                    if (conj4[i] == conj5[y]) {
                      existe = 1;
                    }
                  }
                  if (existe == 0) {
                    conj5[k] = conj4[i];
                    k++;
                    cont5++;
                  }
                }
              }
            }
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i < cont5; i++) {
              if (i != 0 && i < cont5) {
                printf(", ");
              }
              printf("%d", conj5[i]);
            }
            printf("}\n\n\n");
            break;
          }
          //Aloca os conjuntos no conjunto vazio, verificando se tem elemntos iguais
          if (strcmp("C", op2) == 0) {
            cont4 = 0;
            for (i = 0; i <= cont3; i++) {
              conj4[cont4] = conj3[i];
              cont4++;
            }
            for (i = 0; i <= cont1; i++) {
              conj4[cont4] = conj1[i];
              cont4++;
            }
            j = cont4;
            k = 0;
            cont5 = 0;
            for (i = 0; i < 200; i++) {
              conj5[i] = -1;
            }
            for (i = 0; i < j; i++) {
              for (g = 0; g < j; g++) {
                if (conj4[i] == conj4[g]) {
                  existe = 0;
                  for (y = 0; y < j; y++) {
                    if (conj4[i] == conj5[y]) {
                      existe = 1;
                    }
                  }
                  if (existe == 0) {
                    conj5[k] = conj4[i];
                    k++;
                    cont5++;
                  }
                }
              }
            }
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i < cont5; i++) {
              if (i != 0 && i < cont5) {
                printf(", ");
              }
              printf("%d", conj5[i]);
            }
            printf("}\n\n\n");
            break;
          }
        }
        //Aloca os conjuntos no conjunto vazio, verificando se tem elemntos iguais
        if (strcmp("B", op1) == 0) {
          if (strcmp("A", op2) == 0) {
            cont4 = 0;
            for (i = 0; i <= cont2; i++) {
              conj4[cont4] = conj2[i];
              cont4++;
            }
            for (i = 0; i <= cont1; i++) {
              conj4[cont4] = conj1[i];
              cont4++;
            }
            j = cont4;
            k = 0;
            cont5 = 0;
            for (i = 0; i < 200; i++) {
              conj5[i] = -1;
            }
            for (i = 0; i < j; i++) {
              for (g = 0; g < j; g++) {
                if (conj4[i] == conj4[g]) {
                  existe = 0;
                  for (y = 0; y < j; y++) {
                    if (conj4[i] == conj5[y]) {
                      existe = 1;
                    }
                  }
                  if (existe == 0) {
                    conj5[k] = conj4[i];
                    k++;
                    cont5++;
                  }
                }
              }
            }
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i < cont5; i++) {
              if (i != 0 && i < cont5) {
                printf(", ");
              }
              printf("%d", conj5[i]);
            }
            printf("}\n\n\n");
            break;
          }
          if (strcmp("B", op2) == 0) {
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i <= cont2; i++) {
              if (i != 0 && i < cont2 + 1) {
                printf(", ");
              }
              printf("%d", conj2[i]);
            }
            printf("}\n\n\n");
            break;
          }
          //Aloca os conjuntos no conjunto vazio, verificando se tem elemntos iguais
          if (strcmp("C", op2) == 0) {
            cont4 = 0;
            for (i = 0; i <= cont2; i++) {
              conj4[cont4] = conj2[i];
              cont4++;
            }
            for (i = 0; i <= cont3; i++) {
              conj4[cont4] = conj3[i];
              cont4++;
            }
            j = cont4;
            k = 0;
            cont5 = 0;
            for (i = 0; i < 200; i++) {
              conj5[i] = -1;
            }
            for (i = 0; i < j; i++) {
              for (g = 0; g < j; g++) {
                if (conj4[i] == conj4[g]) {
                  existe = 0;
                  for (y = 0; y < j; y++) {
                    if (conj4[i] == conj5[y]) {
                      existe = 1;
                    }
                  }
                  if (existe == 0) {
                    conj5[k] = conj4[i];
                    k++;
                    cont5++;
                  }
                }
              }
            }
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i < cont5; i++) {
              if (i != 0 && i < cont5) {
                printf(", ");
              }
              printf("%d", conj5[i]);
            }
            printf("}\n\n\n");
            break;
          }
        }
        //Aloca os conjuntos no conjunto vazio, verificando se tem elemntos iguais
        if (strcmp("C", op1) == 0) {
          if (strcmp("A", op2) == 0) {
            cont4 = 0;
            for (i = 0; i <= cont3; i++) {
              conj4[cont4] = conj3[i];
              cont4++;
            }
            for (i = 0; i <= cont1; i++) {
              conj4[cont4] = conj1[i];
              cont4++;
            }
            j = cont4;
            k = 0;
            cont5 = 0;
            for (i = 0; i < 200; i++) {
              conj5[i] = -1;
            }
            for (i = 0; i < j; i++) {
              for (g = 0; g < j; g++) {
                if (conj4[i] == conj4[g]) {
                  existe = 0;
                  for (y = 0; y < j; y++) {
                    if (conj4[i] == conj5[y]) {
                      existe = 1;
                    }
                  }
                  if (existe == 0) {
                    conj5[k] = conj4[i];
                    k++;
                    cont5++;
                  }
                }
              }
            }
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i < cont5; i++) {
              if (i != 0 && i < cont5) {
                printf(", ");
              }
              printf("%d", conj5[i]);
            }
            printf("}\n\n\n");
            break;
          }
          //Aloca os conjuntos no conjunto vazio, verificando se tem elemntos iguais
          if (strcmp("B", op2) == 0) {
            cont4 = 0;
            for (i = 0; i <= cont2; i++) {
              conj4[cont4] = conj2[i];
              cont4++;
            }
            for (i = 0; i <= cont3; i++) {
              conj4[cont4] = conj3[i];
              cont4++;
            }
            j = cont4;
            k = 0;
            cont5 = 0;
            for (i = 0; i < 200; i++) {
              conj5[i] = -1;
            }
            for (i = 0; i < j; i++) {
              for (g = 0; g < j; g++) {
                if (conj4[i] == conj4[g]) {
                  existe = 0;
                  for (y = 0; y < j; y++) {
                    if (conj4[i] == conj5[y]) {
                      existe = 1;
                    }
                  }
                  if (existe == 0) {
                    conj5[k] = conj4[i];
                    k++;
                    cont5++;
                  }
                }
              }
            }
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i < cont5; i++) {
              if (i != 0 && i < cont5) {
                printf(", ");
              }
              printf("%d", conj5[i]);
            }
            printf("}\n\n\n");
            break;
          }
          if (strcmp("C", op2) == 0) {
            printf("\n\n%s U %s = {", op1, op2);
            for (i = 0; i <= cont3; i++) {
              if (i != 0 && i < cont3 + 1) {
                printf(", ");
              }
              printf("%d", conj3[i]);
            }
            printf("}\n\n\n");
            break;
          }
        }
        break;

      case 6:
        printf("Qual o primeiro conjunto [A, B ou C]: ");
        scanf("%s", op1);
        printf("Qual o segundo conjunto [A, B, ou C]: ");
        scanf("%s", op2);

        if (strcmp("A", op1) == 0) {
          if (strcmp("A", op2) == 0) {
            printf("\n\n%s ∩ %s = {", op1, op2);
            //Printa o proprio conjunto
            for (i = 0; i <= cont1; i++) {
              if (i != 0 && i < cont1 + 1) {
                printf(", ");
              }
              printf("%d", conj1[i]);
            }
            printf("}\n\n\n");
            break;
          }
          //Faz a verificação dos elementos iguais nos conjuntos e aloca no vetor vazio
          if (strcmp("B", op2) == 0) {
            k = 0;
            for (i = 0; i <= cont1; i++) {
              for (g = 0; g <= cont2; g++) {
                if (conj1[i] == conj2[g]) {
                  conj4[k] = conj1[i];
                  k++;
                }
              }
            }
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i < k; i++) {
              if (i != 0 && i < k) {
                printf(", ");
              }
              printf("%d", conj4[i]);
            }
            printf("}\n\n\n");
            break;
          }
          if (strcmp("C", op2) == 0) {
            k = 0;
            for (i = 0; i <= cont1; i++) {
              for (g = 0; g <= cont3; g++) {
                if (conj1[i] == conj3[g]) {
                  conj4[k] = conj1[i];
                  k++;
                }
              }
            }
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i < k; i++) {
              if (i != 0 && i < k) {
                printf(", ");
              }
              printf("%d", conj4[i]);
            }
            printf("}\n\n\n");
            break;
          }
        }
        //Faz a verificação dos elementos iguais nos conjuntos e aloca no vetor vazio
        if (strcmp("B", op1) == 0) {
          if (strcmp("A", op2) == 0) {
            k = 0;
            for (i = 0; i <= cont1; i++) {
              for (g = 0; g <= cont2; g++) {
                if (conj1[i] == conj2[g]) {
                  conj4[k] = conj1[i];
                  k++;
                }
              }
            }
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i < k; i++) {
              if (i != 0 && i < k) {
                printf(", ");
              }
              printf("%d", conj4[i]);
            }
            printf("}\n\n\n");
            break;
          }
          if (strcmp("B", op2) == 0) {
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i <= cont2; i++) {
              if (i != 0 && i < cont2 + 1) {
                printf(", ");
              }
              printf("%d", conj2[i]);
            }
            printf("}\n\n\n");
            break;
          }
          if (strcmp("C", op2) == 0) {
            k = 0;
            for (i = 0; i <= cont2; i++) {
              for (g = 0; g <= cont3; g++) {
                if (conj2[i] == conj3[g]) {
                  conj4[k] = conj2[i];
                  k++;
                }
              }
            }
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i < k; i++) {
              if (i != 0 && i < k) {
                printf(", ");
              }
              printf("%d", conj4[i]);
            }
            printf("}\n\n\n");
            break;
          }
        }
        //Faz a verificação dos elementos iguais nos conjuntos e aloca no vetor vazio
        if (strcmp("C", op1) == 0) {
          if (strcmp("A", op2) == 0) {
            k = 0;
            for (i = 0; i <= cont3; i++) {
              for (g = 0; g <= cont1; g++) {
                if (conj3[i] == conj1[g]) {
                  conj4[k] = conj3[i];
                  k++;
                }
              }
            }
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i < k; i++) {
              if (i != 0 && i < k) {
                printf(", ");
              }
              printf("%d", conj4[i]);
            }
            printf("}\n\n\n");
            break;
          }
          //Faz a verificação dos elementos iguais nos conjuntos e aloca no vetor vazio
          if (strcmp("B", op2) == 0) {
            k = 0;
            for (i = 0; i <= cont3; i++) {
              for (g = 0; g <= cont2; g++) {
                if (conj3[i] == conj2[g]) {
                  conj4[k] = conj3[i];
                  k++;
                }
              }
            }
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i < k; i++) {
              if (i != 0 && i < k) {
                printf(", ");
              }
              printf("%d", conj4[i]);
            }
            printf("}\n\n\n");
            break;
          }
          //Faz a verificação dos elementos iguais nos conjuntos e aloca no vetor vazio
          if (strcmp("C", op2) == 0) {
            printf("\n\n%s ∩ %s = {", op1, op2);
            for (i = 0; i <= cont3; i++) {
              if (i != 0 && i < cont3 + 1) {
                printf(", ");
              }
              printf("%d", conj3[i]);
            }
            printf("}\n\n\n");
            break;
          }
        }
        break;

      case 7:
        printf("Qual o primeiro conjunto: [A, B ou C]\n");
      	scanf("%s", op1);
      	printf("Qual o segundo conjunto: [A, B, ou C]\n");
      	scanf("%s", op2);

      	// A - X
      	if (strcmp("A", op1) == 0) {
      		// A - A
      		if (strcmp("A", op2) == 0) {
      			// Vazio
      			i_R = 0;
      		} else {
      			// A - B
      			if (strcmp("B", op2) == 0) {
      				k = 0;
      				// Fixando conj1[i]
      				for (i=0, i_R=0; i<cont1; i++) {
      					// Variando conj2[j]
      					for (j = 0; j < cont2; j++) {
      						if (conj1[i] == conj2[j]) {
      							k += 1;
      						}
      					}
      					// Verificando quantas vezes conj1[i] apareceu em conj2
      					if (k == 0) {
      						conjR[i_R]=conj1[i];
      						i_R += 1;
      					}
      					k = 0;
      				}
      			} else {
      				// A - C
      				k = 0;
      				// Fixando conj1[i]
      				for (i = 0, i_R = 0; i < cont1; i++) {
      					// Variando conj3[j]
      					for (j = 0; j < cont3; j++) {
      						if (conj1[i] == conj3[j]) {
      							k+=1;
      						}
      					}
      					// Verificando quantas vezes conj1[i] apareceu em conj3
      					if (k == 0) {
      						conjR[i_R] = conj1[i];
      						i_R += 1;
      					}
      					k = 0;
      				}
      			}
      		}
      	}
      	// B - X
      	if (strcmp("B", op1) == 0) {
      		// B - A
      		if (strcmp("A", op2) == 0) {
      			k = 0;
      			// Fixando conj2[i]
      			for (i=0, i_R=0; i<cont2; i++) {
      				// Variando conj1[j]
      				for (j = 0; j < cont1; j++) {
      					if (conj2[i] == conj1[j]) {
      						k+=1;
      					}
      				}
      				// Verificando quantas vezes conj2[i] apareceu em conj1
      				if (k == 0) {
      					conjR[i_R]=conj2[i];
      					i_R += 1;
      				}
      				k = 0;
      			}
      		} else {
      			// B - B
      			if (strcmp("B", op2) == 0) {
      				// Vazio
      				i_R = 0;
      			} else {
      				// B - C
      				k = 0;
      				// Fixando conj2[i]
      				for (i = 0, i_R = 0; i < cont2; i++) {
      					// Variando conj3[j]
      					for (j = 0; j < cont3; j++) {
      						if (conj2[i] == conj3[j]) {
      							k+=1;
      						}
      					}
      					// Verificando quantas vezes conj2[i] apareceu em conj3
      					if (k == 0) {
      						conjR[i_R] = conj2[i];
      						i_R += 1;
      					}
      					k = 0;
      				}
      			}
      		}
      	}
      	// C - X
      	if (strcmp("C", op1) == 0) {
      		// C - A
      		if (strcmp("A", op2) == 0) {
      			k = 0;
      			// Fixando conj3[i]
      			for (i = 0, i_R = 0; i < cont3; i++) {
      				// Variando conj1[j]
      				for (j = 0; j < cont1; j++) {
      					if (conj3[i] == conj1[j]) {
      						k += 1;
      					}
      				}
      				// Verificando quantas vezes conj3[i] apareceu em conj1
      				if (k == 0) {
      					conjR[i_R] = conj3[i];
      					i_R += 1;
      				}
      				k = 0;
      			}
      		} else {
      			// C - B
      			if (strcmp("B", op2) == 0) {
      				k = 0;
      				// Fixando conj3[i]
      				for (i = 0, i_R = 0; i < cont3; i++) {
      					// Variando conj2[j]
      					for (j = 0; j < cont2; j++) {
      						if (conj3[i] == conj2[j]) {
      							k += 1;
      						}
      					}
      					// Verificando quantas vezes conj3[i] apareceu em conj2
      					if (k == 0) {
      						conjR[i_R] = conj3[i];
      						i_R += 1;
      					}
      					k = 0;
      				}
      			} else {
      				// C- C
      				// Vazio
      				i_R=0;
      			}
      		}
      	}

      	// Imprimindo
      	printf("\n");
      	printf("%s - %s = {", op1, op2);
      	for (k = 0; k < i_R; k++) {
      		if (k != 0 && k < (i_R)) {
      			printf(", ");
      		}
      		printf("%d", conjR[k]);
      	}
      	printf("}\n");
        break;

      case 8:
        printf("Qual o primeiro conjunto: [A, B ou C]\n");
      	scanf("%s", op1);
      	printf("Qual o segundo conjunto: [A, B, ou C]\n");
      	scanf("%s", op2);

      	if (strcmp("A", op1)==0) {
      		// A x A
      		if (strcmp("A", op2) == 0) {
      			i = 0;
      			j = 0;
      			k = 0;
      			i_R = cont1*cont1;
      			printf("\n");
      			printf("%s x %s = {", op1, op2);
      			for (i = 0; i <= cont1; i++) {
      				for (j, k = 0; k <= cont1; j++, k++) {
      					if (j != 0 && j < (i_R)) {
      						printf(",");
      					}
      					printf(" (%d, %d)", conj1[i], conj1[k]);
      				}
      			}
      			printf(" }\n");
      		} else {
      			// A x B
      			if (strcmp("B", op2) == 0) {
      				i = 0;
      				j = 0;
      				k = 0;
      				i_R = cont1*cont2;
      				printf("\n");
      				printf("%s x %s = {", op1, op2);
      				for (i = 0; i <= cont1; i++) {
      					for (j, k = 0; k <= cont2; j++, k++) {
      						if (j!=0 && j<(i_R)) {
      							printf(",");
      						}
      						printf(" (%d, %d)", conj1[i], conj2[k]);
      					}
      				}
      				printf(" }\n");
      			} else {
      				// A x C
      				i = 0;
      				j = 0;
      				k = 0;
      				i_R = cont1*cont3;
      				printf("\n");
      				printf("%s x %s = {", op1, op2);
      				for (i=0; i<=cont1; i++) {
      					for (j, k = 0; k <= cont3; j++, k++) {
      						if (j!=0 && j<(i_R)) {
      							printf(",");
      						}
      						printf(" (%d, %d)", conj1[i], conj3[k]);
      					}
      				}
      				printf(" }\n");
      			}
      		}
      	}
      	if (strcmp("B", op1) == 0) {
      		// B x A
      		if (strcmp("A", op2) == 0) {
      			i = 0;
      			j = 0;
      			k = 0;
      			i_R = cont2*cont1;
      			printf("\n");
      			printf("%s x %s = {", op1, op2);
      			for (i=0; i<=cont2; i++) {
      				for (j, k=0; k<=cont1; j++, k++) {
      					if (j!=0 && j<(i_R)) {
      						printf(",");
      					}
      					printf(" (%d, %d)", conj2[i], conj1[k]);
      				}
      			}
      			printf(" }\n");
      		} else {
      			// B x B
      			if (strcmp("B", op2) == 0) {
      				i = 0;
      				j = 0;
      				k = 0;
      				i_R = cont2*cont2;
      				printf("\n");
      				printf("%s x %s = {", op1, op2);
      				for (i=0; i<=cont2; i++) {
      					for (j, k=0; k<=cont2; j++, k++) {
      						if (j!=0 && j<(i_R)) {
      							printf(",");
      						}
      						printf(" (%d, %d)", conj2[i], conj2[k]);
      					}
      				}
      				printf(" }\n");
      			} else {
      				// B x C
      				i = 0;
      				j = 0;
      				k = 0;
      				i_R = cont2*cont3;
      				printf("\n");
      			    printf("%s x %s = {", op1, op2);
      				for (i=0; i<=cont2; i++) {
      					for (j, k=0; k<=cont3; j++, k++) {
      						if (j!=0 && j<(i_R)) {
      							printf(",");
      						}
      						printf(" (%d, %d)", conj2[i], conj3[k]);
      					}
      				}
      				printf(" }\n");
      			}
      		}
      	}
      	if (strcmp("C", op1) == 0) {
      		// C x A
      		if (strcmp("A", op2)==0) {
      			i = 0;
      			j = 0;
      			k = 0;
      			i_R = cont3*cont1;
      			printf("\n");
      			printf("%s x %s = {", op1, op2);
      			for (i=0; i<=cont3; i++) {
      				for (j, k=0; k<=cont1; j++, k++) {
      					if (j!=0 && j<(i_R)) {
      						printf(",");
      					}
      					printf(" (%d, %d)", conj3[i], conj1[k]);
      				}
      			}
      			printf(" }\n");
      		} else {
      			// C x B
      			if (strcmp("B", op2) == 0) {
      				i = 0;
      				j = 0;
      				k = 0;
      				i_R = cont3*cont2;
      				printf("\n");
      				printf("%s x %s = {", op1, op2);
      				for (i=0; i<=cont3; i++) {
      					for (j, k=0; k<=cont2; j++, k++) {
      						if (j!=0 && j<(i_R)) {
      							printf(",");
      						}
      						printf(" (%d, %d)", conj3[i], conj2[k]);
      					}
      				}
      				printf(" }\n");
      			} else {
      				// C x C
      				i = 0;
      				j = 0;
      				k = 0;
      				i_R = cont3*cont3;
      				printf("\n");
      				printf("%s x %s = {", op1, op2);
      				for (i=0; i<=cont3; i++) {
      					for (j, k=0; k<=cont3; j++, k++) {
      						if (j!=0 && j<(i_R)) {
      							printf(",");
      						}
      						printf(" (%d, %d)", conj3[i], conj3[k]);
      					}
      				}
      				printf(" }\n");
      			}
      		}
        }
        break;

      case 9:
        // Pergunta qual conjunto quer verificar.
        printf("Qual conjunto você quer visualizar? [1-3]: ");
        scanf("%s", op1);

        if (strcmp("A", op1) == 0) {
          // Itera entre os itens do conjunto A e imprime todos seus elementos organizadamente.
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont1; i++) {
            if (i != 0 && i < cont1 + 1) {
              printf(", ");
            }
            printf("%d", conj1[i]);
          }
          printf("}\n\n\n");
          break;
        } else if (strcmp("B", op1) == 0) {
          // Funciona da mesma forma que o elemento A
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont2; i++) {
            if (i != 0 && i < cont2 + 1) {
              printf(", ");
            }
            printf("%d", conj2[i]);
          }
          printf("}\n\n\n");
          break;
        } else if (strcmp("C", op1) == 0) {
          // Funciona da mesma forma que o elemento A.
          printf("\n\n%s = {", op1);
          for (i = 0; i <= cont3; i++) {
            if (i != 0 && i < cont3 + 1) {
              printf(", ");
            }
            printf("%d", conj3[i]);
          }
          printf("}\n\n\n");
          break;
        } else {
          printf("Conjunto especificado não é válido.\n\n");
          break;
        }
        break;

      case 10:
        // Anuncia a finalização do programa, e retornar 0, encerrando o programa.
        printf("Finalizando...\n");
        return 0;

      default:
        printf("Operação inválida.\n");
        break;
    }
  }
  return 0;
}
