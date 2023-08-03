#include <stdio.h>
int showl(char* l,int q){
    int r=0;
    if(q<=strlen(l)){
        if(l[q]!=' '){
            printf("%c ",l[q]);
            showl(l,q+1);
    }
    return r;
}}
int main(){
   char l[80];
   int x = strlen(l);
   scanf("%s",l);
   showl(l,0);
}
