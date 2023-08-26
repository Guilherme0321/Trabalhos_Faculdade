#include <stdio.h>
#include <string.h>
int isPalindromo(char* entrada){
    int len = strlen(entrada);
    for(int i = 0; i < len; i++){
        if(entrada[i] != entrada[len-1-i]){
            return 0;
        }
    }
    return 1;
}

int isEquals(char* x, char* y){
    int len = strlen(x), len2 = strlen(y);
    if(len == len2){
        for(int i = 0; i < len; i ++){
            if(x[i] != y[i]){
                return 0;
            }
        }
    }else{
        return 0;
    }
    return 1;
}

int main(){
    char entrada[255] = {};
    while(!isEquals(entrada,"FIM")){
        fgets(entrada,sizeof(entrada),stdin);
        entrada[strlen(entrada)-1] = '\0';
        getchar();
        if(isEquals(entrada,"FIM")){
            break;
        }
        if(isPalindromo(entrada)){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
    }
    return 0;
}
