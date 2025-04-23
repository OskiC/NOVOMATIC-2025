#include "engine.h"

int main() {
    oc::Engine engine("saved_queries.txt");
    engine.run();

    return 0;
}