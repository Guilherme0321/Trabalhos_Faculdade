#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <algorithm>
#include "UnionFind.hpp"
#include "Heap.hpp"

using namespace std;

class Edge {
public:
    int u, v;
    float w;
    
    Edge(int u, int v, float w) : u(u), v(v), w(w){}

    bool operator<(Edge edge) {
        return w < edge.w;
    }

    string toString() {
        return "< " + to_string(u) + ", " + to_string(v) + ", " + to_string(w) + " >";
    }
};

class Grafo {
private:
    vector<vector<pair<float, int>>> grafo;
    int numV;
    bool isDirected;
public:
    Grafo(int v, bool isDirected = false){
        this->grafo.resize(v);
        this->numV = v;
        this->isDirected = isDirected;
    }

    int quantityVertices() {
        return numV;
    }

    bool validVertice(int v) {
        return v >= 0 && v < numV;
    }

    void setAresta(int v1, int v2, float weight) {
        if(v1 >= 0 && v1 < numV && v2 >= 0 && v2 < numV) {
            if(isDirected) {
                this->grafo[v1].push_back({weight, v2});
            } else {
                this->grafo[v1].push_back({weight, v2});
                this->grafo[v2].push_back({weight, v1});
            }
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

    vector<Edge> toEdgeVector() {
        vector<Edge> edges;
        for(int u = 0; u < numV; u++) {
            for(pair<float, int> v : grafo[u]) {
                edges.push_back({u, v.second, v.first});
            }
        }
        return edges;
    }

    Grafo kruskalMST() {
        vector<Edge> edges = toEdgeVector();
        sort(edges.begin(), edges.end());

        UnionFind unionfind(numV);

        Grafo grafo(numV);
        for(Edge edge : edges) {
            int u = unionfind.find(edge.u);
            int v = unionfind.find(edge.v);
            if(u != v) {
                unionfind.unionSets(edge.u, edge.v);
                grafo.setAresta(edge.u, edge.v, edge.w);
            }
        }
        return grafo;
    }

    Grafo primMST(int inicial) {
        Grafo mst(numV);
        if(validVertice(inicial)) {
            Heap heap;
            vector<int> parent(numV, -1);
            vector<bool> visited(numV, false);
            vector<float> dist(numV, numeric_limits<float>::infinity());
            dist[inicial] = 0;
            heap.push({0, inicial});
            
            while(!heap.empty()) {
                int u = heap.top().second;
                heap.pop();
                heap.heapifyUp();
                visited[u] = true;

                cout << "analisando: " << u << endl;
                for(pair<float, int> edge : grafo[u]) {
                    int v = edge.second;
                    int w = edge.first;
                    if(!visited[v] && w < dist[v]) {
                        dist[v] = w;
                        heap.push({w, v});
                        cout << "< " << u << ", " << v  << ", " << w << ">" << endl;
                        parent[v] = u;
                        cout << endl;
                    }
                    cout << "0 1 2 3 4 5" << endl;
                    for(float i : dist) {
                        cout << i << " ";
                    }
                    cout << endl;
                    for(bool i : visited) {
                        cout << i << " ";
                    }
                    cout << endl <<  endl;

                }
            }
            for(int i = 0; i < numV; i++) {
                if(parent[i] != -1) {
                    mst.setAresta(parent[i], i, dist[i]);
                }
            }
        }
        return mst;
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