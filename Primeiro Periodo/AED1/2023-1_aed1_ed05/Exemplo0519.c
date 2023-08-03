#include <stdio.h>
void show(){
  int q=0, x=0, e=0;
  scanf("%d",&q);

  printf(") e igual a %d\n",elev(q,x,e));
}
int elev(q,x,e){
printf("A soma de (");
  for(int i=6;i<=q+5;i++){
    e = i*i;
    x = x + e;
    printf("%d ",e);
  }return(x);
}
int main(void) {
  printf("Digite uma quantidade ");
  show();
  return 0;
}
