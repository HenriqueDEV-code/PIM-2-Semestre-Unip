#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "../include/product.h"
#include "../include/vendas.h"

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
    borda(120,30);
    borda(120,5);
    int id_produto;
    Mercadoria produto;
    int encontrado = 0;

    Console(5, 7);
    Ler_Int(&id_produto, "\033[36mDigite o ID do produto: \033[0m");

    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "r");
    if (arquivo == NULL) {
        Console(5, 2);
        printf("\a\033[31mERRO AO ABRIR O ARQUIVO❗\033[0m\n");
        return;
    }

    encontrado = BuscarProdutoPorID(arquivo, id_produto, &produto);
    fclose(arquivo);

    if (encontrado) {
        Console(5, 9);
        printf("\033[31m-----------------------------------------\033[0m");
        Console(5, 10);
        printf("\033[36mID:\033[0m %d", produto.UID);
        Console(5, 11);
        printf("\033[36mNOME:\033[0m %s", produto.nome);
        Console(5, 12);
        printf("\033[36mCATEGORIA:\033[0m %s", produto.Grupo);
        Console(5, 13);
        printf("\033[36mPREÇO:\033[0m R\033[32m$\033[0m %.2f", produto.preco);
        Console(5, 14);
        printf("\033[36mUNIDADE DE MEDIDA:\033[0m %s", produto.Medida);
        Console(5, 15);
        printf("\033[36mESTOQUE:\033[0m %d", produto.QNT_Estoque);
        Console(5, 16);
        printf("\033[36mVALIDADE:\033[0m %s", produto.Data_Validade);
        Console(5, 17);
        printf("\033[31m-----------------------------------------\033[0m");
        Console(5, 18);
        printf("\033[32mPressione Enter para continuar...\033[0m");
        getchar();
    } else {
        Console(5, 2);
        printf("\033[31m PRODUTO NÃO ENCONTRADO ❗\033[0m\n");
        Sleep(500);
        system("CLS");
        EntradaMercadoria();
    }
}

int BuscarProdutoPorID(FILE *arquivo, int id, Mercadoria *produto) {
    char row[MAXCHAR];
    char* token;

    while (fgets(row, MAXCHAR, arquivo) != NULL) {
        // Remover nova linha do final da string, se existir
        row[strcspn(row, "\n")] = 0;

        token = strtok(row, ";");
        produto->UID = atoi(token);

        if (produto->UID == id) {
            token = strtok(NULL, ";");
            strcpy(produto->nome, token);

            token = strtok(NULL, ";");
            strcpy(produto->Grupo, token);

            token = strtok(NULL, ";");
            produto->preco = atof(token);

            token = strtok(NULL, ";");
            strcpy(produto->Medida, token);

            token = strtok(NULL, ";");
            produto->QNT_Estoque = atoi(token);

            token = strtok(NULL, "\n");
            strcpy(produto->Data_Validade, token);

            return 1; // Produto encontrado
        }
    }

    return 0; // Produto não encontrado
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
    printf("\t\033[31m-----------------------------------------\n\033[0m");
    printf("\tID: %d\n", UID);
    printf("\tNOME: %s\n", nome);
    printf("\tCATEGORIA: %s\n", grupo);
    printf("\tPREÇO: R\033[32m$\033[0m %.2f\n", preco);
    printf("\tUNIDADE DE MEDIDA: %s\n", medida);
    printf("\tESTOQUE: %d\n", QNT_Estoque);
    printf("\tVALIDADE: %s\n", data_validade);
    printf("\t\033[31m-----------------------------------------\n\033[0m");

    printf("\t\033[32mPressione Enter para continuar...\n\033[0m");
    getchar();
}

void ListarProduto() {
    Sleep(500);
	system("CLS");
    Console(5, 9);
    printf("\033[32m   Lista de produtos cadastrados:\n\033[0m");

    readCSV(ARQUIVO_ESTOQUE, leituraTodosProdutos);
}

