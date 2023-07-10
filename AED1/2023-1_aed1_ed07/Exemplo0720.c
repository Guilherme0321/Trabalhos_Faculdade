#include <stdio.h>

int main(){
    int q = 0;
    char x[80];
    gets(x);
    FILE *a = fopen("RESULTADO10.TXT","wt");
    for(int i = 0; i< strlen(x);i++){
        if(x[i]!=' '){
            fprintf(a,"%c%",x[i]);
        }if(x[i]==' ' || x[i+1]=='\0'){
            fprintf(a," %d\n",q);
            q=0;
        }
        if(((int)x[i]-'0'>=3)&& '0'<=x[i]&& x[i]<='9'){
            q++;
        }
    }fclose(a); return 0;
}
