#include <stdio.h>
int soma(int q){

    int resul = 0;
    if(q>0){
    resul = 6*q + soma(q-1);
    } return resul;
}
int main(){
    int q = 0;
    scanf("%d",&q);
    if(q<0){
        q*=-1;
    }
    printf("%d",soma(q));
    return 0;
}
