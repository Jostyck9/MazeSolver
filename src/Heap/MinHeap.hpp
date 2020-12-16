//
// Created by Hugo on 16/12/2020.
//

#ifndef MAZESOLVER_MINHEAP_HPP
#define MAZESOLVER_MINHEAP_HPP

#include <iostream>
#include <stdexcept>
#include "IHeap.hpp"

template<class T>
class MinHeap : public IHeap<T> {
private:
    bool _isPtr = std::is_pointer<T>::value;
    T *_array;
    int _size;
    int _lastLeafIndex = -1;

public:
    MinHeap(int size) : _array(new T[size]()), _size(size) {
    }

    ~MinHeap() {
        delete[] _array;
    }

    /**
    * Insert the element in the Heap at the according position
    * @param The value to insert
    * @return true is succeed, false otherwise
    * @throw std::out_of_range
    */
    bool insert(T value) override {
        unsigned int freeSpaceIndex;

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
        //display();
        return true;
    }

    /**
     * Extract the value at the top of the heap
     * @return the corresponding value
     * @throw std::out_of_range
     */
    T extractTop() override {
        if (_lastLeafIndex < 0) {
            throw std::out_of_range("Heap is empty");
        }

        if (_lastLeafIndex > 0)
            switchNodes(0, _lastLeafIndex);

        auto toReturn = extractAtIndex(_lastLeafIndex);

        if (_lastLeafIndex > 0)
            heapifyDown(0);

        return toReturn;

    }

    /**
     * Say if the heap is empty
     * @return true if empty, false otherwise
     */
    bool isEmpty() override {
        if (_lastLeafIndex == -1)
            return true;
        return false;
    }

private:
    /**
     * Calculate the index of the right child
     * @param i index of the current node
     * @return index of the child
     */
    unsigned int indexRightChild(unsigned int i) {
        return (2 * i) + 2;
    }

    /**
     * Calculate the index of the left child
     * @param i index of the current node
     * @return index of the child
     */
    unsigned int indexLeftChild(unsigned int i) {
        return (2 * i) + 1;
    }

    /**
     * Calculate the index of the parent
     * @param i index of the current node
     * @return index of the parent
     */
    int indexParent(int i) {
        return (i - 1) / 2;
    }

    /**
     * Add a value at the position i
     * @param value
     * @param i
     * @return true if the node is added, false otherwise
     */
    bool addAtIndex(T value, unsigned int i) {
        if (i >= _size)
            return false;

        _array[i] = value;
        _lastLeafIndex += 1;
        return true;
    }

    /**
     * Extract a value at the position i
     * @param value
     * @param the value
     * @throw std::out_of_range
     */
    T extractAtIndex(unsigned int i) {
        if (i >= _size || i > _lastLeafIndex)
            throw std::out_of_range("Couldn't extract value");

        _lastLeafIndex -= 1;
        return _array[i];
    }

    /**
     * Find an empty node
     * @return the index of this node
     * @throw std::out_of_range
     */
    unsigned int foundFreeNode() {
        if (_lastLeafIndex < _size - 1)
            return _lastLeafIndex + 1;
        throw std::out_of_range("Heap full");
    }

    /**
     * Will move the node up until it will be at the top of his subtree as the minimum value
     * @param nodeIndex index of the node to heapifyUp
     */
    void heapifyUp(unsigned int nodeIndex) {
        int parentIndex = indexParent(nodeIndex);

        while (parentIndex >= 0) {
            if (_isPtr && _array[parentIndex][0] <= _array[nodeIndex][0])
                return;
            else if (_array[parentIndex] <= _array[nodeIndex])
                return;

            switchNodes(parentIndex, nodeIndex);
            nodeIndex = parentIndex;
            parentIndex = indexParent(nodeIndex);
        }
    }

    /**
     * Will move the node up until it will be at the top of his subtree as the minimum value
     * @param nodeIndex index of the node to heapifyDown
     */
    void heapifyDown(unsigned int nodeIndex) {
        while (true) {
            int leftChild = indexLeftChild(nodeIndex);
            int rightChild = indexRightChild(nodeIndex);

            if (_isPtr) {
                if (leftChild <= _lastLeafIndex && (rightChild > _lastLeafIndex || _array[leftChild][0] <= _array[rightChild][0])) {
                    if (_array[leftChild][0] > _array[nodeIndex][0])
                        break;
                    switchNodes(nodeIndex, leftChild);
                    nodeIndex = leftChild;
                    continue;
                }

                if (rightChild <= _lastLeafIndex && (leftChild > _lastLeafIndex || _array[leftChild][0] > _array[rightChild][0])) {
                    if (_array[rightChild][0] > _array[nodeIndex][0])
                        break;
                    switchNodes(nodeIndex, rightChild);
                    nodeIndex = rightChild;
                    continue;
                }
            } else {
                if (leftChild <= _lastLeafIndex && (rightChild > _lastLeafIndex || _array[leftChild] <= _array[rightChild])) {
                    if (_array[leftChild] > _array[nodeIndex])
                        break;
                    switchNodes(nodeIndex, leftChild);
                    nodeIndex = leftChild;
                    continue;
                }

                if (rightChild <= _lastLeafIndex && (leftChild > _lastLeafIndex || _array[leftChild] > _array[rightChild])) {
                    if (_array[rightChild] > _array[nodeIndex])
                        break;
                    switchNodes(nodeIndex, rightChild);
                    nodeIndex = rightChild;
                    continue;
                }
            }

            break;
        }
    }

    /**
     * Switch the position of two nodes
     *
     * @param first node index
     * @param second node index
     */
    void switchNodes(unsigned int first, unsigned int second) {
        T tmpValue = _array[first];

        _array[first] = _array[second];
        _array[second] = tmpValue;
    }

    void display() {
        std::cout << _lastLeafIndex << std::endl;
        for (int i = 0; i < _size; i++) {
            if (i > _lastLeafIndex) {
                std::cout << "NONE ";
            } else {
                if (_isPtr)
                    std::cout << _array[i][0] << " ";
                else
                    std::cout << _array[i] << " ";
            }
        }
        std::cout << std::endl << std::endl;
    }

};

#endif //MAZESOLVER_MINHEAP_HPP