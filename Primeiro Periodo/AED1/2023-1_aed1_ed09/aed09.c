#include <stdio.h>
#include <stdbool.h>
void Exemplo09E2(){
    int l = 0, c = 0;
    printf("\nDigite o n de linhas: ");
    scanf("%d",&l);
    printf("\nDigite o n de colunas: ");
    scanf("%d",&c);
    int t[l][c];
    for(int i = 0; i < l; i++){
        printf("\nLinha: %d\n",i+1);
        for(int j = 0; j < c; j++){
            scanf("%d",&t[i][j]);
        }
    }
    FILE *a = fopen("MATRIZ_02.txt","wt");
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fprintf(a,"%d ",t[i][j]);
        }
        fprintf(a,"\n");
    }
    fclose(a);
}

void Exemplo09E1(){
    int l = 0, c = 0;
    printf("\nDigite o n de linhas: ");
    scanf("%d",&l);
    printf("\nDigite o n de colunas: ");
    scanf("%d",&c);
    int t[l][c];
    for(int i = 0; i < l; i++){
        printf("\nLinha: %d\n",i+1);
        for(int j = 0; j < c; j++){
            scanf("%d",&t[i][j]);
        }
    }
    FILE *a = fopen("MATRIZ_02.txt","wt");
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fprintf(a,"%d ",t[i][j]);
        }
        fprintf(a,"\n");
    }
    fclose(a);
}

void Exemplo0920(){
    bool tst = 1;
    int l = 0, c = 0;
    FILE *a = fopen("MATRIZ_01.txt","rt");
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&x[i][j]);
        }
    }
    float v = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            v = x[i][j];
            if(i <= (c -j -1) && v == 0){
                tst = 0;
            }
        }
    }
    fclose(a);
    if(tst == 0){
        printf("\nTem valor negativo");
    }else{
        printf("\nNao tem valor negativo");
    }
}

void Exemplo0919(){
    bool teste = 1;
    int l = 0, c = 0;
    FILE *a = fopen("MATRIZ_01.txt","rt");
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&x[i][j]);
        }
    }
    fclose(a);
    float y = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            y = x[i][j];
            if(y==0 && i>=j){
            teste = 0;
            }
        }
    }
    if(teste == 1){
        printf("\nNao tem numero nulo");
    }else{
        printf("\nTem numero nulo");
    }
}

void Exemplo0918(){
    int l = 0, c = 0;
    FILE *a = fopen("MATRIZ_01.txt","rt");
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&x[i][j]);
        }
    }if(l == c){
     for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
                if(i <= j){
/*
                0 <= 0 true, 0<=1 true, 0<=2 true, 0<=3 true
                1 <= 0 false, 1<=1 true, 1<=2 true, 1<=3 true
                2 <= 0 false, 2<=1 false, 2<=2 true, 2<=3 true
                3 <= 0 false, 3<=2 false, 3<=2 false, 3<=3 true
*/
            printf("%f ",x[i][j]);
                }
        }
        printf("\n");
    }}
}
void Exemplo0917(){
    int l = 0, c = 0;
    FILE *a = fopen("MATRIZ_01.txt","rt");
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&x[i][j]);
        }
    }
    if(l == c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
                if(i >= (c - j -1)){
/*
                    0 >= 4 -0 -1 ->( 0 >= 3 )false, 0 >= 4 -1 -1 ->( 0 >= 2 )false, 0 >= 4 -2 -1 ->( 0 >= 1 )false, 0 >= 4 -3 -1 ->( 0 >= 0 )true
                    1 >= 4 -1 -1 ->( 1 >= 3 )false, 1 >= 4 -1 -1 ->( 1 >= 2 )false, 0 >= 4 -2 -1 ->( 1 >= 1 )true, 0 >= 4 -3 -1 ->( 1 >= 0 )true
                    2 >= 4 -1 -1 ->( 2 >= 3 )false, 1 >= 4 -1 -1 ->( 2 >= 2 )true, 0 >= 4 -2 -1 ->( 2 >= 1 )true, 0 >= 4 -3 -1 ->( 2 >= 0 )true
                    3 >= 4 -1 -1 ->( 3 >= 3 )true, 1 >= 4 -1 -1 ->( 3 >= 2 )true, 0 >= 4 -2 -1 ->( 3 >= 1 )true, 0 >= 4 -3 -1 ->( 3 >= 0 )true
*/
            printf("%f ",x[i][j]);
                }
        }
        printf("\n");
    }}
}

