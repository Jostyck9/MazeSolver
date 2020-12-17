//
// Created by Hugo on 11/12/2020.
//

#ifndef MAZESOLVER_MAZE_HPP
#define MAZESOLVER_MAZE_HPP

#include <string>
#include "../Node/Node.hpp"

/**
 * Container for the maze graph
 */
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

    Vector2d<int> _size;
    Node ***_maze = nullptr;
    Node *_start = nullptr;
    Node *_finish = nullptr;

public:
    Maze(Vector2d<int> size, Node ***maze, Node *startingNode, Node *finishingNode);

    ~Maze();

    /**
     * Return the starting node of the maze
     * @return starting node
     */
    Node *getStartingNode();

    /**
     * Return the finishing node of the maze
     * @return finishing node
     */
    Node *getFinishingNode();

    /**
     * Display the maze
     */
    void display();

    /**
     * Define if the graph will be displayed with colors or not
     * @param displayColor true or false
     */
    void setDisplayColor(bool displayColor);

    /**
     * Return the size of the maze
     * @return a vector
     */
    Vector2d<int> &getSize();

private:
    std::string printColor(Color color) const;
};


#endif //MAZESOLVER_MAZE_HPP
