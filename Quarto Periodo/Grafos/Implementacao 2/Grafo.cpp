#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>

class Graph {
private:
  int V;                           // Número de vértices
  std::vector<std::list<int>> adj; // Lista de adjacência

public:
int numeroDeSubgrafos = 0;
  // Construtor
  Graph(int V) {
    this->V = V;
    adj.resize(V);
  }


  // Função para adicionar uma aresta ao grafo
  void addEdge(int v, int w) {
    adj[v].push_back(w); // Adiciona w à lista de v
    adj[w].push_back(
        v); // Adiciona v à lista de w (porque o grafo é não direcionado)
  }

  // Função para criar um grafo completo
  void createCompleteGraph() {
    for (int i = 0; i < V; ++i) {
      for (int j = i + 1; j < V; ++j) {
        addEdge(i, j);
      }
    }
  }

  // Função para imprimir os vértices do grafo
  void printVertices() {
    std::cout << "[";
    for (int i = 0; i < V; ++i) {
      std::cout << i + 1;
      if (i < V - 1)
        std::cout << ", ";
    }
    std::cout << "]" << std::endl;
  }

  // fatorial
  unsigned long long factorial(int num) {
    unsigned long long result = 1;
    for (int i = 1; i <= num; ++i) {
      result *= i;
    }
    return result;
  }

  // combinacao apenas vertices
  unsigned long long combination(int n, int r) {
    if (r == n) {
      return 1; // qnd n=r só tem uma combincacao possivel de vertices
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
  }

  // Função auxiliar para imprimir um vetor de inteiros
  void printVector(const std::vector<int> &vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
      std::cout << vec[i];
      if (i < vec.size() - 1)
        std::cout << ", ";
    }
    std::cout << "]";
  }

  // Função auxiliar para imprimir as arestas de um subgrafo
  void printEdges(const std::vector<std::pair<int, int>> &edges,
                  const std::vector<bool> &include) {
    std::cout << "{";
    bool first = true;
    for (size_t i = 0; i < edges.size(); ++i) {
      if (include[i]) {
        if (!first)
          std::cout << ", ";
        std::cout << "(" << edges[i].first << ", " << edges[i].second << ")";
        first = false;
      }
    }
    std::cout << "}";
  }

  // Função para gerar e imprimir todos os subgrafos e suas combinações de
  // arestas
  void printAllSubgraphs() {
    std::vector<int> vertices(V);
    for (int i = 0; i < V; ++i) {
      vertices[i] = i + 1; // Preenche o vetor com os vértices [1, 2, 3, ..., V]
    }

    // Gerar todos os subgrafos para r variando de 1 até V
    for (int r = 1; r <= V; ++r) {
      std::cout << "Subgrafos com r = " << r << ":" << std::endl;
      std::vector<bool> select(r, true); // Seleciona os primeiros r elementos
      select.resize(V, false);           // Preenche o resto com falso

      do {
        std::vector<int> subgraph;
        for (int i = 0; i < V; ++i) {
          if (select[i]) {
            subgraph.push_back(vertices[i]);
          }
        }

        // Gerar todas as combinações de arestas para o subgrafo
        std::vector<std::pair<int, int>> possibleEdges;
        for (size_t i = 0; i < subgraph.size(); ++i) {
          for (size_t j = i + 1; j < subgraph.size(); ++j) {
            possibleEdges.push_back({subgraph[i], subgraph[j]});
          }
        }

        // Gerar todas as combinações de inclusão de arestas
        int totalCombinations = std::pow(2, possibleEdges.size());
        for (int i = 0; i < totalCombinations; ++i) {
          std::vector<bool> include(possibleEdges.size(), false);
          for (size_t j = 0; j < possibleEdges.size(); ++j) {
            if (i & (1 << j)) {
              include[j] = true;
            }
          }
          printVector(subgraph);
          std::cout << " ";
          printEdges(possibleEdges, include);
          numeroDeSubgrafos++;
          std::cout << std::endl;
        }
      } while (std::prev_permutation(select.begin(), select.end()));
    }
  }
};

int main() {

  int n;
  std::cout << "n (vertices): ";
  std::cin >> n;

  Graph g(n);

  g.createCompleteGraph();

  g.printVertices();
  g.printAllSubgraphs();
std::cout << "Numero de subgrafos: " << g.numeroDeSubgrafos;    


  return 0;
}
