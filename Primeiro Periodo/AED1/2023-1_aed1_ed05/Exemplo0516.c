#include <stdio.h>
void show(y,x,z){
  printf(") é igual à %d\n",soma(y,x,z));
}
int soma(y,x,z){
scanf("%d",&y);
getchar();
  printf("A soma de (");
  for(int i=1;i<=y;i++){
    if((i*6)%5!=0){
    x= 6*i;
    printf("%d ",x);
    z=z+x;}
  }
  return(z);
}
int main(void) {
  printf("Digite um valor par \n");
  int x=0,y=0,z=0;

  show(y,x,z);
  return 0;
}
