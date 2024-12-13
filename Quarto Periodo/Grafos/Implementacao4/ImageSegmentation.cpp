#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include "leituraImagem.hpp"
#include "Grafo.hpp"
#include "UnionFind.hpp"

class ImageSegmentation {
private:
    Grafo& graph;
    int width;
    int height;

    struct Edge {
        int source;
        int dest;
        double weight;
        
        Edge(int s, int d, double w) : source(s), dest(d), weight(w) {}
        
        bool operator<(const Edge& other) const {
            return weight < other.weight;
        }
    };

    double pixelDifference(const tuple<int, int, int>& p1, const tuple<int, int, int>& p2) {
        return Grafo::calcularPeso(p1, p2);
    }

public:
    ImageSegmentation(Grafo& g, int w, int h) : graph(g), width(w), height(h) {}

    vector<vector<int>> segment(double threshold = 1.0) {
        vector<Edge> sortedEdges;
        for (const auto& vertexPair : graph.getVertices()) {
            int vertex = vertexPair.first;
            
            for (const auto& neighborPair : graph.getArestas().at(vertex)) {
                int neighbor = neighborPair.first;
                
                if (vertex < neighbor) {
                    double weight = neighborPair.second;
                    sortedEdges.emplace_back(vertex, neighbor, weight);
                }
            }
        }
        
        sort(sortedEdges.begin(), sortedEdges.end());

        vector<int> vertices;
        for (const auto& vertexPair : graph.getVertices()) {
            vertices.push_back(vertexPair.first);
        }
        UnionFind<int> unionFind(vertices);

        for (const Edge& edge : sortedEdges) {
            int u = edge.source;
            int v = edge.dest;
            double weight = edge.weight;

            int rootU = unionFind.find(u);
            int rootV = unionFind.find(v);

            if (rootU != rootV) {
                if (weight < threshold) {
                    unionFind.unionSets(u, v, weight);
                }
            }
        }

        unordered_map<int, vector<int>> components;
        for (const auto& vertexPair : graph.getVertices()) {
            int vertex = vertexPair.first;
            int root = unionFind.find(vertex);
            components[root].push_back(vertex);
        }

        vector<vector<int>> finalSegmentation;
        for (const auto& componentPair : components) {
            finalSegmentation.push_back(componentPair.second);
        }

        return finalSegmentation;
    }

    void saveSegmentationImage(const vector<vector<int>>& segmentation, const string& outputPath) {
        const auto& vertices = graph.getVertices();
        
        vector<tuple<int, int, int>> outputPixels(width * height);
        
        vector<tuple<int, int, int>> componentColors;
        for (size_t i = 0; i < segmentation.size(); ++i) {
            componentColors.push_back({
                static_cast<int>(rand() % 256),
                static_cast<int>(rand() % 256),
                static_cast<int>(rand() % 256)
            });
        }
        
        for (const auto& component : segmentation) {
            int colorIndex = 0;
            for (size_t i = 0; i < segmentation.size(); ++i) {
                if (segmentation[i] == component) {
                    colorIndex = i;
                    break;
                }
            }
            
            for (int pixel : component) {
                outputPixels[pixel] = componentColors[colorIndex];
            }
        }
        
        ofstream outputFile(outputPath, ios::binary);
        if (!outputFile.is_open()) {
            throw runtime_error("Erro ao criar arquivo de saída.");
        }
        
        outputFile << "P6\n" << width << " " << height << "\n255\n";
        
        for (const auto& pixel : outputPixels) {
            outputFile.put(get<0>(pixel));
            outputFile.put(get<1>(pixel));
            outputFile.put(get<2>(pixel));
        }
        
        outputFile.close();
    }

    void printSegmentation(const vector<vector<int>>& segmentation) {
        cout << "Segmentation Results:\n";
        cout << "Number of Components: " << segmentation.size() << "\n";
        for (size_t i = 0; i < segmentation.size(); ++i) {
            cout << "Component " << i + 1 << ": " 
                 << segmentation[i].size() << " pixels\n";
        }
    }
};

int main() {
    try {
        string inputPath = "imagem.ppm";
        int largura, altura, max_valor;
        vector<tuple<int, int, int>> pixels;

        tie(largura, altura, max_valor, pixels) = lerPPM(inputPath);

        Grafo grafo = ppmParaGrafo(largura, altura, pixels);

        ImageSegmentation segmentador(grafo, largura, altura);

        double thresholds[] = {0.1, 0.5, 1, 5, 10.0, 30.0};
        
        for (double threshold : thresholds) {
            cout << "\nSegmentation with Threshold: " << threshold << "\n";
            
            auto segmentacao = segmentador.segment(threshold);
            
            segmentador.printSegmentation(segmentacao);
            
            string outputPath = "./segments/segmentacao_" + to_string(threshold) + ".ppm";
            segmentador.saveSegmentationImage(segmentacao, outputPath);
        }
    } 
    catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }

    return 0;
}