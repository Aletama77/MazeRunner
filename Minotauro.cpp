#include <SFML/Graphics.hpp>
#include "Laberinto.h"
#include "Minotauro.h"
#include "Collisionable.h"


Minotauro::Minotauro(Laberinto& lab)
{
    _texture.loadFromFile("pictures/minotauro7.png");
    _sprite.setTexture (_texture);


    std::vector<sf::Vector2i> caminosAlternativos = lab.getCaminosAlternativos();

    if (!caminosAlternativos.empty())
    {

        int index = rand() % caminosAlternativos.size();
        _pos = caminosAlternativos[index];
    }


    _sprite.setPosition(
        _pos.y * lab.getspritegrass().getGlobalBounds().width,
        _pos.x * lab.getspritegrass().getGlobalBounds().height
    );

}

void Minotauro::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}



sf::FloatRect Minotauro::getBounds() const
{
    return _sprite.getGlobalBounds();
}

sf::Vector2i Minotauro::getPos() const
{
    return _pos;
}
