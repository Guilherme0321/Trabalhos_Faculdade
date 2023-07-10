#include <stdio.h>
#include "io.h"
int main ()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    if (!(x%2 == 0))
    {
    printf("%d e impar\n", x);
    }
    if (y%2 == 0){
    printf("%d e par\n", y);
    }
    return 0;
}
