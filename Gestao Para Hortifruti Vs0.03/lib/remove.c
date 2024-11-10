#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/product.h"

#define MAXCHAR 1000

void ExcluirProduto() {
    Sleep(500);
    system("CLS");
    borda(120,30);
    borda(120,5);
    FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
    if (arquivo == NULL) {
        Console(5, 2);
        printf("\a\033[31mERRO AO ABRIR O ARQUIVO❗\033[0m\n");
        return;
    }

    FILE* temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        Console(36, 2);
        printf("\033[31mERRO AO CRIAR ARQUIVO TEMPORARIO❗\033[0m\n");
        fclose(arquivo);
        return;
    }

    char row[MAXCHAR];
    char* token;
    Mercadoria produto;
    int id_produto = 0, encontrado = 0;
    Console(5, 7);
    Ler_Int(&id_produto, "Digite o ID do produto que deseja excluir do estoque: ");

    while (fgets(row, MAXCHAR, arquivo) != NULL) {
        // Remover nova linha do final da string, se existir
        row[strcspn(row, "\n")] = 0;

        token = strtok(row, ";");
        produto.UID = atoi(token);

        token = strtok(NULL, ";");
        strcpy(produto.nome, token);

        token = strtok(NULL, ";");
        strcpy(produto.Grupo, token);

        token = strtok(NULL, ";");
        produto.preco = atof(token);

        token = strtok(NULL, ";");
        strcpy(produto.Medida, token);

        token = strtok(NULL, ";");
        produto.QNT_Estoque = atoi(token);

        token = strtok(NULL, "\n");
        strcpy(produto.Data_Validade, token);

        if (produto.UID == id_produto) {
            encontrado = 1;
            continue; // Pula a escrita deste produto no arquivo temporário
        }

        fprintf(temp, "%d;%s;%s;%.2f;%s;%d;%s\n", produto.UID, produto.nome, produto.Grupo, produto.preco, produto.Medida, produto.QNT_Estoque, produto.Data_Validade);
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO_ESTOQUE);
    rename("temp.csv", ARQUIVO_ESTOQUE);

    if (encontrado) {
        Console(5, 2);
        printf("\033[32mProduto excluído com sucesso!\033[0m\n");
    } else {
        Console(5, 2);
        printf("\033[31mProduto não encontrado!\033[0m\n");
    }
    Sleep(1500);
    EntradaMercadoria();
}