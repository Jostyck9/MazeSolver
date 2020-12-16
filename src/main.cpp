#include <iostream>
#include "Heap/MinHeap.hpp"
#include "Parser/Parser.hpp"
#include "Solver/ISolver.hpp"
#include "Solver/AStar.hpp"

void printHelp() {
    std::cout << std::endl;

#if defined(_WIN32) || defined(_WIN64)
    std::cout << "./MazeSolver.exe filename [color]" << std::endl << std::endl;
#else
    std::cout << "./MazeSolver filename [color]" << std::endl << std::endl;
#endif

    std::cout << "filename: file with the square to resolve" << std::endl;
    std::cout << "color: optional parameter, must be true or false to display the maze in color; DEFAULT true" << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2 && argc != 3) {
        std::cerr << "Missing argument, a filepath must be given" << std::endl;
        printHelp();
        return 84;
    }
    try {
        std::string filePath = std::string(argv[1]);

        // help management
        if (filePath == "-h") {
            printHelp();
            return 0;
        }

        // Parser
        auto parser = Parser(filePath);
        auto maze = parser.getMaze();

        // Color management
        if (argc == 3) {
            std::string colorParameter = std::string(argv[2]);
            if (colorParameter == "false" || colorParameter == "False")
                maze->setDisplayColor(false);
        }

        // Solver
        std::unique_ptr<ISolver> solver = std::make_unique<AStar>(maze);

        std::cout << "Maze before solving :" << std::endl;
        maze->display();

        solver->solveMaze();

        std::cout << std::endl << "Maze after solving :" << std::endl;
        maze->display();

    } catch (std::ios::failure &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (std::bad_alloc &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (std::exception &e) {
        std::cerr << "Unknown error" << std::endl;
        return 84;
    }
    return 0;
}
