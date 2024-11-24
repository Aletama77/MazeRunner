

#pragma once
#include "Funciones.h"
#include "Jugador.h"
#include "JugadorArchivo.h"
#include <iostream>
#include <SFML\Graphics.hpp>

class Funciones
{
public:

    Jugador cargarJugador();
    void mostrarJugador(Jugador player);
    void mostrarTodos();
    void guardarJugador();
    void modificarJugador();
    void buscarJugador();
    void mostrarTodosOrdenados();//para estadistica
    void eliminarJugador(); //te pone el estado eliminado en true

};




