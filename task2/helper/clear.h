//
// Created by xoska on 19.04.2025.
//

#ifndef CLEAR_H
#define CLEAR_H

#include <cstdlib>

inline void Clear(){
    #if defined _WIN32 || defined(WIN64)
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #endif
}
#endif //CLEAR_H
