// C�digo V.0 feito por Nicolas Menezes Grinet
// Estrutura de dados
// Exemplo de programa que simula lista encadeada em pilha


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct node{    //Struct para os n�s
  int elem;             //Conter um elemento
  struct node *next;    //Ponteiro para o pr�ximo n�
}tNode;                 //Podemos chamar n�s usando 'tNode'

int Pile(tNode *head);        //Uma fun��o para inserir um n� na pilha
int UnPile(tNode *head);      //Uma fun��o para remover um n� da pilha
int PrintNodes(tNode *head);  //Uma fun��o que imprima a pilha de n�s

int main(){

  tNode *head = NULL;       //Declarar a n� cabe�a e definir ela como nula
  int count=0, opt=0;       //Declara dois ints; Um contador, e uma para armazenar a escolha do usu�rio

  if(head==NULL){           //Verificar se a cabe�a � nula

    printf("There are no nodes. Create a node?\n (1) - Yes\n (2) - No\n\n");  //Avisar ao usu�rio que n�o h� n�s, e perguntar se deseja criar um n�
    scanf("%d", &opt);      //Receber a op��o do usu�rio

    if(opt==1){             //Se usu�rio escolheu inserir um n�
        head = Pile(head);  //O endere�o da cabe�a ser� o endere�o retornado pelo fun��o Pile (Chamamos e apontamos para a n� cabe�a, dentro da fun��o)
        count++; }          //Contar +1 n�
  }

  do{                                           //Um loop 'do' para que sempre retorne ao menu
    system("cls");                              //Limpar a tela
    PrintNodes(head);                           //Imprimir a lista cadeada na tela
    printf("\nStats: \n");                      //Stats da lista
    printf("Height of pile: %d\n\n", count);    //Altura da pilha = (contador)
    printf("Choose an option: \n");             //Escolher um op��o
    printf("(1) Pile a new element\n");         //Selecionar 1 para pilhar um novo n�
    printf("(2) Unpile an element\n");          //Selecionar 2 para despilhar um elemento
    printf("(3) Exit program\n");               //Selecionar 3 para sa�r do programa
    scanf("%d", &opt);                          //Escanear a op��o do usu�rio

    if(opt==1){                                 //Verificar se a primeira op��o foi escolhida
        count++;                                //Adicionar +1 ao contador para representar a cria��o de um n�
        head = Pile(head);                      //Declarar uma cabe�a nova que ser� inserida na fun��o pile pelo endere�o retornado da fun��o (chamamos e apontamos para a cabe�a, dentro da fun��o)
        opt = 0;  }                             //Retornar o opt ao 0 para re-iniciar o menu

    if(opt==2){                                         //Verificar se a segunda op��o foi escolhida
        if(head==NULL){                                 //Verificar se n�o h� n�s, verificando a cabe�a se for nula
            printf("\nThere are no nodes to delete.");  //Avisar ao usu�rio que n�o h� n�s para apagar
            getch();  }                                 //Apertar qualquer tecla pra continuar
        else{                                           //Se a cabe�a n�o for nula
            head = UnPile(head);                        //Declarar uma cabe�a nova com o endere�o retornado pela fun��o de despilhar
            count--; }                                  //Descontar um d�gito do contador
        opt = 0; }                                      //Retornar o opt ao 0 para re-iniciar o menu

  }while(opt!=3);                                 //Se a op��o 3 for escolhida, encerrar o loop do 'do'
  return 0;                                       //retornar 0 e encerrar a fun��o main, finalizando o programa
}




int Pile(tNode *head){                            //A fun��o de pilha, usando a cabe�a como passagem de refer�ncia para que possamos apontar para ela
  tNode *aux = (tNode *)malloc(sizeof(tNode));    //Alocar mem�ria para o n� novo, e segurar ele no 'aux'

  if(head==NULL){                                 //Verificar se a cabe�a � nula
      head = (tNode *)malloc(sizeof(tNode));      //O endere�o da n� cabe�a apontar� para um espa�o alocado na mem�ria
      head->elem = head;                          //Salvar o endere�o do n� como o elemento
      head->next = NULL;                          //O n� apontar� para nada
      return head;  }                             //Retornar o endere�o desse novo n�

  aux->next = head;                               //Colocar o novo n� em cima da cabe�a, e declarando a cabe�a como o pr�ximo n�
  aux->elem = aux;                                //Salvar o endere�o do n� como o elemento
  head = aux;                                     //O n� novo ser� nomeado como a cabe�a
  return head;                                    //Retornar o endere�o da cabe�a

}




int UnPile(tNode *head){    //Fun��o despilhar; chamamos a cabe�a na passagem de refer�ncia para que possamos apontar pra ela

  if(head->next == NULL){   //Verificar se a cabe�a � o ultimo n�
      return NULL;  }       //O n� ser� null

  tNode *aux = head;        //Fazer um n� auxiliar em cima da cabe�a
  head = head->next;        //Transferir a cabe�a para o n� vizinho pr�ximo
  free(aux);                //Liberar mem�ria da n� cabe�a anterior
  return head;              //Retornar o novo endere�o da cabe�a

}



int PrintNodes(tNode *head){              //Imprimir a lista; chamamos a cabe�a na passagem para que apontamos apontar pra ela e manipular facilmente

  tNode *current = head;                  //Fazer um n� auxiliar que ir� percorrer a lista; colocar ela em cima da cabe�a

  if(head==NULL){                         //Se a cabe�a for null / Se n�o h� n�s na lista
      printf("Nothing.\n");               //Avisar o usu�rio que n�o h� nada
      return 0; }                         //Finalizar a fun��o

  while(current->next!=NULL){             //Caso que haja n�s, fazer um loop while que ir� percorrer a lista at� chegar no ultimo elemento
      printf(" ( %d )----->", current);   //Imprimir o n� debaixo do n� auxiliar 'current'
      current = current->next;  }         //Fazer o n� auxiliar 'current' pular para o pr�ximo n� vizinho

  printf(" ( %d )-----> NULL", current);  //Quando chegar no ultimo n�, imprimir ela
  return 0;                               //Finalizar o c�digo
}
