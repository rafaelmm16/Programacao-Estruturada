// Código V.0 feito por Nicolas Menezes Grinet
// Estrutura de dados
// Exemplo de programa que simula lista encadeada em pilha


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct node{    //Struct para os nós
  int elem;             //Conter um elemento
  struct node *next;    //Ponteiro para o próximo nó
}tNode;                 //Podemos chamar nós usando 'tNode'

int Pile(tNode *head);        //Uma função para inserir um nó na pilha
int UnPile(tNode *head);      //Uma função para remover um nó da pilha
int PrintNodes(tNode *head);  //Uma função que imprima a pilha de nós

int main(){

  tNode *head = NULL;       //Declarar a nó cabeça e definir ela como nula
  int count=0, opt=0;       //Declara dois ints; Um contador, e uma para armazenar a escolha do usuário

  if(head==NULL){           //Verificar se a cabeça é nula

    printf("There are no nodes. Create a node?\n (1) - Yes\n (2) - No\n\n");  //Avisar ao usuário que não há nós, e perguntar se deseja criar um nó
    scanf("%d", &opt);      //Receber a opção do usuário

    if(opt==1){             //Se usuário escolheu inserir um nó
        head = Pile(head);  //O endereço da cabeça será o endereço retornado pelo função Pile (Chamamos e apontamos para a nó cabeça, dentro da função)
        count++; }          //Contar +1 nó
  }

  do{                                           //Um loop 'do' para que sempre retorne ao menu
    system("cls");                              //Limpar a tela
    PrintNodes(head);                           //Imprimir a lista cadeada na tela
    printf("\nStats: \n");                      //Stats da lista
    printf("Height of pile: %d\n\n", count);    //Altura da pilha = (contador)
    printf("Choose an option: \n");             //Escolher um opção
    printf("(1) Pile a new element\n");         //Selecionar 1 para pilhar um novo nó
    printf("(2) Unpile an element\n");          //Selecionar 2 para despilhar um elemento
    printf("(3) Exit program\n");               //Selecionar 3 para saír do programa
    scanf("%d", &opt);                          //Escanear a opção do usuário

    if(opt==1){                                 //Verificar se a primeira opção foi escolhida
        count++;                                //Adicionar +1 ao contador para representar a criação de um nó
        head = Pile(head);                      //Declarar uma cabeça nova que será inserida na função pile pelo endereço retornado da função (chamamos e apontamos para a cabeça, dentro da função)
        opt = 0;  }                             //Retornar o opt ao 0 para re-iniciar o menu

    if(opt==2){                                         //Verificar se a segunda opção foi escolhida
        if(head==NULL){                                 //Verificar se não há nós, verificando a cabeça se for nula
            printf("\nThere are no nodes to delete.");  //Avisar ao usuário que não há nós para apagar
            getch();  }                                 //Apertar qualquer tecla pra continuar
        else{                                           //Se a cabeça não for nula
            head = UnPile(head);                        //Declarar uma cabeça nova com o endereço retornado pela função de despilhar
            count--; }                                  //Descontar um dígito do contador
        opt = 0; }                                      //Retornar o opt ao 0 para re-iniciar o menu

  }while(opt!=3);                                 //Se a opção 3 for escolhida, encerrar o loop do 'do'
  return 0;                                       //retornar 0 e encerrar a função main, finalizando o programa
}




int Pile(tNode *head){                            //A função de pilha, usando a cabeça como passagem de referência para que possamos apontar para ela
  tNode *aux = (tNode *)malloc(sizeof(tNode));    //Alocar memória para o nó novo, e segurar ele no 'aux'

  if(head==NULL){                                 //Verificar se a cabeça é nula
      head = (tNode *)malloc(sizeof(tNode));      //O endereço da nó cabeça apontará para um espaço alocado na memória
      head->elem = head;                          //Salvar o endereço do nó como o elemento
      head->next = NULL;                          //O nó apontará para nada
      return head;  }                             //Retornar o endereço desse novo nó

  aux->next = head;                               //Colocar o novo nó em cima da cabeça, e declarando a cabeça como o próximo nó
  aux->elem = aux;                                //Salvar o endereço do nó como o elemento
  head = aux;                                     //O nó novo será nomeado como a cabeça
  return head;                                    //Retornar o endereço da cabeça

}




int UnPile(tNode *head){    //Função despilhar; chamamos a cabeça na passagem de referência para que possamos apontar pra ela

  if(head->next == NULL){   //Verificar se a cabeça é o ultimo nó
      return NULL;  }       //O nó será null

  tNode *aux = head;        //Fazer um nó auxiliar em cima da cabeça
  head = head->next;        //Transferir a cabeça para o nó vizinho próximo
  free(aux);                //Liberar memória da nó cabeça anterior
  return head;              //Retornar o novo endereço da cabeça

}



int PrintNodes(tNode *head){              //Imprimir a lista; chamamos a cabeça na passagem para que apontamos apontar pra ela e manipular facilmente

  tNode *current = head;                  //Fazer um nó auxiliar que irá percorrer a lista; colocar ela em cima da cabeça

  if(head==NULL){                         //Se a cabeça for null / Se não há nós na lista
      printf("Nothing.\n");               //Avisar o usuário que não há nada
      return 0; }                         //Finalizar a função

  while(current->next!=NULL){             //Caso que haja nós, fazer um loop while que irá percorrer a lista até chegar no ultimo elemento
      printf(" ( %d )----->", current);   //Imprimir o nó debaixo do nó auxiliar 'current'
      current = current->next;  }         //Fazer o nó auxiliar 'current' pular para o próximo nó vizinho

  printf(" ( %d )-----> NULL", current);  //Quando chegar no ultimo nó, imprimir ela
  return 0;                               //Finalizar o código
}
