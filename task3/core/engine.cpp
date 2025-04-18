//
// Created by xoska on 18.04.2025.
//

#include "engine.h"

#include "../helper/utils.h"

namespace oc {
    Engine::Engine() {
        //initialize 2 triangles
        constexpr std::array<vec2, 3> spawn1 = {
            vec2{0, WINDOW_HEIGHT-10},
            vec2{200, WINDOW_HEIGHT-10},
            vec2{100, WINDOW_HEIGHT-150}
        };
        constexpr std::array<vec2, 3> spawn2 = {
            vec2{WINDOW_WIDTH, WINDOW_HEIGHT-10},
            vec2{WINDOW_WIDTH-200, WINDOW_HEIGHT-10},
            vec2{WINDOW_WIDTH-100, WINDOW_HEIGHT-150}
        };
        triangles.push_back(Triangle(255,255,255, spawn1));
        triangles.push_back(Triangle(120,120,120, spawn2));

        this->font.loadFromFile("../fonts/OptimusPrinceps.ttf");
    }

    void Engine::reDraw(sf::RenderWindow &window) {
        window.clear();
        for (auto& triangle : triangles) {
            triangle.draw(window);
        }

        if (isColliding(triangles[0], triangles[1])) {
            sf::Text text("YOU DIED", this->font, 50);
            text.setFillColor(sf::Color::Red);
            text.setPosition(WINDOW_WIDTH / 2.f - 150.f, WINDOW_HEIGHT / 2.f - 25.f);
            window.draw(text);
        }

        window.display();
    }


    void Engine::run() {
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Novomatic Task 3",
                                sf::Style::Titlebar | sf::Style::Close);

        sf::Clock deltaClock;

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            sf::Time dt = deltaClock.restart();

            inputHandler(dt);
            reDraw(window);
        }

    }

    bool Engine::isColliding(const Triangle &triangle1, const Triangle &triangle2) {
        const auto& pts1 = triangle1.getPointsPlace();
        const auto& pts2 = triangle2.getPointsPlace();

        for (const vec2& p : pts1) {
            if (pointInTriangle(p, pts2[0], pts2[1], pts2[2])) {
                return true;
            }
        }

        for (const vec2& p : pts2) {
            if (pointInTriangle(p, pts1[0], pts1[1], pts1[2])) {
                return true;
            }
        }

        return false;
    }

    void Engine::inputHandler(sf::Time dt) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            triangles[0].move(sf::Keyboard::A, dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            triangles[0].move(sf::Keyboard::D, dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            triangles[0].move(sf::Keyboard::W, dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            triangles[0].move(sf::Keyboard::S, dt);
        }
    }


} // oc