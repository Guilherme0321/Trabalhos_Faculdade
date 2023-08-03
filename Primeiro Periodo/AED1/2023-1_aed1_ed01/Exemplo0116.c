#include <stdio.h>
int main()
{
    float b, h, a, p;
    printf("Digite o valor da altura: ");
    scanf("%f", &h);
    printf("Altura = %.3f\n", h);
    printf("Digite o valor da base: ");
    scanf("%f", &b);
    b = b/6;
    a = (h*b)/2;
    p = b*3;
    printf("Area = %.3f\n", a);
    printf("Perimetro = %.3f", p);
    return 0;
}
