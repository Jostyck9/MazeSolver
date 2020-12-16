//
// Created by Hugo on 12/12/2020.
//

#include <cmath>
#include "Node.hpp"

double Node::gValue() {
    return _gValue;
}

void Node::setHValue(Vector2d<int> &goalPosition) {
    _hValue = std::sqrt(std::pow((position.x - goalPosition.x), 2) + std::pow((position.y - goalPosition.y), 2));
    updateFValue();
}

void Node::setGValue(double gValue) {
    _gValue = gValue;
    updateFValue();
}

bool Node::operator<(const Node &rhs) const {
    return _fValue < rhs._fValue;
}

bool Node::operator>(const Node &rhs) const {
    return rhs < *this;
}

bool Node::operator<=(const Node &rhs) const {
    return !(rhs < *this);
}

bool Node::operator>=(const Node &rhs) const {
    return !(*this < rhs);
}

void Node::updateFValue() {
    _fValue = _hValue + _gValue;
}
