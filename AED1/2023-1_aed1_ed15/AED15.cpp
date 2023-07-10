#include <iostream>
#include <string>
using namespace std;

class push{
  private:
    char* n;
    char novo;
    int t;
  public:
    push(char* x, char n, int t){
      this->n = x;
      this->novo = n;
      this->t = t;
    }
    void push_back(){
      char *novoN = new char[t+1];
      for(int i = 0; i < t; i++){
        novoN[i] = n[i];
      }
      novoN[t-1] = novo;
      novoN[t] = '\0';
      delete[] n;
      n = novoN;
    }
  void take_back(){
    char *novoN = new char[t-1];
    for(int i = 0; i < t-2; i++){
      novoN[i] = n[i];
    }
    novoN[t-1] = '\0';
    delete [] n;
    n = novoN;
  }

  void push_front(){
    char *novoN = new char[t+1];
    novoN[0] = novo;
    for(int i = 1; i <= t; i++){
      novoN[i] = n[i-1];
    }
    delete [] n;
    n = novoN;
  }

  char *getChar(){
    return this->n;
  }

  void shift(){
    char *novoN = new char[t-1];
    for(int i = 0; i < t-2; i++){
      novoN[i] = n[i];
    }
    novoN[t-1] = '\0';
    delete [] n;
    n = novoN;
  }
  int search(){
    for(int i = 0; i < t; i++){
      if(n[i] == novo){
        return i;
      }
    }
    return 0;
  }
};

class separador{
  private:
    int length;
    char *newChar;
  public:
    separador(){
      this->length = 0;
      this->newChar = nullptr;
    }
    char* separar(char* s,char sep){
      this->length = 0;
      while(s[length] != '\0' && s[length] != sep){
        length++;
      }
      char *newS = new char[length+1];
      for(int i = 0; i < length; i++){
        newS[i] = s[i];
      }
      newS[length] = '\0';
      delete[] newChar;
      newChar = newS;
      return newChar;
    }
};

void q01(){
  char *x = new char[5];
  char y[5] = "_ola";
  for(int i = 0; i < 5; i++){
    x[i] = y[i];
  }
  push p(x,'8',5);
  p.push_back();
  cout << p.getChar() << endl;
  delete [] x;
}

void q02(){
  char *a = new char[6];
  char y[6] = "_ola_";
  for(int i = 0; i < 6; i++){
    a[i] = y[i];
  }
  push p(a,'_',6);
  p.take_back();
  cout << p.getChar() << endl;
  delete [] a;
}

void q03(){
  char *a = new char[8];
  char y[8] = "__gui__";
  for(int i = 0; i < 8; i++){
    a[i] = y[i];
  }
  push p(a,'7',8);
  p.push_front();
  cout << p.getChar() << endl;
}

void q04(){
  char *a = new char[9];
  char y[9] = "__arth__";
  for(int i = 0; i < 9; i++){
    a[i] = y[i];
  }
  push p(a,'7',9);
  p.shift();
  cout << p.getChar() << endl;
  delete [] a;
}

void q05(){
  char *a = new char[9];
  char y[9] = "__aaua__";
  for(int i = 0; i < 9; i++){
    a[i] = y[i];
  }
  push pu(a,'u',9);
  int p = pu.search();
  if(p != 0){
    cout << "posicao: " << p << endl;
  }else{
    cout << "Nao existe" << endl;
  }
}

void q06(){
  separador sep;
  char a[14] = "ola, tudo bem";
  char* x = sep.separar(a, ',');
  cout << x << endl;
  delete [] x;
}

template <typename T>

class intArray01{
  public:
    int length;
    T *data;
  intArray01(int length, T *data){
    this->length = length;
    this->data = data;
  }
};

template <typename T>

class intArray02{
  public:
    int length;
    T *data;
  intArray02(int length, T *data){
    this->length = length;
    this->data = data;
  }
};

template <typename T> // para definir o tipo da var somente quando a class for chamada

