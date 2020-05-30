#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STRUCT DE RESERVAS
//   Estrutura de dados que armazena informações sobre reservas.
typedef struct {
  int id;
  char linha[200];
  char horario[10];
  int poltrona;
} Reserva;

// STRUCT DE ONIBUS
//   Estrutura de dados que pode armazenar informações sobre os onibus
typedef struct {
  char linha[200];
  char horario[10];
  int vagas;
  int mapa[10][4];
} Onibus;

/* ALOCAÇÃO PARA ONIBUS
    Esta função aloca memória para a estrutura de dados onibus. Retorna o
    ponteiro para o endereço de memória alocado.
    @var  int   tam   Recebe tamanho do struct
*/
Onibus* allocBus(int tam) {
  Onibus *onibus;
  int i;
  onibus = (Onibus *)calloc(tam, sizeof(Onibus));
  for (i = 0; i < tam; i++) {
    onibus[i].vagas = 40;
  }
  return onibus;
}

Onibus* reallocBus(Onibus *onibus, int tam) {
  onibus = (Onibus *)realloc(onibus, tam * sizeof(Onibus));
  return onibus;
}

/* ALOCAÇÃO DE RESERVAS
    Esta função aloca memória para a estrutura de dados reserva. Retorna o
    ponteiro para o endereço de memória alocada.
*/
Reserva* allocReserva(int tam) {
  Reserva *reserva;
  reserva = (Reserva *)calloc(tam, sizeof(Reserva));
  return reserva;
}

Reserva* reallocReserva(Reserva *reserva, int tam) {
  reserva = (Reserva *)realloc(reserva, tam * sizeof(Reserva));
  return reserva;
}

/* MOSTRAR MENU
    Mostra as opções de operações que o programa pode realizar.
*/
void menu() {
  printf("+--------------------------------------------------+\n"
         "| [1] Criar linha                                  |\n"
         "| [2] Carregar arquivo                             |\n"
         "| [3] Fazer reserva                                |\n"
         "| [4] Cancelar reserva                             |\n"
         "| [5] Procurar reserva                             |\n"
         "| [6] Mostrar mapa de assentos                     |\n"
         "| [7] Salvar alterações                            |\n"
         "| [8] Sair                                         |\n"
         "+--------------------------------------------------+\n");
}

/* CONVERTE PARA MINUSCULO
    Esta função converte uma string para minusculo.
*/
void minusculo(char str[]) {
   int c = 0;
   while (str[c] != '\0') {
      if (str[c] >= 'A' && str[c] <= 'Z') {
         str[c] = str[c] + 32;
      }
      c++;
   }
}

/* CONVERTE PARA MAIUSCULAS
    Esta função converte uma string para maiusculo.
*/
void maiusculo(char str[]) {
   int c = 0;
   while (str[c] != '\0') {
      if (str[c] >= 'a' && str[c] <= 'z') {
         str[c] = str[c] - 32;
      }
      c++;
   }
}

/* CONFIRMAR OPERAÇÃO
    Esta função pergunta o usuário se ele deseja confirmar alguma operação.
      Retorna 1 caso a resposta seja 'sim', e retorna 0 caso seja 'nao'. Persiste
      na pergunta até que o usuario dê uma das duas respostas. Função é case-insensitive,
      o programa identifica qualquer variação das palavras chave uma vez que ele converte
      a string para minusculo e faz a verificação dessa forma.

      @return   int
*/
int confirma() {
  char conf[5];
  while (strcmp(conf, "sim") != 0 || strcmp(conf, "nao") != 0) {
    printf("Você tem certeza que deseja realizar essa operação? [sim/nao]: ");
    scanf("%s", conf);
    minusculo(conf);
    if (!strcmp(conf, "sim")) {
      return 1;
    } else if (!strcmp(conf, "nao")) {
      return 0;
    } else {
      printf("\n\nOpção inválida. Diga 'sim' ou 'nao'.\n");
    }
  }
}


Onibus* criarLinha(int tam) {
  Onibus* linha = allocBus(tam);
  for (int i = 0; i < tam; i++) {
    printf("  [%d] Horário [hh:mm]: ", i+1);
    scanf("%s", linha[i].horario);
  }
  return linha;
}

int horarioexiste(Onibus *linha, char horario[10], int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    if (strcmp(linha[i].horario, horario) == 0) {
      return 1;
    }
  }
  return 0;
}

int getindicehorario(Onibus *linha, char horario[10], int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    if (strcmp(linha[i].horario, horario) == 0) {
      return i;
    }
  }
  return -1;
}

