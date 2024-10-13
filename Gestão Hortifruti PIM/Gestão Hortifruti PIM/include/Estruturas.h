#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <stdio.h>

enum keys {
    ENTER = 13,
};

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char descProduct[100];
    char GroupProduct[100];
    struct {
        int dia;
        int mes;
        int ano;
    } NEWdata;
    char UNProductMedida[10];
    double PrecoProductCompra;
    double MargemProduct;
    int EstoqueEnterProduct;
} Products;

int MenuPrincipalSistema();
int Cadastro();
void Vendas();
void PesquisaPreco();
void RelatoriosGerais();
void QuemSomos();
void Sujestao();

#endif