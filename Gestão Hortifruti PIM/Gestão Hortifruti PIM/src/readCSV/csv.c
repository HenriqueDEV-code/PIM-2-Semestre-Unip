#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/csv.h"

#define PRODUTO_ARQUIVO "produtos.csv"

int VerificaArquivoCSV(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (file != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}

void CriaArquivoCSV(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "w");
    if (file == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }
    fprintf(file, "Descricao,Grupo,Data,Unidade,PrecoCompra,Margem,Estoque\n");
    fclose(file);
}

void SaveProductsToCSV(Products *mercadorias) {

    if (!VerificaArquivoCSV(PRODUTO_ARQUIVO)) {
        CriaArquivoCSV(PRODUTO_ARQUIVO);
    }

    FILE *file = fopen(PRODUTO_ARQUIVO, "a"); // Use "a" para anexar
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Escapando o descProduct para evitar problemas com vírgulas
    fprintf(file, "\"%s\",\"%s\",%02d-%02d-%04d,\"%s\",%.2f,%.2f,%d\n",
        mercadorias->descProduct, mercadorias->GroupProduct,
        mercadorias->NEWdata.dia, mercadorias->NEWdata.mes, mercadorias->NEWdata.ano,
        mercadorias->UNProductMedida, mercadorias->PrecoProductCompra,
        mercadorias->MargemProduct, mercadorias->EstoqueEnterProduct);

    fclose(file);
}