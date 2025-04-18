#ifndef ENGINE_H
#define ENGINE_H

#include "../entities/triangle.h"
#include "SFML/Graphics.hpp"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

namespace oc {

    class Engine {
        void reDraw(sf::RenderWindow &window);
        std::vector<Triangle> triangles;
        void inputHandler(sf::Time dt);

    public:
        Engine();

        void run();

};

} // oc

#endif //ENGINE_H
