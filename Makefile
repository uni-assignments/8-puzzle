CC=g++
CFLAGS=-std=c++17 # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./TP1 # nome do executavel que sera gerado, nao troque

$(EXEC): main.cpp state.o algorithm.o bfs.o ids.o ucs.o a_star.o greedy.o hill_climbing.o
	$(CC) $(CFLAGS) main.cpp build/state.o build/algorithm.o build/bfs.o build/ids.o build/ucs.o build/a_star.o build/greedy.o build/hill_climbing.o -o $(EXEC)

state.o: src/state.cpp 
	$(CC) $(CFLAGS) -c src/state.cpp -o build/state.o

algorithm.o: src/abstract_algorithm.cpp 
	$(CC) $(CFLAGS) -c src/abstract_algorithm.cpp -o build/algorithm.o

bfs.o: src/bfs.cpp 
	$(CC) $(CFLAGS) -c src/bfs.cpp -o build/bfs.o

ids.o: src/ids.cpp 
	$(CC) $(CFLAGS) -c src/ids.cpp -o build/ids.o

ucs.o: src/ucs.cpp 
	$(CC) $(CFLAGS) -c src/ucs.cpp -o build/ucs.o

a_star.o: src/a_star.cpp 
	$(CC) $(CFLAGS) -c src/a_star.cpp -o build/a_star.o

greedy.o: src/greedy.cpp 
	$(CC) $(CFLAGS) -c src/greedy.cpp -o build/greedy.o

hill_climbing.o: src/hill_climbing.cpp 
	$(CC) $(CFLAGS) -c src/hill_climbing.cpp -o build/hill_climbing.o

# To run algorithm B(breadth first search), run make test ALG="B"
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(ALG)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf ./build/*
	rm -rf TP1