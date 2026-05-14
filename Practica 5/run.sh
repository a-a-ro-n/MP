echo "------------------------------"
echo "EJECUCION VALORACION PELICULA"
echo "------------------------------"
./bin/practicafinal -a valoracionpelicula -u 2 -n 3 -p Lord -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt
echo "---------------------------------"
echo "EJECUCION RECOMENDACION PELICULA"
echo "---------------------------------"
./bin/practicafinal -a recomendacion -u 0 -n 3 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt
echo "---------------------------------"
echo "EJECUCION MODIFICACION OPINION"
echo "---------------------------------"
./bin/practicafinal -a modificacion -p Rings -u 3 -op 8.9 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt
