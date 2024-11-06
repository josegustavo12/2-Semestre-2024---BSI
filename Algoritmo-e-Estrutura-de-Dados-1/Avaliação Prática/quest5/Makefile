# Nome do executável
TARGET = main

# Arquivos fonte
SRCS = main.c matriz_esparsa.c

# Arquivos de cabeçalho
HEADERS = matriz_esparsa.h

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -pedantic

# Regra padrão de compilação
$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)

# Permite rodar o programa após compilado com 'make run'
run: $(TARGET)
	./$(TARGET)
