#include <stdio.h>
#include <math.h>
int main()
{
    float r, v;
    printf("Digite o valor do raio: ");
    scanf("%f", &r);
    r = (r)*3/5;
    v = r*r*r*M_PI*4/3;
    printf("Volume = %.3f", v);
    return 0;
}
