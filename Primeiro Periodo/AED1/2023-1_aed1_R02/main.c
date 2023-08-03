#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int estaEmOrdemDecrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return 0; 
        }
    }
    return 1; 
}

void ordenarEmOrdemDecrescente(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    }


void verificarOrdenacaoDecrescente() {
    
    FILE *arquivo = fopen("DADOS1.TXT", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo DADOS1.TXT.\n");
        return;
    }

   
    int quantidade;
    fscanf(arquivo, "%d", &quantidade);

    
    int arr[quantidade];
    for (int i = 0; i < quantidade; i++) {
        fscanf(arquivo, "%d", &arr[i]);
    }

    fclose(arquivo);
   
    if (!estaEmOrdemDecrescente(arr, quantidade)) {
                ordenarEmOrdemDecrescente(arr, quantidade);
        
        arquivo = fopen("DECRESCENTE.TXT", "w");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo DECRESCENTE.TXT.\n");
            return;
        }

        
        fprintf(arquivo, "%d\n", quantidade);

        
        for (int i = 0; i < quantidade; i++) {
            fprintf(arquivo, "%d ", arr[i]);
        }

        fclose(arquivo);

        printf("Valores ordenados em ordem decrescente e gravados no arquivo DECRESCENTE.TXT.\n");
    } else {
        printf("Os valores já estão em ordem decrescente.\n");
    }
}
 void exercicio1 (){
   verificarOrdenacaoDecrescente();
 }

void inverterArray(int arr[], int tamanho) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio < fim) {
        int temp = arr[inicio];
        arr[inicio] = arr[fim];
        arr[fim] = temp;

        inicio++;
        fim--;
    }
}

void inverterOrdemElementos() {
    FILE *arquivo = fopen("DECRESCENTE.TXT", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo DECRESCENTE.TXT.\n");
        return;
    }

    int quantidade;
    fscanf(arquivo, "%d", &quantidade);

    int arr[quantidade];
    for (int i = 0; i < quantidade; i++) {
        fscanf(arquivo, "%d", &arr[i]);
    }

    fclose(arquivo);

    inverterArray(arr, quantidade);

    arquivo = fopen("INVERTIDOS.TXT", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo INVERTIDOS.TXT.\n");
        return;
    }

    fprintf(arquivo, "%d\n", quantidade);

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "%d ", arr[i]);
    }

    fclose(arquivo);

    printf("Valores invertidos e gravados no arquivo INVERTIDOS.TXT.\n");
}

void exercicio2(){
  inverterOrdemElementos();
}



int encontrarSegundoMaior(int arr[], int tamanho) {
    int primeiroMaior = arr[0];
    int segundoMaior = arr[0];

    for (int i = 1; i < tamanho; i++) {
        if (arr[i] > primeiroMaior) {
            segundoMaior = primeiroMaior;
            primeiroMaior = arr[i];
        } else if (arr[i] > segundoMaior && arr[i] < primeiroMaior) {
            segundoMaior = arr[i];
        }
    }

    return segundoMaior;
}

int r03() {
 
    FILE *arquivo = fopen("DADOS1.TXT", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo DADOS1.TXT.\n");
        return 1;
    }

    
    int quantidade;
    fscanf(arquivo, "%d", &quantidade);

    
    int arr[quantidade];
    for (int i = 0; i < quantidade; i++) {
        fscanf(arquivo, "%d", &arr[i]);
    }

    fclose(arquivo);

   
    int segundoMaior = encontrarSegundoMaior(arr, quantidade);

    
    printf("O segundo maior valor no array é: %d\n", segundoMaior);

    return 0;
}


void exercicio3 (){
  r03();
}




int estaNoArray(int arr[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == elemento) {
            return 1;
        }
    }
    return 0; 
}

void filtrarElementosComuns(int arr1[], int tamanho1, int arr2[], int tamanho2, int resultado[], int *tamanhoResultado) {
    *tamanhoResultado = 0;

    for (int i = 0; i < tamanho1; i++) {
        int elemento = arr1[i];

        
        if (estaNoArray(arr2, tamanho2, elemento) && elemento != 0 && !estaNoArray(resultado, *tamanhoResultado, elemento)) {
            resultado[*tamanhoResultado] = elemento;
            (*tamanhoResultado)++;
        }
    }
}

