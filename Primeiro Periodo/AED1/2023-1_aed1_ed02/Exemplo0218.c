#include <stdio.h>
#include "io.h"
int main ()
{
    float x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    if (y < x)
        {printf("%f e menor que %f", y, x);}
    if (y == x)
        {printf("%f e igual %d", y, x);}
    if (y > x)
        {printf("%f e maior que %f", y, x);}

    return 0;
}
