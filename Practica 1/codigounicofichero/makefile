all: bin/programa

bin/programa: build/carta.o build/mano.o build/codigounicofichero.o
	g++ -w build/carta.o build/mano.o build/codigounicofichero.o -o bin/programa

build/carta.o: src/carta.cpp include/Carta.hpp include/TipoPalo.hpp
	g++ -w -Iinclude -c src/carta.cpp -o build/carta.o

build/mano.o: src/mano.cpp include/Mano.hpp include/Carta.hpp include/TipoPalo.hpp
	g++ -w -Iinclude -c src/mano.cpp -o build/mano.o

build/codigounicofichero.o: src/codigounicofichero.cpp include/Mano.hpp include/Carta.hpp include/TipoPalo.hpp
	g++ -w -Iinclude -c src/codigounicofichero.cpp -o build/codigounicofichero.o

clean:
	rm -rf build/*.o bin/programa
