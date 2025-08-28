# Nome do compilador
CC = gcc

# Flags de compilação: -Wall (todos os avisos), -g (informações de debug), -std=c99 (padrão C99)
CFLAGS = -Wall -g -std=c99

# Nome do executável final
EXEC = programa_placas

# Lista de todos os arquivos de código-fonte (.c)
SRCS = main.c placas.c tabela_hash.c ordenacao.c busca.c

# Gera a lista de arquivos objeto (.o) a partir dos arquivos fonte (.c)
OBJS = $(SRCS:.c=.o)

# Regra principal (default): compila o executável
all: $(EXEC)

# Regra para linkar os arquivos objeto e criar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra para compilar cada arquivo .c em um arquivo .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra "clean": remove o executável e os arquivos objeto
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean