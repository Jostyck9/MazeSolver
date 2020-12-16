//
// Created by Hugo on 12/12/2020.
//

#ifndef MAZESOLVER_ISOLVER_HPP
#define MAZESOLVER_ISOLVER_HPP

class ISolver {

public:
    virtual ~ISolver() = default;

    /**
     * Solve the maze by applying the algorithm
     * @return success of the operation - True an exit has been found, false no solution
     */
    virtual bool solveMaze() = 0;

};

#endif //MAZESOLVER_ISOLVER_HPP
