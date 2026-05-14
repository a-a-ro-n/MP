#!/bin/bash
# test_exhaustivo.sh - Script para comprobar casos de uso y manejo de errores

echo "=========================================================="
echo "Compilando el proyecto..."
make 
echo "=========================================================="

# ---------------------------------------------------------
# BLOQUE 1: PRUEBAS DE FUNCIONAMIENTO NORMAL (CASOS DE ÉXITO)
# ---------------------------------------------------------

echo -e "\n[PRUEBA 1.1] Éxito: Recomendación normal"
./bin/practicafinal -a recomendacion -u 2 -n 2 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 1.2] Éxito: Valoración de película con espacios (usando subguiones)"
./bin/practicafinal -a valoracionpelicula -p Top_Gun -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 1.3] Éxito: Modificación (Cambiar valoración a 9.5)"
./bin/practicafinal -a modificacion -u 2 -p Top_Gun -op 9.5 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 1.4] Éxito: Modificación (Eliminar valoración poniendo -1)"
./bin/practicafinal -a modificacion -u 2 -p Top_Gun -op -1 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt


# ---------------------------------------------------------
# BLOQUE 2: PRUEBAS DE LÍMITES Y DATOS INEXISTENTES
# ---------------------------------------------------------

echo -e "\n[PRUEBA 2.1] Límite: Recomendación para un usuario que NO existe (Debería manejarlo sin Segfault)"
./bin/practicafinal -a recomendacion -u 9999 -n 2 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 2.2] Límite: Recomendación pidiendo más usuarios similares de los que existen"
./bin/practicafinal -a recomendacion -u 2 -n 5000 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 2.3] Límite: Valoración de una película que NO existe"
./bin/practicafinal -a valoracionpelicula -p Pelicula_Inventada -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 2.4] Límite: Modificación de una película que NO existe"
./bin/practicafinal -a modificacion -u 2 -p Pelicula_Inventada -op 5.0 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt


# ---------------------------------------------------------
# BLOQUE 3: PRUEBAS DE MANEJO DE ARGUMENTOS ERRÓNEOS
# ---------------------------------------------------------

echo -e "\n[PRUEBA 3.1] Error: Ejecución sin argumentos"
./bin/practicafinal

echo -e "\n[PRUEBA 3.2] Error: Falta acción (-a)"
./bin/practicafinal -u 2 -n 2 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 3.3] Error: Acción desconocida"
./bin/practicafinal -a hackear_nasa -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 3.4] Error: Recomendación sin parámetros -u o -n"
./bin/practicafinal -a recomendacion -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 3.5] Error: Valoración sin parámetro -p"
./bin/practicafinal -a valoracionpelicula -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt

echo -e "\n[PRUEBA 3.6] Error: Modificación sin parámetro -op"
./bin/practicafinal -a modificacion -u 2 -p Top_Gun -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt


# ---------------------------------------------------------
# BLOQUE 4: PRUEBA DE FUGAS DE MEMORIA (Opcional, requiere Valgrind)
# ---------------------------------------------------------
echo -e "\n=========================================================="
echo "Comprobando fugas de memoria con Valgrind (si está instalado)..."
if command -v valgrind &> /dev/null; then
    valgrind --leak-check=full --error-exitcode=1 ./bin/practicafinal -a recomendacion -u 2 -n 2 -fu doc/usuarios.txt -fo doc/opiniones.txt -fp doc/pelis.txt > /dev/null
    if [ $? -eq 0 ]; then
        echo "VALGRIND: OK - No se detectaron fugas de memoria críticas en la recomendación."
    else
        echo "VALGRIND: ADVERTENCIA - Se detectaron posibles problemas de memoria."
    fi
else
    echo "Valgrind no está instalado. Saltando prueba de memoria."
fi

echo -e "\n=========================================================="
echo "Script de pruebas exhaustivas finalizado."
