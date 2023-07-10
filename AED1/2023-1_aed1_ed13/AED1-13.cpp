#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Exemplo1311 {
private:
  string nome;

public:
  void ler() { getline(cin, nome); }
  string getNome() { return nome; }
  void testarValor() {
    ler();
    if (!nome.empty()) {
      cout << "Nome: " << nome << endl;
    } else {
      cout << "Nenhum nome emcontrado";
    }
  }
};

class Exemplo1312 : public Exemplo1311 {
private:
  string celular;

public:
  void value_cell(string n) { this->celular = n; }
  string cellValue() {
    ler();
    celular = getNome();
    return celular;
  }
  string getCelular() { return celular; }
  void testarcelular() {
    celular = cellValue();
    isTrue();
  }
  void isTrue() {
    if (!celular.empty()) {
      cout << "Celular: " << celular << endl;
    } else {
      cout << "Valor nao encontrado" << endl;
    }
  }
};

class Exemplo1313 : public Exemplo1312 {
public:
  void phoneTrue() {
    int q = 0;
    cout << "Digite um numero de celular: ";
    string test = cellValue();
    for (int i = 0; i < test.length(); i++) {
      if (('0' <= test[i] && test[i] <= '9') || test[i] == '-') {
        q++;
      }
    }
    cout << q << getCelular() << endl;
    if (q == test.length()) {
      cout << "Numero valido!" << endl;
    } else {
      cout << "Numero invalido" << endl;
    }
  }
};

class Exemplo1314 {
private:
  string dados;

public:
  void lerArquivo(string arquivo) {
    string *Storege = nullptr;
    ifstream a(arquivo);
    int i = 0;
    while (a >> dados) {
      i++;
    }
    a.clear();
    a.seekg(0, ios::beg); // ir para o começo do arquivo
    Storege = new string[i];
    for (int j = 0; j < i; j++) {
      a >> dados;
      Storege[j] = dados;
    }

    int q = 0;
    while (q < i) {
      cout << Storege[q] << endl;
      q++;
    }
    delete[] Storege;
    a.close();
  }
};

class Exemplo1315 {
private:
  string nome;
  string idade;

public:
  void getNome() { getline(cin, nome); }
  void getIdade() { getline(cin, idade); }
  void Arquivar(string a) {
    getNome();
    getIdade();
    ofstream ar(a);
    ar << 2 << endl;
    if (!nome.empty() && !idade.empty()) {
      ar << "Nome: " << nome << endl;
      ar << "Idade: " << idade << endl;
    } else {
      cout << "Os valores não existem" << endl;
    }
    ar.close();
  }
};

class Exemplo1316 : public Exemplo1312 {
private:
  string number;

public:
  Exemplo1316(string n) { this->number = n; }
  void iniciar() {
    value_cell(number);
    isTrue(); // redireciona para um metedo de herança vindo do Exemplo1312
  }
};

class Exemplo1317 {
private:
  int quant_tel;
  string *tel;

public:
  Exemplo1317() {
    this->quant_tel = 0;
    this->tel = nullptr;
  }
  void setCell(string novo) { tel[1] = novo; }
  void add(string cell) {
    quant_tel += 1;
    string *cells = new string[quant_tel];

    for (int i = 0; i < quant_tel - 1; i++) {
      cells[i] = tel[i];
    }
    cells[quant_tel - 1] = cell;

    delete[] tel;
    tel = cells;
    cout << endl;
  }
  void mostrar() {
    for (int j = 0; j < quant_tel; j++) {
      cout << j + 1 << ":" << tel[j] << endl;
    }
  }
  void liberar() { delete[] tel; }
};

class Exemplo1318 {
private:
  int q;
  string *numbers;

public:
  Exemplo1318() {
    q = 0;
    numbers = nullptr;
  }

  void escolha() {
    int i = 1;
    while (i != 0) {
      cout << endl << endl;
      cout << "0 - Sair\n1 - Adicionar numero\n2 - Mostrar\nDigite qual: ";
      cin >> i;
      cin.ignore();
      switch (i) {
      case 0:
        liberar();
        break;
      case 1:
        addNumber();
        break;
      case 2:
        mostrar();
        break;
      default:
        break;
      }
    }
  }
  void addNumber(string args = "") {
    q++;
    string num;
    cout << args << endl;
    getline(cin, num);
    string *copy = new string[q];
    if (numbers) {
      for (int i = 0; i < q - 1; i++) {
        if (args.length() > 0) {
          copy[i] = args + ": ";
        }
        copy[i] += numbers[i];
      }
      if (!args.empty()) {
        copy[q - 1] = args + ": " + num;
      } else {
        copy[q - 1] = num;
      }
      delete[] numbers;
    } else {
      copy[0] = num;
    }
    numbers = copy;
  }
  void mostrar() {
    cout << endl;
    for (int i = 0; i < q; i++) {
      cout << i + 1 << ": " << numbers[i] << endl;
    }
  }
  void liberar() { delete[] numbers; }
};

