#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Jogador {
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

/* int getArquiveLines(){
    FILE* file = fopen("players.csv","rt");
    if(!file){
        perror("Erro ao abrir arquivo");
        exit(1);
    }
    int lines = 0;
    char x;
    while((x = getc(file)) != EOF){
        if(x == '\n'){
            lines++;
        }
    }
    fclose(file);
    return lines;
} */

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

int searchHeight(Jogador* playes, int size, char * string){
    int height = 0;
    for(int i = 0; i < size; i++){
        if(compareStrings(playes[i].nome, string) == 0){
            height = playes[i].altura;
            i = size;
        }
    }
    return height;
}

typedef struct HashTable{
    Jogador* arr;
    int length;
    void (*incerir)(Jogador, struct HashTable*);
    void (*search)(char*, int, struct HashTable*);
    int (*hashCode)(int, int);
} HashTable;

int hashCode(int index, int length){
    return index % length;
}

void incerir(Jogador player, HashTable* table) {
    if (table != NULL) {
        int index = table->hashCode(player.altura, table->length);
        table->arr[index] = player;
    } else {
        printf("Tabela inválida, NullPointerException!\n");
    }
}

void search(char* name, int altura, HashTable* table) {
    int index = table->hashCode(altura, table->length);

    if (table->arr[index].altura != 0 &&
        compareStrings(name, table->arr[index].nome) == 0) {
        printf("%s SIM\n", name);
    } else {
        printf("%s NAO\n", name);
    }
}


HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));

    table->length = 25;
    table->arr = (Jogador*)malloc(sizeof(Jogador) * table->length);
    for(int i = 0; i < table->length; i++){
        table->arr[i].altura = 0;
        table->arr[i].id = 0;
        table->arr[i].ano_nasc = 0;
        table->arr[i].peso = 0;
        strcpy(table->arr[i].nome, "");
        strcpy(table->arr[i].cidade_nasc, "");
        strcpy(table->arr[i].estado_nasc, "");
        strcpy(table->arr[i].universidade, "");
    }


    table->incerir = incerir;
    table->search = search;
    table->hashCode = hashCode;

    return table;
}


void showHash(HashTable* table){
    for(int i = 0; i < table->length; i++){
        imprimir(table->arr[i]);
    }
}

int main(){
    char entrada[100];
    HashTable* table = createHashTable();

    int size = 0;
    Jogador* players = ler(&size);

    char lines[200][200];
    int i = 0;
    while(fgets(entrada, sizeof(entrada), stdin) != NULL){
        entrada[strcspn(entrada, "\n")] = '\0';
        strcpy(lines[i],entrada);
        i++;
    }
    int j = 0;
    while (j < i) {
        if (strcmp(lines[j], "FIM") == 0) {
            break;
        }

        int index = atoi(lines[j]);
        Jogador temp = players[index];

        incerir(temp, table);
        j++;
    }
j++;
    while(j < i){
        if(compareStrings(lines[j],"FIM") == 0){
            break;;
        }
        int height = searchHeight(players, size, lines[j]);
        search(lines[j], height, table);
        j++;
    }

    //showHash(table);

    free(table->arr);
    free(table);
    free(players);
    return 0;
}