#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/product.h"

void verificarProduto(char** campos, int num_campos, void* dados_ptr) {
    if (num_campos != 7) {
        printf("Linha inválida\n");
        return;
    }

    char** dados = (char**)dados_ptr;
    int id_produto = atoi(dados[0]);
    int* encontrado = (int*)dados[1];

    int UID = atoi(campos[0]);

    if (id_produto == UID) {
        *encontrado = 1; // Marca como encontrado
    }
}

int produtoExiste(int id_produto) {
    int encontrado = 0;
    char id_str[10];
    sprintf(id_str, "%d", id_produto);
    char* dados[] = {id_str, (char*)&encontrado};

    readCSV(ARQUIVO_ESTOQUE, verificarProduto, dados);

    return encontrado;
}

void ExcluirProduto() {
    FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
    
    Sleep(500);
    system("CLS");
    if (arquivo == NULL) {
        Console(5, 2);
        printf("\aERRO AO ABRIR O ARQUIVO❗\n");
        return;
    }
    FILE* temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        Console(36, 2);
        printf("ERRO AO CRIAR ARQUIVO TEMPORÁRIO❗\n");
        fclose(arquivo);
        return;
    }

    Mercadoria produto;
    int id_produto;

    Console(5, 7);
    Ler_Int(&id_produto, "Digite o ID do produto que deseja excluir do estoque: ");

    if (!produtoExiste(id_produto)) {
        Console(5, 2);
        printf("PRODUTO NÃO ENCONTRADO ❗\n");
        Sleep(500);
        system("CLS");
        fclose(arquivo);
        fclose(temp);
        remove("temp.csv");
        EntradaMercadoria();
        return;
    }

    while (fscanf(arquivo, "%d;%[^;];%[^;];%f;%[^;];%d;%[^;]\n", &produto.UID, produto.nome, produto.Grupo, &produto.preco, produto.Medida, &produto.QNT_Estoque, produto.Data_Validade) != EOF) {
        if (id_produto != produto.UID) {
            fprintf(temp, "%d;%s;%s;%.2f;%s;%d;%s\n", produto.UID, produto.nome, produto.Grupo, produto.preco, produto.Medida, produto.QNT_Estoque, produto.Data_Validade);
        }
    }

    fclose(arquivo);
    fclose(temp);
    remove(ARQUIVO_ESTOQUE);
    rename("temp.csv", ARQUIVO_ESTOQUE);

    Console(5, 2);
    printf("PRODUTO EXCLUÍDO COM SUCESSO❗\n");
    Sleep(500);
    system("CLS");
    EntradaMercadoria();
}
