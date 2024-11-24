#include <SFML/Graphics.hpp>
#include "Laberinto.h"
#include "Collisionable.h"
#pragma once


class Minotauro : public sf::Drawable, public Collisionable {
public:
    Minotauro(Laberinto& lab);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

    sf::Vector2i getPos() const;

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2i _pos;
};
