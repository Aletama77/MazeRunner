#ifndef COLLISIONABLE_H_INCLUDED
#define COLLISIONABLE_H_INCLUDED
#include <SFML/Graphics.hpp>
 class Collisionable
{
public:
     virtual sf::FloatRect getBounds() const = 0;

    bool isCollision(const Collisionable &obj) const {
    return getBounds().intersects(obj.getBounds());
}

};

#endif // COLLISIONABLE_H_INCLUDED
