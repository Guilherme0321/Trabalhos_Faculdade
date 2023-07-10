#include <stdio.h>
#include "io.h"

void L_impar(char * x){
    scanf("%s",x);
    int len = strlen(x),contar=0;
    for(int i=0;i<=len;i++){
        if((int)x[i]%2==0){
            printf("%c",x[i]);
        }
    }
    }

int main() {
    char x[20];
    L_impar(x);
    return 0;
}
