#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int Comparar(char *cadeia1, char *cadeia2) {
    return strcmp(cadeia1, cadeia2);
}

void exercicio10() {
    char x[80], y[80], z[80];

    printf("Digite a primeira cadeia: ");
    scanf("%s", x);

    printf("Digite a segunda cadeia: ");
    scanf("%s", y);

    printf("Digite a terceira cadeia: ");
    scanf("%s", z);

    int resultado1 = Comparar(x, y);
    int resultado2 = Comparar(y, z);

    if (resultado1 > 0 && resultado2 > 0) {
        printf("Estao em ordem alfabetica decrescente\n");
    } else if (resultado1 < 0 && resultado2 < 0) {
        printf("Estao em ordem alfabetica crescente.\n");
    } else {
        printf("nao estao em ordem alfabetica\n");

        if (resultado1 > 0) {
        printf("A maior cadeia e: %s\n", x);
        printf("A menor cadeia e: %s\n", z);
        } else if (resultado2 > 0) {
        printf("A maior cadeia e: %s\n", y);
        printf("A menor cadeia e: %s\n", z);
        } else {
        printf("A maior cadeia e: %s\n", y);
        printf("A menor cadeia e: %s\n", x);
        }
    }
}

void mostrarL(char ma, char me){
    printf("\nMaior: %c\nMenor: %c\n",ma,me);
}
int testarL(char x, char y, char z){
    char menor = '0',maior = '0';
    if(x < y && y< z){
        printf("\nEstao em ordem decrescente\n");
    } else if(x>y && y> z){
        printf("\nEstao em ordem decrescente\n");
    } else{
        if(x<y && x<z){
            menor = x;
        } else if(y< x && y < z){
            menor = y;
        } else{
            menor = z;
        }
        if(x > y && x > z){
            maior = x;
        } else if(y > x && y > z){
            maior = y;
        } else{
            maior = z;
        }
        mostrarL(maior, menor);
    }
    return 0;
}
void exercicio09(){
    char x = '0', y = '0', z = '0';
    printf("Digite um valor: ");
    scanf(" %c",&x);getchar();
    printf("Digite outro valor: ");
    scanf(" %c",&y);getchar();
    printf("Digite outro valor: ");
    scanf(" %c",&z);getchar();
    testarL(x, y, z);
}

void mostrarN(int ma, int me){
    printf("\nMaior: %d\nMenor: %d\n",ma,me);
}
int testar(int x, int y, int z){
    int menor = 0,maior = 0;
    if(x < y && y< z){
        printf("\nEstao em ordem decrescente\n");
    } else if(x>y && y> z){
        printf("\nEstao em ordem decrescente\n");
    } else{
        if(x<y && x<z){
            menor = x;
        } else if(y< x && y < z){
            menor = y;
        } else{
            menor = z;
        }
        if(x > y && x > z){
            maior = x;
        } else if(y > x && y > z){
            maior = y;
        } else{
            maior = z;
        }
        mostrarN(maior,menor);
    }
    return 0;
}
void exercicio08(){
    float x = 0, y = 0, z = 0;
    printf("Digite um valor: ");
    scanf("%f",&x);
    printf("Digite outro valor: ");
    scanf("%f",&y);
    printf("Digite outro valor: ");
    scanf("%f",&z);
    testar(x,y,z);
}

void exercicio07(){
    float a = 0, b = 0;
    float d = 0, fc = 0, fb = 0, total = 0;
    printf("Digite um intervalo: ");
    scanf("%f", &a);
    getchar();
    scanf("%f", &b);
    getchar();
    float x = 1;
    while(x != 0){
        if(x == 0){
            break;
        }
        scanf("%f", &x);
        getchar();

        if ((b > a && a <= x && x <= b && x != 0) || (a > b && b <= x && x <= a && x != 0)){
            d++;
        }else{
            if ((a > b && x > a && x != 0) || (b > a && x > b && x != 0)){
                fc++;
            }if((a < b && x < a && x != 0) || (b < a && x < b && x != 0)){
                fb++;
            }
        }
        if(x!=0){total++;}
    }
    printf("%.2f%% estao acima\n%.2f%% estao abaixo", 100 * (fc / total), 100 * (fb / total));
}

