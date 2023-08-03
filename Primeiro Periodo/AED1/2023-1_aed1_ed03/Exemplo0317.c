#include "io.h"
#include <stdio.h>
int main()
{
    int a=0, b=0, q=0, x,c=0;
    printf("Digite valores inteiros ");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Quantidade de valores intteiros que serao testados ");
    scanf("%d", &q);
    for (int i =1; i <= q; i++)
    {
        scanf("%d", &x);
        if((a > b && (b<=x && x<= a) && x%3==0) || (b>a && (a<=x && x<=b) && x%3==0)){
                c++;
        }
    }
    printf("Existem %d multiplos de 3 e esta entre %d e %d",c,a,b);
    return 0;
}

