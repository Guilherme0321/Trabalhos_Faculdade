#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <cmath>

using namespace std;

class Grafo {
private:
    unordered_map<int, tuple<int, int, int>> vertices;
    unordered_map<int, vector<pair<int, double>>> arestas;

public:
    void adicionarVertice(int id, tuple<int, int, int> cor){
        vertices[id] = cor;
    }

    void adicionarAresta(int v1, int v2, double peso){
    // Adiciona apenas se a aresta não existir
        auto& arestasV1 = arestas[v1];
        auto it = find_if(arestasV1.begin(), arestasV1.end(), 
                        [v2](const pair<int, double>& p) { return p.first == v2; });
        
        if (it == arestasV1.end()) {
            arestas[v1].emplace_back(v2, peso);
            arestas[v2].emplace_back(v1, peso);
        }
    }

    static double calcularPeso(const tuple<int, int, int>& p1, const tuple<int, int, int>& p2){
        return sqrt(pow(get<0>(p1) - get<0>(p2), 2) +
                    pow(get<1>(p1) - get<1>(p2), 2) +
                    pow(get<2>(p1) - get<2>(p2), 2));
    }

    const unordered_map<int, tuple<int, int, int>>& getVertices() const {
        return vertices;
    }

    const unordered_map<int, vector<pair<int, double>>>& getArestas() const {
        return arestas;
    }
    
    int contarArestas() const {
        int totalArestas = 0;
        for (const auto& par : arestas) {
            totalArestas += par.second.size();
        }
        return totalArestas / 2; //dividir por 2 pois cada aresta incide em 2 vertices, entao nao precisa contar 2 vezes
    }
};

#endif
