#include <stdio.h>
int mult12(i){
return(i*12);
}


int main(void) {
int q =0;
int m=0;
  printf("Digite a quantidade de valores a serem mostrados: \n");
scanf("%d", &q);
  for(int i=1;i<=q;i++){
    printf("%d ", mult12(i));
  }
  return 0;
}
