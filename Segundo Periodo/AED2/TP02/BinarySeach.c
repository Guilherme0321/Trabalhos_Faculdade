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

int compareString(char * x, char * y){
    int LenX = strlen(x), LenY = strlen(y);
    int minLength = (LenX < LenY) ? LenX : LenY;
    int i = 0;
    while(i < minLength && x[i] == y[i]){
        i++;
    }
    if(i == minLength){
        return LenX < LenY;
    }else{
        return x[i] < y[i];
    }
}

int partition(Jogador* player,int left, int dir){
    int i = left -1;
    Jogador pivo = player[dir];
    for(int j = left; j <= dir-1; j++){
        if(compareString(player[j].nome,pivo.nome)){
            i++;
            Jogador temp = player[i];
            player[i] = player[j];
            player[j] = temp;
        }
    }
    Jogador temp = player[i + 1];
    player[i + 1] = player[dir];
    player[dir] = temp;
    return i + 1;
}

void quickSort(Jogador* player, int left, int dir){
    if(left < dir){
        int i = partition(player,left,dir);
        quickSort(player,i+1,dir);
        quickSort(player,left,i-1);
    }
}

void sort(Jogador* player, int length){
   quickSort(player,0,length-1);
}

int search(Jogador* player, int len, char * x){
    int left = 0, right = len-1;
    int isTrue = 0;
    while(left <= right){
        int meio = (left + right)/2;
        if(!strcmp(player[meio].nome,x)){
            isTrue = 1;
        }
        if(compareString(player[meio].nome,x)){
            left = meio + 1;
        }else{
            right = meio - 1;
        }
    }
    return isTrue;
}

int main() {
    char entrada[100];
    Jogador * player;
    int size = 0;
    player = ler(&size);
    Jogador* newPlayer = NULL;
    int length = 0;
    while(strcmp(entrada,"FIM")){
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        if(strcmp(entrada,"FIM")){
            newPlayer = add(newPlayer,&length,player[atoi(entrada)]);
        }
    }
    sort(newPlayer,length);
    entrada[0] = '\0';
    while(strcmp(entrada,"FIM")){
        fgets(entrada, sizeof(entrada),stdin);
        entrada[strcspn(entrada,"\n")] = '\0';
        if(strcmp(entrada,"FIM")){
            if(search(newPlayer,length,entrada)){
                printf("SIM\n");
            }else{
                printf("NAO\n");
            }
        }
    }
    free(player);
    free(newPlayer);
    return 0;
}
