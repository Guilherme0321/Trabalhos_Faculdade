#include <stdio.h>
#include "io.h"
int main ()
{
    float x, y, z;
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);
    if((z<y && (z>x || x>y))||(z>y && (y>x || x>z))){
    printf("\n%f nao esta entre %f e %f", x, y, z);
        }
    else{printf("Digite tres valores diferentes");
    }
    return 0;
}
