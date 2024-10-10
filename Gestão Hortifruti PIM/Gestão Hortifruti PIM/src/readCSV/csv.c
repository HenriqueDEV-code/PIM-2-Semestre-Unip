#include <stdlib.h>
#include <string.h>
#include "../../include/csv.h"

// Função para ler um arquivo CSV
void ler_csv(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para leitura.\n", nome_arquivo);
        return;
    }

    char linha[1024];
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

void escrever_csv(const char *nome_arquivo, const char *dados) {
    FILE *arquivo = fopen(nome_arquivo, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", nome_arquivo);
        return;
    }

    fprintf(arquivo, "%s\n", dados);
    fclose(arquivo);
}
