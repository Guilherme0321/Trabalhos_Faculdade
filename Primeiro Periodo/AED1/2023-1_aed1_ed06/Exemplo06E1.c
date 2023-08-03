#include <stdio.h>
#include <math.h>
int calcular(int n,int x,int v,int p){
    int r = 0,s=0;
    if(n!=0){
        r = pow(x,v);
        printf("%d ",r);
        return calcular(n-1,x,v+2,p+=r);
    }
    return p;
}
int main(){
    int n = 0, x = 0,v=1;
    scanf("%d %d",&n,&x);
    printf("%d ",v);
    int s = 1+ calcular(n,x,v,0);
    printf("=%d",s);
    return 0;
}
