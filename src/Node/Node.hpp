//
// Created by Hugo on 11/12/2020.
//

#ifndef MAZESOLVER_NODE_HPP
#define MAZESOLVER_NODE_HPP

#include <ostream>
#include "../Vector2d.hpp"

enum State {
    CLOSED,
    OPEN,
    NOT_VISITED,
    PATH
};

enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

class Node {
private:
    double _gValue = 0;
    double _hValue = 0;
    double _fValue = 0;

public:
    Vector2d<int> position;
    State state = NOT_VISITED;
    Node *neighbours[4] = {nullptr, nullptr, nullptr, nullptr};
    Node *parent = nullptr;

    double gValue();
    double hValue();
    double fValue();

    void setGValue(Vector2d<int> &startingPosition);
    void setGValue(double gValue);
    void setHValue(Vector2d<int> &goalPosition);

    bool operator<(const Node &rhs) const;

    bool operator>(const Node &rhs) const;

    bool operator<=(const Node &rhs) const;

    bool operator>=(const Node &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Node &node) {
        os << "{_fValue: " << node._fValue << " position: " << node.position << "}";
        return os;
    }

private:
    void updateFValue();
};

#endif //MAZESOLVER_NODE_HPP
