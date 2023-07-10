#include <stdio.h>
int espiral(int q,int pro,int l1,int l2){

    if(q==0){
        return pro;}
    pro = l1 + l2;
    l1 = l2;
    l2 = pro;
    if(pro%2==0){
        printf("%d ",pro);
        espiral(q-1,pro,l1,l2);
    }
    else{
        espiral(q,pro,l1,l2);
    }
}
int main(){
    int q=0;
    scanf("%d",&q);
    espiral(q,0,1,1);
    return 0;
}
