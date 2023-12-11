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

/* int strcmp(char * x, char * y){
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
 */


typedef struct AVLtree{
    Jogador* raiz;
}AVLtree;

AVLtree* createTree(){
    AVLtree* tree = (AVLtree*)malloc(sizeof(AVLtree));
    tree->raiz = NULL;
    return tree;
}

void updateHeight(Jogador* no){
    if(no != NULL){
        int leftHeight = (no->esq == NULL) ? 0 : no->esq->height;
        int righttHeight = (no->dir == NULL) ? 0 : no->dir->height;
        no->height = 1 + ((leftHeight > righttHeight) ? leftHeight : righttHeight);
    }
}

int getFatorBalanceamento(Jogador* no){
    int heightBalance = 0;
    if(no != NULL){
        int heightDir = (no->dir == NULL) ? 0 : no->dir->height;
        int heightEsq = (no->esq == NULL) ? 0 : no->esq->height;
        heightBalance = heightDir - heightEsq;
    }
    return heightBalance;
}

Jogador* rotacionarDir(Jogador* no){
    if(no == NULL || no->esq == NULL){
        return no;
    }
    Jogador* temp = no->esq;
    no->esq = temp->dir;
    temp->dir = no;

    updateHeight(no);
    updateHeight(temp);

    return temp;
}

Jogador* rotacionarEsq(Jogador* no){
    if(no == NULL || no->dir == NULL){
        return no;
    }
    Jogador* temp = no->dir;
    no->dir = temp->esq;
    temp->esq = no;

    updateHeight(no);
    updateHeight(temp);

    return temp;
}

Jogador* clonePLayer(Jogador player){
    Jogador* temp = (Jogador*)malloc(sizeof(Jogador));
    strcpy(temp->nome, player.nome);
    strcpy(temp->cidade_nasc, player.cidade_nasc);
    strcpy(temp->estado_nasc, player.estado_nasc);
    strcpy(temp->universidade, player.universidade);
    temp->altura = player.altura;
    temp->dir = NULL;
    temp->esq = NULL;
    temp->height = 1;
    temp->id = player.id;
    temp->peso = player.peso;
    temp->ano_nasc = player.ano_nasc;
    return temp;
}

Jogador* addPlayer(Jogador player, Jogador* no){
    if(no == NULL){
        no = clonePLayer(player);
    }else if(strcmp(player.nome, no->nome) < 0){
        no->esq = addPlayer(player, no->esq);
    }else if(strcmp(player.nome, no->nome) > 0){
        no->dir = addPlayer(player, no->dir);
    }

    updateHeight(no);// pegar o a altura do lado que estiver maior e somar +1

    int balandeFator = getFatorBalanceamento(no); // fazer esq.height - dir.height, se -1 < balandeFator ou balandeFator > 1, faz as rotações

    if(balandeFator > 1){
        int balanceSonFactor = getFatorBalanceamento(no->dir);
        if(balanceSonFactor == -1){
            no->dir = rotacionarDir(no->dir);
        }
        no = rotacionarEsq(no);
    }
    if(balandeFator < -1){
        int balanceSonFactor = getFatorBalanceamento(no->esq);
        if(balanceSonFactor == 1){
            no->esq = rotacionarEsq(no->esq);
        }
        no = rotacionarDir(no);
    }

    return no;
}

void addPlayerOnTree(AVLtree* tree, Jogador temp){
    tree->raiz = addPlayer(temp, tree->raiz);
}

void search(char* x, Jogador* no){
    if(no == NULL){
        printf(" NAO");
    }else if(strcmp(x, no->nome) < 0){
        printf(" esq");
        search(x, no->esq);
    }else if(strcmp(x, no->nome) > 0){
        printf(" dir");
        search(x, no->dir);
    }else if(strcmp(x, no->nome) == 0){
        printf(" SIM");
    }
}

void freeNo(Jogador* no){
    if(no == NULL){
        return;
    }
    freeNo(no->esq);
    freeNo(no->dir);
    free(no);
}

void freeTree(AVLtree* tree){
    freeNo(tree->raiz);
    free(tree);
}

void showTree(Jogador* no){
    if(no == NULL){
        return;
    }

    showTree(no->esq);
    printf("%s\n", no->nome);
    showTree(no->dir);
}

int main() {
    char entrada[100];
    AVLtree* tree = createTree();

    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        int index = atoi(entrada);
        Jogador temp = ler(index);
        addPlayerOnTree(tree, temp);
    }

    strcpy(entrada, "");

    while(strcmp(entrada,"FIM") != 0){
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if(strcmp(entrada,"FIM") == 0){
            continue;
        }
        printf("%s raiz", entrada);
        search(entrada, tree->raiz);
        printf("\n");
    }
    freeTree(tree);
    return 0;
}
