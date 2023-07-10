#include <stdio.h>

void info(int j,int n[],int q,int i){
    for(j; j < q; j++){
        if(i == n[j]){
            printf("%d esta no arranjo na posicao %d do array",i,j);
        }
    }
}
int main(){
    int search = 0,x[12],q = 0;
    scanf("%d",&search);
    FILE *A = fopen("DADOS08.txt","rt");
    while(fscanf(A,"%d",&x[q]) == 1){
        q++;
    }
    info(0,x,q,search);
    fclose(A);
    return 0;
}
