#include "io.h"
int main()
{
    char y = '0';
    printf("Digite uma palvra");
    scanf("%c", &y); getchar();
    if ('A'<= y && y <= 'Z')
    {
        printf("%c\n", y);
    }
    return 0;
}

