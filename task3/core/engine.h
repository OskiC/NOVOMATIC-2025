#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "../entities/triangle.h"
#include "SFML/Graphics.hpp"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

namespace oc {

    class Engine {
        std::vector<Triangle> triangles;
        sf::Font font;

        void reDraw(sf::RenderWindow &window);
        void inputHandler(sf::Time dt);
        bool isColliding(const Triangle &triangle1, const Triangle &triangle2);

    public:
        Engine();

        void run();

};

} // oc

#endif //ENGINE_H
