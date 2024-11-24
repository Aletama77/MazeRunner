#include "Display.h"
#include "Laberinto.h"
#include <iostream>
#include <SFML\Graphics.hpp>

Display::Display(){


};
  /**
void Display::jugar(RenderWindow& window, string& nombre){

    Laberinto maze;
    maze.cargarParedes();
    maze.crearLaberinto();
    maze.caminosAlternativos();

    PersonajeJugador jugador(maze);

     sf::Texture   _texturaFondo;
    _texturaFondo.loadFromFile("pictures/fondo_grass2.png");
    sf::Sprite spriteFondo(_texturaFondo);


    //sf::RenderWindow window(sf::VideoMode(600, 600), "Laberinto Aleatorio");
    window.setFramerateLimit(30);
    spriteFondo.setScale(
    window.getSize().x / spriteFondo.getGlobalBounds().width,
    window.getSize().y / spriteFondo.getGlobalBounds().height);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        jugador.update(maze);

        window.clear();
        window.draw(spriteFondo);
        maze.mostrarLaberinto(window);

        window.draw(jugador);

        window.display();

}

*/

Display::~Display(){


};
