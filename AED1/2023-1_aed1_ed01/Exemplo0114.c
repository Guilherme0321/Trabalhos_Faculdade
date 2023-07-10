#include <stdio.h>
int main()
{
    int h, l, a, p;
    printf("Digite um valor inteiro: ");
    scanf("%d", &h);
    printf("Digite outro valor inteiro: ");
    scanf("%d", &l);
    a = (h*l)/4;
    p = (h*2)/4 + (l*2)/4;
    printf("Area = %d\n", a);
    printf("Perimetro = %d", p);
    return 0;
}
