all: bin/ejecutable

bin/ejecutable: build/main.o build/funcionesPalabras.o build/funcionesSopa.o build/MatrizSopa.o build/VectorPalabras.o
	g++ -g build/main.o build/funcionesPalabras.o build/funcionesSopa.o build/MatrizSopa.o build/VectorPalabras.o -o bin/ejecutable

build/main.o: src/main.cpp include/MatrizSopa.h include/VectorPalabras.h include/funcionesSopa.h include/funcionesPalabras.h include/Direcciones.h
	g++ -g -c src/main.cpp -Iinclude -o build/main.o

build/funcionesPalabras.o: src/funcionesPalabras.cpp include/funcionesPalabras.h include/VectorPalabras.h
	g++ -g -c src/funcionesPalabras.cpp -Iinclude -o build/funcionesPalabras.o

build/funcionesSopa.o: src/funcionesSopa.cpp include/funcionesSopa.h include/MatrizSopa.h include/Direcciones.h
	g++ -g -c src/funcionesSopa.cpp -Iinclude -o build/funcionesSopa.o

build/MatrizSopa.o: src/MatrizSopa.cpp include/MatrizSopa.h include/Direcciones.h
	g++ -g -c src/MatrizSopa.cpp -Iinclude -o build/MatrizSopa.o

build/VectorPalabras.o: src/VectorPalabras.cpp include/VectorPalabras.h
	g++ -g -c src/VectorPalabras.cpp -Iinclude -o build/VectorPalabras.o

clean:
	rm -rf build/*.o bin/ejecutable