int assentoreservado(Onibus *linha, char horario[10], int tam, int i, int j) {
  int indice = getindicehorario(linha, horario, tam);
  if (indice == -1) return 0;
  if (linha[indice].mapa[i][j] == 1) return 1;
  else return 0;
}

void mostrarMapa(Onibus *linha, char horario[10], int tam) {
  int i, j, k = 1;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 4; j++) {
      if (assentoreservado(linha, horario, tam, i, j)) {
        printf("*\t");
      } else {
        printf("%d\t", k);
      }
      k++;
    }
    printf("\n");
  }
  printf("\n\n");
}

void pedirMapa(Onibus *linha, int tam) {
  char horario[10];
  int i;
  printf("Qual horário você quer visualizar? [hh:mm]: ");
  scanf("%s", horario);
  while(horarioexiste(linha, horario, tam) == 0) {
    printf("Horário não existe. Diga um horário válido [hh:mm]: ");
    scanf("%s", horario);
  }
  mostrarMapa(linha, horario, tam);
}

void mostrarHorarios(Onibus *linha, int tam) {
  int i, indice, vagas;
  printf("Horários disponíveis nessa linha:\n");
  for (i = 0; i < tam; i++) {
    printf("  + %s\n", linha[i].horario);
  }
  printf("\n");
}

int reservaexiste(Reserva *reservas, int tam, int resv) {
  int i;
  for (i = 0; i < tam; i++) {
    if (reservas[i].id == resv) {
      return 1;
    }
  }
  return 0;
}

