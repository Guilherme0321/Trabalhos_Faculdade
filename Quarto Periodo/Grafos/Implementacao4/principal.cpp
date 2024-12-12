#include <iostream>  
#include <fstream>
#include <vector>  
#include <tuple> 
#include <unordered_map>
#include <cmath>        
#include <stdexcept> 
#include "leituraImagem.hpp"
#include "Grafo.hpp"

/* Funcionamento de tie
A função tie permite "desempacotar" os valores retornados por um std::tuple em variáveis já existentes.
*/
using namespace std;

int main() {
    string caminho = "imagem.ppm";
    int largura, altura, max_valor;
    vector<tuple<int, int, int>> pixels;

    try {
        // Ler o arquivo PPM (P6)
        tie(largura, altura, max_valor, pixels) = lerPPM(caminho);

        // Exibir informações da imagem
        cout << "Largura: " << largura << endl;
        cout << "Altura: " << altura << endl;
        cout << "Valor máximo: " << max_valor << endl;

        // Converter para grafo
        Grafo grafo = ppmParaGrafo(largura, altura, pixels);

        // Exibir informações do grafo
        cout << "Vertices: " << grafo.getVertices().size() << endl;
        cout << "Arestas: " << grafo.contarArestas() << endl;
    } 
    catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
