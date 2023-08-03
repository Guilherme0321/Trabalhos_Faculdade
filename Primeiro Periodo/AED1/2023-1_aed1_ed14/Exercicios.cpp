#include <iostream>
using namespace std;

class len{
    private:
        int i;
    public:
        len(){
            this->i = 0;
        }
        int length(string a){
            while(a[i] != '\0'){
                i++;
            }
            return i;
        }
};

class Converter{
    private:
        string numString;
        int numInt;
    public:
        Converter(string num){
            this->numString = num;
            this->numInt = 0;
        }

        void Inicial(){
            stringToInt();
            cout << numInt << endl;
        }

        int len(string words){
            int i = 0;
            while (words[i] != '\0')
            {
                i++;
            }
            return i;
        }

        void stringToInt(){
            for(int i = 0; i < len(numString);i++){
                if('0' <= numString[i] && numString[i] <= '9'){
                    numInt = numInt * 10 + (numString[i]-'0');
                }
            }
        }

        int getInt(){
            return numInt;
        }
};

class toFloat{
    private:
        double floatPart;
        bool ponto;
        string text;
    public:
        toFloat(string texto){
            this->floatPart = 0;
            this->ponto = false;
            this->text = texto;
        }

        double toDouble(){
            float dividir = 10;
            for(char c : text){ // mesma coisa que for i in lista de python mas para caractere
               if(c == '.' && !ponto){ // se o caracter for igual a ponto declara ponto como true
                    ponto = true;
               }else if(isdigit(c)){ // se c for um digito
                    if(!ponto){ // enquanto a variavel ponto for falsa, oq está nesse if será executado ate que ponto seja verdadeiro para que !True = false
                        floatPart = floatPart * 10 + (c-'0'); // ir andando para a esquerda a medida que a quantidade numeros vão sendo lidas
                    }else{
                        floatPart += (c-'0')/dividir;// ir andando para a direita a medida que a quantidade numeros vão sendo lidos
                        dividir *= 10;
                    }
               }else{
                    return 0.0;
               }
            }
            return floatPart;
        }
        void init(){
            double num = toDouble();
            if(num != 0.0){
                cout << num << endl;
            }else{
                cout << "Esse valor é nulo" << endl;
            }
        }
};

class ConverterBollean{
  private:
    bool contido;
    string texto;
  public:
    ConverterBollean(){
      this->contido = false;
      this->texto = "";
    }
    void passarMinusculo(){
      int i = 0;
      while(texto
[i] != '\0'){
        i++;
      }
      for(int j = 0; j < i; j++){
        if('A' <= texto[j] && texto[j] <= 'Z')
        {
          texto[j] += 'a' - 'A';
        }

      }
    }
    void ParaBollean(){
      cin >> texto;
      passarMinusculo();
      if(texto=="t" || texto == "true" || texto=="1"){
      contido = true;
      }else if(texto == "f" || texto == "false" || texto == "0"){
        contido = false;
      }
      cout << "Resultado: " << contido << endl;
    }
};

class VerificarSeContem{
    private:
        string conteudo;
        bool contem;
        string x;
    public:
        VerificarSeContem(){
            this->contem = false;
            this->conteudo = "A parede esta caindo";
            this->x = "";
        }
        bool Contais(string& text){
            len t;
            int tamanho = t.length(conteudo);
            cout << conteudo << endl;
            for(int i = 0; i <= tamanho; i++){
                if(conteudo[i] != ' ' && conteudo[i] != '\0'){
                    x += conteudo[i];
                }else{
                    if(text == x){
                        return true;
                    }else{
                        x = "";
                    }
                }
            }
            return false;
        }
        void principal(){
            string text = "";
            cin >> text;
            bool encontrado = Contais(text);
            if(encontrado){
                cout << "\nencontrado!\n";
            }else{
                cout << "\nnao encontrado!\n";
            }
        }
};

class ToUpperCase{
  private:
    string antes;
    int tamanho;
  public:
    void maiusculas(){
      cin >> antes;
      len();
      for(int i = 0; i < tamanho; i++){
        if('a' <= antes[i] && antes[i] <= 'z'){
        antes[i] -= 'a'-'A';
}
      }
    }
    void len(){
      int i = 0;
      while(antes[i] != '\0'){
        i++;
      }
      tamanho = i;
    }
void principal(){
  maiusculas();
  cout << antes << endl;
}
};

class toLower{
    private:
        string text;
        int tamanho;
    public:
        int len(string texto = ""){
            int t = 0;
            if(texto == ""){
                while(text[t] != '\0'){
                    t++;
                }
            }else{
                while(texto[t] != '\0'){
                    t++;
                }
            }
            return t;
        }
        void tom(){
            tamanho = len();
            for(int i = 0; i < tamanho; i++){
                if('A' <= text[i] && text[i] <= 'Z'){
                    text[i] += 'a' - 'A';
                }
            }
        }
        void principal(){
            cout << "Palavra: ";
            cin >> text;
            tom();
            cout << endl << text << endl;
        }
};

class Substituir{
private:
    string texto;
    int tamanho;
    char antes;
    char depois;
public:
    Substituir(){
        this->texto = "";
        this->tamanho = 0;
    }
    void Replace(){
        toLower len;
        tamanho = len.len(texto);
        for(int i = 0; i < tamanho; i++){
            if(texto[i] == antes){
                texto[i] = depois;
            }
        }
    }
    void principal(){
        cout << "Texto: ";
        cin >> texto;
        cout << "Subtituir: ";
        cin >> antes;
        cout << "Por: ";
        cin >> depois;
        Replace();
        cout << texto;
    }
};

