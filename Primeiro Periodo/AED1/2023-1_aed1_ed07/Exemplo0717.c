#include <stdio.h>

int main(){
    int q = 0;
    float r = 0;
    float v = 0;
    scanf("%d",&q);
    FILE *a = fopen("Dados04.txt","rt");
    FILE *b = fopen("RESULTADO07.TXT","wt");
    while (fscanf(a,"%f",&v)==1 && q>0) {
        r += 1/v;
        fprintf(b,"%f\n",r);
        q--;
    }
    fclose(a);
    fclose(b);
    return 0;
}
