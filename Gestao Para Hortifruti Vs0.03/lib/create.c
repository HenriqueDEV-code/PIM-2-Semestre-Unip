#include <stdio.h>
#include <windows.h>
#include "../include/product.h"
#include "../include/vendas.h"
#include "../include/menu.h"
#include "../include/misc.h"

void CadastroProduto()
{
    Sleep(500);
    system("CLS");

    int idDuplicado = 0, tecla;
    Mercadoria produto;
    FILE *arquivo;
    ExibirBordas();
    Console(5, 8);
    Ler_Int(&produto.UID, "Digite o ID do produto: ");

    if ((arquivo = fopen(ARQUIVO_ESTOQUE, "r")) != NULL)
    {
        if (VerificarIdDuplicado(arquivo, produto.UID))
        {
            showNotification(L"Produto com Id Duplicado", MB_ICONERROR);
            fclose(arquivo);
            EntradaMercadoria();
            return;
        }
        fclose(arquivo);
    }

    Console(5, 3);

    ColetarDadosProduto(&produto);

    if ((arquivo = fopen(ARQUIVO_ESTOQUE, "a")) != NULL)
    {
        SalvarProduto(arquivo, &produto);
        fclose(arquivo);
        Console(5, 2);
        printf("Produto cadastrado com sucesso!\n");
        Sleep(1500);
    }
    else
    {
        showNotification(L"Erro no arquivo", MB_ICONEXCLAMATION);
    }

    return EntradaMercadoria();
}

void ExibirBordas()
{
    borda(120, 5);
    borda(120, 30);
}

int VerificarIdDuplicado(FILE *arquivo, int id)
{
    char row[MAXCHAR];
    char *token;
    Mercadoria produto;

    while (fgets(row, MAXCHAR, arquivo) != NULL)
    {
        // Remover nova linha do final da string, se existir
        row[strcspn(row, "\n")] = 0;

        token = strtok(row, ";");
        produto.UID = atoi(token);

        if (produto.UID == id)
        {
            return 1;
        }
    }

    return 0;
}

void ColetarDadosProduto(Mercadoria *produto)
{
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

    do
    {
        Console(5, 14);
        Ler_String(produto->Data_Validade, sizeof(produto->Data_Validade), "Digite a data de validade (YYYY-MM-DD): ");
    } while (!Validade_Data(produto->Data_Validade));
}

void SalvarProduto(FILE *arquivo, Mercadoria *produto)
{
    // Verifica se o arquivo está vazio
    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    if (tamanho == 0)
    {
        // Se o arquivo estiver vazio, não adiciona nova linha
        fprintf(arquivo, "%d;%s;%s;%.2f;%s;%d;%s", produto->UID, produto->nome, produto->Grupo, produto->preco, produto->Medida, produto->QNT_Estoque, produto->Data_Validade);
    }
    else
    {
        // Se o arquivo não estiver vazio, adiciona nova linha antes do produto
        fprintf(arquivo, "\n%d;%s;%s;%.2f;%s;%d;%s", produto->UID, produto->nome, produto->Grupo, produto->preco, produto->Medida, produto->QNT_Estoque, produto->Data_Validade);
    }
}

int obterProximoIdCompra(FILE *arquivoVendas) {
    int idCompra = 1;
    fseek(arquivoVendas, 0, SEEK_END); // Ir para o final do arquivo
    long tamanho = ftell(arquivoVendas);

    if (tamanho > 0) {
        fseek(arquivoVendas, -1, SEEK_END);

        // Retroceder até encontrar o início da última linha
        while (ftell(arquivoVendas) > 0) {
            char ch;
            fseek(arquivoVendas, -1, SEEK_CUR);
            ch = fgetc(arquivoVendas);

            if (ch == '\n') {
                break;
            }
            fseek(arquivoVendas, -1, SEEK_CUR);
        }

        // Ler a última linha
        char linha[256];
        fgets(linha, sizeof(linha), arquivoVendas);
        linha[strcspn(linha, "\n")] = '\0'; // Remover o '\n'

        // Obter o ID da última compra
        sscanf(linha, "%d;", &idCompra);
        idCompra++;
    }

    return idCompra;
}

