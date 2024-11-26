# Compilador e flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g

# Diretórios
SRC_DIR = src
LIB_DIR = lib
DIST_DIR = dist

# Arquivos fonte
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/menus/produto.c $(SRC_DIR)/menus/fluxoCaixa.c $(SRC_DIR)/menus/menu.c 
LIB_FILES = $(LIB_DIR)/create.c $(LIB_DIR)/misc.c $(LIB_DIR)/read.c $(LIB_DIR)/remove.c $(LIB_DIR)/update.c

# Arquivo executável
TARGET = $(DIST_DIR)/app.exe

# Regra padrão
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SRC_FILES) $(LIB_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean

# Variáveis:

# CC: O compilador a ser usado (neste caso, gcc).
# CFLAGS: Opções de compilação (por exemplo, -Wall ativa avisos).
# OBJ: Lista de arquivos objeto que serão gerados.
# TARGET: Nome do executável final.
# Regras:

# A primeira regra all define a meta principal, que é compilar o executável.
# A regra para o TARGET especifica que ele depende dos arquivos objeto.
# A regra %.o: %.c descreve como gerar arquivos objeto a partir de arquivos de código-fonte.
# Limpeza:

# A regra clean é utilizada para remover arquivos objeto e o executável, permitindo uma nova compilação limpa.