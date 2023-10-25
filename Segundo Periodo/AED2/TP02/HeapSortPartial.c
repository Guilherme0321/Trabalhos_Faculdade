#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
    int altura;
    int peso;
    char universidade[100];
    int ano_nasc;
    char cidade_nasc[100];
    char estado_nasc[100];
} Jogador;

void replaceSubstring(char* str, const char* find, const char* replace) {
    int findLen = strlen(find);
    int replaceLen = strlen(replace);
    char result[1000]; 

    int i, j, index = 0;
    for (i = 0; str[i] != '\0';) {
        int found = 1;

        for (j = 0; j < findLen; j++) {
            if (str[i + j] != find[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            for (j = 0; j < replaceLen; j++) {
                result[index++] = replace[j];
            }
            i += findLen;
        } else {
            result[index++] = str[i++];
        }
    }

    result[index] = '\0';
    strcpy(str, result);
}

Jogador* add(Jogador* players, int* size, Jogador player) {
    (*size)++;
    players = (Jogador*)realloc(players, (*size) * sizeof(Jogador));
    players[(*size) - 1] = player;
    return players;
}

Jogador* ler(int* size) {
    FILE* file = fopen("/tmp/players.csv", "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    Jogador* jogadores = NULL;
    char line[1000];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        replaceSubstring(line,",,",",nao informado,");
        if(line[strlen(line)-1] == ','){
            strcat(line,"nao informado");
        }
        char* token = strtok(line, ",");
        int i = 0;
        Jogador jogador;

        while (token != NULL) {
            switch (i) {
                case 0:
                    jogador.id = atoi(token);
                    break;
                case 1:
                    strcpy(jogador.nome, token);
                    break;
                case 2:
                    jogador.altura = atoi(token);
                    break;
                case 3:
                    jogador.peso = atoi(token);
                    break;
                case 4:
                    strcpy(jogador.universidade, token);
                    break;
                case 5:
                    jogador.ano_nasc = atoi(token);
                    break;
                case 6:
                    strcpy(jogador.cidade_nasc, token);
                    break;
                case 7:
                    strcpy(jogador.estado_nasc, token);
                    break;
            }
            token = strtok(NULL, ",");
            i++;
        }
        if(jogador.estado_nasc)
        jogadores = add(jogadores, size, jogador);
    }

    fclose(file);
    return jogadores;
}

void imprimir(Jogador jogador) {
    printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n",
           jogador.id, jogador.nome, jogador.altura, jogador.peso,
           jogador.ano_nasc, jogador.universidade, jogador.cidade_nasc,
           jogador.estado_nasc);
}

int compararStrings(char * x, char * y){
    while(*x && *y && *y == *x){
        x++;
        y++;
    }
    if(*x == *y){
        return 0;
    }else{
        return (*x < *y) ? -1 : 1;
    }
}

void heaping(Jogador* heap, int length, int i){
    int j = i, son1 = (2*i) + 1, son2 = (2*i)+2;
    if(son1 < length && heap[son1].altura > heap[j].altura){
        j = son1;
    }
    if(son2 < length && heap[son2].altura > heap[j].altura){
        j = son2;
    }
    if(j != i){
        Jogador temp = heap[j];
        heap[j] = heap[i];
        heap[i] = temp;
        heaping(heap,length,j);
    }
}

void buildHeap(Jogador* heap, int length){
    for(int i = (length/2)-1; i >= 0; i--){
        heaping(heap,length,i);
    }
}

void sort(Jogador* heap, int length, int k){
    Jogador newHeap[length];
    buildHeap(heap, length);
    int i = 0;
    for(i = length-1; i >= 0; i--){
        newHeap[i] = heap[0];
        heap[0] = heap[i];
        heaping(heap,i,0);
    }
    for(int h = 0; h < length; h++){
        heap[h] = newHeap[h];
    }
}

void sortByName(Jogador* heap, int length, int k){
    for(int i = 0; i < k; i++){
        Jogador key = heap[i];
        int j = i - 1;
        while(j >= 0 && key.altura == heap[j].altura && compararStrings(key.nome,heap[j].nome) == -1){
            heap[j+1] = heap[j];
            j--;
        }
        heap[j+1] = key;
    }
}

int main() {
    char entrada[100];
    Jogador* players = NULL;
    int size = 0;
    players = ler(&size);
    Jogador* newPlayers = NULL;
    int length = 0;
    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        int index = atoi(entrada);
        if (index < size) {
            newPlayers = add(newPlayers,&length,players[index]);
        }
    }
    sort(newPlayers,length,10);
    sortByName(newPlayers,length,10);
    for(int i = 0; i < 10; i++){
        imprimir(newPlayers[i]);
    }
    free(newPlayers);
    free(players);
    return 0;
}
