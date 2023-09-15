#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tirarzeros(char *x) {
  int len = strlen(x);
  int naoNUlos = 0;
  int pos = 0;
  for (int i = 0; i < len; i++) {
    if (x[i] == '.') {
      pos = i;
    }
  }
  while (len > pos) {
    if (x[len - 1] != '0' && x[len - 1] != '.') {
      naoNUlos++;
    }
    if (naoNUlos == 0) {
      x[len - 1] = '\0';
    }
    if (x[len - 1] == '.' && naoNUlos == 0) {
      x[len - 1] = '\0';
      len = 0;
    }
    if (x[len - 1] == '.') {
      len = 0;
    }
    len--;
  }
}

void printar(char *x) {
  int len = strlen(x);
  if (x[len - 2] == '.' && x[len - 1] == '0') {
    len -= 2;
  }
  for (int i = 0; i < len; i++) {
    printf("%c", x[i]);
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  FILE *file = fopen("numbers.txt", "w");

  int i = 0;
  float nums;
  char texto[100];

  while (i < n) {
    scanf("%f", &nums);
    fprintf(file, "%.3f\n", nums);
    i++;
  }

  fclose(file);

  file = fopen("numbers.txt", "r");

  fseek(file, 0, SEEK_END);
  long len = ftell(file);
  fseek(file, 0, SEEK_SET);

  char letra;
  memset(texto, 0, sizeof(texto));
  long counter = 1;

  while (counter <= len) {
    fseek(file, -counter - 1, SEEK_END);
    letra = fgetc(file);

    if (letra == '\n' || counter == len) {
      tirarzeros(texto);
      printar(texto);
      memset(texto, 0, sizeof(texto));
    } else {
      if ((letra >= '0' && letra <= '9') || letra == '.') {
        memmove(texto + 1, texto, strlen(texto) + 1);
        texto[0] = letra;
      }
    }
    counter++;
  }

  fclose(file);

  return 0;
}
