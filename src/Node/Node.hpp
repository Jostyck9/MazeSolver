//
// Created by Hugo on 11/12/2020.
//

#ifndef MAZESOLVER_NODE_HPP
#define MAZESOLVER_NODE_HPP

#include <ostream>
#include "../Vector2d.hpp"

/**
 * Node that characterize the graph
 */
class Node {
private:
    double _gValue = 0;
    double _hValue = 0;
    double _fValue = 0;

public:
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

    Vector2d<int> position;
    State state = NOT_VISITED;
    Node *neighbours[4] = {nullptr, nullptr, nullptr, nullptr};
    Node *parent = nullptr;

    /**
     * Return the distance between the starting node and this node
     * @return the distance
     */
    double gValue();

    /**
     * Set the distance between the starting node and this node
     * @param gValue
     */
    void setGValue(double gValue);

    /**
     * Calculate and set the distance between the goal node and this node
     * @param goalPosition
     */
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
