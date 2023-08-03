#include <stdio.h>
int main(){
    int ler=0, guardar = 0;
    scanf("%d",&ler);
    FILE *dados = fopen("Dados01.txt","wt");
    for(int i = 1;i<=ler;i++){
        guardar = 6*i;
        if(guardar%2==0){
        fprintf(dados,"%d\n",guardar);}
    }
    fclose(dados);
    return 0;
}