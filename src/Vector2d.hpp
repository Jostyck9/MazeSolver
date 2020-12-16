//
// Created by Hugo on 11/12/2020.
//

#ifndef MAZESOLVER_VECTOR2D_HPP
#define MAZESOLVER_VECTOR2D_HPP

#include <ostream>

template<class T>
class Vector2d {
public:
    Vector2d(T x = 0, T y = 0) : x(x), y(y) {
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector2d &d) {
        os << "(" << d.x << ";" << d.y << ")";
        return os;
    }

    T x;
    T y;
};


#endif //MAZESOLVER_VECTOR2D_HPP
