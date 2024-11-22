#include <iostream>
#include "Grafo.hpp"

/* int main() {
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
} */




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

    Grafo mst = grafo.primMST(0);
    cout << endl;
    cout << endl;
    mst.show();
    return 0;
}
