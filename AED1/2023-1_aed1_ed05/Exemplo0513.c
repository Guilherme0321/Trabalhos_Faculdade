#include <stdio.h>
void mult(y) { y -= 9;}
int main(void) {
  printf("Digite um valor inteiro\n");
  int x = 0, y = 81;
  scanf("%d", &x);
  for (int i = 0; i < x; i++) {
    mult(y);
    y-=9;
    if(y%2==1){
      printf("%d ",y);
    }
  }
  return 0;
}
