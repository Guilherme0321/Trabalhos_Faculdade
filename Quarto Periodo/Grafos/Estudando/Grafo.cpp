#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Grafo {
private:
    vector<vector<int>> grafo;
    int numV;
public:
    Grafo(int v){
        this->grafo.resize(v);
        this->numV = v;
    }

    bool validVertice(int v) {
        return v >= 0 && v < numV;
    }

    void setAresta(int v1, int v2) {
        if(v1 >= 0 && v1 < numV && v2 >= 0 && v2 < numV) {
            this->grafo[v1].push_back(v2);
        }
    }

    vector<int> buscaNivel(int v) {
        vector<int> result;
        if(validVertice(v)) {
            vector<bool> visitados(numV, false);
            queue<int> fila;
            fila.push(v);
            visitados[v] = true;
            while(!fila.empty()) {
                int temp = fila.front();
                fila.pop();
                result.push_back(temp);
                for(int i = 0; i < grafo[temp].size(); i++) {
                    int h = grafo[temp][i];
                    if(!visitados[h]) {
                        visitados[h] = true;
                        fila.push(h);
                    }
                }
            }
        }
        return result;
    }

    vector<int> buscaProfundidade(int v) {
        vector<int> result;
        if(validVertice(v)) {
            vector<bool> visitados(numV, false);
            stack<int> pilha;
            pilha.push(v);
            visitados[v] = true;
            while(!pilha.empty()) {
                int temp = pilha.top();
                pilha.pop();
                result.push_back(temp);
                for(int i = 0; i < grafo[temp].size(); i++) {
                    int h = grafo[temp][i];
                    if(!visitados[h]) {
                        visitados[h] = true;
                        pilha.push(h);
                    }
                }
            }
        }
        return result;
    }

    void show() {
        for(int i = 0; i < numV; i++) {
            cout << i << " -> { "; 
            for(int j = 0; j < grafo[i].size(); j++) {
                cout << grafo[i][j];
                if(grafo[i][j] != grafo[i].back()) {
                    cout << ", ";
                }
            }
            cout << " }" << endl;
        }
    }
};

int main() {
    int v = 0, a = 0;
    cout << "Quantidade de vertices: ";
    cin >> v;
    cout << endl;

    int maxE = (v * (v-1))/2;

/*     cout << "Quantidade de arestas menos que " << maxE << " : ";
    cin >> a;
    cout << endl; */

    Grafo grafo(v);

/*     for(int i = 0; i < a; i++) {
        int v1 = 0, v2 = 0;
        cout << endl << endl;
        grafo.show();
        cout << endl << endl;
        cin >> v1 >> v2;
        grafo.setAresta(v1, v2);
    } */

    grafo.setAresta(0, 1);
    grafo.setAresta(0, 2);
    grafo.setAresta(1, 2);
    grafo.setAresta(1, 3);
    grafo.setAresta(4, 0);

    grafo.show();

    int temp = 0;

    cout << "Buscar por profundidade a partir de qual vertice: ";
    cin >> temp;
    cout << endl;

    vector<int> result = grafo.buscaProfundidade(temp);

    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}

