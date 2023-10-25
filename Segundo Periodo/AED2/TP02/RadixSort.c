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

int findMAX(Jogador *players, int length) {
    int max = players[0].id;
    for (int i = 1; i < length; i++) {
        if (players[i].id > max) {
            max = players[i].id;
        }
    }
    return max;
}

void countingSortByDigit(Jogador *players, int length, int digit) {
    const int base = 10;
    int count[base];
    Jogador output[length];

    for (int i = 0; i < base; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++) {
        int digitValue = (players[i].id / digit) % base;
        count[digitValue]++;
    }

    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }

    for (int i = length - 1; i >= 0; i--) {
        int digitValue = (players[i].id / digit) % base;
        output[count[digitValue] - 1] = players[i];
        count[digitValue]--;
    }

    for (int i = 0; i < length; i++) {
        players[i] = output[i];
    }
}


void radixSort(Jogador *players, int length) {
    int max = findMAX(players, length);

    for (int digit = 1; max / digit > 0; digit *= 10) {
        countingSortByDigit(players, length, digit);
    }
}



int main() {
    char entrada[100];
    Jogador* players = NULL;
    int size = 0;
    players = ler(&size);
    Jogador* newPlayers = NULL;
    int length = 0;
    while (strcmp(entrada,"FIM")) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strcmp(entrada, "FIM")) {
            int index = atoi(entrada);
            newPlayers = add(newPlayers,&length,players[index]);
        }
    }
    radixSort(newPlayers,length);
    for(int i = 0; i < length; i++){
        imprimir(newPlayers[i]);
    }
    free(newPlayers);
    free(players);
    return 0;
}