void gerarRelatorioVendas(const char *dataInicio, const char *dataFim, int filtroProduto, int filtroUID) {
    FILE *arquivo = fopen(ARQUIVO_VENDAS, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de vendas");
        return;
    }

    char linha[256];
    int encontrouVendas = 0;

    // Cabeçalho do relatório
    printf("=========================================================================================\n");
    printf("| %-5s | %-5s | %-10s | %-10s | %-10s | %-10s | %-10s | %-8s |\n", 
           "UID", "ITEM", "PRODUTO", "QTDE", "PRECO", "TOTAL", "DATA", "STATUS");
    printf("=========================================================================================\n");

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        sales venda;
        sscanf(linha, "%d;%d;%d;%f;%f;%f;%10[^;];%c", 
               &venda.UID, &venda.itemSale, &venda.productCode, &venda.quantity,
               &venda.precoUnitario, &venda.total, venda.dateSale, &venda.bloqueado);

        // Aplicar os filtros
        int incluir = 1;
        if (dataInicio && strcmp(venda.dateSale, dataInicio) < 0) incluir = 0;
        if (dataFim && strcmp(venda.dateSale, dataFim) > 0) incluir = 0;
        if (filtroProduto > 0 && venda.productCode != filtroProduto) incluir = 0;
        if (filtroUID > 0 && venda.UID != filtroUID) incluir = 0;

        if (incluir) {
            encontrouVendas = 1;
            // Imprimir a linha do relatório
            printf("| %-5d | %-5d | %-10d | %-10.2f | %-10.2f | %-10.2f | %-10s | %-8c |\n", 
                   venda.UID, venda.itemSale, venda.productCode, venda.quantity, 
                   venda.precoUnitario, venda.total, venda.dateSale, venda.bloqueado);
        }
    }

    fclose(arquivo);

    if (!encontrouVendas) {
        printf("| Nenhuma venda encontrada com os filtros especificados.                             |\n");
    }
    printf("=========================================================================================\n");

    // Aguardar o pressionamento de uma tecla antes de sair
    printf("\nPressione qualquer tecla para retornar...");
    getch();
    system("CLS");
}

void gerarRelatorioEstoque(const char *dataInicio, const char *dataFim, int filtroProduto, int filtroUID) {
    FILE *arquivo = fopen(ARQUIVO_ESTOQUE, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de estoque");
        return;
    }

    char linha[256];
    int encontrouEstoque = 0;

    // Cabeçalho do relatório
    printf("=========================================================================================\n");
    printf("| %-5s | %-15s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", 
           "UID", "NOME", "GRUPO", "PREÇO", "MEDIDA", "SALDO", "VALIDADE");
    printf("=========================================================================================\n");

    // Ler cada linha do arquivo
    while (fgets(linha, sizeof(linha), arquivo)) {
        Mercadoria estoque;
        // Ajuste no formato da leitura
        sscanf(linha, "%d;%49[^;];%d;%f;%f;%f;%10[^;]", 
               &estoque.UID, estoque.nome, &estoque.Grupo, &estoque.preco, 
               &estoque.Medida, &estoque.QNT_Estoque, estoque.Data_Validade);

        // Aplicar os filtros
        int incluir = 1;
        if (dataInicio && strcmp(estoque.Data_Validade, dataInicio) < 0)
            incluir = 0;
        if (dataFim && strcmp(estoque.Data_Validade, dataFim) > 0)
            incluir = 0;
        if (filtroProduto > 0 && estoque.Grupo != filtroProduto)
            incluir = 0;
        if (filtroUID > 0 && estoque.UID != filtroUID)
            incluir = 0;

        // Se passar nos filtros, imprime a linha
        if (incluir) {
            encontrouEstoque = 1;
            printf("| %-5d | %-15s | %-10d | %-10.2f | %-10.2f | %-10.2f | %-10s |\n", 
                   estoque.UID, estoque.nome, estoque.Grupo, estoque.preco, 
                   estoque.Medida, estoque.QNT_Estoque, estoque.Data_Validade);
        }
    }

    fclose(arquivo);

    if (!encontrouEstoque) {
        printf("| Nenhum item encontrado com os filtros especificados. |\n");
    }

    printf("=========================================================================================\n");

    // Aguardar o pressionamento de uma tecla antes de sair
    printf("\nPressione qualquer tecla para retornar...");
    getch();
    system("CLS");
}