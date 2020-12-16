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
    /*std::unique_ptr<IHeap<int>> test = std::make_unique<MinHeap<int>>(20);

    int value1 = 10;
    int value2 = 5;
    int value3 = 7;
    int value4 = 9;
    int value5 = 1;

    test->Insert(10);
    test->Insert(5);
    test->Insert(7);
    test->Insert(9);
    test->Insert(1);
    test->Insert(1);

    auto test1 = test->extractTop();
    auto test2 = test->extractTop();
    auto test3 = test->extractTop();
    auto test4 = test->extractTop();
    auto test5 = test->extractTop();
    auto test6 = test->extractTop();*/

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
