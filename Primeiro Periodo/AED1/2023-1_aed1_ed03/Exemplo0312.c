#include "io.h"
int main()
{
    char y[80];
    int i;
    printf("Digite uma palavra ");
    scanf("%s", y); getchar();
     for (i = 0; i < strlen(y); i++){
         char letra = y[i];
        if ('A'<=letra && letra<='Z')
        {
            printf("%c",letra);
        }
     }
    IO_println("");
    return 0;
}

