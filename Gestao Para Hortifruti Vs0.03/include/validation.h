#ifndef VALIDATION_H
#define VALIDATION_H
#include "Estrutura.h"

#define MAX_PRODUCTS 100

int ValidateProductFields(Mercadoria *mercadorias);
int ValidateDate(const char* data);

#endif