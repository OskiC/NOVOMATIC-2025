//
// Created by xoska on 21.04.2025.
//

#include "exit_override.h"

namespace oc {
    ExitHandler exit_handler = nullptr;

    void ExitProgram(int code) {
        if (exit_handler) {
           exit_handler(code);
        }else {
            std::exit(code);
        }
    }

    void SetExitHandler(ExitHandler handler) {
        exit_handler = handler;
    }

}