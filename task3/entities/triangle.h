#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>
#include "../helper/vec2.h"
#include "SFML/Graphics.hpp"

namespace oc {

class Triangle {
    std::array<vec2,3> pointsPlace;
    sf::Uint8 r, g, b;

public:
    Triangle(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, const std::array<vec2, 3> &spawn_point);
    void draw(sf::RenderTarget &target);
};

} // oc

#endif //TRIANGLE_H
