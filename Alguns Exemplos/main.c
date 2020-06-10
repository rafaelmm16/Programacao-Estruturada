#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char matricula[14];
    char nome[50];
    float CR;
    }Aluno;

int main(){


    Aluno*Lista=NULL;
    int capacidade=100, tam=0, op=0, i;
    FILE*fp;
    char nomearq[50];

    printf("Digite o nome do arquivo:");
    scanf("%s", nomearq);

    fp=fopen(nomearq,"rb");

    if(fp!=NULL){
        fread(&tam, sizeof(int),1,fp);

    if(tam>capacidade) capacidade=tam;
    Lista=(Aluno*)calloc(capacidade,sizeof(Aluno));

    fread(Lista,sizeof(Aluno),tam,fp);
    fclose(fp);
    }else{
        Lista=(Aluno*)calloc(capacidade,sizeof(Aluno));
        }

    while(op!=4){
    printf("1. Inserir um novo aluno\n2. imprimir a lista\n3. Sair\n Escolha uma opção: ");
    scanf("%d", &op);

    switch (op){
        case 1:
            if(tam>capacidade-1){
           printf("Duplicação da capacidade da lista\n");
           capacidade*=2;
           Lista = (Aluno*)realloc(Lista,capacidade*sizeof(Aluno));
           }
           printf("Digite a matricula");
           scanf("%s", Lista[tam].matricula);
           printf("digite o nome");
           scanf("%s", Lista[tam].nome);
           printf("Digite o CR");
           scanf("%f", &(Lista[tam].CR));
           tam+=1;
           break;
        case 2:
            for(i=0; i<tam; i++){
            printf("matricula %s\n nome: %s\n CR: %2.f\n\n",Lista[i].matricula, Lista[i].nome, Lista[i].CR);
            break;
            }
        case 3:
        fp = fopen(nomearq,"wb");
        if (fp != NULL) {
        fwrite(&tam,sizeof(int),1,fp);
        fwrite(Lista,sizeof(Aluno),tam,fp);
        fclose(fp);}
        else{
            printf("Nao foi possivel salvar os dados");
        }
        break;
    default:
        break;
        }
    }
    return 0;
    }
