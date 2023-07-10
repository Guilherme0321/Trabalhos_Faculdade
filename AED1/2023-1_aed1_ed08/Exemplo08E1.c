#include <stdio.h>
void mostrar(int x[],int d){
    FILE *a = fopen("DIVISORES.TXT","wt");
    for(int i = 0;i<d;i++){
        printf("%d ",x[i]);
        fprintf(a,"%d\n",x[i]);
    }
    fclose(a);
}

void divisores(int x[],int n){
    int d =0;
    for(int i = 1;i<=n;i++){
            if(n%i==0){
                x[d]= i;
                d++;
            }
        }
        mostrar(x,d);
}


int main(){
    int n = 0;
    scanf("%d",&n);
    int x[n];
    divisores(x,n);
    return 0;
}
