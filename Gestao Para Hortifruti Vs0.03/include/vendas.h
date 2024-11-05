#ifndef SALES_H

#define SALES_H
#define ARQUIVO_VENDAS "sales.csv"
#define MAX_NOME 101

typedef struct {
    int UID;
    float precoUnitario;
    int numberSale;
    char dateSale[11];  // Formato: YYYY-MM-DD
} sales;

void fluxoDeVendas();
void cancelVendas();
void listVendas();

#endif 