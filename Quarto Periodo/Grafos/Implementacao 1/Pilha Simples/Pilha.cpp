#include <iostream>
using namespace std;

class Celula {
public:
    int elemento; 
    Celula* prox; 

    //Construtor sem parâmetros
     Celula() : elemento(0), prox(nullptr) {}

    // Construtor parâmetro elemento
    Celula(int elemento) : elemento(elemento), prox(nullptr) {}
};


class Pilha {
private:
    Celula* topo;

public:
    //cria uma pilha sem elementos.
    Pilha() : topo(nullptr) {}

    // Insere elemento FILO
    void inserir(int x) {
        Celula* tmp = new Celula(x);
        tmp->prox = topo;
        topo = tmp;
    }

    //Remove FILO
    int remover() {
        if (topo == nullptr) {
            throw runtime_error("Erro ao remover!");
        }
        int resp = topo->elemento;
        Celula* tmp = topo;
        topo = topo->prox;
        delete tmp;
        return resp;
    }

    //Mostra do topo
    void mostrar() const {
        cout << "[ ";
        for (Celula* i = topo; i != nullptr; i = i->prox) {
            cout << i->elemento << " ";
        }
        cout << "]" << endl;
    }

    //Mostra em ordem reversa
    void mostraPilha() const {
        mostraPilha(topo);
    }

    //Procura um elemento
    bool contem(int elemento) const {
        for (Celula* i = topo; i != nullptr; i = i->prox) {
            if (i->elemento == elemento) {
                return true;
            }
        }
        return false;
    }

private:
    void mostraPilha(Celula* i) const {
        if (i != nullptr) {
            mostraPilha(i->prox);
            cout << i->elemento << endl;
        }
    }
};

int main() {
    Pilha pilha;
    int n, k, elemento;

    cout << "Quantos elementos deseja inserir na pilha? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Digite o elemento " << i + 1 << ": ";
        cin >> elemento;
        pilha.inserir(elemento);
    }

    pilha.mostrar();

    cout << "Quantos elementos deseja remover da pilha? ";
    cin >> k;

    for (int i = 0; i < k; i++) {
        try {
            cout << "Elemento removido: " << pilha.remover() << endl;
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    pilha.mostrar();

    cout << "Digite um elemento para verificar se esta na pilha: ";
    cin >> elemento;

    if (pilha.contem(elemento)) {
        cout << "Elemento " << elemento << " encontrado" << endl;
    } else {
        cout << "Elemento " << elemento << " nao encontrado" << endl;
    }

    return 0;
}
