#include <SFML/Graphics.hpp>
#include "Laberinto.h"
#include "GamePlay.h"
#include "Menu.h"
#include "Celda.h"
#include "PersonajeJugador.h"
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include "Configuracion.h"

int main()
{
    Configuracion conf;
    sf::Music musica;
    sf::Music musica2;
    musica.openFromFile("musica/maintheme2.ogg");
    musica.setLoop(false);

    musica.setVolume(conf.getvolumenMainTheme());
    musica.play();


    musica2.openFromFile("musica/mainthemeLoop.ogg");
    musica2.setLoop(true);
    musica2.setVolume(conf.getvolumenMainTheme());

    GamePlay play;
    play.jugar(musica,conf,musica2);



    return 0;
}

