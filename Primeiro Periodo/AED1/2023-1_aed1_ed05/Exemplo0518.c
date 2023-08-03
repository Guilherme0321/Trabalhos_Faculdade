#include <stdio.h>
void show(q,x,y){
printf("Digite uma quantidade ");
scanf("%d",&q);
printf(") e igual a %d\n", arit(q,x,y));
}
int arit(q,x,y){
  printf("A soma de (");
  for(int i=0;i<q;i++){
    x=x + i;
    printf("%d ",x);
    y = y+x;
  } return(y);
}
int main(void) {
  int q=0, x=6, y=0;
  show(q,x,y);
  return 0;
}
