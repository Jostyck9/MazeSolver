//
// Created by Hugo on 17/12/2020.
//

#include "MinHeap.hpp"

MinHeap::MinHeap(int size) : _array(new Node *[size]()), _size(size) {
}

MinHeap::~MinHeap() {
    delete[] _array;
}

bool MinHeap::insert(Node *value) {
    int freeSpaceIndex;

    try {
        freeSpaceIndex = foundFreeNode();
    } catch (std::out_of_range &e) {
        std::cerr << "Heap error : " << e.what() << std::endl;
        return false;
    }

    if (!addAtIndex(value, freeSpaceIndex)) {
        std::cerr << "Heap error : Couldn't add value in the heap" << std::endl;
        return false;
    }
    heapifyUp(freeSpaceIndex);
    return true;
}


Node *MinHeap::extractTop() {
    if (_lastLeafIndex < 0) {
        throw std::out_of_range("Heap is empty");
    }

    if (_lastLeafIndex > 0)
        switchNodes(0, _lastLeafIndex);

    auto toReturn = extractAtIndex(_lastLeafIndex);

    if (_lastLeafIndex > 0)
        heapifyDown(0);

    return
            toReturn;

}

bool MinHeap::isEmpty() {
    if (_lastLeafIndex == -1)
        return true;
    return false;
}

int MinHeap::indexRightChild(int i) {
    return (2 * i) + 2;
}

int MinHeap::indexLeftChild(int i) {
    return (2 * i) + 1;
}

int MinHeap::indexParent(int i) {
    return (i - 1) / 2;
}

bool MinHeap::addAtIndex(Node *value, int i) {
    if (i >= _size)
        return false;

    _array[i] = value;
    _lastLeafIndex += 1;
    return true;
}

Node *MinHeap::extractAtIndex(int i) {
    if (i >= _size || i > _lastLeafIndex)
        throw std::out_of_range("Couldn't extract value");

    _lastLeafIndex -= 1;
    return _array[i];
}

int MinHeap::foundFreeNode() {
    if (_lastLeafIndex < _size - 1)
        return _lastLeafIndex + 1;
    throw std::out_of_range("Heap full");
}

void MinHeap::heapifyUp(int nodeIndex) {
    int parentIndex = indexParent(nodeIndex);

    while (parentIndex >= 0) {
        if (_array[parentIndex][0] <= _array[nodeIndex][0])
            return;

        switchNodes(parentIndex, nodeIndex);
        nodeIndex = parentIndex;
        parentIndex = indexParent(nodeIndex);
    }
}

void MinHeap::heapifyDown(int nodeIndex) {
    while (true) {
        int leftChild = indexLeftChild(nodeIndex);
        int rightChild = indexRightChild(nodeIndex);

        if (leftChild <= _lastLeafIndex &&
            (rightChild > _lastLeafIndex || _array[leftChild][0] <= _array[rightChild][0])) {
            if (_array[leftChild][0] > _array[nodeIndex][0])
                break;
            switchNodes(nodeIndex, leftChild);
            nodeIndex = leftChild;
            continue;
        }

        if (rightChild <= _lastLeafIndex &&
            (leftChild > _lastLeafIndex || _array[leftChild][0] > _array[rightChild][0])) {
            if (_array[rightChild][0] > _array[nodeIndex][0])
                break;
            switchNodes(nodeIndex, rightChild);
            nodeIndex = rightChild;
            continue;
        }

        break;
    }
}

void MinHeap::switchNodes(int first, int second) {
    Node *tmpValue = _array[first];

    _array[first] = _array[second];
    _array[second] = tmpValue;
}

void MinHeap::display() {
    std::cout << _lastLeafIndex << std::endl;
    for (int i = 0; i < _size; i++) {
        if (i > _lastLeafIndex) {
            std::cout << "NONE ";
        } else {
            std::cout << _array[i][0] << " ";
        }
    }
    std::cout << std::endl << std::endl;
}