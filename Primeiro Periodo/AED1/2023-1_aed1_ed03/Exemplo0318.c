#include "io.h"
#include <stdio.h>
int main()
{
   int a=0,b=0,q=0,x=0,c=0;
   IO_println("Digite um valor inteiro");
   scanf("%d", &a); getchar();
   IO_println("Digite outro valor inteiro");
   scanf("%d", &b); getchar();
   IO_println("Digite o numero de valores a serem lidos");
   scanf("%d", &q); getchar();
   for(int i = 1; i<=q; i++){
        scanf("%d",&x);
        getchar();
    if((a > b && (b<=x && x<=a) && x%2==0 && x%5!=0) || (b>a && (a<=x && x<=b) && x%2==0 && x%5!=0))
   {
       ++c;
   }}
    printf("Existem %d numeros multiplos de 2 que nao sao multiplos de 5 entre %d e %d",c,a,b);
    return 0;
}

