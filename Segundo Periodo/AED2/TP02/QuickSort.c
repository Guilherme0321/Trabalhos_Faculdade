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

int compararString(char * x, char * y){
    int LenX = strlen(x), LenY = strlen(y);
    int i = 0, minLength = (LenX < LenY) ? LenX : LenY;
    while(i < minLength && x[i] == y[i]){
        i++;
    }
    if(i == minLength){
        return (LenX < LenY);
    }else{
        return x[i] < y[i];
    }
    
}

int partition(Jogador* player,int left, int dir){
    int i = left -1;
    Jogador pivo = player[dir];
    for(int j = left; j <= dir-1; j++){
        if(strcmp(player[j].estado_nasc,pivo.estado_nasc) != 0 && compararString(player[j].estado_nasc,pivo.estado_nasc)){
            i++;
            Jogador temp = player[j];
            player[j] = player[i];
            player[i] = temp;
        }else if(strcmp(player[j].estado_nasc,pivo.estado_nasc) == 0 && compararString(player[j].nome,pivo.nome)){
            i++;
            Jogador temp = player[j];
            player[j] = player[i];
            player[i] = temp;
        }
    }
    Jogador temp = player[i + 1];
    player[i + 1] = player[dir];
    player[dir] = temp;
    return i + 1;

}

void quicksort(Jogador* player, int left, int dir){
    if(left < dir){
        int i = partition(player, left, dir);
        quicksort(player,i+1,dir);
        quicksort(player,left, i-1);
    }
}

void sort(Jogador* player, int length){
    quicksort(player, 0, length-1);
}

int main() {
    char entrada[100];
    Jogador* players = NULL;
    int size = 0;
    players = ler(&size);
    Jogador* newPlayer = NULL;
    int length = 0;
    while (strcmp(entrada, "FIM")) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strcmp(entrada, "FIM")) {
            int index = atoi(entrada);
            newPlayer = add(newPlayer,&length,players[index]);
        }
    }
    sort(newPlayer, length);
    for(int i = 0; i < length; i++){
        imprimir(newPlayer[i]);
    }

    free(players);
    free(newPlayer);
    return 0;
}
