#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[20];
    int altura;
    int peso;
    char universidade[20];
    int ano_nasc;
    char cidade_nasc[20];
    char estado_nasc[20];
} Jogador;

typedef struct {
    Jogador* jogadores;
    int length;
} Jogadores;

void add(Jogadores* jogadores, Jogador jogador) {
    jogadores->jogadores = (Jogador*)realloc(jogadores->jogadores, sizeof(Jogador) * (jogadores->length + 1));

    jogadores->jogadores[jogadores->length] = jogador;
    jogadores->length++;
}

int toInt(char * x){
    int number = 0, ten = 1;
    for(int i = strlen(x)-1; i >= 0 ; i--){
        number += (x[i] - '0') * ten;
        ten = ten * 10;
    }
    return number;
}

void createJogador(Jogador* player, char* entrada) {
    char infos[8][100];  // Aumente o tamanho de cada string para 50
    char part[50];
    int j = 0, h = 0;

    for (int i = 0; i < strlen(entrada); i++) {
        if (entrada[i] == ',' || entrada[i] == '\0') {
            part[j] = '\0';
            if (strlen(part) == 0) {
                strcpy(infos[h], "nao informado");
            } else {
                strcpy(infos[h], part);
            }
            h++;
            j = 0;
            h %= 8;
        } else {
            part[j] = entrada[i];
            j++;
        }
    }

    if (h < 8) {
        part[j] = '\0';
        if (strlen(part) == 0) {
                strcpy(infos[h], "nao informado");
        } else {
            strcpy(infos[h], part);
        }
    }
    player->id = atoi(infos[0]);
    strcpy(player->nome, infos[1]);
    player->altura = atoi(infos[2]);
    player->peso = atoi(infos[3]);
    strcpy(player->universidade, infos[4]);
    player->ano_nasc = atoi(infos[5]);
    strcpy(player->cidade_nasc, infos[6]);
    strcpy(player->estado_nasc, infos[7]);
}



void ler(Jogadores* players) {
    players->jogadores = NULL;
    players->length = 0;
    FILE* file = fopen("/tmp/players.csv", "rt");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char entrada[100];
    fgets(entrada, sizeof(entrada), file);

    while (fgets(entrada, sizeof(entrada), file) != NULL) {
        entrada[strlen(entrada) - 1] = '\0'; // Substitui '\n' por '\0'.
        Jogador player;
        createJogador(&player, entrada);
        add(players, player);
    }

    fclose(file);
}

void printar(Jogador player) {
    printf("[%d ## %s ## %d ## %d ## %s ## %d ## %s ## %s]\n", player.id, player.nome, player.altura, player.peso, player.universidade, player.ano_nasc, player.cidade_nasc, player.estado_nasc);
}

int main() {
    Jogadores players;
    char entrada[10] = "";
    ler(&players);
    while(strcmp(entrada,"FIM")){
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strlen(entrada)-1] = '\0';
        if(strcmp(entrada,"FIM")){
            for(int i = 0; i < players.length; i++){        
                if(atoi(entrada) == players.jogadores[i].id){
                    printar(players.jogadores[i]);
                }
            }
        }
    }
    free(players.jogadores);

    return 0;
}
