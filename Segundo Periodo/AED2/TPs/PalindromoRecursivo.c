#include <stdio.h>
#include <string.h>

int comp(char * x, char * y,int i){
    if(i == strlen(x)){
        return 1;
    }
    if(x[i] != y[i]){
        return 0;
    }
    return comp(x,y,i+1);
}

int strcomparar(char * x, char * y){
    if(strlen(x) != strlen(y)){
        return 0;
    }else{
        return comp(x,y,0);
    }
}

int isPalindromo(char * x, int i){
    if((int)(strlen(x)/2) == i){
        return 1;
    }
    if(x[i] != x[strlen(x)-i-1]){
        return 0;
    }
    return isPalindromo(x,i+1);
}

void loop(){
    char x[255] = "";

    fgets(x,sizeof(x),stdin);
    x[strlen(x)-1] = '\0';
    if(!strcomparar(x,"FIM")){
        if(strcomparar(x,"FIM")){
            return;
        }
        if(isPalindromo(x,0)){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
        loop();
    }
}

int main(){
    loop();
    return 0;
}