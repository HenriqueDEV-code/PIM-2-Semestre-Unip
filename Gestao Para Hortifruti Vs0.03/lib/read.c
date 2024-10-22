#include <stdio.h>
#include <string.h>
#include "../include/product.h"


void BuscarProduto() {
    Sleep(500);
    system("CLS");
    FILE* arquivo = fopen(ARQUIVO_ESTOQUE, "r");
    if (arquivo == NULL) {
        Console(5, 2);
        printf("\aERRO AO ABRIR O ARQUIVO!\n");
        return;
    }

    Mercadoria produto;
    char nome_busca[MAX_NOME];
    int encontrado = 0;
    Console(5, 7);
    Ler_String(nome_busca, MAX_NOME, "Digite o nome do produto: ");

    while (fscanf(arquivo, "%d;%[^;];%[^;];%f;%[^;];%d;%[^;]\n", &produto.UID, produto.nome, produto.Grupo, &produto.preco, produto.Medida, &produto.QNT_Estoque, produto.Data_Validade) != EOF) {
        if (strstr(produto.nome, nome_busca)) {
            Console(5, 9);
            printf("PRODUTO ENCONTRADO:\n");
            printf("ID: %d\n", produto.UID);
            printf("NOME: %s\n", produto.nome);
            printf("CATEGORIA: %s\n", produto.Grupo);
            printf("PREÇO: R$ %.2f\n", produto.preco);
            printf("UNIDADE DE MEDIDA: %s\n", produto.Medida);
            printf("ESTOQUE: %d\n", produto.QNT_Estoque);
            printf("VALIDADE: %s\n", produto.Data_Validade);
            encontrado = 1;
            break; // Produto encontrado, sair do loop
        }
    }

    if (!encontrado) {
        Console(5, 2);
        printf("PRODUTO NÃO ENCONTRADO ❗\n");
        Sleep(500);
        system("CLS");
        EntradaMercadoria();
    }

    fclose(arquivo);
}

void leituraTodosProdutos(char** campos, int num_campos) {
    if (num_campos != 7) {
        printf("Linha inválida\n");
        return;
    }

    int UID = atoi(campos[0]);
    char* nome = campos[1];
    char* grupo = campos[2];
    float preco;
	sscanf(campos[3], "%f", &preco);
    char* medida = campos[4];
    int QNT_Estoque = atoi(campos[5]);
    char* data_validade = campos[6];

    printf("-----------------------------------------\n");
    printf("ID: %d\n", UID);
    printf("NOME: %s\n", nome);
    printf("CATEGORIA: %s\n", grupo);
    printf("PREÇO: R$ %.2f\n", preco);
    printf("UNIDADE DE MEDIDA: %s\n", medida);
    printf("ESTOQUE: %d\n", QNT_Estoque);
    printf("VALIDADE: %s\n", data_validade);
    printf("-----------------------------------------\n");

    printf("Pressione Enter para continuar...\n");
    getchar();
}

void ListarProduto() {
    Sleep(500);
    system("CLS");
    Console(5, 9);
    printf("Lista de produtos cadastrados:\n");

    readCSV(ARQUIVO_ESTOQUE, leituraTodosProdutos);
}
