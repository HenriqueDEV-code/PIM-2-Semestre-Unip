#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "../include/product.h"
#include "../include/misc.h"

void EditeProduto() {
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
    Ler_Int(&id_produto, "\033[36mDigite o ID do produto que deseja editar:\033[0m ");

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
            Console(5, 2);
            printf("\033[32mProduto encontrado! Atualize os dados:\033[0m\n");
            Console(5, 8);
            Ler_String(produto.nome, sizeof(produto.nome), "\033[36mNovo nome:\033[0m ");
            Console(5, 9);
            Ler_String(produto.Grupo, sizeof(produto.Grupo), "\033[36mNova categoria:\033[0m ");
            Console(5, 10);
            Ler_Float(&produto.preco, "\033[36mNovo preço:\033[0m ");
            Console(5, 11);
            Ler_Int(&produto.QNT_Estoque, "\033[36mNova quantidade em estoque:\033[0m ");

            // Validação da nova data de validade
            do {
                Console(5, 12);
                Ler_String(produto.Data_Validade, sizeof(produto.Data_Validade), "Nova data de validade (YYYY-MM-DD): ");
            } while (!Validade_Data(produto.Data_Validade));
        }

        fprintf(temp, "%d;%s;%s;%.2f;%s;%d;%s\n", produto.UID, produto.nome, produto.Grupo, produto.preco, produto.Medida, produto.QNT_Estoque, produto.Data_Validade);
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO_ESTOQUE);
    rename("temp.csv", ARQUIVO_ESTOQUE);

    if (encontrado) {
        Console(5, 2);
        printf("\033[32mProduto editado com sucesso!\033[0m\n");
    } else {
        Console(5, 2);
        printf("\033[31mProduto nao encontrado!\033[0m\n");
    }
    Sleep(1500);
    EntradaMercadoria();
}