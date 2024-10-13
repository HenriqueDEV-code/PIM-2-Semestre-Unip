#include <string.h>
#include "../../include/validation.h"

#define INVALID 0
#define VALID 1

int ValidateProductFields(Products *mercadorias) {
    if (strlen(mercadorias->descProduct) == 0 ||
        strlen(mercadorias->GroupProduct) == 0 ||
        mercadorias->NEWdata.dia == 0 ||
        mercadorias->NEWdata.mes == 0 ||
        mercadorias->NEWdata.ano == 0 ||
        strlen(mercadorias->UNProductMedida) == 0 ||
        mercadorias->PrecoProductCompra <= 0 ||
        mercadorias->MargemProduct <= 0 ||
        mercadorias->EstoqueEnterProduct < 0) {
        return INVALID;
    }
    return VALID;
}