class compararArray{
  public:
    int* comp(T* a01, T* a02,int length){
      int *resul = new int[length];
      int i = 0;
      int j = 0;
      while(j < length){
      //if(*a01 && *a02){ // se a01 e a02 s�o diferentes de 0 , mas nesse caso n�o � bom, pois
        if(*a01 > *a02){
          resul[i] = -1;
        }else if(*a01 < *a02){
          resul[i] = 1;
        }else{
          resul[i] = 0;
        }
      //}
        a01++; // para ir para o proximo valor do array de a01
        a02++; // mesma coisa que acima, so que para a02
        i++;
        j++;
    }
      return resul;
    }
    void showArray(T * a, int length){
      //while(*a){ nao bom ultilizar neste caso, pois existe 0 no array }
      int i = 0;
      while(i < length){
        cout << *a << " ";
        a++;
        i++;
      }
      cout << endl;
    }
};

void q07(){
  int a[] = {5,9,7,4,3,1,2,6,8};
  int b[] = {1,2,4,5,6,7,3,1,8};
  intArray01<int> a01(9,a);
  intArray02<int> a02(9,b);
  compararArray<int> comp;
  int *resul = nullptr;
  if(a01.length == a02.length){
    resul = comp.comp(a01.data, a02.data,9);
  }else{
    cout << "Tamanhos diferentes!" << endl;
  }
  comp.showArray(resul, a02.length);
  delete [] resul;
  cout << endl;
}

template <typename T>

class concatenar{
  public:
    int* conc(T *a,int len01,T *b,int len02){
      int *concatenado = new int[len01 + len02];
      for(int i = 0; i < len01+len02; i++){
        if(i < len01){
          concatenado[i] = a[i];
        }else{
          concatenado[i] = b[i-len01];
        }
      }
      return concatenado;
    }
    void show(T *a,int len){
      for(int i = 0; i < len; i++){
        cout << a[i] << " ";
      }
      cout << endl;
    }
};

void q08(){
  int a[] = {5,9,7,4,3,1,2,6,8};
  int b[] = {1,2,4,5,6,7,3,1,8};
  intArray01<int> a01(9,a);
  intArray02<int> a02(9,b);
  concatenar<int> concat;
  int *cat = concat.conc(a, 9, b, 9);
  concat.show(cat, 18);
  delete[] cat;
}

template <typename T>

class search{
  private:
    T *a;
    int len;
  public:
    search(T *a, int len){
      this->a = a;
      this->len = len;
    }

    T SearchPor(T busca){
      for(int j = 0; j < len; j++){
        if(a[j] == busca){
            return j;
         }
      }
    }
};

void q09(){
  int a[] = {5,9,7,4,3,1,2,6,8};
  intArray01<int> a01(9,a);
  search<int> sr(a01.data,a01.length);
  int x = 3;
  int retorno = sr.SearchPor(x);
  cout << "Posicao: " << retorno << endl;
}

template <typename T>
class procurar{
  private:
    T* a;
    int len;
  public:
    procurar(intArray01<int> a){
      this->a = a.data;
      this->len = a.length;
    }
    T *procurarBy(T value){
      for(int i = 0; i < len; i++){
        if(a[i] == value){
          return &a[i];
        }
      }
      return NULL;
    }
    void liberar(){
      delete [] a;
    }
};
void q10(){
  int a[] = {2,5,9,7,6,4,3,1};
  intArray01<int> array(8,a);
  procurar<int> search(array);
  int* value = search.procurarBy(1);
  concatenar<int> show;
  show.show(value, 1);
  delete[] value;
}

int main() {
  int op = 0;
  cin >> op;
  switch(op){
    case 0:
      break;
    case 1:
      q01();
      break;
    case 2:
      q02();
      break;
    case 3:
      q03();
      break;
    case 4:
      q04();
      break;
    case 5:
      q05();
      break;
    case 6:
      q06();
      break;
    case 7:
      q07();
      break;
    case 8:
      q08();
      break;
    case 9:
      q09();
      break;
    case 10:
      q10();
      break;
    default:
      break;
  }
  return 0;
}
