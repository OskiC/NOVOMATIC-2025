#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>
#include "../helper/vec2.h"
#include "../helper/config.h"
#include "SFML/Graphics.hpp"

namespace oc {

class Triangle {
    std::array<vec2,3> pointsPlace;
    sf::Uint8 r, g, b;
    float movementSpeed = 200.f;

public:
    Triangle(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, const std::array<vec2, 3> &spawn_point);
    void draw(sf::RenderTarget &target);
    void move(sf::Keyboard::Key key, sf::Time dt);

    std::array<vec2, 3> getPointsPlace() const {
        return pointsPlace;
    }
};

} // oc

#endif //TRIANGLE_H
