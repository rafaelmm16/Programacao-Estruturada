#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fp;
    char caractere;
    
    //ler até "0"
    fp = fopen("arq.txt", "a");
    while(1){
        scanf("%c", &caractere);
        if (caractere!='0'){
            fprintf(fp, "%c",caractere);
        }
        else{
            fprintf(fp, "%c",'\n');
            break;
        }
    }
    fclose(fp);
    
    //imprimir até "EOF"
    fp = fopen("arq.txt", "r");
    while(!feof(fp)){
        fscanf(fp, "%c", &caractere);
        printf("%c", caractere);
    }   
    fclose(fp);
    
    return 0;
}
