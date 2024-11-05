#include <stdio.h>
#include <string.h>
#include "../include/product.h"

void processarProduto(char** campos, int num_campos, void* dados_ptr) {
    if (num_campos != 7) {
        printf("Linha inválida\n");
        return;
    }

    char** dados = (char**)dados_ptr;
    char* nome_busca = dados[0];
    int* encontrado = (int*)dados[1];

    Mercadoria produto;
    produto.UID = atoi(campos[0]);
    strcpy(produto.nome, campos[1]);
    strcpy(produto.Grupo, campos[2]);
    sscanf(campos[3], "%f", &produto.preco);
    strcpy(produto.Medida, campos[4]);
    produto.QNT_Estoque = atoi(campos[5]);
    strcpy(produto.Data_Validade, campos[6]);

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
        *encontrado = 1; // Marca como encontrado
    }
}

void BuscarProduto() {
    Sleep(500);
    system("CLS");
    char nome_busca[MAX_NOME];
    int encontrado = 0;

    Console(5, 7);
    Ler_String(nome_busca, MAX_NOME, "Digite o nome do produto: ");

    char* dados[] = {nome_busca, (char*)&encontrado};
    readCSV(ARQUIVO_ESTOQUE, processarProduto, dados);

    if (!encontrado) {
        Console(5, 2);
        printf("\033[31m PRODUTO NÃO ENCONTRADO ❗\033[0m\n");
        Sleep(500);
        system("CLS");
        EntradaMercadoria();
    }
}

void leituraTodosProdutos(char** campos, int num_campos) {
    if (num_campos != 7) {
        printf("\033[31m Linha inválida\033[0m\n");
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

    printf("\033[32mPressione Enter para continuar...\n\033[0m");
    getchar();
}

void ListarProduto() {
    Sleep(500);
    system("CLS");
    Console(5, 9);
    printf("\033[32mLista de produtos cadastrados:\n\033[0m");

    readCSV(ARQUIVO_ESTOQUE, leituraTodosProdutos);
}
