//
// Created by Hugo on 12/12/2020.
//

#ifndef MAZESOLVER_PARSER_HPP
#define MAZESOLVER_PARSER_HPP


#include <string>
#include <memory>
#include "../Maze/Maze.hpp"

class Parser {
private:
    const std::string _sizeDelimiter = ",";
    const char _startCharacter = 'S';
    const char _finishingCharacter = 'F';
    const char _pathCharacter = ' ';
    const std::string _wallCharacters = "+-|";

    std::string &_filePath;
    Vector2d<unsigned int> _size;
    Node ***_maze = nullptr;
    Node *_startingNode = nullptr;
    Node *_endingNode = nullptr;

public:
    Parser(std::string &filePath);

    std::shared_ptr<Maze> getMaze();

private:
    /**
     * Open the file and return the stream
     *
     * @return
     */
    std::fstream openFile();

    /**
     * Parse the size of the maze
     *
     * @param firstLine
     */
    void parseSize(std::string &firstLine);

    /**
     * Create the ampty maze array initialized with nullptr
     *
     * @return
     */
    Node ***createMazeArray();

    /**
     * Parse a line and fill the map
     *
     * @param line
     * @param y
     * @param lineToFill
     */
    void fillLine(std::string &line, int y, Node **lineToFill);

    /**
     * Create a Node for the given position and connect to the neighbour and put it in the map
     *
     * @param position
     * @return the node created
     */
    Node *createNode(Vector2d<int> position);
};


#endif //MAZESOLVER_PARSER_HPP
