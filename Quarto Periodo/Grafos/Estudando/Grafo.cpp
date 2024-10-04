#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include "Heap.hpp"

using namespace std;

class Grafo {
private:
    vector<vector<pair<float, int>>> grafo;
    int numV;
public:
    Grafo(int v){
        this->grafo.resize(v);
        this->numV = v;
    }

    bool validVertice(int v) {
        return v >= 0 && v < numV;
    }

    void setAresta(int v1, int v2, float weight) {
        if(v1 >= 0 && v1 < numV && v2 >= 0 && v2 < numV) {
            this->grafo[v1].push_back({weight, v2});
        }
    }

    vector<int> buscaLargura(int v) {
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
                    int h = grafo[temp][i].second;
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
                    int h = grafo[temp][i].second;
                    if(!visitados[h]) {
                        visitados[h] = true;
                        pilha.push(h);
                    }
                }
            }
        }
        return result;
    }

    /**
     * @brief Calcula a distancia entre um determinado vertice e todos os outros para um grafo CONEXO com PESOS POSITIVOS.
     * 
     * Recebe como parametro o vertice de inicio.
     * 
     * @param int
     * @return vector com a distancia entre todos os vertices
    */
    vector<float> dijkstra(int ini) {
        Heap heap;
        vector<float> dist(numV, numeric_limits<float>::infinity());
        dist[ini] = 0.0;
        heap.push({0.0, ini});

        while(!heap.empty()) {
            int u = heap.top().second;
            int peso = heap.top().first;
            heap.pop();
            
            for(pair<float, int> edge : grafo[u]) {
                int v = edge.second;
                float weight = edge.first;
                if(weight + dist[u] < dist[v]) {
                    dist[v] = weight + dist[u];
                    heap.push({dist[v], v});
                }
            }
            heap.heapifyDown();
        }
        return dist;
    }

    float max(float i, float j) {
        return (i > j) ? i : j;
    }

    float min(float i, float j) {
        return (i < j) ? i : j;
    }

    vector<int> loadGrausEntrada() {
        vector<int> graus(numV, 0);
        for(int i = 0; i < numV; i++) {
            for(int j = 0; j < grafo[i].size(); j++) {
                graus[grafo[i][j].second]++;
            }
        }
        return graus;
    }

    // forma de resolver a questão de nao sair do vertice ate vizitar todas as arestas de entrada, somar o grau com o peso

    vector<float> MaxMin(int inicio) {
        Heap heap;
        vector<float> cap(numV, -numeric_limits<float>::infinity());
        vector<bool> visitados(numV, false);
        cap[inicio] = numeric_limits<float>::infinity();
        heap.push({cap[inicio], inicio});
        while(!heap.empty()) {
            int u = heap.top().second;
            visitados[u] = true;
            heap.pop();

            for(pair<float, int> temp : grafo[u]) {
                int v = temp.second;

                if(!visitados[v]) {
                    int minWeight = min(cap[u], temp.first);

                    if(minWeight > cap[v]) {
                        cap[v] = minWeight;
                    }
                    heap.push({cap[v], v});
                }
            }
            heap.heapifyUp();
        }
        return cap;
    }

    vector<float> MinMax(int inicio) {
        Heap heap;
        vector<float> cap(numV, numeric_limits<float>::infinity());
        vector<bool> visitados(numV, false);
        cap[inicio] = -numeric_limits<float>::infinity();
        heap.push({cap[inicio], inicio});
        while(!heap.empty()) {
            int u = heap.top().second;
            visitados[u] = true;
            heap.pop();

            for(pair<float, int> temp : grafo[u]) {
                int v = temp.second;

                if(!visitados[v]) {
                    int maxWeight = max(cap[u], temp.first);

                    if(maxWeight < cap[v]) {
                        cap[v] = maxWeight;
                    }
                    heap.push({cap[v], v});
                }

            }
            heap.heapifyDown();
        }
        return cap;
    }

    void show() {
        for(int i = 0; i < numV; i++) {
            cout << i << " -> { "; 
            for(int j = 0; j < grafo[i].size(); j++) {
                cout << "<" << grafo[i][j].second << ", " << grafo[i][j].first << "> ";
                if(grafo[i][j].second != grafo[i].back().second) {
                    cout << ", ";
                }
            }
            cout << " }" << endl;
        }
    }
};

int main() {
    Grafo grafo(6);

    grafo.setAresta(0, 1, 3.0);
    grafo.setAresta(0, 2, 5.0);
    grafo.setAresta(0, 3, 4.0);
    grafo.setAresta(1, 4, 7.0);
    grafo.setAresta(1, 5, 5.0);
    grafo.setAresta(1, 2, 1.0);
    grafo.setAresta(2, 4, 2.0);
    grafo.setAresta(3, 2, 2.0);
    grafo.setAresta(5, 4, 8.0);

    grafo.show();

    cout << endl;

    cout << "Grau de entrada dos vertices" << endl;
    for(int i : grafo.loadGrausEntrada()) {
        cout << i << " ";
    }

    cout << endl;
    int temp = 0;

    cout << "Buscar por profundidade a partir de qual vertice: ";
    cin >> temp;
    cout << endl;

    vector<int> result = grafo.buscaProfundidade(temp);

    for(int i : result) {
        cout << i << " ";
    }
    
    cout << endl;
    
    result = grafo.buscaLargura(temp);

    for(int i : result) {
        cout << i << " ";
    }

    cout << "\nPegar a menor distancia entre de qual vertice para todos os outros: ";
    cin >> temp;
    cout << endl;
    vector<float> dist = grafo.dijkstra(temp);
    for(int i = 0; i < dist.size(); i++) {
        cout << (char)('a' + i) << " ";
    }
    cout << endl;
    for(float i : dist) {
        cout << i << " ";
    }
    
    cout << endl;

    cout << "MaxMin: " << endl;

    vector<float> capa = grafo.MaxMin(0);
    for(float i : capa) {
        cout << i << " ";
    }

    cout << endl << "MinMax: " << endl;

    capa = grafo.MinMax(0);
    for(float i : capa) {
        cout << i << " ";
    }
    

    return 0;
}

