# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -pedantic

# Bibliotecas adicionais
LIBS = -lm

# Arquivos de origem
SRCS = main.c Ponto.c

# Arquivos objeto (gerados a partir dos fontes)
OBJS = $(SRCS:.c=.o)

# Regra padrão (primeira regra executada)
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Regra para criar os arquivos .o (objetos)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos objetos e executáveis gerados
clean:
	rm -f $(OBJS) $(TARGET)

# Permite rodar o programa após compilado com 'make run'
run: $(TARGET)
	./$(TARGET)
