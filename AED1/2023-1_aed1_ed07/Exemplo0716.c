#include <stdio.h>
#include <math.h>
int main(){
    int n = 0;
    float q = 0, s = 0;
    scanf("%d",&n);
    FILE *a = fopen("Dados05.txt","rt");
    FILE *b = fopen("RESULTADO06.TXT","wt");
    while (!feof(a) && fscanf(a,"%f",&q)!=0)
    {
        s += q;
    }
    fprintf(b,"%f",s);
    fclose(b);
    fclose(a);
    return 0;
}