#include <stdio.h>
int qM(char* x,int q){
    int c = 0;
    if(x[q]!='\0'){
     if('A'<=x[q] && x[q]<= 'Z'){
        c = 1 + qM(x,q+1);
    } else{
        return qM(x,q+1);
    }} else{
        return 0;
    }
}
int main(){
    char x[80];
    scanf("%s",x);
    printf("%d",qM(x,0));
}
