#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jogador {
  int id;
  struct Jogador *next;
  struct Jogador *before;
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
  temp->before = NULL;
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

void imprimir(Jogador jogador) {
  printf("[%d ## %s ## %d ## %d ## %d ## %s ## %s ## %s]\n", jogador.id,
         jogador.nome, jogador.altura, jogador.peso, jogador.ano_nasc,
         jogador.universidade, jogador.cidade_nasc, jogador.estado_nasc);
}

typedef struct DoubleLinkedLIst {
  Jogador *first;
  Jogador *last;
} DoubleLinkedLIst;

DoubleLinkedLIst *createDoubleLinkedList(int length) {
  DoubleLinkedLIst *list = NULL;
  if (length > 0) {
    list = (DoubleLinkedLIst *)malloc(sizeof(DoubleLinkedLIst));
    list->first = (Jogador *)malloc(sizeof(Jogador));
    list->first->before = NULL;
    Jogador *temp = list->first;
    for (int i = 0; i < length; i++) {
      temp->next = (Jogador *)malloc(sizeof(Jogador));
      temp->next->before = temp;
      temp = temp->next;
    }
    list->last = temp;
    list->last->next = NULL;
  } else {
    printf("Length não pode ser menor ou igual a 0\n");
  }
  return list;
}

void addOnListFinal(DoubleLinkedLIst *list, Jogador temp) { // adiciona ao final
  if (list == NULL) {
    printf("Nao pode adicionar em uma lista nula\n");
  } else {
    Jogador *tempLast = createPlayer(temp);
    tempLast->next = NULL;
    tempLast->before = list->last;
    list->last->next = tempLast;
    list->last = tempLast;
  }
}

void addOnList(DoubleLinkedLIst *list, Jogador temp, int pos) {
  if (pos >= 0) {
    Jogador *tmp = list->first;
    int i = 0;
    for (i = 0; i < pos - 1 && tmp != NULL; i++, tmp = tmp->next)
      ;
    if (i != pos - 1) {
      printf("Posicao invalida!");
    } else {
      Jogador *tempPlayer =
          createPlayer(temp);       // cria um ponteiro com o jogador passado
      tempPlayer->next = tmp->next; // proximo do jogador adicionado = proximo
                                    // do jogador em pos
      tempPlayer->before = tmp;     // anterior = ao jogador de pos
      tmp->next->before =
          tempPlayer; // anterior do proximo jogador do jogador em pos = jogador
                      // que está sendo adicionado
      tmp->next = tempPlayer; // proximo jogador do jogador em pos = o jogador
                              // adicionado
      if (tempPlayer->next == NULL) {
        list->last = tempPlayer;
        list->last->next = NULL;
      }
    }
  }
}

void addOnStart(DoubleLinkedLIst *list, Jogador temp) {
  if (list == NULL) {
    printf("Nao pode adicionar em uma lista nula\n");
  } else {
    Jogador *tempPlayer = createPlayer(temp);
    tempPlayer->next = list->first;
    list->first->before = tempPlayer;
    list->first = tempPlayer;
    list->first->before = NULL;
  }
}

void setAllAtributos(Jogador *x, Jogador *y) {
  x->altura = y->altura;
  x->ano_nasc = y->ano_nasc;
  strcpy(x->cidade_nasc, y->cidade_nasc);
  strcpy(x->estado_nasc, y->estado_nasc);
  x->id = y->id;
  strcpy(x->nome, y->nome);
  x->peso = y->peso;
  strcpy(x->universidade, y->universidade);
}

void swap(Jogador *x, Jogador *y) {
  Jogador temp = *x;
  setAllAtributos(x, y);
  setAllAtributos(y, &temp);
}

int compareString(char *x, char *y) {
  int lenX = strlen(x), lenY = strlen(y);
  int minLength = (lenX < lenY) ? lenX : lenY;
  int i = 0;
  while (i < minLength && x[i] == y[i]) {
    i++;
  }
  if (i == minLength) {
    return lenX - lenY;
  } else {
    return x[i] - y[i];
  }
}

Jogador *partition(Jogador *ini, Jogador *final) {
  Jogador *pivo = final, *i = ini->before;
  for (Jogador *j = ini; j != final; j = j->next) {
    if (compareString(j->estado_nasc, pivo->estado_nasc) < 0) {
      i = (i == NULL) ? ini : i->next;
      swap(i, j);
    }
  }
  i = (i == NULL) ? ini : i->next;
  swap(i, final);
  return i;
}

void quickSort(Jogador *ini, Jogador *final) {
  if (ini != NULL && final != NULL && ini != final && ini != final->next) {
    Jogador *temp = partition(ini, final);
    quickSort(ini, temp->before);
    quickSort(temp->next, final);
  }
}

void sortByName(Jogador *ini) {
  for (Jogador *i = ini; i != NULL; i = i->next) {
    for (Jogador *j = i; j->next != NULL; j = j->next) {
      if (compareString(j->next->nome, j->nome) < 0 &&
          strcmp(j->estado_nasc, j->next->estado_nasc) == 0) {
        swap(j, j->next);
      }
    }
  }
  for (Jogador *i = ini; i != NULL; i = i->next) {
    for (Jogador *j = i; j->next != NULL; j = j->next) {
      if (compareString(j->next->nome, j->nome) < 0 &&
          strcmp(j->estado_nasc, j->next->estado_nasc) == 0) {
        swap(j, j->next);
      }
    }
  }
}

void sort(DoubleLinkedLIst *list) {
  quickSort(list->first, list->last);
  sortByName(list->first);
}

void showList(DoubleLinkedLIst *list) {
  for (Jogador *i = list->first; i != NULL; i = i->next) {
    if (i->peso > 0) {
      imprimir(*i);
    }
  }
}

void freePlayer(Jogador *player) {
  if (player == NULL) {
    return;
  }
  freePlayer(player->next);
  free(player);
}

void freeList(DoubleLinkedLIst *list) {
  if (list != NULL) {
    freePlayer(list->first);
    free(list);
  }
}

int main() {
  char entrada[50];
  int length = 0;
  DoubleLinkedLIst *list = createDoubleLinkedList(1);
  Jogador *players = ler(&length);
  while (strcmp(entrada, "FIM") != 0) {
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = '\0';
    if (strcmp(entrada, "FIM") == 0) {
      break;
    }
    int id = atoi(entrada);
    addOnListFinal(list, players[id]);
  }
  sort(list);
  showList(list);
  freeList(list);
  free(players);
  return 0;
}
