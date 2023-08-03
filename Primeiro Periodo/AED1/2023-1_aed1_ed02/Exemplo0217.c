#include <stdio.h>
#include "io.h"
int main ()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    if ((x%2 == 0) && (x < 0))
    {
    printf("%d e par\n %d  menor e negativo", x, x);
    }
    if ((!(y%2 == 0)) && (y>0)) {
    printf("%d e impar\n %d e positivo", y, y);
    }
    return 0;
}
