#include <stdio.h>
#include "io.h"
int main ()
{
    int x;
    scanf("%d", &x);
    if (x>10 && x<=25 || x>=15 && x<60)
    {
    printf("%d pertence a este intervalo\n", x);
    }
    else{
    printf("%d n pertence a este intervalo\n", x);
    }
    return 0;
}
