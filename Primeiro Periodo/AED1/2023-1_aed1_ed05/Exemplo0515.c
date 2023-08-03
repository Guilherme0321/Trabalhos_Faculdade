#include <stdio.h>
#include <math.h>
int elevar(x,i){
  return(pow(x,i));
}
int main(void) {
  int q=0;
  int x = 0;
  int y= 0;
  printf("Digite um valor para quantidade: ");
  scanf("%d",&q);
  printf("Digite um valor para começar: ");
  scanf("%d", &x);
  for(int i=1;i<=q;i++){
    printf("1/%d ",elevar(x,i));
  }
  return 0;
}
