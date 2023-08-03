#include <stdio.h>
int mult(int irA, int atual,int z){
    int resul = 1;

    if(atual == 1){
        printf("%d ",resul);}
    if(irA == 0){
        return resul;}
    if(atual < z){
    resul = 6 * atual;
    printf("%d ",resul);
    mult(irA-1,atual+1,z);}
    return resul;
}

int main(){
    int irA=0;
    scanf("%d",&irA);
    int z = irA;
    mult(irA,1,z);
}
