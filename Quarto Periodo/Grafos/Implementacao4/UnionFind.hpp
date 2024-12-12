#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


template<typename T>
class UnionFind {
private:
    unordered_map<T, T> parent;
    unordered_map<T, int> rank;
    unordered_map<T, float> maxEdge; 
public:
    UnionFind(vector<T> vertices) {
        for (int i = 0; i < vertices.size(); ++i) {
            T tmp = vertices[i];
            parent[tmp] = tmp;
            rank[tmp] = 1;
            maxEdge[tmp] = 0.0;
        }
    }

    T find(T u) {
        T raiz = parent[u];
        while(parent[raiz] != raiz)
            raiz = parent[raiz];

        while(parent[u] != u) {
            T tmp = parent[u];
            parent[u] = raiz;
            u = tmp;
        }
        return raiz;
    }

    void unionSets(T u, T v, float weight) {
        T rootU = find(u);
        T rootV = find(v);
        
        if (rootU != rootV) {
            if(rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
                maxEdge[rootV] = max({maxEdge[rootU], maxEdge[rootV], weight});
                rank[rootV] += rank[rootU];
            } else {
                parent[rootV] = rootU;
                maxEdge[rootU] = max({maxEdge[rootU], maxEdge[rootV], weight});
                rank[rootU] += rank[rootV];
            }
        } else {
            maxEdge[rootU] = max({weight, maxEdge[rootU]});
        }
    }

    float getMaxEdge(T u) {
        return maxEdge[find(u)];
    }

    void printSets() {
        for (const auto& p : parent) {
            cout << "Elemento " << p.first << " -> Raiz: " << find(p.first)
                 << ", Maior Aresta: " << maxEdge[find(p.first)] << "\n";
        }
    }
};