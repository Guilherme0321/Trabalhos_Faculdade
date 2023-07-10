#include <stdio.h>
#include "io.h"
void lerChar(char* x){
  scanf("%s",x);
  int y = strlen(x);

  for(int i=0;i <= y;i++){
    if((x[i]< 'k' && ('a'<= x[i] && x[i]<='z')) || ('K'>x[i] && 'A'<=x[i] && x[i]<='Z'))
    {
      printf("%c",x[i]);}
}IO_println("");}

int main() {
  char x[20];
  lerChar(x);
  return 0;
}
