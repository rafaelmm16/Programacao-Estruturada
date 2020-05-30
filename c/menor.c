#include<stdio.h>
#include<stdlib.h>

int m(int *vet, int men, int i);

int main(){
  int v[100], i=0;

  for(i=0;i<100;i++){
    v[i]=i;
  }
  i=-1;
  i = m(v, 0,0);
  printf("mneor %d:", i);
  return 0;
}

int m(int *vet, int men, int i){
  if(i>99){
    men = vet[0];
    return men;
  }
  if(i>=100){
    return men;
  }
  else{
    if(vet[i]<men){
      men=vet[i];
    }
    return m(vet, men, i+=1);
  }
}