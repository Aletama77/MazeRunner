#ifndef NIEBLA_H_INCLUDED
#define NIEBLA_H_INCLUDED


#include "Laberinto.h"
#include <SFML/Graphics.hpp>
class PersonajeJugador;

class Niebla : public sf::Drawable {
public:
    Niebla(PersonajeJugador& jug, Laberinto& lab, sf::RenderWindow& window);
    void update(PersonajeJugador& jug, Laberinto& lab);
    ~Niebla();
    void aumentarradio();
    void disminuirradio();
    void revelarmapa();
    void restaurarniebla();

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::CircleShape _Circulo;  // Radio de la niebla
    sf::Sprite _Sprite;
    sf::RenderTexture _Textura; // No debe ser const si planeamos modificarlo
    int radio;
    int radioviejo;
};





#endif // NIEBLA_H_INCLUDED
