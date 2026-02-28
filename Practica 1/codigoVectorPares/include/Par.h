#ifndef PAR_H
#define PAR_H

/**
  @file Par.h
  @class Par
  Esta clase implementa el manejo de un par de enteros.
  Permite consultar y modificar cada entero por separado.
*/
class Par
{
    public:
        Par();
        Par(int newx, int newy);
        ~Par();
        int verX();
        int verY();
        void setX(int newx);
        void setY(int newy);
        void mostrar();
    private:
    /**
    @brief Primer entero.
    */
    int x;
    /**
    @brief Segundo entero.
    */
    int y;
};
Par suma(Par uno, Par dos);

#endif // PAR_H
