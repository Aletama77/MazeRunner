#ifndef PERSONAJEJUGADOR_H
#define PERSONAJEJUGADOR_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include "Laberinto.h"
#include <vector>
#include <utility>
#include <iostream>
#include "Niebla.h"
#include <SFML/Audio.hpp>
#include "Configuracion.h"
class PersonajeJugador : public sf::Drawable, public Collisionable {

public:
    PersonajeJugador(Laberinto& lab,Configuracion& confi);
    void update(Laberinto& laberinto, Niebla& nie,int& s,bool& activacionniebla);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setVida(float vida);
    float getVida() const;
    bool isGameOver() const;
    void sumarvida();
    void restarvida();
    void setSalida(bool salida);
    bool getSalida() const;
    bool ganador() const;
    int getx();
    int gety();

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    float _velocity;
    int _personajeSprint;
    sf::Vector2i playerPos;

    float _vida;
    bool _salida;
    //Efectos especiales consumibles
    sf::SoundBuffer _buffercomer;
    sf::Sound _soundcomer;

    sf::FloatRect getBounds() const override;
};


#endif // PERSONAJEJUGADOR_H
