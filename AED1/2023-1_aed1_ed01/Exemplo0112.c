#include <stdio.h>

int main ()
{
    int x, a, p;
    printf("Lado= ");
    scanf("%d", &x);
    a = (x*x)/2;
    p = (x*4)/2;
    printf("Area = %d\n", a);
    printf("Perimetro = %d", p);
    return 0;
}
