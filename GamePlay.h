#pragma once
#include "Menu.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Jugador.h"
#include <SFML/Audio.hpp>
#include "JugadorArchivo.h"
#include "Funciones.h"
#include "Configuracion.h"
class GamePlay{

public:

    sf::RenderWindow window;
    GamePlay();
    virtual ~GamePlay();
    void jugar(sf::Music& musica,Configuracion& confi,sf::Music& musica2); //manejo del menu

    void pedirDNI(sf::RenderWindow& window, sf::Music& musica,Configuracion& confi,sf::Music& musica2); // para pedir el DNI
    void subMenuJugar(RenderWindow& window,sf::Music& musica,Configuracion& confi,sf::Music& musica2); // para el submenú de jugar

    void display(RenderWindow& window, string& name,Jugador& jug, sf::Music& musica,Configuracion& confi,sf::Music& musica2); //opcion jugar

    void historia(RenderWindow& window,sf::Music& musica,Configuracion& confi,sf::Music& musica2); //otras opciones del menu
    void configuracion(RenderWindow& window,sf::Music& musica, Configuracion& config,sf::Music& musica2);
    void creditos(RenderWindow& window,sf::Music& musica,Configuracion& confi,sf::Music& musica2);
    void estadisticas(RenderWindow& window,sf::Music& musica,Configuracion& confi,sf::Music& musica2); //es como mostrar todos, pero ordenado por puntaje de mayor a menor

    void jugador(RenderWindow& window,sf::Music& musica,Configuracion& confi,sf::Music& musica2);
    void agregJugador(sf::Music& musica,Configuracion& confi,sf::Music& musica2);
    void elimJugador(sf::Music& musica,Configuracion& confi,sf::Music& musica2);
    void mostJugador(sf::Music& musica,Configuracion& confi,sf::Music& musica2);

    void updateText(sf::Text& text, const std::string& label, float volume);
private:
    std::string name;

    sf::SoundBuffer bufferganaste;
    sf::Sound soundganaste;

    sf::SoundBuffer bufferperdiste;
    sf::Sound soundperdiste;

    sf::Clock relojMusica;
};
