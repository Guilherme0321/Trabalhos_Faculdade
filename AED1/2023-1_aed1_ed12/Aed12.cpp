#include <fstream>
#include <iostream>
#include <random>

using namespace std;

class Comandos {
private:
  int tamanho = 0;
  int *info = nullptr;

public:
  int *GerarAleatorios(int q) {
    std::random_device rd;

    // Criando um gerador de numeros aleatorios usando a semente
    std::mt19937 gen(rd());

    // Definindo o intervalo dos numeros aleatorios
    int min = 1;
    int max = 100;

    // Criando uma distribuicao uniforme dentro do intervalo
    std::uniform_int_distribution<int> dist(min, max);

    int *V = new int[q];

    for (int i = 0; i < q; i++) {
      V[i] = dist(gen);
    }
    return V;
  }

  void GravarArquivo(int *x, int t) {
    ofstream ar("DADOS.txt");
    ar << t << endl;
    for (int i = 0; i < t; i++) {
      ar << x[i] << endl;
    }
    ar.close();
    delete[] x;
  }

  void Exemplo1211() {
    int q = 0;
    cin >> q;
    int *V = GerarAleatorios(q);
    GravarArquivo(V, q);
  }

  int *ler(string x) {
    ifstream a(x);
    a >> tamanho;
    int *dados = new int[tamanho];
    for (int i = 0; i < tamanho; i++) {
      a >> dados[i];
    }
    return dados;
  }

  int *escalar(int x) {
    for (int i = 0; i < tamanho; i++) {
      info[i] *= x;
    }
    return info;
  }

  void Exemplo1212() {
    info = ler("DADOS.txt");
    int *x = escalar(3);
    for (int i = 0; i < tamanho; i++) {
      cout << x[i] << endl;
    }
    delete[] x;
  }

  int **criarMatriz(int linhas, int c) {
    int **matriz = nullptr;
    matriz = new int *[linhas];
    for (int i = 0; i < linhas; i++) {
      matriz[i] = new int[c];
    }
    return matriz;
  }

