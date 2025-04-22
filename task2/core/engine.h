#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "../entities/triangle.h"

namespace oc {

    class Engine {
        std::vector<Triangle> triangles;
        sf::Font font;

        void reDraw(sf::RenderWindow &window);
        void inputHandler(sf::Time dt);

    public:
        Engine();

        void run();

        bool isColliding(const Triangle &triangle1, const Triangle &triangle2);
};

} // oc

#endif //ENGINE_H
