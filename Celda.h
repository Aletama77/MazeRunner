#ifndef CELDA_H
#define CELDA_H
#include "Consumible.h"
enum ESTADO {

    CAMINO = 0,
    MURO = 1,
    ENTRADA = 2,
    SALIDA = 3,
    CAMINO_ALTERNATIVO  = 4

    // La idea de los ESTADO del objeto Celda es que en caso de que querramos determinar un comportamiento especifico para cada Celda adentro del laberinto
    // Por ejemplo, si recorremos CAMINO_ALTERNATIVO en la matriz podemos colocar de manera Random el Minotauro para que no obstaculice el camino pcpal.
};

class Celda
{
    public:
        Celda();
        ~Celda();

        void setEstado(int estado);
        int getEstado();

        // Sobrecarga del operador de comparación ==
        bool operator==(int estado) const {
            return _estado == estado;
        }
        void settieneconsumible();
        bool gettieneconsumible();
        void settipoconsumible(int n);
        int gettipoconsumible();
        void settieneconsumibleFALSE();
    private:
        int _estado;
        bool _tieneconsumible;
        Consumible obj;
};

#endif // CELDA_H
