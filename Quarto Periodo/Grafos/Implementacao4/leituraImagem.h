#include <tuple>
#include <vector>
#include <string>
#include "Grafo.h"
#include <fstream>
#include <vector>
#include <tuple>
#include <stdexcept>

using namespace std;

/*
A leitura do arquivo PPM será realizada usando std::ifstream. Cada pixel será armazenado como uma tupla de três inteiros
para representar os valores RGB.


Vou explicar detalhadamente o cálculo do índice indice = y * largura + x
Este é um método padrão de mapeamento de coordenadas 2D (x, y) para um índice linear 1D em um array ou vetor.
Funciona da seguinte forma:
y * largura faz o "pulo" para a linha correta:
Cada linha completa tem largura pixels
Multiplicar y por largura "pula" todas as linhas anteriores
*/

// Função para ler um arquivo PPM no formato P6
tuple<int, int, int, vector<tuple<int, int, int>>> lerPPM(string &caminho)
{
    ifstream arquivo(caminho, ios::binary);
    if (!arquivo.is_open())
    {
        throw runtime_error("Erro ao abrir o arquivo PPM.");
    }

    // Ler o cabeçalho
    string tipo;
    arquivo >> tipo;
    if (tipo != "P6")
    {
        throw runtime_error("Formato PPM não suportado. Apenas P6 é aceito.");
    }

    int largura, altura, max_valor;
    arquivo >> largura >> altura >> max_valor;

    // Ignorar o caractere de nova linha após o cabeçalho
    arquivo.ignore();

    // Ler os dados binários dos pixels
    vector<tuple<int, int, int>> pixels(largura * altura);
    for (int i = 0; i < largura * altura; ++i)
    {
        unsigned char r, g, b;
        arquivo.read(reinterpret_cast<char *>(&r), 1);
        arquivo.read(reinterpret_cast<char *>(&g), 1);
        arquivo.read(reinterpret_cast<char *>(&b), 1);
        pixels[i] = {r, g, b};
    }

    arquivo.close();
    return {largura, altura, max_valor, pixels};
}

Grafo ppmParaGrafo(int largura, int altura, const vector<tuple<int, int, int>> &pixels)
{
    Grafo grafo;

    // Adicionar vértices
    for (int y = 0; y < altura; ++y)
    {
        for (int x = 0; x < largura; ++x)
        {
            int indice = y * largura + x;
            grafo.adicionarVertice(indice, pixels[indice]);
        }
    }

    // Adicionar arestas com pesos
    for (int y = 0; y < altura; ++y)
    {
        for (int x = 0; x < largura; ++x)
        {
            int indice = y * largura + x;

            // Vértices vizinhos
            if (x + 1 < largura){ // Vizinho à direita
                int vizinho = y * largura + (x + 1);
                double peso = Grafo::calcularPeso(pixels[indice], pixels[vizinho]);
                grafo.adicionarAresta(indice, vizinho, peso);
            }
            if (y + 1 < altura){ // Vizinho abaixo
                int vizinho = (y + 1) * largura + x;
                double peso = Grafo::calcularPeso(pixels[indice], pixels[vizinho]);
                grafo.adicionarAresta(indice, vizinho, peso);
            }
        }
    }

    return grafo;
}
