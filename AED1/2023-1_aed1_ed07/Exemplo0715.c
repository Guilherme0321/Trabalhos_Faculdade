#include <stdio.h>
#include <math.h>
int main(){
    int n = 0;
    float x = 0;
    scanf("%d",&n);
    scanf("%f",&x);
    FILE *a = fopen("Dados05.txt","wt");
    for(int i = 0; i< n*2; i+=2){
        if(pow(x,i)!=1){
            fprintf(a,"%.5f\n",1/pow(x,i));
        }else{
            fprintf(a,"1\n");
        }
    }
    fclose(a);
    return 0;
}