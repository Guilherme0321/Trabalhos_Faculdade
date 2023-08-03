#include <stdio.h>

int main(){
    int ini = 1, v = 1,v2 = 1,x = 0;
    scanf("%d",&x);
    FILE *a = fopen("RESULTADO08.TXT","wt");
    for(int i = 0;i <= (x+1)*2; i++){
        ini = v + v2;
        v2 = v;
        v = ini;
        if(ini%2==0){
            fprintf(a,"%d\n",ini);
        }
    }fclose(a);
    return 0;
}
