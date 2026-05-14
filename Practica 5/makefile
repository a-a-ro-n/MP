# Regla principal: compila el ejecutable final en la carpeta bin
bin/practicafinal: build/Usuario.o build/ConjuntoUsuarios.o build/Pelicula.o build/ConjuntoPeliculas.o build/Opiniones.o build/main.o
	g++ build/Usuario.o build/ConjuntoUsuarios.o build/Pelicula.o build/ConjuntoPeliculas.o build/Opiniones.o build/main.o -o bin/practicafinal

# Compilación de cada archivo fuente individualmente
build/Usuario.o: src/Usuario.cpp include/Usuario.h
	g++ -Iinclude -Wall -g -c src/Usuario.cpp -o build/Usuario.o

build/ConjuntoUsuarios.o: src/ConjuntoUsuarios.cpp include/ConjuntoUsuarios.h include/Usuario.h
	g++ -Iinclude -Wall -g -c src/ConjuntoUsuarios.cpp -o build/ConjuntoUsuarios.o

build/Pelicula.o: src/Pelicula.cpp include/Pelicula.h
	g++ -Iinclude -Wall -g -c src/Pelicula.cpp -o build/Pelicula.o

build/ConjuntoPeliculas.o: src/ConjuntoPeliculas.cpp include/ConjuntoPeliculas.h include/Pelicula.h
	g++ -Iinclude -Wall -g -c src/ConjuntoPeliculas.cpp -o build/ConjuntoPeliculas.o

build/Opiniones.o: src/Opiniones.cpp include/Opiniones.h include/ConjuntoUsuarios.h include/ConjuntoPeliculas.h
	g++ -Iinclude -Wall -g -c src/Opiniones.cpp -o build/Opiniones.o

build/main.o: src/main.cpp include/Opiniones.h
	g++ -Iinclude -Wall -g -c src/main.cpp -o build/main.o

# Regla para limpiar los archivos generados
clean:
	rm -rf build/*.o bin/practicafinal
