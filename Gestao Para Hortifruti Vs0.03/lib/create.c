#include <stdio.h>
#include <windows.h>  // Para Sleep e system
#include "../include/product.h"
#include "../include/menu.h"
#include "../include/misc.h"

void CadastroProduto() {
    Sleep(500);
    system("CLS");

    int idDuplicado = 0;
    Mercadoria produto;
    FILE* arquivo;

    ExibirBordas();
    Console(5, 8);
    Ler_Int(&produto.UID, "Digite o ID do produto: ");

    if ((arquivo = fopen(ARQUIVO_ESTOQUE, "r")) == NULL) {
        ExibirErroArquivo();
        return EntradaMercadoria();
    }

    if (VerificarIdDuplicado(arquivo, produto.UID)) {
        ExibirErroIdDuplicado(produto.UID);
        return EntradaMercadoria();
    }

    fclose(arquivo);

    Console(5, 3);
    printf("ID %d CADASTRADO COM SUCESSO❗", produto.UID);

    ColetarDadosProduto(&produto);

    if ((arquivo = fopen(ARQUIVO_ESTOQUE, "a")) != NULL) {
        SalvarProduto(arquivo, &produto);
        fclose(arquivo);
        Console(5, 2);
        printf("Produto cadastrado com sucesso!\n");
        Sleep(1500);
    } else {
        ExibirErroArquivo();
    }

    EntradaMercadoria();
}

void ExibirBordas() {
    borda(120, 5);
    borda(120, 30);
}

void ExibirErroArquivo() {
    Console(5, 2);
    printf("\aERRO AO ABRIR O ARQUIVO❗\n");
}

int VerificarIdDuplicado(FILE* arquivo, int id) {
    Mercadoria temp;
    while (fscanf(arquivo, "%d;%*[^;];%*[^;];%*f;%*[^;];%*d;%*[^;]\n", &temp.UID) != EOF) {
        if (temp.UID == id) {
            return 1;
        }
    }
    return 0;
}

void ExibirErroIdDuplicado(int id) {
    Console(5, 2);
    printf("ERRO: O ID %d JA EXISTE NO SISTEMA❗", id);
    Console(5, 3);
    printf("CADASTRO ABORTADO DEVIDO A DUPLICIDADE DE ID.");
    Sleep(500);
    system("CLS");
}

void ColetarDadosProduto(Mercadoria* produto) {
    Console(5, 9);
    Ler_String(produto->nome, sizeof(produto->nome), "Digite o nome do produto: ");
    Console(5, 10);
    Ler_String(produto->Grupo, sizeof(produto->Grupo), "Digite a categoria do produto: ");
    Console(5, 11);
    Ler_Float(&produto->preco, "Digite o preço do produto: ");
    Console(5, 12);
    Ler_Unidade_Medida(produto->Medida, sizeof(produto->Medida), "Digite a unidade de medida (UN, CX, KG): ");
    Console(5, 13);
    Ler_Int(&produto->QNT_Estoque, "Digite a quantidade em estoque: ");

    do {
        Console(5, 14);
        Ler_String(produto->Data_Validade, sizeof(produto->Data_Validade), "Digite a data de validade (YYYY-MM-DD): ");
    } while (!Validade_Data(produto->Data_Validade));
}

void SalvarProduto(FILE* arquivo, Mercadoria* produto) {
    fprintf(arquivo, "\n%d;%s;%s;%.2f;%s;%d;%s", produto->UID, produto->nome, produto->Grupo, produto->preco, produto->Medida, produto->QNT_Estoque, produto->Data_Validade);
}