int r04() {
    FILE *arquivo1 = fopen("DADOS1.TXT", "r");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir o arquivo DADOS1.TXT.\n");
        return 1;
    }

    int tamanho1;
    fscanf(arquivo1, "%d", &tamanho1);

    int arr1[tamanho1];
    for (int i = 0; i < tamanho1; i++) {
        fscanf(arquivo1, "%d", &arr1[i]);
    }

    fclose(arquivo1);

    FILE *arquivo2 = fopen("DADOS2.TXT", "r");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo DADOS2.TXT.\n");
        return 1;
    }

    int tamanho2;
    fscanf(arquivo2, "%d", &tamanho2);

    int arr2[tamanho2];
    for (int i = 0; i < tamanho2; i++) {
        fscanf(arquivo2, "%d", &arr2[i]);
    }

    fclose(arquivo2);

    int resultado[tamanho1 + tamanho2];
    int tamanhoResultado;

    filtrarElementosComuns(arr1, tamanho1, arr2, tamanho2, resultado, &tamanhoResultado);

    FILE *arquivoResultado = fopen("FILTRADOS.TXT", "w");
    if (arquivoResultado == NULL) {
        printf("Erro ao abrir o arquivo FILTRADOS.TXT.\n");
        return 1;
    }

    fprintf(arquivoResultado, "%d\n", tamanhoResultado);

    for (int i = 0; i < tamanhoResultado; i++) {
        fprintf(arquivoResultado, "%d ", resultado[i]);
    }

    fclose(arquivoResultado);

    printf("Elementos comuns filtrados gravados no arquivo FILTRADOS.TXT.\n");

    return 0;
}
void exercicio4(){
  r04();
}

int binarioParaDecimal(char *binario) {
    int tamanho = strlen(binario);
    int decimal = 0;

    for (int i = 0; i < tamanho; i++) {
        if (binario[i] == '1') {
            decimal += pow(2, tamanho - i - 1);
        }
    }

    return decimal;
}

int r05() {
    FILE *arquivo = fopen("BINARIOS1.TXT", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo BINARIOS1.TXT.\n");
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    int tamanhoArquivo = ftell(arquivo);
    rewind(arquivo);

    char *binarios = (char *)malloc((tamanhoArquivo + 1) * sizeof(char));

    fscanf(arquivo, "%s", binarios);

    fclose(arquivo);

    int tamanho = strlen(binarios);
    int *arr = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        if (binarios[i] == '0' || binarios[i] == '1') {
            arr[i] = binarios[i] - '0'; 
        }
    }

    
    printf("Valores decimais:\n");
    for (int i = 0; i < tamanho; i++) {
        int decimal = binarioParaDecimal(&binarios[i]);
        printf("%d ", decimal);
    }
    printf("\n");

    free(binarios);
    free(arr);

    return 0;
}

void exercicio5(){
  r05();
}

void montarMatriz(int N, int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                matriz[i][j] = i + 1; 
            } else if (j == i + 1) {
                matriz[i][j] = j; 
            } else if (j == i - 1) {
                matriz[i][j] = i; 
            } else {
                matriz[i][j] = 0; 
            }
        }
    }
}

void mostrarMatriz(int N, int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void gravarMatriz(int N, int matriz[N][N]) {
    FILE *arquivo = fopen("MATRIZ2.TXT", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo MATRIZ2.TXT.\n");
        return;
    }

    fprintf(arquivo, "%d\n", N); 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

int r06() {
    int N;

    
    printf("Digite a quantidade de linhas e colunas da matriz: ");
    scanf("%d", &N);

    int matriz[N][N];

    montarMatriz(N, matriz);

    printf("Matriz:\n");
    mostrarMatriz(N, matriz);

    gravarMatriz(N, matriz);

    printf("Matriz gravada no arquivo MATRIZ2.TXT.\n");

    return 0;
}
void exercicio6(){
  r06();
}

void MontarMatriz(int N, int matriz[N][N]) {
    int valor = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                matriz[i][j] = valor; 
            } else if (j == i + 1) {
                matriz[i][j] = valor - 1; 
            } else if (j == i - 1) {
                matriz[i][j] = valor - 1; 
            } else {
                matriz[i][j] = 0; 
            }
        }
        valor--;
    }
}

void MostrarMatriz(int N, int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


void GravarMatriz(int N, int matriz[N][N]) {
    FILE *arquivo = fopen("MATRIZ2.TXT", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo MATRIZ2.TXT.\n");
        return;
    }

    fprintf(arquivo, "%d\n", N); 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

int r07() {
    int N;

    FILE *A = fopen("MATRIZ1.TXT","r");
    fscanf(A,"%d", &N);
  fclose(A);
    int matriz[N][N];

    MontarMatriz(N, matriz);

    printf("Matriz:\n");
    MostrarMatriz(N, matriz);

    GravarMatriz(N, matriz);

    printf("Matriz gravada no arquivo MATRIZ2.TXT.\n");

    return 0;
}

void exercicio7(){
  r07();
}

#define MAX_ROWS 4
#define MAX_COLS 4

bool verificaPotenciasPorLinha(int matriz[MAX_ROWS][MAX_COLS], int numLinhas, int numColunas) {
    for (int i = 0; i < numLinhas; i++) {
        int potencia = 1;
        for (int j = 0; j < numColunas; j++) {
            if (matriz[i][j] != potencia) {
                return false;
            }
            potencia *= (i + 1); 
        }
    }
    return true;
}

int r08() {
    FILE *arquivo;
    int matriz[MAX_ROWS][MAX_COLS];
    int numLinhas = MAX_ROWS;
    int numColunas = MAX_COLS;

    
    arquivo = fopen("MATRIZ3.TXT", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo MATRIZ3.TXT\n");
        return 1;
    }

    
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            if (fscanf(arquivo, "%d", &matriz[i][j]) != 1) {
                printf("Erro ao ler a matriz do arquivo\n");
                fclose(arquivo);
                return 1;
            }
        }
    }

    
    fclose(arquivo);

    
    if (verificaPotenciasPorLinha(matriz, numLinhas, numColunas)) {
        printf("A matriz possui a característica de potências por linha.\n");
    } else {
        printf("A matriz NÃO possui a característica de potências por linha.\n");
    }

    return 0;
}

