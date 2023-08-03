#include <stdio.h>
#include "io.h"
void seletor(char* x)
{
    printf("Digite uma cadeia de caracteres: ");
    scanf("%s",x);
    int len = strlen(x);
    int i = 0;
    for(i=0;i<=len;i++)
    {
        if(('A'<=x[i] && x[i]<='Z') || ('a'<=x[i] && x[i]<='z') || ('0'<=x[i] && x[i]<='9')){
            printf("%c",x[i]);
        }
    }
}
int main(){
    char x[80];
    seletor(x);
    return 0;
}
