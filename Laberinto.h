#pragma once
#include "Celda.h"
#include <iostream>
#include <ctime>
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>

class Laberinto
{
    public:
        Laberinto();
        void cargarParedes();
        void crearLaberinto();
        void mostrarLaberinto(sf::RenderWindow& window);
        void caminosAlternativos();
        void setconsumibles();
        bool getestadoconsumible(int x, int y);
        void setestadoconsumible(int x, int y);
        int gettipoconsumible(int x, int y);
        virtual ~Laberinto();
        int getcolumnaincial();
        int getfilainicial();
        int getLaberinto(int x, int y);
        sf::Sprite getspritegrass();

         std::vector<sf::Vector2i> getCaminosAlternativos() ;


    private:

    Celda matriz[23][23]={};
    int i, j;
    int fila, columna, contador=21;
    int direccion, direccionAlternativos;
    int seDibujo = 0;
    bool fueIzquierda = 0;
    int abajo = 3;
    bool conecto;
    int filaInicial, columnaInicial;
    sf::Texture _textureMuro;
    sf::Sprite _spriteMuro;
    sf::Texture _textureGrass;
    sf::Sprite _spriteGrass;
    sf::RectangleShape _rectSalida;

    // Texturas y sprites de consumibles
    sf::Texture _texturesumavida;
    sf::Sprite _spritesumavida;
    sf::Texture _texturerestavida;
    sf::Sprite _spriterestavida;
    sf::Texture _texturesumatiempo;
    sf::Sprite _spritesumatiempo;
    sf::Texture _texturerestatiempo;
    sf::Sprite _spriterestatiempo;
    sf::Texture _textureaumentavision;
    sf::Sprite _spritereaumentavision;
    sf::Texture _texturerestavision;
    sf::Sprite _spritererestavision;
    sf::Texture _texturemostrarmapa;
    sf::Sprite _spriteremostrarmapa;





};