void exercicio8(){
  r08();
}
#define MAX_ROWS 4
#define MAX_COLS 4

bool verificaPotenciasPorColuna(int matriz[MAX_ROWS][MAX_COLS], int numLinhas, int numColunas) {
    for (int j = 0; j < numColunas; j++) {
        int potencia = 1;
        for (int i = 0; i < numLinhas; i++) {
            if (matriz[i][j] != potencia) {
                return false;
            }
            potencia *= (j + 1); 
        }
    }
    return true;
}

int r09() {
    FILE *arquivo;
    int matriz[MAX_ROWS][MAX_COLS];
    int numLinhas = MAX_ROWS;
    int numColunas = MAX_COLS;

    
    arquivo = fopen("MATRIZ4.TXT", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo MATRIZ4.TXT\n");
        return 1;
    }

   
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            if (fscanf(arquivo, "%d", &matriz[i][j]) != 1) {
                printf("Erro ao ler a matriz do arquivo\n");
                fclose(arquivo);
                return 1;
            }
        }
    }

    
    fclose(arquivo);

    
    if (verificaPotenciasPorColuna(matriz, numLinhas, numColunas)) {
        printf("A matriz possui a característica de potências por coluna.\n");
    } else {
        printf("A matriz NÃO possui a característica de potências por coluna.\n");
    }

    return 0;
}

void exercicio9(){
  r09();
}

#define MAX_SUPERMERCADOS 100
#define MAX_NOME 50

typedef struct {
    int codigo;
    char nome[MAX_NOME];
    float preco;
} Supermercado;

void lerSupermercados(Supermercado supermercados[], int N) {
    for (int i = 0; i < N; i++) {
        printf("Supermercado %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", supermercados[i].nome);
        printf("Código: ");
        scanf("%d", &supermercados[i].codigo);
        printf("Preço: ");
        scanf("%f", &supermercados[i].preco);
        printf("\n");
    }
}

float calcularPrecoMedio(Supermercado supermercados[], int N) {
    float soma = 0;
    for (int i = 0; i < N; i++) {
        soma += supermercados[i].preco;
    }
    return soma / N;
}

void exibirSupermercadosInferioresMedia(Supermercado supermercados[], int N, float precoMedio) {
    int contador = 0;
    printf("Supermercados com preço inferior:\n");
    for (int i = 0; i < N; i++) {
        if (supermercados[i].preco < precoMedio) {
            printf("Supermercado: %s\n", supermercados[i].nome);
            printf("Código: %d\n", supermercados[i].codigo);
            printf("Preço: %.2f\n\n", supermercados[i].preco);
            contador++;
            if (contador == 2) {
                break;
            }
        }
    }
    if (contador == 0) {
        printf("Nenhum supermercado com preço inferior à média encontrado.\n");
    }
}

int r10() {
    int N;
    printf("Quantidade de supermercados: ");
    scanf("%d", &N);

    Supermercado supermercados[MAX_SUPERMERCADOS];

    lerSupermercados(supermercados, N);

    float precoMedio = calcularPrecoMedio(supermercados, N);

    printf("Preço médio: %.2f\n\n", precoMedio);

    exibirSupermercadosInferioresMedia(supermercados, N, precoMedio);

    return 0;
}

void exercicio10(){
  r10();
}
int main() {
    int op = 0;
  scanf ("%d", &op);
  switch(op){
    case 0:
    break;
    case 1:
    exercicio1();
    case 2:
    exercicio2();
    case 3:
    exercicio3();
    case 4:
    exercicio4();
    case 5:
    exercicio5();
    case 6:
    exercicio6();
    case 7:
    exercicio7();
    case 8:
    exercicio8();
     case 9:
    exercicio9();
    case 10:
    exercicio10();
    default:
    break;
  }
}