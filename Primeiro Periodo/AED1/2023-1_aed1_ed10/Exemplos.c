#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void comecar(){
    srand(time(NULL));//iniciar contador
}

int gerarValor(int max,int min){
    int valor = rand() % (max - min +1)+min; // gerar um valor entre max e min
    return valor;
}

void Exemplo01(){
    int max = 0, min = 0;
    comecar();
    printf("Digite um intervalor:\nMenor: ");
    scanf("%d", &min);
    printf("Maior: ");
    scanf("%d", &max);
    int q = max - min;
    if(q<0){
        q = q*(-1);
    }
    int t[q];
    FILE *a = fopen("DADOS.txt","wt");
    fprintf(a,"tamanho:%d\n",q);
    for(int i = 0; i < q; i++){
        t[i] = gerarValor(max,min);
        printf("%d ",t[i]);
    }
    for(int i = 0; i < q; i++){
        fprintf(a,"%d\n",t[i]);
    }
    fclose(a);
}



int searchN(char *nomeA, int procurar){
    int arq = 0, valor = 0;
    bool teste = false;
    FILE *a = fopen(nomeA,"rt");
    fscanf(a,"tamanho:%d",&arq);
    while(arq > 0){
        fscanf(a,"%d",&valor);
        if(procurar == valor){
            teste = true;
        }
        arq-=1;
    }
    fclose(a);
    return teste;
}

void Exemplo02(){
    int procurar = 0;
    printf("Digite o numero que deseja procurar: ");
    scanf("%d",&procurar);
    bool teste = searchN("DADOS.txt",procurar);
    if(teste){
        printf("\nEsse valor esta no arquivo!");
    }else{
        printf("\nEsse valor nao esta no arquivo!");
    }
}

int TamanhoDoArquivo(char *arquivo){ // Cada vez que ler um elemento adicionar +1 à variavel tamanho e retorna-lo
    FILE *a = fopen(arquivo,"rt");
    int tamanho = 0, test = 0;

    while(fscanf(a,"%d ",&test)==1){
        tamanho++;
    }
    fclose(a);
    return tamanho;
}

void compararArquivos(char* x, char* y)
{
    int t1 = TamanhoDoArquivo(x);
    int t2 = TamanhoDoArquivo(y);
    if(t1 > t2){
        printf("O primeiro eh maior");
    }
    else if(t1 < t2){
        printf("O segundo eh maior");
    }
    else{
        printf("Sao do mesmo tamanho");
}
}

void Exemplo03(){
    compararArquivos("DADOS1.txt","DADOS2.txt");
}

int* LerUm(char *arquivo, int tamanho){
    FILE *a = fopen(arquivo,"rt");
    int* t = malloc(tamanho * sizeof(int));
    for(int i = 0; i < tamanho; i++){
        fscanf(a,"%d",&t[i]);
    }
    fclose(a);
    return t;
}

int* somarARRAY(int e,int* array01, int* array02, int t1, int t2){
    int* soma = malloc( (t1+t2) * sizeof(int) );
    int tcompleto = t1+t2;
    for(int i = 0; i < tcompleto; i++){
        if(i < t1){
            soma[i] = array01[i];
        }else{
            soma[i] = array02[i-t1];
        }
    }
    return soma;
}
void mostrar(int* ar,int t){
    for(int i = 0; i < t; i++){
        printf("%d ", ar[i]);
    }
}
void Exemplo04(){
    int arquivo01 = TamanhoDoArquivo("DADOS1.txt");
    int arquivo02 = TamanhoDoArquivo("DADOS2.txt");
    int* dados1 = NULL;
    int* dados2 = NULL;
    if(arquivo01 == arquivo02){
        dados1 = LerUm("DADOS1.txt",arquivo01);
        dados2 = LerUm("DADOS2.txt",arquivo02);
    int* soma = NULL;
    if(dados1 != NULL && dados2 != NULL){
        soma = somarARRAY(-1,dados1,dados2,arquivo01,arquivo02);
}
    mostrar(soma,arquivo01+arquivo02);
    free(dados1);
    free(dados2);
    free(soma);
    }
}

int estaDecrescendo(int tamaho, int *ar){
    bool teste = false;
    for(int i = 0; i < tamaho-1; i++){
        if(ar[i]>ar[i+1]){
            teste = true;
        }else{
            return false;
        }
    }
    return teste;
}

void Exemplo05(){
    int t1 = TamanhoDoArquivo("DADOS2.txt");
    int* ar1 = LerUm("DADOS2.txt",t1);
    if(estaDecrescendo(t1,ar1)){
        printf("Esta decrescendo");
    }else{
        printf("Nao esta decrescendo");
    }
}
void transposicao(int **arq1, int linha, int colunas, int **resul) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < colunas; j++) {
            resul[j][i] = arq1[i][j];
        }
    }
}

