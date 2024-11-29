#ifndef SALES_H

#define SALES_H
#define ARQUIVO_VENDAS "sales.csv"
#define MAX_NOME 101
#define MAX_VENDAS 100

typedef struct {
    int UID;
    int itemSale;
    int productCode;
    float quantity;
    float precoUnitario;
    float total;
    char dateSale[11];  // Formato: YYYY-MM-DD
    char bloqueado;
} sales;

void fluxoDeVendas();
void cancelVendas();
void listVendas();
void atualizarEstoque();
void gerarRelatorioVendas(const char *dataInicio, const char *dataFim, int filtroProduto, int filtroUID);

#endif 