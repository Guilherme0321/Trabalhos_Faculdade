#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <unordered_map>
#include <cstdlib>
#include <ctime>


class Grafo; 


using Pixel = std::tuple<int, int, int>;


template <typename T>
class UnionFind {
private:
    std::unordered_map<T, T> parent;
    std::unordered_map<T, int> rank;
    std::unordered_map<T, double> componentWeight;

public:
    UnionFind(const std::vector<T>& elements) {
        for (const T& elem : elements) {
            parent[elem] = elem;
            rank[elem] = 0;
            componentWeight[elem] = 0.0;
        }
    }

    T find(T x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(T x, T y, double weight) {
        T rootX = find(x);
        T rootY = find(y);

        if (rootX == rootY) return;

        
        if (rank[rootX] < rank[rootY]) {
            std::swap(rootX, rootY);
        }

        parent[rootY] = rootX;
        componentWeight[rootX] += componentWeight[rootY] + weight;

        if (rank[rootX] == rank[rootY]) {
            rank[rootX]++;
        }
    }
};


double calculatePixelDifference(const Pixel& p1, const Pixel& p2) {
    return std::sqrt(
        std::pow(std::get<0>(p1) - std::get<0>(p2), 2) +
        std::pow(std::get<1>(p1) - std::get<1>(p2), 2) +
        std::pow(std::get<2>(p1) - std::get<2>(p2), 2)
    );
}


class Grafo {
private:
    std::unordered_map<int, Pixel> vertices;
    std::unordered_map<int, std::unordered_map<int, double>> edges;

public:
    void addVertex(int id, const Pixel& pixel) {
        vertices[id] = pixel;
    }

    void addEdge(int source, int dest, double weight) {
        edges[source][dest] = weight;
        edges[dest][source] = weight;
    }

    const std::unordered_map<int, Pixel>& getVertices() const { 
        return vertices; 
    }

    const std::unordered_map<int, std::unordered_map<int, double>>& getEdges() const { 
        return edges; 
    }
};


std::tuple<int, int, int, std::vector<Pixel>> readPPM(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file: " + filename);
    }

    std::string magic;
    int width, height, maxVal;
    file >> magic >> width >> height >> maxVal;
    file.ignore(1); 

    std::vector<Pixel> pixels;
    pixels.reserve(width * height);

    for (int i = 0; i < width * height; ++i) {
        unsigned char r, g, b;
        file.read(reinterpret_cast<char*>(&r), 1);
        file.read(reinterpret_cast<char*>(&g), 1);
        file.read(reinterpret_cast<char*>(&b), 1);
        pixels.push_back(std::make_tuple(r, g, b));
    }

    return {width, height, maxVal, pixels};
}


Grafo createGraphFromPPM(int width, int height, const std::vector<Pixel>& pixels) {
    Grafo graph;
    
    
    for (int i = 0; i < width * height; ++i) {
        graph.addVertex(i, pixels[i]);
    }

    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int current = y * width + x;
            
            
            if (x + 1 < width) {
                int right = y * width + (x + 1);
                double weight = calculatePixelDifference(pixels[current], pixels[right]);
                graph.addEdge(current, right, weight);
            }
            
            
            if (y + 1 < height) {
                int bottom = (y + 1) * width + x;
                double weight = calculatePixelDifference(pixels[current], pixels[bottom]);
                graph.addEdge(current, bottom, weight);
            }
        }
    }

    return graph;
}

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

public:
    ImageSegmentation(Grafo& g, int w, int h) : graph(g), width(w), height(h) {}

    std::vector<std::vector<int>> segment(double threshold = 1.0) {
        std::vector<Edge> sortedEdges;
        for (const auto& vertexPair : graph.getVertices()) {
            int vertex = vertexPair.first;
            
            for (const auto& neighborPair : graph.getEdges().at(vertex)) {
                int neighbor = neighborPair.first;
                
                if (vertex < neighbor) {
                    double weight = neighborPair.second;
                    sortedEdges.emplace_back(vertex, neighbor, weight);
                }
            }
        }
        
        std::sort(sortedEdges.begin(), sortedEdges.end());

        std::vector<int> vertices;
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

        std::unordered_map<int, std::vector<int>> components;
        for (const auto& vertexPair : graph.getVertices()) {
            int vertex = vertexPair.first;
            int root = unionFind.find(vertex);
            components[root].push_back(vertex);
        }

        std::vector<std::vector<int>> finalSegmentation;
        for (const auto& componentPair : components) {
            finalSegmentation.push_back(componentPair.second);
        }

        return finalSegmentation;
    }

    void saveSegmentationImage(const std::vector<std::vector<int>>& segmentation, 
                                const std::string& outputPath) {
        const auto& vertices = graph.getVertices();
        
        std::vector<Pixel> outputPixels(width * height);
        
        std::vector<Pixel> componentColors;
        std::srand(std::time(nullptr)); 
        for (size_t i = 0; i < segmentation.size(); ++i) {
            componentColors.push_back(std::make_tuple(
                std::rand() % 256,
                std::rand() % 256,
                std::rand() % 256
            ));
        }
        
        for (size_t colorIndex = 0; colorIndex < segmentation.size(); ++colorIndex) {
            for (int pixel : segmentation[colorIndex]) {
                outputPixels[pixel] = componentColors[colorIndex];
            }
        }
        
        std::ofstream outputFile(outputPath, std::ios::binary);
        if (!outputFile.is_open()) {
            throw std::runtime_error("Error creating output file.");
        }
        
        outputFile << "P6\n" << width << " " << height << "\n255\n";
        
        for (const auto& pixel : outputPixels) {
            outputFile.put(std::get<0>(pixel));
            outputFile.put(std::get<1>(pixel));
            outputFile.put(std::get<2>(pixel));
        }
        
        outputFile.close();
    }

    void printSegmentation(const std::vector<std::vector<int>>& segmentation) {
        std::cout << "Segmentation Results:\n";
        std::cout << "Number of Components: " << segmentation.size() << "\n";
        for (size_t i = 0; i < segmentation.size(); ++i) {
            std::cout << "Component " << i + 1 << ": " 
                      << segmentation[i].size() << " pixels\n";
        }
    }
};

int main() {
    try {
        std::string inputPath = "imagem.ppm";
        int width, height, maxVal;
        std::vector<Pixel> pixels;

        std::tie(width, height, maxVal, pixels) = readPPM(inputPath);

        Grafo graph = createGraphFromPPM(width, height, pixels);

        ImageSegmentation segmentator(graph, width, height);

        double thresholds[] = {10, 15, 20};
        
        for (double threshold : thresholds) {
            std::cout << "\nSegmentation with Threshold: " << threshold << "\n";
            
            auto segmentation = segmentator.segment(threshold);
            
            segmentator.printSegmentation(segmentation);
            
            std::string outputPath = "./segments/segmentation_" 
                                     + std::to_string(threshold) + ".ppm";
            segmentator.saveSegmentationImage(segmentation, outputPath);
        }
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}