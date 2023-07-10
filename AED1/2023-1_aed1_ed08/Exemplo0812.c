#include <stdio.h>
void salvar(){
    int x[8]={2,0,4,6,5,-5,7,0};
    FILE *a = fopen("DADOS02.txt","wt");
    for(int i = 0; i < 8; i++){
        if(x[i]%2 == 0 && x[i]>=0){
            fprintf(a,"%d\n",x[i]);
        }
    }
    fclose(a);
}

int main(){
    salvar();
    return 0;
}
