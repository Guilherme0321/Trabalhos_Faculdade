#include <stdio.h>
int testarS(char* x,int q){
    int r=0;
    if(x[q]=='\0'){
        return 0;
    }
    if((int)x[q]%2==1){
        return 1 + testarS(x,q+1);
    }else{
        return testarS(x,q+1);}
    }


int main(){
 char x[80];
 int q=0;
 scanf("%s",x);
 printf("%d",testarS(x,q));
 return 0;
}