void Exemplo0916(){
    int l = 0, c = 0;
    FILE *a = fopen("MATRIZ_01.txt","rt");
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&x[i][j]);
        }
    }if(l == c){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            if(j>=i){
/*
                0 >= 0 true, 1>=0 true, 2>=0 true, 3>=0 true
                0 >= 1 false, 1>=1 true, 2>=1 true, 3>=1 true
                0 >= 2 false, 1>=2 false, 2>=2 true, 3>=2 true
                0 >= 3 false, 1>=3 false, 2>=3 false, 3>=3 true
*/
                printf("%f ",x[i][j]);
            }
        }
            printf("\n");
    }}
    fclose(a);
}

void Dbaixo(int l, int c, float x[l][c]){
    int i = 0, j = 0;
    if(l == c){
    while(i < c){
        printf("%f ",x[i+1][j]);
        i++;
        j++;
    }}
}

void Exemplo0915(){
    int l = 0, c = 0;
    FILE *a = fopen("MATRIZ_01.txt","rt");
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&x[i][j]);
        }
    }
    fclose(a);
    Dbaixo(l,c,x);
}

void Exemplo0914(){
    int l = 0, c = 0;
    FILE *a = fopen("MATRIZ_01.txt","rt");
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&x[i][j]);
        }
    }
    fclose(a);
    getchar();
    int i = 0, j = 0;
    if(l == c){
    while(i < c){
        printf("%f ",x[i][j+1]);
        i++;
        j++;
    }
    }


}



void Mdiagonal(int l,int c,float x[l][c]){
    int i = 0, j = 0;
    if(l == c){
    while(i<c){
        printf("%f ",x[i][j]);
        i++;
        j++;
    }}
}
void Exemplo0913(){
    FILE *a = fopen("MATRIZ_01.txt","rt");
    int l = 0, c = 0;
    fscanf(a,"Linhas:%d Colunas:%d",&l,&c);
    float x[l][c];
    float v = 0;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            fscanf(a,"%f",&v);
            x[i][j] = v;
        }
    }
    Mdiagonal(l,c,x);
    fclose(a);
}





void lerA(const char* a, double y[10][10]) {
    FILE *ar = fopen(a,"rt");
    float x = 0, m = 0;
    float value = 0;
    fscanf(ar,"Linhas:%f Colunas:%f",&x,&m);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < m; j++){
            fscanf(ar,"%f",&value);
            y[i][j] = value;
        }
    }
    for(int i = 0; i<x;i++){
        for(int j = 0; j < m; j++){
            printf("%f ",y[i][j]);
        }
        printf("\n");
    }
    fclose(ar);
}

void Exemplo0912() {
    int c = 0, l = 0;
    double y[10][10];
    lerA("MATRIZ_01.txt", y);
}




void mostrarD(int c, int l, float v[c][l]){//metodo para mostrar a tabela do array na tela
    FILE *a = fopen("MATRIZ_01.txt","wt");
    fprintf(a,"Linhas:%d Colunas:%d\n",c,l);
    for(int i = 0; i < c; i++){
        for(int j = 0; j < l; j++){
            printf("| %.2f ",v[i][j]);
            fprintf(a,"%.2f ",v[i][j]);
        }
        printf("|\n");
        fprintf(a,"\n");
    }
    fclose(a);
}
/* metodo para testar se o numero de linhas ou colunas e negativo ou nulo
e caso sim, voltar no metodo para ler o numero de colunas e linhas novamente e caso
nao ler os valores de cada espaco do array*/
void lerVetor(int c, int l){
    float v[c][l];
    if(c <= 0 || l <= 0 || c>10 || l>10){
        printf("O numero de colunas e de linhas nao pode ser negativo ou nulo\ne tem que ser menor ou igual a 10\n");
        Exemplo0911();
    }
    printf("Digite apenas numeros negativos: \n");
    for(int i = 0; i < c; i++){
        printf("\nLinha: %d\n",i+1);
        for(int j = 0; j < l; j++){
            scanf("%f",&v[i][j]);
        }
    }
    mostrarD(c,l,v);
}
void Exemplo0911(){//metodo para ler o numero de colunas e linhas
    int l = 0, c = 0;
    printf("Digite o numero de linhas: ");
    scanf("%d",&c);
    printf("Digite o numero de colunas: ");
    scanf("%d",&l);
    lerVetor(c,l);
}

int main(){
    int op = 0;
    scanf("%d",&op);
    switch(op){
    case 0:
        break;
    case 1:
        Exemplo0911();
        break;
    case 2:
        Exemplo0912();
        break;
    case 3:
        Exemplo0913();
        break;
    case 4:
        Exemplo0914();
        break;
    case 5:
        Exemplo0915();
        break;
    case 6:
        Exemplo0916();
        break;
    case 7:
        Exemplo0917();
        break;
    case 8:
        Exemplo0918();
        break;
    case 9:
        Exemplo0919();
        break;
    case 10:
        Exemplo0920();
        break;
    case 11:
        Exemplo09E1();
        break;
    case 12:
        Exemplo09E2();
        break;
    default:
        break;
    }
}