double somar(int soma){
    float s = 1/pow(soma,3);
    return s;
}
void exercicio06(){
    int a = 0, b = 0;
    printf("Digite um intervalo:");
    scanf("%d",&a);getchar();
    scanf("%d",&b);getchar();
    int i = 0;
    float soma = 0;
    while(i != -1){
        scanf("%d",&i);
        if(a <= i && i <= b || b <= i && i <= a){
            if(i%2 != 0){
                soma += somar(i);
            }
        }
    }
    printf("%f", soma);
}

double separarM(float t[], int h){
    float soma1 = 0,soma2 = 0,soma3 = 0;
    float q1 = 0, q2 = 0, q3 = 0;
    for(int i = 0; i < h; i++){
        if(t[i]< -32.25){
            soma1 += t[i];
            q1++;
        }
        if(-32.25 <= t[i] && t[i] <= 63.75){
            soma2 += t[i];
            q2++;
        }
        if(t[i] >= 63.75){
            soma3 += t[i];
            q3++;
        }
    }
    float media1 = 0, media2 = 0, media3 = 0;
    if(soma1 != 0){
        media1 = soma1/q1;
        printf("Media dos menores que -32.25: %.3f\n",media1);
    }
    if(soma2 != 0){
        media2 = soma2/q2;
        printf("Media dos entre -32.25 e 63.75: %.3f\n",media2);
    }
    if(soma3 != 0){
        media3 = soma3/q3;
        printf("Media dos maiores que 63.75: %.3f\n",media3);
    }

    if(media1 > media2 && media1 > media3){
        return media1;
    }else if(media2 > media1 && media2 > media3){
        return media2;
    }else{
        return media3;
    }
    printf("%f",media1);
    return 0;
}
void exercicio05(){
    int n = 0;
    scanf("%d",&n); getchar();
    float q[n];
    int i = 0;
    while(i<n){
        scanf("%f",&q[i]);
        getchar();
        i++;
    }
    double media = separarM(q,n);
    printf("\nMaior media: %.3lf\n",media);
}

