all: bin/programa

bin/programa: obj/carta.o obj/mano.o obj/codigounicofichero.o
	g++ -w obj/carta.o obj/mano.o obj/codigounicofichero.o -o bin/programa

obj/carta.o: src/carta.cpp include/Carta.hpp include/TipoPalo.hpp
	g++ -w -Iinclude -c src/carta.cpp -o obj/carta.o

obj/mano.o: src/mano.cpp include/Mano.hpp include/Carta.hpp include/TipoPalo.hpp
	g++ -w -Iinclude -c src/mano.cpp -o obj/mano.o

obj/codigounicofichero.o: src/codigounicofichero.cpp include/Mano.hpp include/Carta.hpp include/TipoPalo.hpp
	g++ -w -Iinclude -c src/codigounicofichero.cpp -o obj/codigounicofichero.o

clean:
	rm -rf obj/*.o bin/programa
