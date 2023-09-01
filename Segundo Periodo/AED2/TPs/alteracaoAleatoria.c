#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int equals(char* x, char* y){
    int len1 = strlen(x), is = 1;
    if(len1 == strlen(y)) {
        for(int i = 0; i < len1; i++){
            if(x[i] != y[i]){
                is = 0;
                i = len1;
            }
        }
    }else{
        is = 0;
    }
    return is;
}

int main(){
    srand(4);
    char entrada[255];
    while(!equals(entrada,"FIM")){
        fgets(entrada,sizeof(entrada),stdin);
        entrada[strlen(entrada)-1] = '\0';
        if(equals(entrada,"FIM")){
            break;
        }
        char x = 'a' + (abs(rand()) % 26);
        char y = 'a' + (abs(rand()) % 26);
        for(int i = 0;i < strlen(entrada); i++){
            if(entrada[i] == x){
                entrada[i] = y;
            }
        }
        printf("%s\n",entrada);
    }
    return 0;
}
