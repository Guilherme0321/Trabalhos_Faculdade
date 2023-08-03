#include <stdio.h>
int mult(i){
return(i*6);
}
int main(void) {
  int q=0;
  printf("Digite uma quantidade: \n");
  scanf("%d",&q);
for(int i=1;i<=q;i++){
  printf("%d ", mult(i));
}
  return 0;
}
