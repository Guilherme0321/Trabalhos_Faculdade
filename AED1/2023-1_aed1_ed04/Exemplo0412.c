#include <stdio.h>

int main() {
  char x[80];
  printf("Digite uma palvra:\nCom letras maiusculas ");
  scanf("%s",x);
  for(int i=0; i <= strlen(x); i++){
    if(x[i]< 'K')
    {
      printf("%c",x[i]);
    }
  }
  printf("\n");
  return 0;
}
