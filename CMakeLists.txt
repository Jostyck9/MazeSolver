cmake_minimum_required(VERSION 3.16)
project(MazeSolver)

set(CMAKE_CXX_STANDARD 14)

add_executable(MazeSolver src/main.cpp src/Maze/Maze.cpp src/Maze/Maze.hpp src/Node/Node.hpp src/Vector2d.hpp src/Parser/Parser.cpp src/Parser/Parser.hpp src/Node/Node.cpp src/Solver/ISolver.hpp src/Solver/AStar.cpp src/Solver/AStar.hpp src/Heap/IHeap.hpp src/Heap/MinHeap.hpp src/Heap/MinHeap.cpp)