#include<stdio.h>
#include<stdlib.h>
//deu ruim, tentar de novo

int main(){
    FILE *fp, *fp2, *fp3;
    char nome1[50], nome2[50], caractere;
    
    printf("Digite o nome do primeiro arquivo (sem espaços):  ");
    scanf("%s", nome1);
    printf("Digite o nome do segundo arquivo (sem espaços):  ");
    scanf("%s", nome2);
    fp = fopen(nome1, "r");
    fp2 = fopen(nome2, "r");
    fp3 = fopen("resultado.txt", "w");
    if(fp!=NULL && fp2!=NULL){
        while(!feof(fp)){
            fscanf(fp, "%c", &caractere);
            fprintf(fp3, "%c", caractere);
        }  
        fprintf(fp3, "%c", '\n');
        fclose(fp);
        while(!feof(fp2)){
            fscanf(fp2, "%c", &caractere);
            fprintf(fp3, "%c", caractere);
        }
        fclose(fp2);
        fclose(fp3);  
    }
    else{
        printf("deu ruim manim\n");
    }



    return 0;
}