// FUNÇÃO PRINCIPAL
int main() {
  int i, k = 1, j, g, h, line = 0, coluna = 0, op, resv, poltrona, tamhorarios, id_maximo = 0, carregado = 0, salvo = 0;
  int indice = 0, contres = 0, poltrona_aux, tamhorarios_aux, indice_aux;/// contres = contador de reservas
  char enter, nomelinha[200], novonome[200], arq[210], arqaux[215], arqres[215], horario[10], linha_aux[200], horario_aux[10];
  Onibus *linha, *linha_de_cancelamento;
  Reserva *reservas;
  FILE *fptr;

  reservas = allocReserva(5);

  op = 0;
  carregado = 0;
  salvo = 1;

  printf("        SISTEMA DE RESERVA PARA ONIBUS\n");
  while (1) {
    // Mostra o menu de opções para o usuário e pede para que ele diga qual
    //  operação deseja realizar.
    if (op < 10) {
      menu();
      printf(">>> Qual operação? [1-8]: ");
      scanf("%d", &op);
    } else {
      op = op-10;
    }

    // Identifica qual operação o usuário quer realizar.  Uma vez identificado, ele chama funções
    //  para realizar a operação.  Cada operação possui sua própria função.
    switch(op) {
      case 1:
        // Verifica se já existe um arquivo carregado. Se sim, avisar o usuário dos riscos.
        if (salvo == 0) {
          printf("Existem alterações não salvas na linha carregada atualmente. Você perderá todas as alterações feitas ao criar uma nova linha sem salvar as alterações.\n");
          if (!confirma()) {
            break;
          }
        }
        // Pede ao usuário qual o nome da linha e quantos horários ela terá.
        printf("Qual o nome da linha [e.g.: Centro-Guriri]: ");
        scanf("%s", nomelinha);

        // Concatena o nome da linha com ''.txt', formando assim o nome do arquivo da linha onde a mesma será salva.
        strcpy(arq, nomelinha);
        strcat(arq, ".txt");

        fptr = fopen(arq, "rb");
        if (fptr != NULL) {
          printf("Já existe uma linha com esse nome. Tente outro.\n\n");
          fclose(fptr);
          break;
        }

        printf("Quantos horários essa linha terá?: ");
        scanf("%d", &tamhorarios);

        // Cria o arquivo da Linha de onibus sendo criada. criarLinha() pede os horários que a Linha terá e retorna estrutura pronta para salvar.
        fptr = fopen(arq, "wb");
        linha = criarLinha(tamhorarios);
        fwrite(&tamhorarios, sizeof(int), 1, fptr);
        fwrite(linha, sizeof(Onibus), tamhorarios, fptr);
        fclose(fptr);

        // Cria o arquivo de reservas caso ele não exista. Caso exista, só reescreve as reservas contidas na estrutura Reserva.
        fptr = fopen("reservas.txt", "wb");
        fwrite(&contres, sizeof(int), 1, fptr);
        fwrite(&id_maximo, sizeof(int), 1, fptr);
        fwrite(reservas, sizeof(Reserva), contres, fptr);
        fclose(fptr);

        // Existe um arquivo carregado no programa agora.
        carregado = 1;
        // Nenhum dado pendente para ser salvo. Dados acabaram de ser lidos.
        salvo = 1;
        // Confirma ao usuário que o arquivo foi carregado.
        printf("Linha '%s' cadastrada. %d horário(s) registrado(s).\n\n", nomelinha, tamhorarios);
        break;

      case 2:
        // Verifica se já existe um arquivo carregado. Se sim, avisar o usuário dos riscos.
        if (carregado == 0) {
          linha = allocBus(1);
        }
        printf("Qual o nome do arquivo? [Nome da linha.txt]: ");
        scanf("%s", novonome);

        if (strcmp(nomelinha, novonome) == 0) {
          printf("A linha '%s' já está carregada e sendo utilizada nesse programa.\n\n", novonome);
          break;
        }

        // Atualiza a variável para representar o nome da nova linha carregada
        strcpy(nomelinha, novonome);

        fptr = fopen("reservas.txt", "rb");
        if (fptr == NULL) {
          printf("Não foi possível achar o arquivo contendo as reservas.\n\n");
          break;
        }
        fread(&contres, sizeof(int), 1, fptr);
        fread(&id_maximo, sizeof(int), 1, fptr);
        reservas = allocReserva(contres);
        fread(reservas, sizeof(Reserva), contres, fptr);
        fclose(fptr);

        // Obtém o nome do arquivo da linha solicitada para ler os dados.
        strcpy(arq, nomelinha);
        strcat(arq, ".txt");

        fptr = fopen(arq, "rb");
        if (fptr == NULL) {
          printf("Não foi possível encontrar o arquivo para a linha solicitada. Crie uma nova linha.\n\n");
          op = 11;
          salvo = 0;
          break;
        }
        fread(&tamhorarios, sizeof(int), 1, fptr);
        linha = allocBus(tamhorarios);
        fread(linha, sizeof(Onibus), tamhorarios, fptr);
        fclose(fptr);

        // Existe um arquivo carregado no programa.
        carregado = 1;
        // Arquivo acabou de ser carregado. Logo, não existem alterações não salvas.
        salvo = 1;
        // Notifica sucesso das operações.
        printf("Arquivo '%s' carregado com sucesso.\n\n", arq);
        break;

      case 3:
        // Verifica se existe arquivo carregado atualmente.
        if (carregado == 0) {
          printf("Nenhum arquivo foi carregado. Crie uma nova linha ou carregue um arquivo contendo uma linha existente. Use as operações do menu a seguir.\n\n");
          break;
        }

        mostrarHorarios(linha, tamhorarios);

        printf("Em qual horário você gostaria de fazer uma reserva? [hh:mm]: ");
        scanf("%s", horario);

        while (!horarioexiste(linha, horario, tamhorarios)) {
          printf("Horário não existe. Diga um horário válido [hh:mm]: ");
          scanf("%s", horario);
        }

        indice = getindicehorario(linha, horario, tamhorarios);
        if (linha[indice].vagas <= 0) {
          printf("Não há vagas nesse horário.\n\n");
          break;
        }

        mostrarMapa(linha, horario, tamhorarios);

        k = 1;
        do {
          do {
            printf("Qual poltrona você deseja reservar?: ");
            scanf("%d", &poltrona);
          } while (poltrona < 1 || poltrona > 40);

          for (i = 0; i < 10; i++) {
            for (j = 0; j < 4; j++) {
              if (k == poltrona) {
                line = i;
                coluna = j;
              }
              k++;
            }
          }
        } while (assentoreservado(linha, horario, tamhorarios, line, coluna));

        linha[indice].mapa[line][coluna] = 1;
        linha[indice].vagas -= 1;
        // editar estrutura Reserva.
        // obter ID da nova reservar
        id_maximo++;
        // Aloca espaço para criar a nova reserva no vetor reservas.
        reservas = reallocReserva(reservas, contres+1);
        // Configura os dados no vetor de reservas com os dados de reservação.
        reservas[contres].id = id_maximo;
        reservas[contres].poltrona = poltrona;
        strcpy(reservas[contres].linha, nomelinha);
        strcpy(reservas[contres].horario, horario);
        // Aumenta o contador de indices no vetor reservas.
        contres++;
        // Alterações foram feitas e não estão salvas ainda.
        salvo = 0;
        // Verifica se a reserva foi realmente fetuada. Se sim, notifica sucesso. Contrário, passa o erro.
        if (assentoreservado(linha, horario, tamhorarios, line, coluna)) {
          printf("Reserva efetuada com sucesso! Dados de registro:\n");
          printf("  ID da reserva: %d\n", reservas[contres-1].id);
          printf("  Linha:         %s\n", reservas[contres-1].linha);
          printf("  Horário:       %s\n", reservas[contres-1].horario);
          printf("  Poltrona:      %d\n", reservas[contres-1].poltrona);
          printf("---\n\n");
        } else {
          printf("Ocorreu um erro ao reservar seu assento. Tente novamente.\n\n");
        }
        break;

      case 4:
        // Verifica se existe arquivo carregado atualmente.
        if (carregado == 0) {
          printf("Nenhum arquivo foi carregado. Crie uma nova linha ou carregue um arquivo contendo uma linha existente. Use as operações do menu a seguir.\n\n");
          break;
        }

        printf("Qual o número de identificação da reserva?: ");
        scanf("%d", &resv);

        if (!reservaexiste(reservas, contres, resv)) {
          printf("Não existe nenhuma reserva com esse número de identificação.\n\n");
          break;
        }

        // Identifica qual reserva possiu esse ID
        for (i = 0; i < contres; i++) {
          /*
          Remove a reserva especificado do vetor reservas. Para isso, substitui-se o indice
          contendo o valor a ser removido pelo valor do ultimo indice e decresce o
          número de indices do vetor contido em contres, forçando o programa a verificar só até esse.
          */
          if (reservas[i].id == resv) {
            // Atribuir as informações para variáveis auxiliares
            strcpy(linha_aux, reservas[i].linha);
            strcat(linha_aux, ".txt");
            strcpy(horario_aux, reservas[i].horario);
            poltrona_aux = reservas[i].poltrona;
            // Mudando mapa de assentos da reserva cancelada
    		    if (strcmp(arq, linha_aux) != 0) {
    		    	/*
      				Se a reserva não esta na linha atualmente aberta,
      				devemos abrir a linha correta e realizar as alterações
    		    	*/
  		        fptr = fopen(linha_aux, "rb");
  		        if (fptr == NULL) {
  		        	printf("Falha na abertura da linha para o cancelamento da reserva!1\n");
  		        	break;
  		        }
  		        fread(&tamhorarios_aux, sizeof(int), 1, fptr);
  		        linha_de_cancelamento = allocBus(tamhorarios_aux);
  		        fread(linha_de_cancelamento, sizeof(Onibus), tamhorarios_aux, fptr);
  		        fclose(fptr);

  		        // Identificando posição horario na linha
  		        indice_aux = getindicehorario(linha_de_cancelamento, horario_aux, tamhorarios_aux);

    		     	// Mudando a situação do assento
    		     	k = 1;
  		        for (g = 0; g < 10; g++) {
  		        	for (h = 0; h < 4; h++) {
  		        		if (k == poltrona_aux) {
  		        			linha_de_cancelamento[indice_aux].mapa[g][h] = 0;
  		        		}
  		        		k += 1;
  		        	}
  		        }
              // Mudando situação das vagas
              linha_de_cancelamento[indice_aux].vagas += 1;

  		        // Atualizando arquivo da linha
  		        fptr = fopen(linha_aux, "wb");
  		        if (fptr == NULL) {
  		        	printf("Falha na abertura da linha para o cancelamento da reserva!2\n");
  		        	break;
  		        }
  		        fwrite(&tamhorarios_aux, sizeof(int), 1, fptr);
  		        fwrite(linha_de_cancelamento, sizeof(Onibus), tamhorarios_aux, fptr);
  		        fclose(fptr);

  		        // Liberando memória
  		        free(linha_de_cancelamento);

  		        printf("Cancelamento efetuado com sucesso!\n\n");
  	        } else {
  	        	// A reserva está na linha atualmente aberta
  	        	indice_aux = getindicehorario(linha, horario_aux, tamhorarios);

  	        	// Mudando a situação do assento
  	        	k = 1;
  		        for (g = 0; g < 10; g++) {
  		        	for (h = 0; h < 4; h++) {
  		        		if (k == poltrona_aux) {
  		        			linha[indice_aux].mapa[g][h] = 0;
  		        		}
  		        		k += 1;
  		        	}
  		        }
              // Mudando situação das vagas
              linha[indice_aux].vagas += 1;

  		        printf("Cancelamento efetuado com sucesso!\n\n");
  	        }

            // Alterações foram feitas e não estão salvas ainda.
            salvo = 0;

            // Mudando valores
            reservas[i].id = reservas[contres-1].id;
            strcpy(reservas[i].linha, reservas[contres-1].linha);
            strcpy(reservas[i].horario, reservas[contres-1].horario);
            reservas[i].poltrona = reservas[contres-1].poltrona;

            // Mudando valor de contres (diminuindo vetor de reservas)
            contres -= 1;

            // Realocando vetor de reservas para condizer com as reservas "úteis"
            reservas = reallocReserva(reservas, contres);
          }
        }

        printf("---\n\n");
        break;
      case 5:
        // Verifica se existe arquivo carregado atualmente.
        if (carregado == 0) {
          printf("Nenhum arquivo foi carregado. Crie uma nova linha ou carregue um arquivo contendo uma linha existente. Use as operações do menu a seguir.\n\n");
          break;
        }

        printf("Qual o número de identificação da reserva?: ");
        scanf("%d", &resv);

        if (!reservaexiste(reservas, contres, resv)) {
          printf("Não existe nenhuma reserva com esse número de identificação.\n\n");
          break;
        }

        for (i = 0; i < contres; i++) {
          if (reservas[i].id == resv) {
            printf("Mostrando reserva sob o ID: %d\n", reservas[i].id);
            printf("  Linha:    %s\n", reservas[i].linha);
            printf("  Horário:  %s\n", reservas[i].horario);
            printf("  Poltrona: %d\n", reservas[i].poltrona);
          }
        }
        printf("---\n\n");
        break;

      case 6:
        // Verifica se existe arquivo carregado atualmente.
        if (carregado == 0) {
          printf("Nenhum arquivo foi carregado. Crie uma nova linha ou carregue um arquivo contendo uma linha existente. Use as operações do menu a seguir.\n\n");
          break;
        }
        // Mostrar horários disponíveis na linha carregada.
        mostrarHorarios(linha, tamhorarios);
        // Chama a função para solicitar o usuário que informe qual horário ele quer exibir o mapa.
        pedirMapa(linha, tamhorarios);
        break;

      case 7:
        // Verifica se existe arquivo carregado atualmente.
        if (carregado == 0) {
          printf("Nenhum arquivo foi carregado. Crie uma nova linha ou carregue um arquivo contendo uma linha existente. Use as operações do menu a seguir.\n\n");
          break;
        }

        // Concatena o nome da linha com ''.txt', formando assim o nome do arquivo da linha onde a mesma será salva.
        strcpy(arq, nomelinha);
        strcat(arq, ".txt");

        // Grava os dados das linhas no disco. Grava a quantidade de horários.
        fptr = fopen(arq, "wb");
        fwrite(&tamhorarios, sizeof(int), 1, fptr);
        fwrite(linha, sizeof(Onibus), tamhorarios, fptr);
        fclose(fptr);

        // Grava os dados de reservas em disco. Grava o número de indices no vetor e o ID maximo.
        fptr = fopen("reservas.txt", "wb");
        fwrite(&contres, sizeof(int), 1, fptr);
        fwrite(&id_maximo, sizeof(int), 1, fptr);
        fwrite(reservas, sizeof(Reserva), contres, fptr);
        fclose(fptr);

        // Existe um arquivo carregado no programa agora.
        carregado = 1;
        // Nenhum dado pendente para ser salvo. Dados acabaram de ser lidos.
        salvo = 1;
        // Notifica sucesso da operação.
        printf("Todos os dados gravados em disco. Você pode seguramente fechar o programa.\n\n");
        break;

      // SAIR DO PROGRAMA
      // Pergunta o usuário se ele realmente deseja encerrar o programa e, caso positivo,
      //   encerra o programa da forma que está.
      case 8:
        // Recolhe o enter que não foi recolhido durante a escoolha da operação para evitar erros.
        if (salvo == 0) {
          printf("Existem alterações que não foram salvas. Você perderá todos os dados se sair do programa agora.\n");
          if (confirma()) {
            printf("Encerrando...\n");
            return 0;
          } else {
            break;
          }
        } else {
          printf("Encerrando...\n");
          return 0;
        }

      // Nenhuma operação válida (i.e. 1-8) foi dada.  Informamos o usuário do
      //   erro e prosseguimos o loop para que ele possa tentar novamente.
      default:
        printf("Operação inválida. Por favor, especifique uma das operações do menu.\n\n");
    }
  }

  return 0;
}
