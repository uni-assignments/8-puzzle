CC=g++
CFLAGS=-std=c++17 # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./TP1 # nome do executavel que sera gerado, nao troque
TMPOUT=TP1.testresult

$(EXEC): main.cpp bfs.o ucs.o state.o algorithm.o # ids.o ucs.o
	$(CC) $(CFLAGS) main.cpp bfs.o ucs.o state.o algorithm.o -o $(EXEC)

bfs.o: src/bfs.cpp 
	$(CC) $(CFLAGS) -c src/bfs.cpp -o bfs.o

state.o: src/state.cpp 
	$(CC) $(CFLAGS) -c src/state.cpp -o state.o

algorithm.o: src/abstract_algorithm.cpp 
	$(CC) $(CFLAGS) -c src/abstract_algorithm.cpp -o algorithm.o

# ids.o: cpps/ids.cpp 
# 	$(CC) $(CFLAGS) -c src/ids.cpp -o ids.o

ucs.o: src/ucs.cpp 
	$(CC) $(CFLAGS) -c src/ucs.cpp -o ucs.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf bfs.o
	rm -rf ucs.o
	rm -rf state.o
	rm -rf algorithm.o
	rm -rf TP1