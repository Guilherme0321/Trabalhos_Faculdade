#include <stdio.h>
int div(int q){
int resul = 0;
if(q>0){
    if(q==1){
        printf("1 ");
        return resul;
    }else{
    resul = 6 * (q-1);
    printf("1/%d ",resul);
    div(q-1);
    }

}return resul;}


int main(){
    int q = 0;
    scanf("%d",&q);
    div(q);
    return 0;
}
