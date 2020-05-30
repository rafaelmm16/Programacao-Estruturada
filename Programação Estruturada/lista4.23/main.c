#include <stdio.h>
#include <stdlib.h>

int main()
{
    float chico=1.5, ze=1.1, cont=1;
    while(ze<=chico){
            printf("%.1f\t",cont);
            ze+=0.03;
            chico+=0.02;
            cont++;}

    return 0;
}
