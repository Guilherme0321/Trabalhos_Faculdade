#include "io.h"
#include <stdio.h>
int main()
{
   int q=0,c=0;
   float a=0, b=0, x=0;
   IO_println("Digite um valor maior que 0");
   scanf("%f", &a); getchar();
   IO_println("Digite outro valor menor que 1");
   scanf("%f", &b); getchar();
   IO_println("Digite o numero de valores a serem lidos");
   scanf("%d", &q); getchar();
   IO_println("Digite os numeros que quiser testar");
   for(int i = 1; i<=q; i++){
        scanf("%f",&x);
        getchar();
    float teste = (x - (int)x);
    if((a < b && !(a<=teste && teste<=b)))
   {
       ++c;
   }}
    printf("Existem %d numeros com a parte inteira par entre [%d,%d]",c,a,b);
    return 0;
}

