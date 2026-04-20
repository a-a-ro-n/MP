# Regla principal: compila el ejecutable final vinculando los objetos
bin/ejecutable: build/main.o build/Usuario.o build/ConjuntoUsuarios.o
	g++ build/main.o build/Usuario.o build/ConjuntoUsuarios.o -o bin/ejecutable

# Compilación de main.cpp
build/main.o: src/main.cpp include/Usuario.h include/ConjuntoUsuarios.h
	g++ -c src/main.cpp -Iinclude -o build/main.o

# Compilación de Usuario.cpp
build/Usuario.o: src/Usuario.cpp include/Usuario.h
	g++ -c src/Usuario.cpp -Iinclude -o build/Usuario.o

# Compilación de ConjuntoUsuarios.cpp
build/ConjuntoUsuarios.o: src/ConjuntoUsuarios.cpp include/ConjuntoUsuarios.h include/Usuario.h
	g++ -c src/ConjuntoUsuarios.cpp -Iinclude -o build/ConjuntoUsuarios.o

# Regla para limpiar los archivos generados
clean:
	rm build/*.o bin/ejecutable
