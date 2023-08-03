#include <stdio.h>
int mostrar(int x,int atual){
if(x==0)
    return mostrar(x,atual);
if(atual%2==0){
    printf("%d ",atual);
    mostrar(x-1,atual+2);
}else
{
    mostrar(x,atual+1);
}
}

int main(){
int x=0, r=6;
scanf("%d",&x);
printf("%d",mostrar(x,6));
return 0;
}
