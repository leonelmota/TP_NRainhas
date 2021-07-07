# == VARIAVEIS ===
# ================
#
# Podemos declarar algumas variaveis dentro do Makefile (sintaxe similar a bash)
# Isso facilita o seu trabalho caso voce opte trocar alguma versao do
# compilador ou flag para seu processo de compilacao
# Uma variavel com nome VAR eh declarada da seguinte maneira:
# 	VAR=conteudo
# e eh chamada atraves do comando $(VAR)

CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra -ggdb -std=c++14 # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./Nrainhas # nome do executavel que sera gerado, nao troque



$(EXEC):  Nrainhas.cpp
	$(CC) $(CFLAGS) $^ -o $(EXEC)


clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf *.o

# === OUTROS =====
# ================
# 
# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile