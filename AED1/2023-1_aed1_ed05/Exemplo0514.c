#include <stdio.h>
int mult(i){
return(i*6);
}
int main(void) {
  int q=0;
printf("Digite a quantidade de multiplos de 6 que quer mostrar: ");
  scanf("%d",&q);
  for(int i=1;i<q;i++){
  printf("1/%d ",mult(i));
  }
    return 0;
  }

