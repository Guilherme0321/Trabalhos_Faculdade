#include <stdio.h>
int main()
{
    float b, h, a;
    printf("Digite o valor da altura: ");
    scanf("%f", &h);
    printf("Digite o valor da base: ");
    scanf("%f", &b);
    a = (2*h*b)/2;
    printf("Area = %.2f\n", a);
    return 0;
}
