#include <stdio.h>
int ler (char* lerp){
  int i=0,c=0;
  for(i=0;i<strlen(lerp);i++){
    if(lerp[i]<'K' && (lerp[i]>='A' && 'Z'>=lerp[i])){
     printf("%c",lerp[i]);
    }
  }
  return (ler);
}
int main() {
  char lerp[80];
  printf("Digite uma palavra:\nCom letras maiusculas ");
  scanf("%s", lerp);
  ler(lerp);
  printf("\n");
  return 0;
}
