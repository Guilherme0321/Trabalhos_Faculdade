#include <stdio.h>
#include "io.h"
int main ()
{
    float x, y, z;
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);
    if (x!=z && z != y && x != y){
    if (x>z && x<y || x<z && x>y)
        {printf("\n%f esta entre %f e %f", x, y, z);
        }
    }else{printf("Digite tres valores diferentes");
    }
    return 0;
}
