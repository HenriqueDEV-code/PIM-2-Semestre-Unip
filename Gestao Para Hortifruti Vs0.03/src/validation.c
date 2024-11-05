#include <string.h>
#include "../include/validation.h"

#define INVALID 0
#define VALID 1

int ValidateProductFields(Mercadoria *mercadorias) {
    if (mercadorias->UID == 0 ||
        strlen(mercadorias->nome) == 0 ||
        strlen(mercadorias->Grupo) == 0 ||
        mercadorias->preco == 0 ||
        strlen(mercadorias->Medida) <= 0 ||
        mercadorias->QNT_Estoque <= 0 ||
        strlen(mercadorias->Data_Validade) <= 0) {
        return INVALID;
    }
    return VALID;
}

