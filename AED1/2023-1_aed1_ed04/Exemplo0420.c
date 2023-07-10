#include <stdio.h>
#include "io.h"
void seletor(char* x)
{
    printf("Digite uma cadeia de caracteres: ");
    gets(x);
    int len = strlen(x),count=0;
    int i = 0;
    for(i=0;i<=len;i++)
    {
        if(('A'<=x[i] && x[i]<='Z') || ('a'<=x[i] && x[i]<='z') || ('0'<=x[i] && x[i]<='9')){
            printf("%c",x[i]);
            count++;
        }
    }
    printf("\n%d",count);
}
int main(){
    char x[80];
    seletor(x);
    return 0;
}
