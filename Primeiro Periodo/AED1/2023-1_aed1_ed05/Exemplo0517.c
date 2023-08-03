#include <stdio.h>
void show(q,z,y){
  printf(") é igual a 1/%d\n",soma(q,z,y));
}
int soma(q,z,y){
  scanf("%d",&q);
  printf("\nA soma de (");
  for(int i=1;i<=q;i++){
    if((6*i)%5!=0){
      z= i*6;
      printf("1/%d ", z);
      y= z + y;

    }
  }return(y);
}
int main(void) {
  int q=0,z=0,y=0;
  printf("Digite o valor da quantidade ");
  show(q,z,y);
  return 0;
}
