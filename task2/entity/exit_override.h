//
// Created by xoska on 21.04.2025.
//

#ifndef EXIT_OVERRIDE_H
#define EXIT_OVERRIDE_H

#include <cstdlib>

namespace oc {
    using ExitHandler = void(*)(int);

    void ExitProgram(int code);
    void SetExitHandler(ExitHandler handler);
}
#endif //EXIT_OVERRIDE_H
