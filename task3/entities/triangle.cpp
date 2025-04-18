#include "triangle.h"

namespace oc {
    Triangle::Triangle(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, const std::array<vec2, 3> &spawn_point) {
        for (int i = 0; i < 3; i++) {
                this->pointsPlace[i] = {spawn_point[i].x, spawn_point[i].y};
        }
        this->r = r;
        this->g = g;
        this->b = b;
    }

    void Triangle::draw(sf::RenderTarget &target) {
        sf::VertexArray points(sf::PrimitiveType::Triangles, 3);
        for (int i = 0; i < 3; i++) {
            points[i].position = {pointsPlace[i].x, pointsPlace[i].y};
            points[i].color = {r, g, b};
        }
        target.draw(points);
    }

    void Triangle::move(sf::Keyboard::Key key) {
        switch (key) {
            case sf::Keyboard::A:
                pointsPlace[0].x -= movementSpeed;
                pointsPlace[1].x -= movementSpeed;
                pointsPlace[2].x -= movementSpeed;
            break;
            case sf::Keyboard::D:
                pointsPlace[0].x += movementSpeed;
                pointsPlace[1].x += movementSpeed;
                pointsPlace[2].x += movementSpeed;
            break;
            default:break;
        }
    }


} // oc