#ifndef ENGINE_H
#define ENGINE_H

#include "SFML/Graphics.hpp"

namespace oc {

    class Engine {
        void reDraw(sf::RenderWindow &window);


    public:
        Engine();

        void run();

};

} // oc

#endif //ENGINE_H
