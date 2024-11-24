#pragma once
#include "Funciones.h"
#include "Jugador.h"
#include "JugadorArchivo.h"
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace std;

Jugador Funciones::cargarJugador()
{
    int dni, puntaje;
    string nombre;

    cout << "Ingrese dni: ";
    cin >> dni;

    puntaje = 0;

    cout << "Ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);

    return Jugador(dni, puntaje, nombre);




}

// Función para mostrar un jugador
void Funciones::mostrarJugador(Jugador player)
{

}

// Función para mostrar todos los jugadores
void Funciones::mostrarTodos()
{
    JugadorArchivo pa;
    Jugador *players;

    int cantidad = pa.getCantidad();

    players = new Jugador[cantidad];

    pa.leerTodos(players, cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        if (!players[i].getEliminado())
        {
            mostrarJugador(players[i]);
        }
    }

    delete[] players;
}

// Función para guardar un jugador
void Funciones::guardarJugador()
{
    Jugador p;
    JugadorArchivo pa;
    int dni;

    cout << "Ingrese DNI nuevo a cargar: ";
    cin >> dni;


    int pos = pa.buscar(dni);

    if (pos != -1)
    {
        cout << "El jugador ya esta registrado." << endl;
    }
    else
    {
        p = cargarJugador();

        if (pa.guardar(p))
        {
            cout << "Jugador guardado con exito!" << endl;
        }
        else
        {
            cout << "No se pudo guardar el jugador." << endl;
        }
    }



}

// Función para modificar un jugador
void Funciones::modificarJugador()
{
    Jugador p;
    JugadorArchivo pa;
    int dni;

    cout << "Ingrese DNI a modificar: ";
    cin >> dni;

    int pos = pa.buscar(dni);

    if (pos != -1)
    {
        p = pa.leer(pos);

        cout << "Datos del jugador: " << endl;
        mostrarJugador(p);

        cout << "MODIFICAR: " << endl;

        p = cargarJugador();

        pa.guardar(pos, p);
    }
    else
    {
        cout << "El jugador no se encuentra en el sistema." << endl;
    }
}

// Función para buscar un jugador por DNI
void Funciones::buscarJugador()
{
    Jugador p;
    JugadorArchivo pa;
    int dni;

    cout << "Ingrese dni a buscar: ";
    cin >> dni;

    int pos = pa.buscar(dni);

    if (pos != -1)
    {
        p = pa.leer(pos);

        cout << "Datos del jugador: " << endl;
        mostrarJugador(p);
    }
    else
    {
        cout << "El jugador no se encuentra en el sistema." << endl;
    }
}

// Función para mostrar todos los jugadores ordenados por puntaje
void Funciones::mostrarTodosOrdenados()
{
    JugadorArchivo pa;
    Jugador *players;

    int cantidad = pa.getCantidad();

    players = new Jugador[cantidad];

    pa.leerTodos(players, cantidad);

    // Ordenamiento por burbujeo
    for (int i = 0; i < cantidad; ++i)
    {
        for (int j = 0; j < cantidad - 1; ++j)
        {
            if (players[j].getPuntaje() < players[j + 1].getPuntaje())
            {
                Jugador aux = players[j + 1];
                players[j + 1] = players[j];
                players[j] = aux;
            }
        }
    }

    // Mostrar ordenado
    for (int i = 0; i < cantidad; i++)
    {
        if (!players[i].getEliminado())
        {
            mostrarJugador(players[i]);
        }
    }

    delete[] players;
}

void Funciones::eliminarJugador()
{
    JugadorArchivo pa;
    int dni;

    cout << "Ingrese el DNI del jugador que desea eliminar: ";
    cin >> dni;

    int pos = pa.buscar(dni);

    if (pos != -1)
    {
        Jugador p = pa.leer(pos);

        // marcar al jugador como eliminado
        p.setEliminado(true);


        if (pa.guardar(pos, p))
        {
            cout << "El jugador ha sido eliminado." << endl;
        }
        else
        {
            cout << "No se pudo eliminar el jugador." << endl;
        }
    }
    else
    {
        cout << "El jugador no se encuentra en el sistema." << endl;
    }
}

