#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
    int id;
    struct Jogador* dir;
    struct Jogador* esq;
    int height;

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

Jogador ler(int targetLine) {
    FILE* file = fopen("/tmp/players.csv", "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    char line[1000];
    int currentLine = -1;

    // Lê cada linha até atingir a linha desejada
    while (fgets(line, sizeof(line), file) && currentLine < targetLine) {
        currentLine++;
    }

    // Processa a linha desejada
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

    // Adiciona o jogador à lista
    jogador.dir = NULL;
    jogador.esq = NULL;
    jogador.height = 1;
    fclose(file);
    return jogador;
}


void imprimir(Jogador jogador) {
    printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n",
           jogador.id, jogador.nome, jogador.altura, jogador.peso,
           jogador.ano_nasc, jogador.universidade, jogador.cidade_nasc,
           jogador.estado_nasc);
}

int compareStrings(char * x, char * y){
    int lenX = strlen(x), lenY = strlen(y);
    int minlenth = (lenX < lenY) ? lenX : lenY;
    int response = 0;
    for(int i = 0; i < minlenth; i++){
        response += x[i] - y[i];
    }
    if(response == 0){
        return lenX - lenY;
    }else{
        return response;
    }
}