#include <iostream>
using namespace std;

class Celula {
public:
    int elemento;
    Celula* prox;

    // Construtor sem parâmetros
    Celula() : elemento(0), prox(nullptr) {}

    // Construtor com parâmetro elemento
    Celula(int elemento) : elemento(elemento), prox(nullptr) {}
};

class Fila {
private:
    Celula* primeiro;
    Celula* ultimo;

public:
    // Construtor que cria uma fila vazia
    Fila() : primeiro(nullptr), ultimo(nullptr) {}

    // Insere elemento na fila (FIFO)
    void inserir(int x) {
        Celula* tmp = new Celula(x);
        if (ultimo != nullptr) {
            ultimo->prox = tmp;
        }
        ultimo = tmp;
        if (primeiro == nullptr) {
            primeiro = ultimo;
        }
    }

    // Remove elemento FIFO
    int remover() {
        if (primeiro == nullptr) {
            throw runtime_error("Erro ao remover!");
        }
        int resp = primeiro->elemento;
        Celula* tmp = primeiro;
        primeiro = primeiro->prox;
        if (primeiro == nullptr) {
            ultimo = nullptr;
        }
        delete tmp;
        return resp;
    }

    // Mostra os elementos da fila
    void mostrar() const {
        cout << "[ ";
        for (Celula* i = primeiro; i != nullptr; i = i->prox) {
            cout << i->elemento << " ";
        }
        cout << "]" << endl;
    }

    // Verifica se um elemento está na fila
    bool contem(int elemento) const {
        for (Celula* i = primeiro; i != nullptr; i = i->prox) {
            if (i->elemento == elemento) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Fila fila;
    int n, k, elemento;

    cout << "Quantos elementos deseja inserir na fila? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Digite o elemento " << i + 1 << ": ";
        cin >> elemento;
        fila.inserir(elemento);
    }

    fila.mostrar();

    cout << "Quantos elementos deseja remover da fila? ";
    cin >> k;

    for (int i = 0; i < k; i++) {
        try {
            cout << "Elemento removido: " << fila.remover() << endl;
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    fila.mostrar();

    cout << "Digite um elemento para verificar se esta na fila: ";
    cin >> elemento;

    if (fila.contem(elemento)) {
        cout << "Elemento " << elemento << " encontrado" << endl;
    } else {
        cout << "Elemento " << elemento << " nao encontrado" << endl;
    }

    return 0;
}
