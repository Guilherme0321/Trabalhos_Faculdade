#include <stdio.h>
#include "io.h"
int main ()
{
    int x;
    scanf("%d", &x);
    if (x%2 == 0)
    {
    printf("%d e um numero par\n", x);
    }
    else{
    printf("%d e um numero impar\n", x);
    }
    return 0;
}
