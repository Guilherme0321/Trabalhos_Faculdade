#include <stdio.h>
int main(){
    int t = 0;
    do{
    printf("Digite um numero positivo maior que 0: ");
    scanf("%d",&t);
    }while(t==0 || t < 0);
    int n[t];
    for(int i = 0; i < t; i++){
        scanf("%d",&n[i]);
        getchar();
    }
    return 0;
}