void salvarVendasCSV(sales vendas[], int totalVendas) {
    FILE *arquivoVendas;

    // Verificar ou criar o arquivo
    if (!verificarCriarArquivo(ARQUIVO_VENDAS)) {
        return;
    }

    // Abrir o arquivo em modo de append
    arquivoVendas = fopen(ARQUIVO_VENDAS, "a");
    if (arquivoVendas == NULL) {
        perror("Erro ao abrir o arquivo de vendas");
        return;
    }

    int itemSale = 1; // Contador para os itens de uma mesma compra

    for (int i = 0; i < totalVendas; i++) {
        // Validar os dados essenciais antes de salvar
        if (vendas[i].UID <= 0 || vendas[i].productCode <= 0 || vendas[i].quantity <= 0 || vendas[i].precoUnitario <= 0) {
            fprintf(stderr, "Erro: Dados inválidos para o item %d na compra %d\n", itemSale, vendas[i].UID);
            continue; // Pule este item e prossiga com os demais
        }

        // Garantir que o bloqueado está com o valor padrão 'N'
        vendas[i].bloqueado = 'N';

        // Escrever os dados no arquivo
        fprintf(arquivoVendas, "%d;%d;%d;%.2f;%.2f;%.2f;%s;%c\n", // ;%d;%.2f;%.2f;%.2f;%s;%c\n
                vendas[i].UID,           // ID da compra
                i,      // Item da compra
                vendas[i].productCode,   // Código do produto --ok
                vendas[i].quantity,      // Quantidade
                vendas[i].precoUnitario, // Preço unitário
                vendas[i].total,         // Total do item
                vendas[i].dateSale,      // Data da venda
                vendas[i].bloqueado      // Status bloqueado
        );

        // Se o próximo item pertence a uma nova compra, reiniciar o contador `itemSale`
        if (i + 1 < totalVendas && vendas[i + 1].UID != vendas[i].UID) {
            itemSale = 1;
        } else {
            itemSale++;
        }
    }

    fclose(arquivoVendas);

    // Notificação de sucesso
    showNotification(L"Vendas salvas com sucesso.\n", MB_ICONINFORMATION);
}