class Exemplo1319 : public Exemplo1317 {
private:
  string newPhone;

public:
  Exemplo1319() { this->newPhone; }
  void mudar2() {
    cout << "Novo valor do segundo celular: ";
    cin >> newPhone;
    cin.ignore();
    setCell(newPhone);
  }
};

class Exemplo1320 {
private:
  string *number;
  int q;

public:
  Exemplo1320() {
    number = nullptr;
    q = 0;
  }
  void mostrar() {
    for (int i = 0; i < q; i++) {
      cout << number[i] << endl;
    }
  }
  void adicionarNum(string cell) {
    q++;
    string *newCell = new string[q];
    if (number) {
      for (int i = 0; i < q - 1; i++) {
        newCell[i] = number[i];
      }
      newCell[q - 1] = cell;
      delete[] number;
    } else {
      newCell[0] = cell;
    }
    number = newCell;
  }
  void deletar2() {
    if (q >= 2) {
      int p = 0;
      string *copy = new string[q - 1];
      for (int i = 0; i < q; i++) {
        if (i != 1) {
          copy[p] = number[i];
          p++;
        }
      }
      delete[] number;
      q--;
      number = copy;
    } else {
      throw runtime_error("Essa posicao nao existe");
    }
  }
  void liberar() { delete[] number; }
};

class Exemplo1321 : public Exemplo1318 {
public:
  void lerQuantity() {
    int ler = 0;
    cout << "Max-10\nPasse a quantidade de numeros: ";
    cin >> ler;
    cin.ignore();
    while (ler > 0 && ler <= 10) {
      addNumber();
      ler--;
    }
    mostrar();
  }
};

class Exemplo1322 {
public:
  void tipoCell() {
    Exemplo1318 contato;
    int type = 1;
    while (type != 0) {
      cout << endl;
      cout << "Escolha um destes:\n0 - Sair\n1 - Residencial\n2 - Profissional\n3 - mostrar lista\nOpcao: ";
      cin >> type;
      getchar();
      switch (type) {
      case 0:
        contato.liberar();
        break;
      case 1:
        contato.addNumber("Residencial");
        break;
      case 2:
        contato.addNumber("Profissional");
        break;
      case 3:
        contato.mostrar();
        break;
      default:
        break;
      }
    }
  }
};

int main() {
  int op = 0;
  cout << "Digite a opcao: ";
  cin >> op;
  cin.ignore();
  Exemplo1311 a;
  Exemplo1312 b;
  Exemplo1313 c;
  Exemplo1314 d;
  Exemplo1315 e;
  Exemplo1316 f("99974-385");
  Exemplo1317 g;
  Exemplo1318 h;
  Exemplo1319 i;
  Exemplo1320 j;
  Exemplo1321 k;
  Exemplo1322 l;
  switch (op) {
  case 0:
    break;
  case 1:
    a.testarValor();
    break;
  case 2:
    b.testarcelular();
    break;
  case 3:
    c.phoneTrue();
    break;
  case 4:
    d.lerArquivo("DADOS.txt");
    break;
  case 5:
    e.Arquivar("Pessoa1.txt");
    break;
  case 6:
    f.iniciar();
    break;
  case 7:
    g.add("99342-593");
    g.add("99743-320");
    g.mostrar();
    g.liberar();
    break;
  case 8:
    h.escolha();
    break;
  case 9:
    i.add("99976-201");
    i.add("99743-543");
    i.mostrar();
    i.mudar2();
    i.mostrar();
    i.liberar();
    break;
  case 10:
    try {
      j.adicionarNum("99563-675");
      j.adicionarNum("92474-103");
      j.adicionarNum("93462-902");
      j.deletar2();
      j.mostrar();
      j.liberar();
    } catch (const exception &error) {
      cout << "Ocorreu um erro: " << error.what() << endl;
    }
    break;
  case 11:
    k.lerQuantity();
    break;
  case 12:
    l.tipoCell();
    break;
  default:
    cout << "Esta opcao nao existe" << endl;
    break;
  }
}