int contarN(char *x){
    int identificador = 8;
    int h = strlen(x), i = 0, j = 0;
    char t[h];
    for(i = 0; i < h; i++){
        if('0'<= x[i] && x[i]<= '9'){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
    return 0;
}
int contarM(char *x){
    int identificador = 6;
    int h = strlen(x), i = 0, j = 0;
    char t[h];
    for(i = 0; i < h; i++){
        if('A' <= x[i] && x[i] <= 'Z'){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
    return 0;
}
int contarm(char *x){
    int identificador = 7;
    int h = strlen(x), i = 0, j = 0;
    char t[h];
    for(i = 0; i < h; i++){
        if('a'<= x[i] && x[i]<='z'){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
    return 0;
}

void exercicio04(){
    char x[80];
    scanf("%s", x);getchar();
    contarM(x);
    contarm(x);
    contarN(x);
    opL(x);
    opA(x);
    opR(x);
    s(x);
}

void mostrar(char *t,int q, int *identificador){
    if(strlen(t) > 0){
        if(identificador == 1){
            printf("\nSao operadores logicos: ");
        }
        else if(identificador == 2){
            printf("\nSao operadores aritimetricos: ");
        }
        else if(identificador == 3){
            printf("\nSao operadores relacionais: ");
        }
        else if(identificador == 4){
            printf("\nSao separadores: ");
        }
        else if(identificador == 5){
            printf("\nOutros: ");
        }
        else if(identificador == 6){
            printf("\nSao letras maiusculas: ");
        }
        else if(identificador == 7){
            printf("\nSao letras minusculas: ");
        }
        else if(identificador == 8){
            printf("\nSao numerais: ");
        }
        for(int i = 0; i < q; i++){
            printf("%c ", t[i]);
        }

    }
}
int outros(char *x){
    int identificador = 5;
    int h = strlen(x), i = 0, j = 0;
    char t[h];

    for(i = 0; i < h; i++){
    bool t1 = (x[i] == ' ' || x[i] == ',' || x[i] == '.' || x[i] == ';' || x[i] == ':' || x[i] == '_');
    bool t2 = (x[i]=='>' || x[i] == '<' || x[i] == '=');
    bool t3 = (x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '%' || x[i] == '/');
    bool t4 = ( x[i] == '&' || x[i] == '|' || x[i] == '!');
        if(!(t1) && !(t2) && !(t3) && !(t4)){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
    return 0;
}

int s(char *x){
    int identificador = 4;
    int h = strlen(x), i = 0, j = 0;
    char t[h];
    for(i = 0; i < h; i++){
        if(x[i] == ' ' || x[i] == ',' || x[i] == '.' || x[i] == ';' || x[i] == ':' || x[i] == '_'){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
}

int opR(char *x){
    int identificador = 3;
    int h = strlen(x), i = 0, j = 0;
    char t[h];
    for( i = 0; i < h; i++){
        if(x[i]=='>' || x[i] == '<' || x[i] == '='){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
    return 0;
}
int opA(char *x){
    int identificador = 2;
    int h = strlen(x), i = 0, j = 0;
    char t[h];
    for(i = 0; i < h;i++){
        if(x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '%' || x[i] == '/'){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
    return 0;
}
int opL(char *x){
    int identificador = 1;
    int h = strlen(x);
    char t[h]; int i = 0, j = 0;
    for(i = 0; i < strlen(x);i++){
        if( x[i] == '&' || x[i] == '|' || x[i] == '!'){
            t[j] = x[i];
            j++;
        }
    }mostrar(t,j,identificador);
    return 0;
}
void exercicio03(){
    char x[80];
    int i = 0;
    scanf("%s", x);getchar();
    opL(x);
    opA(x);
    opR(x);
    s(x);
    outros(x);
}

int funcao02(){
    int x=0;
    printf("Digite o valor que sera testado: ");
    scanf("%d",&x);getchar();
    for(int i = 2; i < x; i++){
        if(x%i==0){
            return(0);
        }
    }
    return 1;
}
void exercicio02(){
    int q = 0;
    printf("Digite uma quantidade valores que deseja testar: ");
    scanf("%d",&q);
    for(int i = 0; i < q;i++){
        int t = funcao02();
        if(t==1){
            printf("\nEh um valor primo\n");
        }else{
            printf("\nNao eh um valor primo\n");
        }
    }
}

int funcao01(int n){
    int soma = 0;
        for(int i = 1; i <= n; i++){
            if(n%i==0){
                soma += i;
        }
    }
    printf("soma dos divisores de %d eh %d\n",n,soma);
    return soma;
}
void exercicio01(){
    printf("Digite uma quantidade de n que queira saber seus divisores somados: ");
    int q = 0;
    scanf("%d",&q);getchar();
    int n = 0;
    int i = 0;
    while(i < q){
        scanf("%d",&n);
        int soma = funcao01(n);
        i++;
    }
}

int main(){
    int option = 0;
    scanf("%d",&option);
    switch(option){
    case 0:
        break;
    case 1:
        exercicio01();
        break;
    case 2:
        exercicio02();
        break;
    case 3:
        exercicio03();
        break;
    case 4:
        exercicio04();
        break;
    case 5:
        exercicio05();
        break;
    case 6:
        exercicio06();
        break;
    case 7:
        exercicio07();
        break;
    case 8:
        exercicio08();
        break;
    case 9:
        exercicio09();
        break;
    case 10:
        exercicio10();
        break;
    default:
        break;
    }

    return 0;
}
