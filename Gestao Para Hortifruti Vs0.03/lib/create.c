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

    int idDuplicado = 0;
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

    EntradaMercadoria();
}

void ExibirBordas()
{
    borda(120, 5);
    borda(120, 30);
}

int VerificarIdDuplicado(FILE *arquivo, int id)
{
    char row[MAXCHAR];
    char* token;
    Mercadoria produto;

    while (fgets(row, MAXCHAR, arquivo) != NULL) {
        // Remover nova linha do final da string, se existir
        row[strcspn(row, "\n")] = 0;

        token = strtok(row, ";");
        produto.UID = atoi(token);

        if (produto.UID == id) {
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
    if (tamanho == 0) {
        // Se o arquivo estiver vazio, não adiciona nova linha
        fprintf(arquivo, "%d;%s;%s;%.2f;%s;%d;%s", produto->UID, produto->nome, produto->Grupo, produto->preco, produto->Medida, produto->QNT_Estoque, produto->Data_Validade);
    } else {
        // Se o arquivo não estiver vazio, adiciona nova linha antes do produto
        fprintf(arquivo, "\n%d;%s;%s;%.2f;%s;%d;%s", produto->UID, produto->nome, produto->Grupo, produto->preco, produto->Medida, produto->QNT_Estoque, produto->Data_Validade);
    }
}

void fluxoDeVendas() {
    int escolha, linha, coluna, tecla;
    sales vendas;
    vendas.total = 0;

    Sleep(10);
    system("CLS");
    borda(120, 30);
    borda(120, 7);
    borda(33, 30);
    borda(120, 28);

    do {
        // primeiro do para mostrar as informacoes do front de caixa
        Console(114, 2);
        printf("❌");
        Console(3, 2);
        printf("\033[33mＣＡＩＸＡ－ＶＥＮＤＡＳ\033[0m");

        Console(3, 5);
        printf("\033[35mC̲O̲D̲I̲G̲O̲: \033[0m");
        Console(40, 5);
        printf("\033[35mQ̲U̲A̲N̲T̲I̲D̲A̲D̲E̲: \033[0m");
        Console(77, 5);
        printf("\033[35mP̲R̲E̲C̲O̲ U̲N̲I̲T̲A̲R̲I̲O̲: \033[0m");
        Console(40, 7);
        printf("\033[35mT̲O̲T̲A̲L̲ I̲T̲E̲M̲: \033[0m");
        Console(18, 28);
        printf("Usar -> \033[31m← →\033[0m para se guiar no menu. O \033[32mENTER\033[0m para confirmar e o ❌ para sair ou retornar");

        escolha = 1;
        linha = 5;
        coluna = 17;
        Console(coluna, linha);
        printf("➤");

        while (1) {
            setvbuf(stdin, NULL, _IONBF, 0);
            tecla = getch();

            if (tecla == ENTER) {
                switch (escolha) {
                case 1:
                    Console(17, 5);
                    printf(" ");
                    Console(17, 5);
                    scanf(&vendas.productCode);
                    break;
                case 2:
                    Console(61, 5);
                    printf(" ");
                    Console(61, 5);
                    scanf(&vendas.quantity);
                    break;
                case 3:
                    Console(99, 5);
                    printf(" ");
                    Console(99, 5);
                    scanf(&vendas.precoUnitario);
                    break;
                case 4:
                    vendas.total = vendas.quantity * vendas.precoUnitario;
                    Console(140, 5);
                    printf("%.2f", vendas.total);
                    break;
                case 0:
                    // Função para sair ou retornar ao menu anterior
                    printf("Saindo...\n");
                    return;
                }
            }

            if (tecla == 77 || tecla == 75) { // Right or Left arrow keys
                Console(coluna, linha);
                printf(" ");

                if (tecla == 77)
                    escolha++;
                else if (tecla == 75)
                    escolha--;

                if (escolha < 1)
                    escolha = 4;
                else if (escolha > 4)
                    escolha = 1;

                if (escolha == 1) {
                    coluna = 17;
                    linha = 5;
                } else if (escolha == 2) {
                    coluna = 61;
                    linha = 5;
                } else if (escolha == 3) {
                    coluna = 106;
                    linha = 5;
                } else if (escolha == 4) {
                    coluna = 140;
                    linha = 5;
                }

                Console(coluna, linha);
                printf("➤");
            }
        }
    } while (1);
}
