#include <iostream>

using namespace std;

template <typename K>
class No {
    public:
        K element;
        No* next;

        No(K element) {
            this->element = element;
            this->next = nullptr;
        }
};

template <typename T>
class LinkedList
{
    public:
        No<T> *first, *last;
        int length;

        LinkedList() {
            this->first = nullptr;
            this->last = nullptr;
            this->length = 0;
        }

        void push_end(T element) {
            if(!this->first) {
                this->first = new No(element);
                this->last = this->first;
            } else {
                this->last->next = new No(element);
                this->last = last->next;
            }
            this->last->next = nullptr;
            this->length++;
        }

        void push(T element, int pos) {
            if((pos < 0 && pos > length) || (!this->first && pos != 0)) {
                throw out_of_range("Index out of bounds");
            } else if(pos == 0) {
                push_start(element);
            } else if(pos == length) {
                push_end(element);
            } else {
                int i = 0;
                No<T> *temp = first;
                while(i < pos -1 && temp->next != nullptr) {
                    i++;
                    temp = temp->next;
                }
                No<T> *newNo = temp->next;
                temp->next = new No(element);
                temp->next->next = newNo;
                this->length++;
            }
        }

        void push_start(T element) {
            if(!this->first) {
                this->first = new No(element);
                this->last = this->first;
            } else {
                No<T> *temp = new No(element);
                temp->next = this->first;
                this->first = temp;
            }
            this->length++;
        }

        No<T>* pop_end() {
            No<T>* temp = nullptr;
            if(first) {
                No<T>* i = this->first;
                if(!i->next) {
                    temp = first;
                    first = nullptr;
                    last = nullptr;
                } else {
                    temp = this->last;
                    for(i = first; i->next != last; i = i->next);
                    i->next = nullptr;
                    this->last = i;
                }
                length--;
            } else {
                throw runtime_error("List is empty!");
            }
            return temp;
        }

        No<T>* pop(int pos) {
            No<T>* temp = nullptr;
            if(!first) {
                throw runtime_error("List is empty!");
            } else if(pos == 0) {
                temp = pop_start();
            } else if(pos == length) {
                temp = pop_end();
            } else {
                No<T>* i = first;
                for(int j = 0; j < pos - 1 && i->next != nullptr; i = i->next, j++);
                temp = i->next;
                i->next = i->next->next;
                length--;
            }
            return temp;
        }

        No<T>* pop_start() {
            No<T>* temp = nullptr;
            if(first) {
                temp = first;
                if(first == last) {                    
                    last = nullptr;
                }
                first = first->next;
                length--;
            } else {
                throw runtime_error("List is empty!");
            }
            return temp;
        }

        int search(T element) {
            int pos = 0;
            No<T>* temp = first;
            while(temp != nullptr) {
                if(temp->element == element) {
                    return pos;
                }
                temp = temp->next;
                pos++;
            }
            return -1;
        }

        No<T>* get(int pos) {
            int i = 0;
            No<T>* temp = first;
            while (i < pos - 1 && temp != nullptr) {
                temp = temp->next;
                i++;
            }
            return temp;
        }

        void show() {
            for(No<T> *temp = first; temp != nullptr; temp = temp->next) {
                cout << temp->element << " ";
            }
            cout << endl;
        }

        ~LinkedList(){
            No<T> *temp = first;
            while (temp != nullptr) {
                No<T> *temp2 = temp;
                temp = temp->next;
                delete temp2;
            }
            
        }
};

int main(int argc, char const *argv[])
{
    LinkedList<int> lista;
    int n, k, elemento;

    cout << "Quantos elementos deseja incerir na lista? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Digite o elemento " << i + 1 << ": ";
        cin >> elemento;
        lista.push_end(elemento);
    }

    lista.show();

    cout << "Quantos elementos deseja remover da lista? ";
    cin >> k;

    No<int>* tempNo = nullptr;

    for (int i = 0; i < k; i++) {
        cout << endl << endl;
        lista.show();
        cout << "Digite a posicao do elemento que deseja remover: " << endl;
        int temp = 0;
        cin >> temp;
        try {
            tempNo = lista.pop(temp);
            cout << "Elemento removido: " << tempNo->element << endl;
            delete tempNo;
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    lista.show();
    cout << "Digite a posicao do elemento que deseja printar: " << endl;
    cin >> k;
    tempNo = lista.get(k);
    cout << tempNo->element << endl;
    delete tempNo;

    return 0;
}
