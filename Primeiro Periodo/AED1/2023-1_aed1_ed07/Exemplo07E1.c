#include <stdio.h>

int main(){
    int q = 0;
    scanf("%d",&q);
    FILE *a = fopen("RESULTADO11.TXT","wt");
    for(int i = q; i>1 ;i--){
        if(q%i==0){
            fprintf(a,"%d\n",i);
        }
    }fclose(a); return 0;
}
