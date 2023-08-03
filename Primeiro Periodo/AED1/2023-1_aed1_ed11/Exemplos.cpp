#include <fstream> //biblioteca para importar os comandos para escrever no arquivo
#include <iostream>
#include <random> // biblioteca para poder usar as funções de geração de numeros aleatorios

using namespace std; // usado para não precisar escrever std: antes de cin e
                     // cout e outros comandos

class arquivo {
private:
  int teste = 0;

public:
  int maior(int *a, int tamanho, string executer) {
    if (executer == "maior") {
      for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
          if (a[i] >= a[j]) {
            teste += 1;
          }
          if (teste == tamanho) {
            return a[i];
          }
        }
        teste = 0;
      }
      return 0;
    } else if (executer == "menor") {
      for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
          if (a[i] <= a[j]) {
            teste += 1;
          }
          if (teste == tamanho) {
            return a[i];
          }
        }
        teste = 0;
      }
      return 0;
    }
  }

  int *lerValores(string archive) {
    ifstream a(archive);
    string x;
    int t = 0;
    a >> x >> t;
    int *vetor = nullptr; // significa: sem local
    vetor = new int[t];
    for (int i = 0; i < t; i++) {
      a >> vetor[i];
    }

    a.close();
    return vetor;
  }

  int *somarArray(int *a, int t, int p1, int p2) {
    int r = 0;
    int q = 0;
    for (int i = 0; i < t; i++) {
      if (p1 > p2 && p2 <= a[i] && a[i] <= p1 ||
          p2 > p1 && p1 <= a[i] && a[i] <= p2) {
        r += a[i];
        q++;
      }
    }
    int *valores = new int[r * q];
    valores[0] = r;
    valores[1] = q;

    return valores;
  }

  float media(int v, int t) {
    float media1 = v / t;
    return media1;
  }
  int tamanho(string x) {
    string y;
    int tamanho = 0;
    ifstream ar(x);
    ar >> y >> tamanho;
    ar.close();
    return tamanho;
  }
  int *testarPositivios(int *a, int t) {
    int *x = new int[t];
    int c = 0;

    for (int i = 0; i < t; i++) {
      if (a[i] > 0) {
        x[c] = a[i];
        c++;
      }
    }
    teste = c;
    return x;
  }
  int ValorC() { return teste; }

  int Crescente(int *x, int tamanho) {
    teste = 0;
    for (int i = 0; i < tamanho - 1; i++) {
      if (x[i] < x[i + 1]) {
        teste++;
      }
    }
    if (teste == tamanho - 1) {
      return true;
    } else {
      return false;
    }
  }

  int procurar(string ar, int p1, int p2, int v) {
    bool y = false;
    int *x = lerValores(ar);
    int a = tamanho(ar);
    for (int i = 0; i < a; i++) {
      if ((v == x[i]) && ((p1 > p2) && (p2 <= v) && (v <= p1)) ||
          (v == x[i]) && ((p2 > p1) && p1 <= v && v <= p2)) {
        y = true;
      }
    }
    delete[] x;
    return y;
  }

  int* LerLocal(string b, int p1, int p2, int c){
    int t = tamanho(b);
    ifstream dados(b);
    int *x = new int[t];
    string a; int y;
    dados >> a >> y;
    y = 0;
    for(int i = 0; i < t; i++){
      dados >> teste;
      if((p1 > p2) && (p2 <= teste && teste <= p1) || (p2 > p1) &&  (p1 <= teste && teste <= p2)){
        x[y] = teste;
        y++;
      }
    }
    for(int i = 0; i < y; i++){
      x[i] *= c;
    }
    dados.close();
    teste = y;
    return x;
  }
  int* analisar(int* array,int t){
    int before = 0;
    for(int i = 0; i < t; i++){
      for(int j = 0; j < t; j++){
        if(array[i] < array[j]){
          before = array[i];
          array[i] = array[j];
          array[j] = before;
        }
      }
    }
  return array;
  }

  bool compararARRAY(int *x, int *y,int t1,int t2){
    if(t1 == t2){
      teste = 0;
      for(int i = 0; i < t1; i++){
          if(x[i] == y[i]){
            teste++;
          }
      }
      if(teste == t1){
        return true;
      }
    }
    delete[] x;
    delete[] y;
    return false;
  }

  int* analisarPosition(string x,string y){
    int *arquivo01 = lerValores(x);
    int *arquivo02 = lerValores(y);
    int t1 = tamanho(x);
    int t2 = tamanho(y);
    if(t1 == t2){
      int* infos = new int[t1];
      for(int i = 0; i < t1; i++){
        if(arquivo01[i] == arquivo02[i]){
          infos[i] = 1;
        }else{
          infos[i] = 0;
        }
      }
    delete[] arquivo01;
    delete[] arquivo02;
    teste = t1;
    return infos;
    }else{
      return 0;
    }
  }
};

void FileWrite(int Q, int *a) {
  ofstream t("DADOS.txt");
  t << "Tamanho: " << Q << endl;
  for (int i = 0; i < Q; i++) {
    t << a[i] << endl;
  }

  t.close();
}

int *Aleatorio(int q) {
  int *a = nullptr;
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(1, 10);
  a = new int[q]; // semelhante ao malloc de c
  for (int i = 0; i < q; i++) {
    a[i] = uni(rng);
  }
  return a;
}

void Exemplo1111() {
  int Q = 0;
  int *a = nullptr;
  cin >> Q;
  a = Aleatorio(Q);
  FileWrite(Q, a);
  delete[] a; // libera a memoria, semelhante ao free()
}

