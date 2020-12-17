//
// Created by Hugo on 12/12/2020.
//

#include <cmath>
#include "AStar.hpp"

AStar::AStar(std::shared_ptr<Maze> &maze) : _maze(maze) {
    _open = std::make_unique<MinHeap>(calculateSizeOpenAllocation(maze->getSize()));
}

bool AStar::solveMaze() {
    Vector2d<int> startingPosition = _maze->getStartingNode()->position;
    Vector2d<int> finishingPosition = _maze->getFinishingNode()->position;

    openNode(_maze->getStartingNode());
    _maze->display();

    while (!_open->isEmpty()) {
        //We take the node with the smallest F value
        Node *current = getOpenNode();

        //We add it in the close set
        closeNode(current);

        // If we reached the end, we stop
        if (current == _maze->getFinishingNode()) {
            applyPathToNode();
            return true;
        }

        // We visit each neighbour of the node
        for (auto &neighbour : current->neighbours) {
            if (neighbour == nullptr || neighbour->state == Node::State::CLOSED)
                continue;

            double distanceFromStart = calculateDistance(startingPosition, neighbour->position);
            if (distanceFromStart < neighbour->gValue() || neighbour->state != Node::State::OPEN) {
                neighbour->setGValue(distanceFromStart);
                neighbour->setHValue(finishingPosition);

                neighbour->parent = current;

                if (neighbour->state != Node::State::OPEN)
                    openNode(neighbour);
            }
        }
    }

    return false;
}

void AStar::openNode(Node *current) {
    current->state = Node::State::OPEN;
    _open->insert(current);
}

void AStar::closeNode(Node *current) {
    current->state = Node::State::CLOSED;
}

Node *AStar::getOpenNode() {
    Node *current = _open->extractTop();
    return current;
}

double AStar::calculateDistance(Vector2d<int> &first, Vector2d<int> &second) {
    return std::sqrt(std::pow((first.x - second.x), 2) + std::pow((first.y - second.y), 2));
}

void AStar::applyPathToNode() {
    Node *current = _maze->getFinishingNode();

    current->state = Node::State::PATH;
    while (current->parent != nullptr) {
        current = current->parent;
        current->state = Node::State::PATH;
    }
}

int AStar::calculateSizeOpenAllocation(Vector2d<unsigned int> &size) {
    return (size.x + size.y) / 2;
}
