#include <stdio.h>

int main(void) {
  float x = 0,b=0,a=0;
  int q=0, contar=0;
  printf("Digite uma intervalo\nDigite a quantidade de valores a serem testados");
  scanf("%f%f%d",&a,&b,&q);
  for(int i=0;i<q;i++){
      scanf("%f",&x);
  if((a>b && (b<=x && x<=a)) || (b>a && (a<=x && x<=b))){
    contar++;
  }
  }
  printf("%d",contar);
    return 0;
  }

