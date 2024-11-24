#include "Niebla.h"

#include "PersonajeJugador.h"
#include "Laberinto.h"

Niebla::Niebla(PersonajeJugador& jug, Laberinto& lab, sf::RenderWindow& window) {
    _Textura.create(window.getSize().x, window.getSize().y);

    sf::RectangleShape capa(sf::Vector2f(window.getSize().x, window.getSize().y));
    capa.setFillColor(sf::Color::Black);
     radio=100;
     radioviejo=100;
    _Circulo.setRadius(radio);   // Fija radio del círculo
    _Circulo.setOrigin(radio, radio);   // Centrar el círculo
    _Circulo.setFillColor(sf::Color::White);

    _Textura.clear(sf::Color::Transparent); // Limpia la textura con transparencia
    _Textura.draw(capa);              // Dibuja la capa de niebla
    _Textura.draw(_Circulo, sf::BlendNone); // Dibuja el círculo transparente
    _Textura.display();

    _Sprite.setTexture(_Textura.getTexture());
}

void Niebla::update(PersonajeJugador& jug, Laberinto& lab) {
    // Actualiza la posición del círculo basado en la posición del jugador
    _Circulo.setPosition(jug.gety() * lab.getspritegrass().getGlobalBounds().width,
                          jug.getx() * lab.getspritegrass().getGlobalBounds().height);

    _Textura.clear(sf::Color::Transparent);

    sf::RectangleShape capa(sf::Vector2f(_Textura.getSize().x, _Textura.getSize().y));
    capa.setFillColor(sf::Color::Black);

    _Textura.draw(capa);
    _Textura.draw(_Circulo, sf::BlendNone);
    _Textura.display();

    _Sprite.setTexture(_Textura.getTexture());
}

void Niebla::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_Sprite, states);
}

void Niebla::aumentarradio(){
   radio *= 1.4;
   _Circulo.setRadius(radio);
   _Circulo.setOrigin(radio, radio);
};

void Niebla::disminuirradio(){
    radio *= 0.8;
   _Circulo.setRadius(radio);
   _Circulo.setOrigin(radio, radio);
};
void Niebla::revelarmapa(){

   radioviejo=radio;
   radio=2000;
   _Circulo.setRadius(radio);
   _Circulo.setOrigin(radio, radio);


}
void Niebla::restaurarniebla(){
  radio=radioviejo;
   _Circulo.setRadius(radio);
   _Circulo.setOrigin(radio, radio);

}

Niebla::~Niebla(){
}
