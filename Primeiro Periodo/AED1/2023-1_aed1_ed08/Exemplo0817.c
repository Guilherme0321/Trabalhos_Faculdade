#include <stdio.h>

int teste(int n[], int q){
    int qc = 0;
    for(int i = 0; i < q; i++){
        if(n[i]<n[i+1]){
            qc++;
        }
    }
    if(qc == q){
        return 1;
    }else{
        return 0;
    }
}

void info(int n[],int q){
    FILE *a = fopen("DADOS07.txt","rt");
    while(fscanf(a,"%d",&n[q])==1){
        q++;
    }
    if(teste(n,q)==1){
        printf("Esta ordenado em ordem crescente!");
    }else{
        printf("Nao esta ordenado em ordem crescente!");
    }
    fclose(a);
}
int main(){
    int q = 0;
    int x[5];
    info(x,q);
    return 0;
}
