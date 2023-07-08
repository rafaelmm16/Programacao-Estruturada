#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp; //ponteiro do tipo arquivo
    int digitado;//valor a ser entrado
    
    fp = fopen("nada.txt", "rb");
    if(fp != NULL){
        fread(&digitado, sizeof(int),1,fp);
        fclose(fp);
        printf("Você digitou %d\n", digitado);
    }
    else{
        printf("Digite um número: ");
        scanf("%d", &digitado);
        fp = fopen("nada.txt", "wb");
        if(fp != NULL){
            fwrite(&digitado, sizeof(int),1,fp);
            fclose(fp);
        }   
        else{
            printf("Deu ruim!\n");
        }
    }
    return 0;
}