void fluxoDeVendas() {
    int escolha, linha, coluna, tecla;
    int linhaAtual = 5;
    char dataVenda[11];
    sales vendas[MAX_VENDAS];
    int totalVendas = 0;
    float subtotal = 0.0;
    Mercadoria produto;
    FILE *arquivo;

    int idCompra = 1; // Valor padrão caso o arquivo esteja vazio
    FILE *arquivoVendas = fopen(ARQUIVO_VENDAS, "r+");
    if (arquivoVendas) {
        idCompra = obterProximoIdCompra(arquivoVendas);
        fclose(arquivoVendas);
    }

    Sleep(10);
    system("CLS");
    borda(120, 30);
    borda(120, 5);
    borda(120, 25);
    borda(120, 28);
    borda(30, 25);
    borda(100, 25);

    Console(2, 1);
    printf("\033[33m▒█▀▀█ ░█▀▀█ ▀█▀ ▀▄▒▄▀ ░█▀▀█");
    Console(2, 2);
    printf("▒█░░░ ▒█▄▄█ ▒█░ ░▒█░░ ▒█▄▄█");
    Console(2, 3);
    printf("▒█▄▄█ ▒█░▒█ ▄█▄ ▄▀▒▀▄ ▒█░▒█\033[0m");
    Console(18, 28);
    printf("Usar -> \033[31m← →\033[0m para se guiar no menu. O \033[32mENTER\033[0m para confirmar e o \033[34mESC\033[0m para sair ou retornar");

    // Cabeçalho do Menu Superior
    Console(30, 3);
    printf("\033[36mITEM\033[0m");
    Console(38, 3);
    printf("\033[36mDESCRICAO\033[0m");
    Console(59, 3);
    printf("\033[36mQUANTIDADE\033[0m");
    Console(72, 3);
    printf("\033[36mTIPO\033[0m");
    Console(79, 3);
    printf("\033[36mVALOR\033[0m");
    Console(88, 3);
    printf("\033[36mTOTAL\033[0m");
    Console(100, 3);
    printf("\033[33mSUB TOTAL: \033[0m");

    // Menu inferior para entrada de dados
    Console(2, 26);
    printf("\033[35mID: \033[0m");
    Console(29, 26);
    printf("\033[35mQUANTIDADE: \033[0m");

    // Botão Confirmar Compra
    Console(98, 26);
    printf("\033[32mCONFIRMAR COMPRA\033[0m");

    escolha = 1;
    linha = 26;
    coluna = 6;
    Console(coluna, linha);
    printf(" ");

    while (1)
    {
        setvbuf(stdin, NULL, _IONBF, 0);
        tecla = _getch();

        if (tecla == ENTER)
        {
            if (escolha == 1)
            {
                Console(6, 26);
                scanf("%d", &vendas[totalVendas].productCode);
            }

            if (escolha == 2) {
                Console(26, 26);
                scanf("%f", &vendas[totalVendas].quantity);

                // Abrir o arquivo de produtos e buscar o produto
                arquivo = fopen(ARQUIVO_ESTOQUE, "r");
                if (arquivo == NULL)
                {
                    printf("Erro ao abrir o arquivo de produtos.\n");
                    return;
                }

                // Buscar o produto pelo ID
                if (BuscarProdutoPorID(arquivo, vendas[totalVendas].productCode, &produto))
                {
                    // Exibir os dados do produto na linha atual
                    Console(30, linhaAtual);
                    printf("%d", produto.UID);
                    Console(38, linhaAtual);
                    printf("%s", produto.nome);
                    Console(59, linhaAtual);
                    printf("%.2f", vendas[totalVendas].quantity); // Quantidade informada pelo usuário
                    Console(72, linhaAtual);
                    printf("%s", produto.Medida);
                    Console(79, linhaAtual);
                    printf("%.2f", produto.preco);
                    Console(88, linhaAtual);
                    float totalProduto = produto.preco * vendas[totalVendas].quantity;
                    printf("%.2f", totalProduto);

                    // Atualizar o subtotal
                    subtotal += totalProduto;
                    Console(100, 5);
                    printf("\033[33m%.2f\033[0m", subtotal);

                    // Armazenar a venda no array
                    vendas[totalVendas].UID = idCompra; // um id incremental do arquivo
                    vendas[totalVendas].productCode = produto.UID;
                    vendas[totalVendas].precoUnitario = produto.preco;
                    vendas[totalVendas].total = totalProduto;
                    obterDataAtual(dataVenda);
                    strcpy(vendas[totalVendas].dateSale, dataVenda);// Data da venda (exemplo)

                    // Mover para a próxima linha para o próximo produto
                    linhaAtual++;
                    totalVendas++;
                }
                else
                {
                    Console(30, linhaAtual);
                    showNotification(L"Produto não encontrado.", MB_ICONINFORMATION);
                }

                fclose(arquivo); // Fechar o arquivo após o uso
            }

            // Confirmar compra
            if (escolha == 3)
            {
                salvarVendasCSV(vendas, totalVendas);
                FluxoDeCaixa();
            }
        }
        else if (tecla == ESC)
        {
            return FluxoDeCaixa();
        }

        if (tecla == 77 || tecla == 75)
        {
            Console(coluna, linha);
            printf(" ");

            if (tecla == 77) escolha--;
            else if (tecla == 75) escolha++;

            if (escolha < 1)
                escolha = 3;
            else if (escolha > 3)
                escolha = 1;

            if (escolha == 1) { coluna = 6; linha = 26; }
            else if (escolha == 2) { coluna = 23; linha = 26; }
            else if (escolha == 3) { coluna = 100; linha = 26; }
            Console(coluna, linha);
            printf(" ");
        }
    }
}