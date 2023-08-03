#include <stdio.h>
int achar(int x[],int p,int q){
    for(int i = 0; i < q; i++){
        if(p == x[i]){
            printf("%d esta na posicao %d array\n",p,i);
        }
    }
    return 0;
}
void atribuir(int x[],int p,int q){
    FILE *a = fopen("DADOS09.txt","rt");
    while(fscanf(a,"%d",&x[q])==1){
        q++;
    }
    achar(x,p,q);
    fclose(a);
}

int main(){
    int x[12], n = 0, q = 0;
    scanf("%d",&n);
    atribuir(x,n,q);
}
