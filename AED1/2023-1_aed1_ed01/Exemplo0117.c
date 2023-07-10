#include <stdio.h>
int main()
{
    float l, v;
    printf("Defina o valor do lado: ");
    scanf("%f", &l);
    l = 4*l;
    v = l*l*l;
    printf("Volume = %.3f", v);
    return 0;
}
