#include <stdio.h>
#include <math.h>
int main()
{
    float r, a;
    printf("Digite o valor do raio: ");
    scanf("%f", &r);
    r = r/2;
    a = r*r*M_PI;
    printf("Area = %.3f", a);
    return 0;
}
