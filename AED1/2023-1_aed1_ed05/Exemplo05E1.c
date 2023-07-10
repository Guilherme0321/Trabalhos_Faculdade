#include <stdio.h>
void show(){
  int q=0, e=0,f=0,y=1,x=0;
  scanf("%d",&q);
  printf("Resultado: %d\n",elev(q,e,f,y,x));
}
int elev(q,e,f,y,x,z){
printf("Para fazer 5! precisa multiplicar:\n");
    e=q;
    printf("%d ",q);
  for(int i=1;i<q;i++){
    y = y*(e-i);
    printf("%d ",e-i);
  }
    f= q * y;
  return(f);
}
int main(void) {
  printf("Calcular o fatorial de: ");
  show();
  return 0;
}
