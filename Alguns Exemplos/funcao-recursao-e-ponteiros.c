#include<stdio.h>
#include<stdlib.h>

//prototipando a função
void contador(int valor);
int maisum(int num);
int *soma(int *kleyton);

//main
int main(){
    int i;
    int *ptr;//ponteiro de inteiro
    
    //contador(10);
    
    i = maisum(1);
    printf("Primeira função: %d\n", i);
        
    ptr = soma(ptr); 
    printf("Valor do cont. do ponteiro: %d\n", *ptr);

    return 0;
}

//funções
void contador(int valor){
    if(valor<=0){
        printf("%d\n", valor);
    }
    else{
        printf("%d\n", valor);
        valor--;
        return contador(valor);  
    }
}

int maisum(int num){
    return num+=1;
}

int *soma(int *kleyton){
    int final=100;//cria-se uma variável qualquer e atribui-se um valor qualquer
    
    kleyton = &final;//a variável passada recebe o ponteiro da variável criada
    
    return kleyton;//retorna-se a variável dada com seu novo endereço
}