void Exemplo1112() {
  ifstream a("DADOS.txt"); // abre para ler o arquivo
  string text;
  int t = 0;
  int *n = nullptr;
  a >> text;
  a >> t;

  n = new int[t];
  for (int i = 0; i < t; i++) {
    a >> n[i];
  }
  a.close();
  arquivo a1;
  int resul = a1.maior(n, t, "maior");

  cout << "O maior numero eh: " << resul;
  cout << endl;
  delete[] n;
}

void Exemplo1113() {
  ifstream a("DADOS.txt");
  string x;
  int t = 0;
  a >> x;
  a >> t;
  int *n = nullptr;
  n = new int[t];
  for (int i = 0; i < t; i++) {
    a >> n[i];
  }
  a.close();
  arquivo a1;
  int r = a1.maior(n, t, "menor");
  cout << "O menor numero eh: " << r;
  cout << endl;
  delete[] n;
}

void Exemplo1114() {
  arquivo x;
  string z;
  int *num = nullptr;
  num = x.lerValores("DADOS.txt");
  ifstream y("DADOS.txt");
  int t = 0;
  y >> z >> t;
  y.close();
  int p1 = 0, p2 = 0;
  cout << "posicao 1: ";
  cin >> p1;
  cout << endl << "posicao 2: ";
  cin >> p2;
  int *soma = x.somarArray(num, t, p1, p2);
  cout << "A soma dos valores eh: " << soma[0];
  cout << endl;
  delete[] num;
  delete[] soma;
}

void Exemplo1115() {
  string y;
  int tamanho = 0;
  ifstream ar("DADOS.txt");
  ar >> y >> tamanho;
  ar.close();

  int p1 = 0, p2 = 0;

  cout << "posicao 1: ";
  cin >> p1;
  cout << endl << "posicao 2: ";
  cin >> p2;

  arquivo x;
  int *num = x.lerValores("DADOS.txt");
  int *values = x.somarArray(num, tamanho, p1, p2);
  float media = x.media(values[0], values[1]);
  cout << media;
  cout << endl;
  delete[] num;
  delete[] values;
}

void Exemplo1116() {
  arquivo a;
  int *ar = a.lerValores("DADOS.txt");
  int t = a.tamanho("DADOS.txt");
  int *vTestados = a.testarPositivios(ar, t);
  cout << "Valores Testados e passaram: " << endl;
  t = a.ValorC();
  for (int i = 0; i < t; i++) {
    cout << vTestados[i] << endl;
  }
  delete[] ar;
  delete[] vTestados;
}

void Exemplo1117() {
  arquivo a;
  int *teste = a.lerValores("DADOS.txt");
  int t = a.tamanho("DADOS.txt");
  bool ordenado = a.Crescente(teste, t);
  if (ordenado == true) {
    cout << "Esta em ordem crescente" << endl;
  } else {
    cout << "Não esta em ordem crescente";
  }
}

void Exemplo1118() {
  int p1 = 0, p2 = 0;
  int n = 0;
  cout << "Digite uma intervalo: " << endl;
  cin >> p1;
  cin >> p2;
  cout << "Numero que deseja procurar: ";
  cin >> n;
  arquivo a;
  bool testar = a.procurar("DADOS.txt", p1, p2, n);
  if (testar == true) {
    cout << endl << n << " esta no arquivo";
  } else {
    cout << endl << n << " nao esta no arquivo";
  }
}

void Exemplo1119(){
  int p1 = 0, p2 = 0;
  cout << "Digite um intervalo: ";
  cin >> p1 >> p2;
  cout << "Digite a constante que deseja multiplicar ";
  int c = 0;
  cin >> c;
  arquivo a;
  int *x = a.LerLocal("DADOS.txt",p1,p2,c);
  int t = a.ValorC();
  for(int i = 0; i < t; i++){
    cout << x[i] << endl;
  }
  delete[] x;
}

void Exemplo1120(){
  int item1 = 0, item = 2;
  arquivo a;
  int *x = a.lerValores("DADOS.txt");
  int t = a.tamanho("DADOS.txt");
  x = a.analisar(x, t);
  cout << endl;
  for(int i = 0; i < t; i++){
    cout << x[i] << endl;
  }
  delete[] x;
}

void Exemplo11E1(){
  arquivo a;
  int* x = a.lerValores("DADOS.txt");
  int *y = a.lerValores("DADOS1.txt");
  int t = a.tamanho("DADOS.txt");
  int t1 = a.tamanho("DADOS1.txt");
  bool z = a.compararARRAY(x, y, t, t1);
  if(z){
    cout << endl << "Sao de iguais";
  }else{
    cout << endl << "Sao diferentes";
  }
}

void Exemplo11E2(){
  arquivo a;
  int *x = a.analisarPosition("DADOS.txt","DADOS1.txt");
  int t = a.ValorC();
  for(int i = 0; i < t; i++){
    if(x[i] != 1){
      cout << endl << "Sao diferentes na posicao: " << i << endl;
    }
  }
  delete[] x;
}

int main() {
  int option = 0;
  cin >> option;
  switch (option) {
  case 0:
    break;
  case 1:
    Exemplo1111();
    break;
  case 2:
    Exemplo1112();
    break;
  case 3:
    Exemplo1113();
    break;
  case 4:
    Exemplo1114();
    break;
  case 5:
    Exemplo1115();
    break;
  case 6:
    Exemplo1116();
    break;
  case 7:
    Exemplo1117();
    break;
  case 8:
    Exemplo1118();
    break;
  case 9:
    Exemplo1119();
    break;
  case 10:
    Exemplo1120();
    break;
  case 11:
    Exemplo11E1();
    break;
  case 12:
    Exemplo11E2();
    break;
  default:
    break;
  }
}
