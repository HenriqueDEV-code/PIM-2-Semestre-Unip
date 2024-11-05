#ifndef SALES_H

#define SALES_H
#define ARQUIVO_VENDAS "sales.csv"
#define MAX_NOME 101

typedef struct {
    int UID;
    int numberSale;
    int productCode;
    float quantity;
    float precoUnitario;
    float total;
    char dateSale[11];  // Formato: YYYY-MM-DD
} sales;

void fluxoDeVendas();
void cancelVendas();
void listVendas();

#endif 