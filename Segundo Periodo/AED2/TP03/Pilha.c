#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador{
    int id;
    struct Jogador* next;
    char nome[100];
    int altura;
    int peso;
    char universidade[100];
    int ano_nasc;
    char cidade_nasc[100];
    char estado_nasc[100];
} Jogador;

Jogador* createPlayer(Jogador player){
    Jogador* temp = (Jogador*)malloc(sizeof(Jogador));
    temp->altura = player.altura;
    temp->ano_nasc = player.ano_nasc;
    strcpy(temp->cidade_nasc,player.cidade_nasc);
    strcpy(temp->estado_nasc,player.estado_nasc);
    temp->id = player.id;
    temp->next = NULL;
    strcpy(temp->nome,player.nome);
    temp->peso = player.peso;
    strcpy(temp->universidade, player.universidade);
    return temp;
}

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
        jogadores = add(jogadores, size, jogador);
    }

    fclose(file);
    return jogadores;
}

void imprimir(Jogador jogador, int i) {
    printf("[%d] ## %s ## %d ## %d ## %d ## %s ## %s ## %s ##\n",
           i, jogador.nome, jogador.altura, jogador.peso,
           jogador.ano_nasc, jogador.universidade, jogador.cidade_nasc,
           jogador.estado_nasc);
}

typedef struct Pilha{
    Jogador* topo;
} Pilha;

Pilha* createPilha(){
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void addPilha(Pilha* stack, Jogador player){
    Jogador* temp = createPlayer(player);
    if(temp == NULL){
        printf("Erro ao tentar criar jogador!\n");
    }
    if(stack->topo == NULL){
        stack->topo = temp;
    }else{
        temp->next = stack->topo;
        stack->topo = temp;
    }
}

Jogador* popToPilha(Pilha* pilha){
    Jogador* temp;
    if(pilha->topo == NULL){
        printf("Pilha vazia!");
    }else{
        temp = pilha->topo;
        pilha->topo = pilha->topo->next;
    }
    return temp;
}

void liberJogador(Jogador* player){
    if(player == NULL){
        return;
    }
    liberJogador(player->next);
    free(player);
}

void liberarPilha(Pilha * pilha){
    if(pilha != NULL){
        liberJogador(pilha->topo);
        free(pilha);
    }
}

void printJogador(Jogador* x, int i){
    if(x == NULL){
        return;
    }
    printJogador(x->next, i - 1);
    imprimir(*x,i);
}

int getPilhaLength(Pilha pilha){
    Jogador* player;
    int i = 0;
    for(player = pilha.topo; player != NULL; player = player->next, i++);
    return i;
}

void printarPilha(Pilha* pilha){
    if(pilha->topo == NULL){
        printf("Pilha vazia\n");
    }else{
        int length = getPilhaLength(pilha[0]);
        printJogador(pilha->topo,length-1);
    }
}

 int takeNumber(char * x){
    char num[7];
    int lenX = strlen(x);
    int j = 0, h = 0;
    for(int i = 0; i < lenX; i++){
        if(x[i] == ' '){
            h = ++i;
            i = lenX;
        }
    }
    while(h < lenX){
        num[j] = x[h];
        j++;
        h++;
    }
    return atoi(num);
}

int main() {
    char entrada[100];
    Jogador* players = NULL;
    int size = 0;
    players = ler(&size);
    Pilha* pilha = createPilha();

    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        int index = atoi(entrada);
        if (index < size) {
            addPilha(pilha, players[index]);
        }
    }

    int counter = 0;
    scanf("%d",&counter);
    getchar();
    while(counter > 0){
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        if(entrada[0] == 'I'){
            int pos = takeNumber(entrada);
            if (pos != -1) {
                addPilha(pilha, players[pos]);
            }
        }else{
            Jogador* temp = popToPilha(pilha);
            printf("(R) %s\n",temp->nome);
            free(temp);
        }
        counter--;
    }

    printarPilha(pilha);
    free(players);
    liberarPilha(pilha);
    return 0;
}
