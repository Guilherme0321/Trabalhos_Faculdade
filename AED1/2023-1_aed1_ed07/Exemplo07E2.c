#include <stdio.h>

int main(){
    char q;
    int x = 0;
    FILE *a = fopen("RESULTADO12.TXT","rt");
    while(fscanf(a,"%c",&q) == 1){
        if(q=='c'||q=='C'){
            x++;
        }
    } printf("%d",x);
    fclose(a); return 0;
}
