#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int equals1(char* x, char* y,int i){
    if(strlen(x) == i){
        return 1;
    }
    if(x[i] != y[i]){
        return 0;
    }
    return equals1(x,y,i+1);
}

int equals(char *x, char *y){
    if(strlen(x) != strlen(y)){
        return 0;
    }else{
        equals1(x,y,0);
    }
}

void change(char *x, int i,char a, char b){
    if(i == strlen(x)){
        return;
    }
    if(x[i] == a){
        x[i] = b;
    }
    change(x,i+1,a,b);
}

void loop(){
    char entrada[255];
    srand(4);
    fgets(entrada,sizeof(entrada),stdin);
    entrada[strlen(entrada)-1] = '\0';

    if(equals(entrada,"FIM")){
        return;
    }
    char x = 'a' + (abs(rand()) % 26);
    char y = 'a' + (abs(rand()) % 26);
    change(entrada,0,y,x);
    printf("%s\n",entrada);
    loop();
}

int main(){
    loop();
    return 0;
}
