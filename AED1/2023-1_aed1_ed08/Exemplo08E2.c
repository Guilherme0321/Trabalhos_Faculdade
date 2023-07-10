#include <stdio.h>
void palavras(char *x){
    if(('a' <= x[0] && x[0] <= 'z' && x[0]!='c') || 'A' <= x[0] && x[0] <= 'Z' && x[0]!='C'){
    for(int i = 0; i < strlen(x) && i <= 10;i++){
            printf("%c",x[i]);
    }
}
    else{
            printf("\n%s",x);
        }
        printf("\n");
    }

int main(){
    char x[20];
    FILE *l = fopen("Palavras.txt","rt");
    while(fscanf(l,"%s",x)==1){
        palavras(x);
    }
    fclose(l);
    return 0;
}
