/*CABEÇALHO
Desafio: Fazer uma programa para eleições
Autor:Rafael Merlo Mendes
Versão:1.0
Data:26/05/17 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int cand1=0, cand2=0, cand3=0, cand4=0, nulo=0, total=-1,voto;
    printf("********************Eleições 2018********************\n");
    do{
        printf("Escolha seu candidato:");
        scanf("%d", &voto);
        if (voto==1){
            cand1++;}
            else {
                if (voto==2){
                    cand2++;}

                 else{
                    if(voto==3){
                        cand3++;}

                     else{
                        if(voto==4){
                            cand4++;}

                         else{
                            if(voto==5){
                                nulo++;}
                            }
                        }
                    }
            }

    total++;
    }while (voto!=0);
    printf("*******RESULTADO*******\n");
    printf("\ncand1  %d\n", cand1);
    printf("\ncand2  %d\n", cand2);
    printf("\ncand3  %d\n", cand3);
    printf("\ncand4  %d\n", cand4);
    printf("\nnulo   %d\n", nulo);
    printf("\ntotal  %d\n", total);

    return 0;
}
