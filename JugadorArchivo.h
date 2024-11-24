#pragma once
#include "Jugador.h"

class JugadorArchivo
{
public:
    JugadorArchivo (const char *fileName = "partidas.dat");
    bool guardar(const Jugador &registro);
    bool guardar(int pos, const Jugador &registro);
    int buscar(int dni);

    Jugador leer(int pos);
    bool leerTodos(Jugador registros[], int cantidad);
    int getCantidad();

private:
    char _fileName[30];
};

