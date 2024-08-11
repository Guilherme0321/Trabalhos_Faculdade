#include <iostream>
#include <vector>

class Matriz {
private:
    std::vector<std::vector<int>> data;

public:
    // Incluir n elementos na matriz
    void insert(int row, int col, int value) {
        if (row >= data.size()) {
            data.resize(row + 1);
        }

        if (col >= data[row].size()) {
            for(auto &r : data) {
                r.resize(col + 1, 0);
            }
        }

        data[row][col] = value;
            
    }

    // Verificar se um elemento específico está na matriz
    bool contains(int value) {
        for (const auto &row : data) {
            for (const auto &element : row) {
                if (element == value) {
                    return true;
                }
            }
        }

        return false;
    }

    // Remover k elementos da matriz
    void remove(int value, int k) {
        for (auto &row : data) {
            for (int i = 0; i < row.size() && k > 0; ++i) {
                if (row[i] == value) {
                    row.erase(row.begin() + i);
                    --k;
                }
            }
        }
    }

    // Função para imprimir a matriz
    void print() {
        for (const auto &row : data) {
            for (const auto &element : row) {
                std::cout << element << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main() {
    Matriz matriz;
    int row, col, value, k;
    char op;

    while (true) {
        std::cout << "Escolha uma operação: \n"
                  << "i: Inserir elemento na matriz\n"
                  << "c: Verificar se um elemento está na matriz\n"
                  << "r: Remover elementos da matriz\n"
                  << "p: Imprimir a matriz\n"
                  << "q: Sair\n";
        std::cin >> op;

        switch (op) {
            case 'i':
                std::cout << "Digite a linha, coluna e valor para inserir: ";
                std::cin >> row >> col >> value;
                matriz.insert(row, col, value);
                break;
            case 'c':
                std::cout << "Digite o valor para verificar: ";
                std::cin >> value;
                std::cout << (matriz.contains(value) ? "O valor está na matriz\n" : "O valor não está na matriz\n");
                break;
            case 'r':
                std::cout << "Digite o valor e o número de ocorrências para remover: ";
                std::cin >> value >> k;
                matriz.remove(value, k);
                break;
            case 'p':
                std::cout << "Matriz:\n";
                matriz.print();
                break;
            case 'q':
                return 0;
            default:
                std::cout << "Operação inválida!\n";
        }
    }

    return 0;
}