//
// Created by xoska on 18.04.2025.
//

#include "engine.h"

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
    }

    void Engine::reDraw(sf::RenderWindow &window) {
        window.clear();
        for (auto& triangle : triangles) {
            triangle.draw(window);
        }
        window.display();
    }


    void Engine::run() {
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Novomatic Task 3",
                                sf::Style::Titlebar | sf::Style::Close);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if (event.type == sf::Event::KeyPressed) {
                    inputHandler(event);
                }
            }
            reDraw(window);
        }

    }

    void Engine::inputHandler(const sf::Event &event) {
        triangles[0].move(event.key.code);
    }


} // oc