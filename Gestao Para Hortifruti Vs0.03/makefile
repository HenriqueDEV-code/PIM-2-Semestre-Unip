CC = gcc
CFLAGS = -Wall
OBJ = arquivo1.o arquivo2.o arquivo3.o
TARGET = nome_do_programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

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