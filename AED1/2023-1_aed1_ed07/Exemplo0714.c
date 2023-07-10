#include <stdio.h>
#include <math.h>
int main(){
    int m =0,q=0;
    scanf("%d",&q);
    FILE *a = fopen("Dados04.txt","wt");
    for (int i = pow(6,q-1); i >= 1; i/=6)
    {
        if(i!=1){
            fprintf(a,"%d\n",i);
        }else{
            fprintf(a,"1");
        }
    }
    fclose(a);
    return 0;
}
