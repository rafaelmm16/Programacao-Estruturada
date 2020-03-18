//
//  main.c
//  Conteudo
//
//  Created by Rafael on 07/02/20.
//  Copyright © 2020 Rafael. All rights reserved.
//

//test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct estrutura{
    int a;
    float b;
    char c;
}estruturaop;

void fun(){
    printf("\nEssa é uma função void.\n");
}
int fun2(){
    int a,b,c;
    a=2;
    b=3;
    c=a+b;
    printf("\n%d\n", c);
    printf("\nEssa é uma função com retorno.\n");
    return c;
}
int fun3(int a, int b, int c){
    c=a+b;
    printf("\n%d\n", c);
    printf("\nEssa é uma função com paramêtros.\n");
    return c;
}

int main() {
    
    int op = 0;
    estruturaop estrutura;
    
    setlocale(LC_ALL, NULL);
    
    do {
        printf("*********************************");
        printf("\nOpções:\n\n 1: if/else \n 2: Repetição \n 3: Struct \n 4: Vetor \n 5: Matriz \n 6: Ponteiro \n 7: Função \n 8: Sair \n\n");
        printf("*********************************\n");
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                system("clear||cls");
                printf("\nIf(se) o primeiro número for maior que o segundo número, ele será mostrado.\n");
                printf("Else(se não) o segundo número será mostrado.\n");
                printf("\nif = decisão\n");
                
                int escolha1, escolha2;
                
                printf("\nDigite dois número:\n");
                scanf("%d %d", &escolha1, &escolha2);
               
                if(escolha1>escolha2){
                    printf("\n%d foi maior que o segundo.\n", escolha1);
                }
                else
                    printf("\n%d foi maior que o primeiro.\n", escolha2);
                printf("\nif/else támbem pode ser usado com trechos de códigos dentro das condições.\n");
                printf("\n\n");
                
            break;
                
            case 2:
                system("clear||cls");
                printf("---- Laços de repetição ---\n");
                printf("\t++ while ++ \n\t++ do while ++ \n\t++ for ++ \n");
                
                printf("\nwhile = enquanto\n");
                printf("\ndo while = faça até\n");
                printf("\nfor = para(conjunto, começo, parada e incremento)\n");
                
                int cont=0, num;
                
                op=0;
                do{
                printf("\nEscolha um dos 3\n");
                printf("\n 1: while \n 2: do while \n 3: for \n 4: sair\n");
                scanf("%d", &op);
                
                printf("\nDigite um número:");
                scanf("%d", &num);
                
                if(op==1){
                    while(cont<num){
                        printf("\n%d\n", num);
                        cont++;
                    }

                }
                else
                    if(op==2){
                        do{
                            printf("\n%d\n", num);
                        }
                        while(num==cont);
                    }
               else
                   if(op==3){
                       for(cont=0; cont<num; cont++){
                           printf("\n%d\n", num);
                       }
                   }
                    printf("\n\n");
                }while(op!=4);
                
                break;
                
            case 3:
                system("clear||cls");
                printf("\nStruct é um conjunto de variaveis guardadas dentro de uma unica estrutura.\n");
                
                printf("\nDigite um número inteiro;\n");
                scanf("%d", &estrutura.a);
                printf("\nDigite um real;\n");
                scanf("%f", &estrutura.b);
                fflush(stdin);
                printf("\nDigite um caracter:\n");
                scanf("%c", &estrutura.c);
                fflush(stdin);
                
                printf("\nToda manipulação de dados é feita dentro da estrutura;");
                
                
                printf("\n\n");
                
                break;
                
            case 4:
                system("clear||cls");
                printf("\nVetor é um espaço de mémoria previamente 'reservado'.\n");
                printf("\nAssim ele pode ter um tamnho fixo ou maleavel.\n");
                printf("\nPorém o maleavel só é pssível atraves de ponteiro, ou com uma especíe de gambiarra(entretanto não deve ser utilizada)\n");
                printf("\n");
                printf("\nPara preenhcer, percorrer e alterar um vetor é utilizado um 'for'\n");
                
                int tam,i;
                
                printf("\nDigite o tamanho do vetor:\n");
                scanf("%d", &tam);

                int *v = NULL;
                
                 v = (int *) malloc(tam * sizeof(int));

                
                for(i=0;i<tam;i++){
                    printf("\nPreencha o vetor:");
                    scanf("%d", &v[i]);
                }
                for(i=0;i<tam;i++){
                printf("\nImpressão do vetor [%d]:%d", i, v[i]);
                }
                
                free(v);
                i=0;
                printf("\n\n");
                
                break;
                
            case 5:
                system("clear||cls");
                printf("\nBem não há muito o que explicar de uma matriz;");
                printf("\nEntretanto ela é composta por 2 for's uma para linha e outro para coluna;");
                
                printf("\nPara exemplo vamos utilizar uma matriz 2x2;\n");
                
                int mat[2][2];
                int k, j;
                
                for(k=0;k<2;k++){
                    for(j=0;j<2;j++){
                        printf("\nPreencha a matriz:\n");
                        scanf("%d", &mat[k][j]);
                    }
                }
                for(k=0;k<2;k++){
                    for(j=0;j<2;j++){
                        printf("\nMatriz: [%d][%d] : [%d]", k, j, mat[k][j]);
                    }
                }
                printf("\n\n");
                
                break;
                
            case 6:
                system("clear||cls");
                printf("\nPonteiro é uma varíavel que acessa um espaço de mémoria;");
                printf("\nTambém sendo possível alocar e realocar espaços em mémoria;");
                printf("\nAlém de conter o endereço e valor de uma variavel.");
                
                int *ptr = NULL;
                int tamanho, newtam, m,n;
                
                printf("\nInforme o tamanho do ponteiro:\n");
                scanf("%d", &tamanho);
                
                ptr = (int *) malloc (tamanho * sizeof(int));
                
                for(m=0;m<tamanho;m++){
                    printf("\nPreencha o ponteiro:");
                    scanf("%d", &ptr[m]);
                }
                for(m=0;m<tamanho;m++){
                    printf("\nValor guardado: %d", ptr[m]);
                    printf("\nEndereço: %d\n", &ptr[m]);
                }
                
                printf("\nDeseja alterar o tamnho do ponteiro?");
                printf("\n1-sim \n2-não\n");
                scanf("%d", &n);
                
                if(n==1){
                    printf("\nInforme o novo tamanho:\n");
                    scanf("%d", &newtam);
                    ptr =(int *) realloc(ptr, (newtam + tamanho)*sizeof(int));
                    
                    for(m=0;m<tamanho+newtam;m++){
                        printf("\nPreencha os novos espaços:\n");
                        scanf("%d", &ptr[m]);
                    }
                    for(m=0;m<tamanho+newtam;m++){
                        printf("\nValor guardado: %d\n", ptr[m]);
                        printf("\nEndereço: %d\n", &ptr[m]);
                    }
                }
                else
                printf("\n\n");
                
                break;
                
            case 7:
                system("clear||cls");
                printf("\nFunção é utilizado fora da main, como uma especie de prótotipo;\n");
                printf("\nTambém podem ter paramêtros, retorno vazio, ou algum tipo de retorno.\n");
                int a = 0, b = 0, c = 0;
                a=5;
                b=5;
                printf("\n");
                printf("\nEm sequência: void, retorno e paramêtro;\n");
                fun();
                fun2();
                fun3(a, b, c);
                printf("\n\n");
                
                break;
                
            default:
                break;
        }
    }while(op<8);
    
    return 0;
}

