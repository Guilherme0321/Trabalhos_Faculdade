#include <stdio.h>
int main()
{
    float l, h, c, v;
    printf("Defina o valor do lado: ");
    scanf("%f", &l);

    printf("Defina o valor do comprimento: ");
    scanf("%f", &c);

    printf("Defina o valor da altura: ");
    scanf("%f", &h);

    v = l*c*h;
    printf("Volume = %.3f", v);
    return 0;
}
