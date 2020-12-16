//
// Created by Hugo on 11/12/2020.
//

#ifndef MAZESOLVER_MAZE_HPP
#define MAZESOLVER_MAZE_HPP

#include <string>
#include "../Node/Node.hpp"

class Maze {
private:
    enum Color {
        RED      = 1,
        GREEN    = 2,
        BLUE     = 4,
        WHITE    = 7,
        DEFAULT  = 9,
    };

    const char _wall = '#';
    const char _path = 'O';
    const char _freeSpace = ' ';
    bool _displayColor = true;

    Vector2d<unsigned int> _size;
    Node ***_maze = nullptr;
    Node *_start = nullptr;
    Node *_finish = nullptr;

public:
    Maze(Vector2d<unsigned int> size, Node ***maze, Node *startingNode, Node *finishingNode);

    ~Maze();

    Node *getStartingNode();

    Node *getFinishingNode();

    void display();

    void setDisplayColor(bool displayColor);

private:
    std::string printColor(Color color) const;
};


#endif //MAZESOLVER_MAZE_HPP
