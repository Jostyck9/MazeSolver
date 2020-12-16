//
// Created by Hugo on 12/12/2020.
//

#ifndef MAZESOLVER_ASTAR_HPP
#define MAZESOLVER_ASTAR_HPP

#include <memory>
#include <list>
#include <queue>
#include "../Heap/MinHeap.hpp"
#include "ISolver.hpp"
#include "../Maze/Maze.hpp"

class AStar : public ISolver {
private:

    std::shared_ptr<Maze> &_maze;
    /*std::priority_queue<Node *, std::vector<Node *>, std::less<>> _open;*/
    std::unique_ptr<IHeap<Node *>> _open;

public:

    AStar(std::shared_ptr<Maze> &maze);

    bool solveMaze() override;

private:
    void openNode(Node *current);

    Node *getOpenNode();

    void closeNode(Node *current);

    static float calculateDistance(Vector2d<int> &first, Vector2d<int> &second);

    void applyPathToNode();
};


#endif //MAZESOLVER_ASTAR_HPP
