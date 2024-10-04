#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Heap {
private:
    vector<pair<float, int>> heap; // < peso, vertice destino >
public:

    int getRight(int i) {
        return i * 2 + 2;
    }

    int getLeft(int i) {
        return i * 2 + 1;
    }

    void push(pair<float, int> weight) {
        heap.push_back(weight);
    }

    void pop() {
        if(heap.size() == 0) {
            cout << "Não é possivel remover itens de um heap vazio!" << endl;
        } else {
            heap[0] = heap.back();
            heap.pop_back();
        }
    }

    pair<float, int> top() {
        if(heap.size() == 0) {
            return {numeric_limits<float>::infinity(), -1};
        }
        return heap[0];
    }

    bool empty() {
        return heap.size() == 0;
    }

    void swap(int i, int j) {
        pair<float, int> temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void heapifyDown() {
        for(int i = heap.size() / 2; i >= 0; --i) {
            int smallest = i;
            int left = getLeft(i);
            int right = getRight(i);
            
            if(left < heap.size() && heap[left].first < heap[smallest].first)
                smallest = left;
            if(right < heap.size() && heap[right].first < heap[smallest].first)
                smallest = right;
            if(i != smallest) {
                swap(i, smallest);
            }
        } 
    }

    void heapifyUp() {
        for(int i = heap.size() / 2; i >= 0; --i) {
            int smallest = i;
            int left = getLeft(i);
            int right = getRight(i);
            
            if(left < heap.size() && heap[left].first > heap[smallest].first)
                smallest = left;
            if(right < heap.size() && heap[right].first > heap[smallest].first)
                smallest = right;
            if(i != smallest) {
                swap(i, smallest);
            }
        } 
    }

    void show() {
        cout << endl;
        for(pair<float, int> temp : heap) {
            cout << "<" << temp.first << " " << temp.second << "> , ";
        }
        cout << endl;
    }
};