void Exemplo06() {
    int colunas = 0, linhas = 0;
    FILE *A = fopen("DADOSMATRIZ.txt", "rt");
    fscanf(A, "linhas:%d colunas:%d", &linhas, &colunas);

    int **x = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        x[i] = (int *)malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(A, "%d", &x[i][j]);
        }
    }
    fclose(A);

    int **resultados = (int **)malloc(colunas * linhas * sizeof(int *)); // alocar memoria para cada array
    for (int i = 0; i < colunas; i++) {
        resultados[i] = (int *)malloc(linhas * sizeof(int)); // alocar memoria para cada array dentro do array
    }

    transposicao(x, linhas, colunas, resultados);

    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d ", resultados[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++) {
        free(x[i]); //liberando o espaço de cada array dentro de um array
    }
    free(x); // liberando memoria do array

    for (int i = 0; i < colunas; i++) {
        free(resultados[i]);
    }
    free(resultados);
}

int testeZERO(){
    bool tst = false;
    int t = TamanhoDoArquivo("DADOS.txt");
    int *x = LerUm("DADOS.txt",t);
    for(int i = 0; i < t; i++){
        if(x[i] == 0){
            tst = true;
        }else{
            return false;
        }
    }
    return tst;
}

void Exemplo07(){
    if(testeZERO()==1){
        printf("\nTodos os elementos sao nulos");
    }else{
        printf("\nContem elementos nao nulos");
    }
}

int verificarigualdade(int t1, int*x, int *y){
    bool teste = false;
    for(int i = 0; i < t1; i++){
        if(x[i] == y[i]){
            teste = true;
        }else{
            return false;
        }
    }
    return teste;
}

void Exemplo08(){
    int t1 = TamanhoDoArquivo("DADOS1.txt");
    int *x = LerUm("DADOS1.txt",t1);
    int t2 = TamanhoDoArquivo("DADOS2.txt");
    int *y = LerUm("DADOS2.txt",t2);
    bool z = false;
    if(t1 == t2){
        z = verificarigualdade(t1,x,y);
    }
    if(z == true){
        printf("\nSao iguais");
    }else{
        printf("\nSao diferentes");
    }
}

void Exemplo09(){
    Exemplo04();
}

int *produto(int *array01, int *array02, int t1){
    int *product = malloc( t1 * sizeof(int));
    for(int i = 0; i < t1; i++){
        product[i] = array01[i] * array02[i];
    }
    return product;
}

void Exemplo10(){
    int t1 = TamanhoDoArquivo("DADOS1.txt");
    int t2 = TamanhoDoArquivo("DADOS2.txt");
    int *matriz01 = LerUm("DADOS1.txt",t1);
    int *matriz02 = LerUm("DADOS2.txt",t2);
    int *z = NULL;
    if(t1 == t2){
        z = produto(matriz01,matriz02,t1);
    }
    for(int i = 0; i<t1; i++){
        printf("%d ",z[i]);
    }
    free(matriz01);
    free(matriz02);
    free(z);
}

void trocarPosicao(int *arr, int i, int j) {
    int temp = arr[i]; //temp fica com o valor antes
    arr[i] = arr[j];//arra[i] fica com o valor que estava na sua frente
    arr[j] = temp;// arr[j] fica com o valor qua esta atraz de sua posição original
}

void Exemplo10E1(char *nomeArquivo) {
    int tamanho = TamanhoDoArquivo(nomeArquivo);
    int *arr = LerUm(nomeArquivo, tamanho);

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[i] > arr[j]) { //testar se o proximo valor é maior, e caso sim chamar a função
                trocarPosicao(arr, i, j);
            }
        }
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

void Exemplo10E2(){
    int t1 = TamanhoDoArquivo("DADOS1.txt");
    int t2 = TamanhoDoArquivo("DADOS2.txt");
    int *matriz01 = LerUm("DADOS1.txt",t1);
    int *matriz02 = LerUm("DADOS2.txt",t2);
    int *z = NULL;
    if(t1 == t2){
        z = produto(matriz01,matriz02,t1);
    }
    for(int i = 0; i<t1; i++){
        printf("%d ",z[i]);
    }
    free(matriz01);
    free(matriz02);
    free(z);
}

int main() {
    int op = 0;
    scanf("%d",&op);
    switch(op){
    case 0:
        break;
    case 1:
        Exemplo01();
        break;
    case 2:
        Exemplo02();
        break;
    case 3:
        Exemplo03();
        break;
    case 4:
        Exemplo04();
        break;
    case 5:
        Exemplo05();
        break;
    case 6:
        Exemplo06();
        break;
    case 7:
        Exemplo07();
        break;
    case 8:
        Exemplo08();
        break;
    case 9:
        Exemplo09();
        break;
    case 10:
        Exemplo10();
        break;
    case 11:
        Exemplo10E1("DADOS1.txt");
        break;
    case 12:
        Exemplo10E2();
        break;
    default:
        break;
    }
}
