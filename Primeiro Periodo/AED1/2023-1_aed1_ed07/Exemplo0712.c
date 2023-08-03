#include <stdio.h>
int main(){
    int quant = 0;
    scanf("%d",&quant);
    FILE *a = fopen("Dados02.txt","wt");
    for (int i = 10*quant+5; i >= 15; i-=5)
    {
        if(i%2!=0){
            fprintf(a,"%d\n",i);
        }
    }
    fclose(a);
    return 0;
}