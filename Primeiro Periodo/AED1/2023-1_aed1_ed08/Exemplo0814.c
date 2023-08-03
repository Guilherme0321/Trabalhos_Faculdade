#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int acharmenor(int n[], int tamanho) {
    int menor = n[0], x =0;
    for(int j = 0; j < tamanho; j++) {
        if (n[j] <= menor) {
            x = n[j];
            printf("%d ",n[j]);
        }
    }
    return x;
}

int main(){
    FILE *a = fopen("DADOS04.txt", "rt");
    int x[5];
    int i = 0;
    while(fscanf(a, "%d", &x[i]) == 1 && i < 5) {
        i++;
    }
    fclose(a);
    printf("Valores lidos do arquivo:\n");
    for(int j = 0; j < i; j++) {
        printf("%d ", x[j]);
    }
    printf("\n");
    int valor = acharmenor(x, i);
    printf("Menor valor encontrado: %d\n", valor);
    return 0;
}
