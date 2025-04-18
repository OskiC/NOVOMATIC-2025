//
// Created by xoska on 18.04.2025.
//

#include "engine.h"

namespace oc {
    Engine::Engine() {}

    void Engine::reDraw(sf::RenderWindow &window) {
        window.clear();
        window.display();
    }


    void Engine::run() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Novomatic Task 3",
                                sf::Style::Titlebar | sf::Style::Close);

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            reDraw(window);
        }

    }

} // oc