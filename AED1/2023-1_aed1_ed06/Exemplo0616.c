#include <stdio.h>
int soma(int q){
    int r = 0;
    if(q!=0){
        r = 6*q + soma(q-1);
    } return r;
}
int main(){
    int q =0;
    scanf("%d",&q);
    printf("1/%d",soma(q));
}
