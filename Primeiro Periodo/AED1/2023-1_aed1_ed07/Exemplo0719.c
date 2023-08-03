#include <stdio.h>

int main(){
    int q = 0;
    char x[80];
    gets(x);
    FILE *a = fopen("RESULTADO09.TXT","wt");
    fprintf(a,"%s\n\n",x);
    for(int i = 0;i<strlen(x); i++){
        char z = x[i];
        if(z != ' '){
            fprintf(a,"%c",z);
        }
            if('a'<=z && z<='z'){
                q++;
            }
            if((z==' ' || x[i+1]=='\0')&& q>0){
                fprintf(a," %d\n",q);
                q = 0;
            }
        }
    fclose(a);
    return 0;
}
