//
// Created by xoska on 19.04.2025.
//

#ifndef UTILS_H
#define UTILS_H
#include "vec2.h"

namespace oc {
    inline bool pointInTriangle(const vec2& p, const vec2& a, const vec2& b, const vec2& c) {
        float denominator = ((b.y - c.y)*(a.x - c.x) + (c.x - b.x)*(a.y - c.y));
        float alpha = ((b.y - c.y)*(p.x - c.x) + (c.x - b.x)*(p.y - c.y)) / denominator;
        float beta  = ((c.y - a.y)*(p.x - c.x) + (a.x - c.x)*(p.y - c.y)) / denominator;
        float gamma = 1.0f - alpha - beta;

        return (alpha >= 0 && beta >= 0 && gamma >= 0);
    }
}

#endif //UTILS_H
