#include "Collisionable.h"
#include <SFML/Graphics.hpp>

bool Collisionable::isCollision(const Collisionable &obj) const {
    return getBounds().intersects(obj.getBounds());
}
