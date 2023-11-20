#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
  int id;
  struct Jogador *next;
  char nome[100];
  int altura;
  int peso;
  char universidade[100];
  int ano_nasc;
  char cidade_nasc[100];
  char estado_nasc[100];
} Jogador;

Jogador *createPlayer(Jogador player) {
  Jogador *temp = (Jogador *)malloc(sizeof(Jogador));
  temp->altura = player.altura;
  temp->ano_nasc = player.ano_nasc;
  strcpy(temp->cidade_nasc, player.cidade_nasc);
  strcpy(temp->estado_nasc, player.estado_nasc);
  temp->id = player.id;
  temp->next = NULL;
  strcpy(temp->nome, player.nome);
  temp->peso = player.peso;
  strcpy(temp->universidade, player.universidade);
  return temp;
}

void replaceSubstring(char *str, const char *find, const char *replace) {
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

Jogador *add(Jogador *players, int *size, Jogador player) {
  (*size)++;
  players = (Jogador *)realloc(players, (*size) * sizeof(Jogador));
  players[(*size) - 1] = player;
  return players;
}

Jogador *ler(int *size) {
  FILE *file = fopen("/tmp/players.csv", "r");
  if (!file) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  Jogador *jogadores = NULL;
  char line[1000];
  fgets(line, sizeof(line), file);

  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = '\0';
    replaceSubstring(line, ",,", ",nao informado,");
    if (line[strlen(line) - 1] == ',') {
      strcat(line, "nao informado");
    }
    char *token = strtok(line, ",");
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
  printf("[%d] ## %s ## %d ## %d ## %d ## %s ## %s ## %s ##\n", i, jogador.nome,
         jogador.altura, jogador.peso, jogador.ano_nasc, jogador.universidade,
         jogador.cidade_nasc, jogador.estado_nasc);
}

typedef struct Lista{
  Jogador* jogadores;
  int length;
  int quantidade;
} Lista;

Lista* createLista(int length) {
  Lista * list = (Lista*)malloc(sizeof(Lista));
  if (list == NULL) {
    printf("Falha na alocação de memória para a lista");
    return NULL;
  }

  if (length > 0) {
    list->jogadores = (Jogador*)malloc(sizeof(Jogador) * length);
    if (list->jogadores == NULL) {
      printf("Falha na alocação de memória para jogadores");
      free(list);
      return NULL;
    }
    list->length = length;
  } else {
    list->jogadores = NULL;
    list->length = 0;
  }
  list->quantidade = 0;
  return list;
}

void destroyLista(Lista* list) {
  if (list == NULL) {
    return;
  }

  if (list->jogadores != NULL) {
    free(list->jogadores);
  }
  free(list);
}

void addToLista(Lista* list, Jogador x, int pos) {
  if (list->jogadores == NULL) {
    printf("A lista de jogadores está nula\n");
    return;
  }

  if (pos < 0) {
    printf("Posição inválida\n");
    return;
  }

    list->length++;
    Jogador* temp = (Jogador*)malloc(sizeof(Jogador) * list->length);

    int i = 0, j = 0;
    while (i < list->length) { // troquei list->quantidade por list->length e de certo
      if (i != pos) {
        temp[i] = list->jogadores[j];
        j++;
      } else {
        temp[i] = x;
      }
      i++;
    }

    free(list->jogadores);
    list->jogadores = temp;
  

  list->quantidade++;
}




void addStart(Lista* list, Jogador x){
  addToLista(list, x, 0);
}

void addEnd(Lista* list, Jogador x){
  addToLista(list,x,list->quantidade);
}

Jogador removeFromList(Lista* list, int pos){
  Jogador removed;
  if(list == NULL){
    printf("Lista igual a null");
  }else if(list->jogadores == NULL || list->length == 0){
    printf("Lista vazia");
  }else{
    Jogador* temp = (Jogador*)malloc(sizeof(Jogador)*list->length-1);
    int j = 0;
    for(int i = 0; i < list->length; i++){
      if(i != pos){
        temp[j++] = list->jogadores[i];
      }
    }
    removed = list->jogadores[pos];
    free(list->jogadores);
    list->length--;
    list->jogadores = temp;
    list->quantidade--;
  }
  return removed;
}

void showList(Lista* list){
  for(int i = 0; i < list->quantidade; i++){
    printf("[%d] ## %s ## %d ## %d ## %d ## %s ## %s ## %s ##\n", i, list->jogadores[i].nome,
         list->jogadores[i].altura, list->jogadores[i].peso, list->jogadores[i].ano_nasc, list->jogadores[i].universidade,
         list->jogadores[i].cidade_nasc, list->jogadores[i].estado_nasc);
  }
}

int countSpace(char * x){
  int count = 0;
  for(int i = 0; i < strlen(x); i++){
    if(x[i] == ' '){
      count++;
    }
  }
  return count;
}

int getPosition(char * x){
  int i = 0;
  char pos[5];
  while(x[i] != ' '){
    i++;
  }
  i++;
  int j = 0;
  while(x[i] != ' ' && x[i] != '\0'){
    pos[j] = x[i];
    i++; j++;
  }
  return atoi(pos);
}

int getInID(char * x){
  char y[5];
  int i = 0, j = 0;
  while(x[i] != '\0' && j != 2){
    if(x[i] == ' '){
      j++;
    }
    i++;
  }
  j = 0;
  while(x[i] != '\0'){
    y[j] = x[i];
    i++; j++;
  }
  y[j] = '\0';
  return atoi(y);
}

int main() {
    char entrada[100];
    Jogador* players = NULL;
    int size = 0;
    players = ler(&size);
    Lista* list = createLista(1);

    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strcmp(entrada, "FIM") == 0) {
            break;
        }

        int index = atoi(entrada);
        if (index < size) {
            addEnd(list,players[index]);
        }
    }

    int counter = 0;
    scanf("%d",&counter);
    getchar();
    while(counter > 0){
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        int counterSpace = countSpace(entrada);
        if(counterSpace == 2){
            int pos = getPosition(entrada);
            int id = getInID(entrada);
          if(entrada[0] == 'I'){
            addToLista(list,players[id],pos);
          }
        }else{
          if(entrada[0] == 'I'){
            if(entrada[1] == 'I'){
              addStart(list,players[getPosition(entrada)]);
            }else{
              addEnd(list, players[getPosition(entrada)]);
            }
          }else{
            if(entrada[1] == '*'){
              int pos = getPosition(entrada);
              Jogador temp = removeFromList(list, pos);
              printf("(R) %s\n", temp.nome);
            }else if(entrada[1] == 'I'){
              Jogador temp = removeFromList(list,0);
              printf("(R) %s\n", temp.nome);
            }else{
              Jogador temp = removeFromList(list,list->quantidade-1);
              printf("(R) %s\n", temp.nome);
            }
          }
        }
        counter--;
    }

    showList(list);
    free(list->jogadores);
    free(list);
    free(players);
    return 0;
}