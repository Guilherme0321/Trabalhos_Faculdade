#include <stdio.h>
float Calmedia(int n[], int q){
    float soma = 0,r = 0;
    for(int i = 0; i < q; i++){
        soma += n[i];
    }
    return soma/(q-1);
}

void indo(int x[], int q){
    FILE *a = fopen("DADOS06.txt","rt");
    while(fscanf(a,"%d",&x[q])==1){
        q++;
    }
    printf("%.2f",Calmedia(x,q));
    fclose(a);
}

int main(){
    int q = 0;
    int x[5];
    indo(x,q);
    return 0;
}
