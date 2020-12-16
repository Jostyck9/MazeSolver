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
    std::unique_ptr<IHeap> _open;

public:

    explicit AStar(std::shared_ptr<Maze> &maze);

    bool solveMaze() override;

private:
    /**
     * Set the node in the open MinHeap
     * @param current - node to inset
     */
    void openNode(Node *current);

    /**
     * Get the node with the lowest F value
     * @return node
     */
    Node *getOpenNode();

    /**
     * Set the node in the close list as visited
     * @param current
     */
    static void closeNode(Node *current);

    /**
     * Calculate the distance between two points
     * @param first position
     * @param second position
     * @return the distance
     */
    static double calculateDistance(Vector2d<int> &first, Vector2d<int> &second);

    /**
     * From the finishing node, will set the solution path in the nodes
     */
    void applyPathToNode();
};


#endif //MAZESOLVER_ASTAR_HPP
