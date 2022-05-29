CC=g++
CFLAGS=-std=c++17 # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./TP1 # nome do executavel que sera gerado, nao troque

$(EXEC): main.cpp bfs.o ucs.o state.o algorithm.o # ids.o ucs.o
	$(CC) $(CFLAGS) main.cpp build/bfs.o build/ucs.o build/state.o build/algorithm.o -o $(EXEC)

bfs.o: src/bfs.cpp 
	$(CC) $(CFLAGS) -c src/bfs.cpp -o ./build/bfs.o

state.o: src/state.cpp 
	$(CC) $(CFLAGS) -c src/state.cpp -o ./build/state.o

algorithm.o: src/abstract_algorithm.cpp 
	$(CC) $(CFLAGS) -c src/abstract_algorithm.cpp -o build/algorithm.o

# ids.o: src/ids.cpp 
# 	$(CC) $(CFLAGS) -c src/ids.cpp -o build/ids.o

ucs.o: src/ucs.cpp 
	$(CC) $(CFLAGS) -c src/ucs.cpp -o build/ucs.o

# To run algorithm B(breadth first search), run make test ALG="B"
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(ALG)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf ./build/*
	rm -rf TP1