class codificar{
private:
    string texto;
    int tamanho;
public:
    void codigicar(){
        toLower len;
        tamanho = len.len(texto);
        for(int j = 0; j < tamanho; j++){
            if(('a' <= texto[j] && texto[j] <= 'z') || ('A' <= texto[j] && texto[j] <= 'Z')){
                if('x' <= texto[j] && texto[j] <= 'z' || 'X' <= texto[j] && texto[j] <= 'Z'){
                    texto[j] -= 23;
                }else{
                    texto[j] += 3;
                }
            }
        }
    }
    void Principal1(){
        cin >> texto;
        codigicar();
        cout << texto << endl;
    }

    void descodificar(){
        toLower len;
        tamanho = len.len(texto);
        for(int h = 0; h < tamanho; h++){
            if(('a' <= texto[h] && texto[h] <= 'z') || ('A' <= texto[h] && texto[h] <= 'Z')){
                if(('a' <= texto[h] && texto[h] <= 'c') || ('A' <= texto[h] && texto[h] <= 'C')){
                    texto[h] += 23;
                }else{
                    texto[h] -= 3;
                }
            }
        }
    }
    void Principal2(){
        cin >> texto;
        descodificar();
        cout << texto << endl;
    }
};

class separar{
private:
    string * Palavras;
    string frase;
    int tamanho;
    string passagem;
public:
    separar(){
        this->frase = "";
        this->Palavras = nullptr;
        this->tamanho = 0;
        this->passagem = "";
    }
    int lenght(string text){
        int t = 0;
        while(text[t] != '\0'){
            t++;
        }
        return t;
    }

    string inverter(string y){
        int t = lenght(y);
        string z = y;
        int t0 = 0;
        for(int j = t-1; j >= 0; j--){
            y[j] = z[t0];
            t0++;
        }
        return y;
    }

    void add(string x,string sep = "", bool invertido = false){
        tamanho++;
        string *novaString = new string[tamanho];
        if(invertido){
            x = inverter(x);
        }
        if(sep != "" && x != ""){
            for(int a = 0; a < tamanho -1; a++){
                novaString[a] = Palavras[a];
            }
            if(tamanho == 1){
                novaString[tamanho-1] = x;
            }else{
                novaString[tamanho-1] = sep + ' ' + x;
            }
        }else{
            for(int a = 0; a < tamanho-1; a++){
                novaString[a] = Palavras[a];
            }
            novaString[tamanho-1] = x;
        }
        delete[] Palavras;
        Palavras = novaString;
    }
    void Separar1(){
        int t = lenght(frase);
        passagem = "";
        for(int j = 0; j <= t; j++){ // dessa vez eu coloquei j <= t, pq eu quero que chegue no '\0' para poder testar a condição abaixo
            if(frase[j] != ' ' && frase[j] != '\0'){
                passagem += frase[j];
            }else{
                add(passagem);
                passagem = "";
            }
        }
    }
    void Separar2(){
        int t = lenght(frase);
        passagem = "";
        for(int j = 0; j <= t; j++){
            if(frase[j] != ' ' && frase[j] != '\0'){
                passagem += frase[j];
            }else{
                add(passagem,"|");
                passagem = "";
            }
        }
    }
    void Separar3(){
        int t = lenght(frase);
        passagem = "";
        for(int j = 0; j <= t; j++){
            if(frase[j] != ' ' && frase[j] != '\0'){
                passagem += frase[j];
            }else{
                add(passagem,"",true);
                passagem = "";
            }
        }
    }
    void printar(){
        for(int j = 0; j < tamanho; j++){
            cout << Palavras[j] << " ";
        }
        cout << endl;
    }
    void principal(){
        cout << "Digite uma frase: ";
        getline(cin,frase);

        Separar1();
        printar();
        delete [] Palavras;
    }
    void principal2(){
        cout << "Digite uma frase: ";
        getline(cin,frase);
        Separar2();
        printar();
        delete [] Palavras;
    }
    void principal3(){
        cout << "Digite uma frase: ";
        getline(cin,frase);
        Separar3();
        printar();
        delete [] Palavras;
    }
};

int main(){
    Converter conversao("75648");
    toFloat converterFloat("54.4536");
    ConverterBollean toBollean;
    VerificarSeContem contains;
    ToUpperCase upper;
    toLower lower;
    Substituir sub;
    codificar code;
    separar sep;
    int option = -1;
    cout << "Exercicio: ";
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case 0:
        break;
    case 1:
        conversao.Inicial();
        break;
    case 2:
        converterFloat.init();
        break;
    case 3:
        toBollean.ParaBollean();
        break;
    case 4:
        contains.principal();
        break;
    case 5:
        upper.principal();
        break;
    case 6:
        lower.principal();
        break;
    case 7:
        sub.principal();
        break;
    case 8:
        code.Principal1();
        break;
    case 9:
        code.Principal2();
        break;
    case 10:
        sep.principal();
        break;
    case 11:
        sep.principal2();
        break;
    case 12:
        sep.principal3();
        break;
    default:
        break;
    }
}
