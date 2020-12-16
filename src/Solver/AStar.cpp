//
// Created by Hugo on 12/12/2020.
//

#include <cmath>
#include "AStar.hpp"

bool AStar::solveMaze() {
    Vector2d<int> startingPosition = _maze->getStartingNode()->position;
    Vector2d<int> finishingPosition = _maze->getFinishingNode()->position;

    openNode(_maze->getStartingNode());
    _maze->display();

    //while (!_open.empty()) {
    while (!_open->isEmpty()) {
        Node *current = getOpenNode();
        closeNode(current);

        // If we reached the end stop
        if (current == _maze->getFinishingNode()) {
            applyPathToNode();
            return true;
        }

        for (auto &neighbour : current->neighbours) {
            if (neighbour == nullptr || neighbour->state == State::CLOSED)
                continue;

            double distanceFromStart = calculateDistance(startingPosition, neighbour->position);
            if (distanceFromStart < neighbour->gValue() || neighbour->state != State::OPEN) {
                neighbour->setGValue(distanceFromStart);
                neighbour->setHValue(finishingPosition);

                neighbour->parent = current;

                if (neighbour->state != State::OPEN)
                    openNode(neighbour);
            }
            //_maze->display();
        }
    }

    return false;
}

AStar::AStar(std::shared_ptr<Maze> &maze) : _maze(maze), _open(std::make_unique<MinHeap<Node*>>(2000)) {}

void AStar::openNode(Node *current) {
    current->state = State::OPEN;
    //_open.push(current);
    _open->insert(current);
}

void AStar::closeNode(Node *current) {
    current->state = State::CLOSED;
}

Node *AStar::getOpenNode() {
    /*Node *current = _open.top();
    _open.pop();*/
    Node *current = _open->extractTop();
    return current;
}

float AStar::calculateDistance(Vector2d<int> &first, Vector2d<int> &second) {
    auto value1 = std::pow((first.x - second.x), 2);
    auto value2 = std::pow((first.y - second.y), 2);
    return std::sqrt(value1 + value2);
}

void AStar::applyPathToNode() {
    Node *current = _maze->getFinishingNode();

    current->state = State::PATH;
    while (current->parent != nullptr) {
        current = current->parent;
        current->state = State::PATH;
    }
}
