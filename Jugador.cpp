#include "Jugador.h"
#include <cstring>
#include <iostream>

Jugador::Jugador()
{
    _dni = 0;
    _puntaje = 0;

    strcpy(_nombre, "SIN NOMBRE");
    _eliminado = false;
}

Jugador::Jugador(int dni, int puntaje, std::string nombre)
{
    setDni(dni);
    setPuntaje(puntaje);
    setNombre(nombre);
    _eliminado = false;
}

void Jugador::setDni(int dni)
{
    if(dni >= 0)
    {
        _dni = dni;
    }
}

void Jugador::setPuntaje(int puntaje)
{
    _puntaje = puntaje;
}

void Jugador::setNombre(std::string nombre)
{
    if(nombre.size() < 100)
    {
        strcpy(_nombre, nombre.c_str());
    }
}

void Jugador::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}





int Jugador::getDni() const
{
    return _dni;
}

int Jugador::getPuntaje() const
{
    return _puntaje;
}

std::string Jugador::getNombre() const
{
    return _nombre;
}

bool Jugador::getEliminado() const
{
    return _eliminado;
}

void Jugador::incrementarPuntaje(int valor)
{

    _puntaje += valor;

}
