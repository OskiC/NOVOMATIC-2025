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

    Triangle::Triangle(const std::array<vec2, 3> &points) {
        for (int i = 0; i < 3; i++) {
            this->pointsPlace[i] = {points[i].x, points[i].y};
        }
    }


    void Triangle::draw(sf::RenderTarget &target) {
        sf::VertexArray points(sf::PrimitiveType::Triangles, 3);
        for (int i = 0; i < 3; i++) {
            points[i].position = {pointsPlace[i].x, pointsPlace[i].y};
            points[i].color = {r, g, b};
        }
        target.draw(points);
    }

    void Triangle::move(sf::Keyboard::Key key, sf::Time dt) {
        vec2 moveOffset{0.f, 0.f};

        float distance = movementSpeed * dt.asSeconds();

        switch (key) {
            case sf::Keyboard::A: moveOffset.x = -distance;
                break;
            case sf::Keyboard::D: moveOffset.x = distance;
                break;
            case sf::Keyboard::W: moveOffset.y = -distance;
                break;
            case sf::Keyboard::S: moveOffset.y = distance;
                break;
            default:
                break;
        }

        bool canMove = true;
        for (const vec2& p : pointsPlace) {
            float newX = p.x + moveOffset.x;
            float newY = p.y + moveOffset.y;

            if (newX < 0 || newX > WINDOW_WIDTH || newY < 0 || newY > WINDOW_HEIGHT) {
                canMove = false;
                break;
            }
        }

        if (canMove) {
            for (vec2& p : pointsPlace) {
                p.x += moveOffset.x;
                p.y += moveOffset.y;
            }
        }
    }


} // oc