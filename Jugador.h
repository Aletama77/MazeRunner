#pragma once
#include <cstring>
#include <iostream>



class Jugador
{

private:
    int _dni;
    int _puntaje;
    // std::string _nombre;/// como es dinamico no lo puedo guardar en archivos
    char _nombre[39];
    bool _eliminado;

public:
    Jugador();
    Jugador(int dni, int puntaje, std::string nombre);

    void setDni (int dni);
    void setPuntaje(int puntaje);
    void setNombre(std::string nombre);
    void setEliminado(bool eliminado);
    int getDni() const;
    int getPuntaje() const;
    std::string getNombre() const;
    bool getEliminado() const;
    void incrementarPuntaje(int valor);

};


