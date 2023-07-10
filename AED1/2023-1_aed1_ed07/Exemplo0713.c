#include <stdio.h>
#include <math.h>
int main(){
    int quant = 0, expo=0;
    scanf("%d",&quant);
    FILE *a = fopen("Dados03.txt","wt");
    for(int i = 0; i<=quant;i++){
        expo = pow(6,i);
        fprintf(a,"%d\n",expo);
    }
    fclose(a);
    return 0;
}