#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* values = NULL;

void readAll(char* x, int archiveLen, FILE* file) {
    fread(x, 1, archiveLen, file);
    x[archiveLen] = '\0';
}

int getLenth(FILE* file) {
    fseek(file, 0, SEEK_END);
    int len = ftell(file);
    fseek(file, 0, SEEK_SET);
    return len;
}

char* getCode() {
    FILE* file = fopen("codigos.txt", "rt");
    if(file == NULL) {
        printf("Arquivo não existe!");
        exit(0);
    }
    int archiveLen = getLenth(file);

    char* mainCode = (char*)malloc(sizeof(char)*archiveLen);
        
    if(mainCode == NULL) {
        printf("Erro ao alocar memoria!");
        exit(0);
    }

    readAll(mainCode, archiveLen, file);
    fclose(file);
    return mainCode;
}

char* deleteSpace(char* x) {
    char* newX = (char*)malloc(sizeof(char)*strlen(x));
    int pos = 0;
    for(int i = 0; i < strlen(x); i++) {
        if(x[i] != ' '){
            newX[pos++] = x[i];
        }
    }
    newX[pos] = '\0';
    free(x);

    return newX;
}

char toHex(char* instrution) {
    if(strcmp(instrution, "nB") == 0) {
        return '0';
    } else if(strcmp(instrution, "nAeBn") == 0) {
        return  '1';
    } else if(strcmp(instrution, "nAeB") == 0) {
        return '2';
    } else if(strcmp(instrution, "Lzero") == 0) {
        return '3';
    } else if(strcmp(instrution, "AeBn") == 0) {
        return '4';
    } else if(strcmp(instrution, "nA") == 0) {
        return '5';
    } else if(strcmp(instrution, "AxB") == 0) {
        return '6';
    } else if(strcmp(instrution, "AenB") == 0) {
        return '7';
    } else if(strcmp(instrution, "nAonB") == 0) {
        return '8';
    } else if(strcmp(instrution, "nAxnB") == 0) {
        return '9';
    } else if(strcmp(instrution, "Bcopia") == 0) {
        return 'A';
    } else if(strcmp(instrution, "AeB") == 0) {
        return 'B';
    } else if(strcmp(instrution, "Lum") == 0) {
        return 'C';
    } else if(strcmp(instrution, "AonB") == 0) {
        return 'D';
    } else if(strcmp(instrution, "AoB") == 0) {
        return 'E';
    } else if(strcmp(instrution, "Acopia") == 0) {
        return 'F';
    }
}

char* getInstruction(char* code, int ini) {
    char* x = (char*)malloc(sizeof(char)*10);
    int i = ini, j = 0;
    for(i = ini; code[i] != ';'; i++) {
        x[j++] = code[i];
    }
    x[j] = '\0';

    return x;
}

void compiler(char* code) {
    FILE* file = fopen("compiled.txt", "wt");
    for(int i = 0; i < strlen(code); i++) {
        if(code[i] == 'X') {
            i += 2;
            values[0] = code[i];
        } else if(code[i] == 'Y') {
            i += 2;
            values[1] = code[i];
        } else if(code[i] == 'W') {
            i += 2;
            char* instruction = getInstruction(code, i);
            values[2] = toHex(instruction);
            fprintf(file, "%s\n", values);
            printf("%s\n", values);
            free(instruction);
        }
    }
    fprintf(file, "ZZZ");
    fclose(file);
}


int main() {
    values = (char*)malloc(sizeof(char)*4);
    values[3] = '\0';
    char* mainCode = getCode();
    mainCode = deleteSpace(mainCode);
    compiler(mainCode);
    free(mainCode);
    free(values);
}

