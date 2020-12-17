//
// Created by Hugo on 12/12/2020.
//

#include <fstream>
#include <iostream>
#include "Parser.hpp"

Parser::Parser(std::string &filePath) : _filePath(filePath) {

}

std::shared_ptr<Maze> Parser::getMaze() {
    unsigned int currentY = 0;
    std::string line;
    std::fstream file = openFile();

    if (getline(file, line))
        parseSize(line);
    else {
        file.close();
        throw std::invalid_argument("Invalid file format, the first line needs to have the size");
    }
    _maze = createMazeArray();
    while (getline(file, line)) {
        if (line.empty())
            continue;
        fillLine(line, currentY, _maze[currentY]);
        currentY++;
    }

    if (_startingNode == nullptr)
        throw std::invalid_argument(&"Invalid file format, the maze must contain a starting node : " [ _startCharacter]);

    if (_endingNode == nullptr)
        throw std::invalid_argument(&"Invalid file format, the maze must contain an ending node : " [ _startCharacter]);

    file.close();
    return std::make_shared<Maze>(_size, _maze, _startingNode, _endingNode);
}

std::fstream Parser::openFile() {
    std::fstream myFile;

    std::cout << "Reading file : " + _filePath << std::endl;
    myFile.open(_filePath, std::ios::in);
    if (!myFile)
        throw std::ios::failure("Couldn't open the file" + _filePath);

    return myFile;
}

void Parser::parseSize(std::string &firstLine) {
    if (firstLine.empty())
        throw std::invalid_argument("Invalid file format, the first line needs to have the size");

    auto index = firstLine.find(_sizeDelimiter);
    if (index == std::string::npos)
        throw std::invalid_argument("Invalid file format, the first line needs to have the size delimited by character ','");

    _size.x = std::stoi(firstLine.substr(0, index));
    _size.y = std::stoi(firstLine.substr(index + 1, firstLine.length()));
}

Node ***Parser::createMazeArray() {
    Node ***maze = new Node **[_size.y]();

    for (unsigned int i = 0; i < _size.y; i++) {
        maze[i] = new Node *[_size.x]();
    }

    return maze;
}

void Parser::fillLine(std::string &line, int y, Node **lineToFill) {
    int x = 0;

    for (auto &item : line) {

        // if wall pass to next
        if (item != _pathCharacter && item != _startCharacter && item != _finishingCharacter) {
            x++;
            continue;
        }

        // Create path node for the graph
        _maze[y][x] = createNode(Vector2d<int>(x, y));
        if (x > 0 && _maze[y][x - 1] != nullptr) {
            _maze[y][x - 1]->neighbours[Node::RIGHT] = _maze[y][x];
            _maze[y][x]->neighbours[Node::LEFT] = _maze[y][x - 1];
        }
        if (y > 0 && _maze[y - 1][x] != nullptr) {
            _maze[y - 1][x]->neighbours[Node::DOWN] = _maze[y][x];
            _maze[y][x]->neighbours[Node::UP] = _maze[y - 1][x];
        }

        // Save start
        if (item == _startCharacter) {
            if (_startingNode != nullptr)
                throw std::invalid_argument("Maze must have only one starting node");
            _startingNode = _maze[y][x];
        }

        // Save ending
        if (item == _finishingCharacter) {
            if (_endingNode != nullptr)
                throw std::invalid_argument("Maze must have only one ending node");
            _endingNode = _maze[y][x];
        }

        x++;
    }
}

Node *Parser::createNode(Vector2d<int> position) {
    Node *nodeToReturn = new Node;

    nodeToReturn->position = position;
    return nodeToReturn;
}

