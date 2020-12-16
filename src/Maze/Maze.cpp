//
// Created by Hugo on 11/12/2020.
//

#include <string>
#include <iostream>
#include "Maze.hpp"

Maze::Maze(Vector2d<unsigned int> size, Node ***maze, Node *startingNode, Node *finishingNode) : _size(size),
                                                                                                 _maze(maze),
                                                                                                 _start(startingNode),
                                                                                                 _finish(finishingNode) {

}

Maze::~Maze() {
    if (_maze != nullptr) {
        for (unsigned int i = 0; i < _size.y; i++) {
            if (_maze[i] != nullptr) {
                for (unsigned int j = 0; j < _size.x; j++) {
                    if (_maze[i][j] != nullptr)
                        delete _maze[i][j];
                }
                delete[] _maze[i];
            }
        }
        delete[] _maze;
    }
}

Node *Maze::getStartingNode() {
    return _start;
}

Node *Maze::getFinishingNode() {
    return _finish;
}

void Maze::display() {
    for (unsigned int y = 0; y < _size.y; y++) {
        std::string toPrint;
        for (unsigned int x = 0; x < _size.x; x++) {
            if (_maze[y][x] != nullptr) {

                //Colors
                switch (_maze[y][x]->state) {

                    case Node::State::NOT_VISITED:
                        toPrint += printColor(DEFAULT) + _freeSpace;
                        break;

                    case Node::State::OPEN:
                        toPrint += printColor(GREEN) + _freeSpace;
                        break;

                    case Node::State::CLOSED:
                        toPrint += printColor(RED) + _freeSpace;
                        break;

                    case Node::State::PATH:
                        toPrint += printColor(BLUE) + printColor(BLUE) + _path;
                        break;

                    default:
                        toPrint += printColor(DEFAULT) + _freeSpace;
                        break;
                }
            } else {
                toPrint += printColor(WHITE) + _wall;
            }
        }
        std::cout << toPrint << printColor(DEFAULT) << std::endl;
    }
    std::cout << std::endl;
}

std::string Maze::printColor(Maze::Color color) const {
    if (!_displayColor)
        return "";

    std::string codeColor = std::to_string(color);
    return "\033[3" + codeColor + ";4" + codeColor + "m";
}

void Maze::setDisplayColor(bool displayColor) {
    _displayColor = displayColor;
}
