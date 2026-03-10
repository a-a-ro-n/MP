all : bin/ejecutable

bin/ejecutable: build/ConjuntoPeliculas.o build/Pelicula.o build/main.o
	g++ build/ConjuntoPeliculas.o build/Pelicula.o build/main.o -o bin/ejecutable

build/ConjuntoPeliculas.o: src/ConjuntoPeliculas.cpp include/ConjuntoPeliculas.h include/Pelicula.h
	g++ -Iinclude -c src/ConjuntoPeliculas.cpp -o build/ConjuntoPeliculas.o

build/Pelicula.o: src/Pelicula.cpp include/Pelicula.h
	g++ -Iinclude -c src/Pelicula.cpp -o build/Pelicula.o

build/main.o: src/main.cpp include/ConjuntoPeliculas.h include/Pelicula.h
	g++ -Iinclude -c src/main.cpp -o build/main.o