  void Exemplo1213() {
    int **matriz = nullptr;
    int linhas = 0, c = 0;
    cout << "Quantidade de elementos: ";
    cin >> linhas;
    cout << "Quantidade de colunas: ";
    cin >> c;
    matriz = criarMatriz(linhas, c);

    for (int i = 0; i < linhas; i++) {
      matriz[i] = GerarAleatorios(c);
    }

    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < c; j++) {
        cout << matriz[i][j] << " ";
      }
      cout << endl;
    }
    if (linhas == c) {
      cout << "A matriz eh identidade" << endl;
    } else {
      cout << "A matriz nao eh identidade" << endl;
    }
    for (int i = 0; i < linhas; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
  }

  int Comparar(int *x, int *y, int t) {
    int c = 0;
    for (int i = 0; i < t; i++) {
      if (x[i] == y[i]) {
        c++;
      }
    }
    delete[] x;
    delete[] y;
    if (c == t) {
      return 1;
    }
    return 0;
  }

  void Exemplo1214() {
    int *x = ler("DADOS.txt");
    int t1 = tamanho;

    int *y = ler("DADOS1.txt");
    int t2 = tamanho;
    int c = 0;
    if (t1 == t2) {
      c = Comparar(x, y, t1);
    } else {
      cout << "Tamanhos diferentes" << endl;
    }
    if (c == 1) {
      cout << "Sao iguais" << endl;
    } else {
      cout << "Sao diferentes" << endl;
    }
  }

  int *soma(int *x, int *y, int t) {
    int *s = new int[t];
    for (int i = 0; i < t; i++) {
      s[i] = x[i] + y[i];
    }
    delete[] x;
    delete[] y;
    return s;
  }

  void mostrar(int *a, int t) {
    for (int i = 0; i < t; i++) {
      cout << a[i] << endl;
    }
    delete[] a;
  }
  void Exemplo1215() {
    int *x = ler("DADOS.txt");
    int t1 = tamanho;
    int *y = ler("DADOS1.txt");
    int t2 = tamanho;
    if (t1 == t2) {
      int *s = soma(x, y, t1);
      mostrar(s, tamanho);
    } else {
      cout << "Nao foi possivel realizar a soma, tamanho diferentes" << endl;
    }
  }

  int *somarNaMatriz(int *x, int t, int *y, int t2) {
    for (int i = 0; i < t; i++) {
      x[i] += y[i];
    }
    return x;
  }

  void Exemplo1216() {
    int *x = ler("DADOS.txt");
    int t1 = tamanho;
    int *y = ler("DADOS1.txt");
    int t = tamanho;
    int T = 0;
    if (t1 >= t) {
      T = t1;
    } else if (t >= t1) {
      T = t;
    }
    int **matriz = criarMatriz(2, T);
    for (int i = 0; i < t1; i++) {
      matriz[0][i] = x[i];
    }
    for (int i = 0; i < t; i++) {
      matriz[1][i] = y[i];
    }
    matriz[0] = somarNaMatriz(matriz[0], t1, matriz[1], t);
    for (int i = 0; i < T; i++) {
      cout << matriz[0][i] << endl;
    }

    delete[] x;
    delete[] y;
    for (int i = 0; i < 2; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
  }

  int *addValores(int *x, int t, int *add) {
    for (int i = 0; i < t; i++) {
      x[i] = add[i];
    }
    return x;
  }
  int *subtra(int *x, int t, int *y, const int c) {
    for (int i = 0; i < t; i++) {
      x[i] -= y[i];
      x[i] *= c;
    }
    return x;
  }

  void Exemplo1217() {
    int *x = ler("DADOS.txt");
    int t1 = tamanho;
    int *y = ler("DADOS1.txt");
    int t2 = tamanho;

    int T = 0;
    if (t1 >= t2) {
      T = t1;
    } else if (t2 >= t1) {
      T = t2;
    }
    int **matriz = criarMatriz(2, T);
    matriz[0] = addValores(matriz[0], T, x);
    matriz[1] = addValores(matriz[1], T, y);

    for (int i = 0; i < t2; i++) {
      cout << "x = " << matriz[0][i] << " y = " << matriz[1][i] << endl;
    }

    matriz[0] = subtra(matriz[0], T, matriz[1], 2);

    for (int i = 0; i < T; i++) {
      cout << matriz[0][i] << endl;
    }

    delete[] x;
    delete[] y;
    for (int i = 0; i < 2; i++) {
      delete[] matriz[i];
    }
    delete matriz;
  }

  int procurarl(int p, int **s, int t) {

    int resul = 0;
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < p; j++) {
        if (s[i][j] == t) {
          resul = i + 1;
          return resul;
        }
      }
    }
    return resul;
  }

  void Exemplo1218() {
    int p = 0;

    int **matriz = criarMatriz(5, 5);
    for (int i = 0; i < 5; i++) {
      matriz[i] = GerarAleatorios(5);
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cout << matriz[i][j] << " ";
      }
      cout << endl;
    }
    cout << "Digite o numero: ";
    scanf("%d", &p);
    int valor = procurarl(5, matriz, p);
    if (valor != 0) {
      cout << "Linha: " << valor << endl;
    } else {
      cout << "Valor nao encontrado" << endl;
    }
    for (int i = 0; i < 5; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
  }
  int procurarc(int p, int **s, int t) {

    int resul = 0;
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < p; j++) {
        if (s[i][j] == t) {
          resul = j + 1;
          return resul;
        }
      }
    }
    return resul;
  }
  void Exemplo1219() {
    int p = 0;

    int **matriz = criarMatriz(5, 5);
    for (int i = 0; i < 5; i++) {
      matriz[i] = GerarAleatorios(5);
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cout << matriz[i][j] << " ";
      }
      cout << endl;
    }
    cout << "Digite o numero: ";
    cin >> p;
    int valor = procurarc(5, matriz, p);
    if (valor != 0) {
      cout << "Coluna: " << valor << endl;
    } else {
      cout << "Valor nao encontrado" << endl;
    }
    for (int i = 0; i < 5; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
  }

  void Exemplo1220() {
    int p = 0;

    int **matriz = criarMatriz(4, 5);
    for (int i = 0; i < 4; i++) {
      matriz[i] = GerarAleatorios(5);
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 5; j++) {
        cout << matriz[i][j] << " ";
      }
      cout << endl;
    }
    int **Transposta = criarMatriz(5, 4);
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 4; j++) {
        Transposta[i][j] = matriz[j][i];
      }
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 4; j++) {
        cout << Transposta[i][j] << " ";
      }
      cout << endl;
    }

    for (int i = 0; i < 4; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
    for (int i = 0; i < 5; i++) {
      delete[] Transposta[i];
    }
    delete[] Transposta;
  }

  void Exemplo12E1() {
    int l = 0, c = 0;
    cout << "Linhas: ";
    cin >> l;
    cout << "Colunas: ";
    cin >> c;
    int **matriz = criarMatriz(l, c);
    int contar = 1;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        matriz[i][j] = contar;
        contar++;
      }
    }

    int a = 0;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c - 1; j++) {
        if (matriz[i][j] <= matriz[i][j + 1]) {
          a++;
        }
      }
    }
    if (a == l * (c - 1)) {
      cout << "Esta na forma indicada" << endl;
    } else {
      cout << "Nao esta na forma indicada" << endl;
    }
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < l; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
  }
  void Exemplo12E2() {
    int l = 0, c = 0;
    getchar();
    cout << "Linhas: ";
    cin >> l;getchar();
    cout << "Colunas: ";
    cin >> c;getchar();
    int **matriz = criarMatriz(l, c);
    int contar = 1;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        matriz[j][i] = contar;
        contar++;
      }
    }
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    int a = 0;
    for (int i = 0; i < l-1; i++) {
      for (int j = 0; j < c; j++) {
        if (matriz[j][i] <= matriz[j][i+1]) {
          a++;
        }
      }
    }
    if (a == (l-1)*c) {
      cout << "Esta na forma indicada" << endl;
    } else {
      cout << "Nao esta na forma indicada" << endl;
    }

    for (int i = 0; i < l; i++) {
      delete[] matriz[i];
    }
    delete[] matriz;
  }
};

int main() {
  Comandos functions;
  int option = 0;
  cin >> option;
  switch (option) {
  case 0:
    break;
  case 1:
    functions.Exemplo1211();
    break;
  case 2:
    functions.Exemplo1212();
    break;
  case 3:
    functions.Exemplo1213();
    break;
  case 4:
    functions.Exemplo1214();
    break;
  case 5:
    functions.Exemplo1215();
    break;
  case 6:
    functions.Exemplo1216();
    break;
  case 7:
    functions.Exemplo1217();
    break;
  case 8:
    functions.Exemplo1218();
    break;
  case 9:
    functions.Exemplo1219();
    break;
  case 10:
    functions.Exemplo1220();
    break;
  case 11:
    functions.Exemplo12E1();
    break;
  case 12:
    functions.Exemplo12E2();
    break;
  default:
    break;
  }
}
