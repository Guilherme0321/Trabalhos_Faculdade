#include <iostream>
#include <vector>
#include "UnionFind.hpp"

using namespace std;

int main() {
    // Exemplo de uso com strings como vértices
    vector<string> elements = {"A", "B", "C", "D", "E", "F"};
    UnionFind<string> uf(elements);

    // Operações de união com pesos das arestas
    uf.unionSets("A", "B", 3.0); // A --3-- B
    uf.unionSets("B", "C", 5.0); // B --5-- C
    uf.unionSets("D", "E", 2.0); // D --2-- E
    uf.unionSets("E", "F", -1.0); // A --4-- E

    // Imprime os conjuntos e suas maiores arestas
    uf.printSets();

    // Exemplo de obtenção da maior aresta de um conjunto específico
    cout << "Maior aresta no conjunto de 'A': " << uf.getMaxEdge("A") << "\n"; // Deve ser 5

    return 0;
}