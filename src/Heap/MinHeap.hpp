//
// Created by Hugo on 16/12/2020.
//

#ifndef MAZESOLVER_MINHEAP_HPP
#define MAZESOLVER_MINHEAP_HPP

#include <iostream>
#include <stdexcept>
#include "IHeap.hpp"

class MinHeap : public IHeap {
private:
    Node **_array;
    int _size;
    int _lastLeafIndex = -1;

public:
    MinHeap(int size);

    ~MinHeap();

    /**
    * Insert the element in the Heap at the according position
    * @param The value to insert
    * @return true is succeed, false otherwise
    * @throw std::out_of_range
    */
    bool insert(Node *value) override;

    /**
     * Extract the value at the top of the heap
     * @return the corresponding value
     * @throw std::out_of_range
     */
    Node *extractTop() override;

    /**
     * Say if the heap is empty
     * @return true if empty, false otherwise
     */
    bool isEmpty() override;

private:
    /**
     * Calculate the index of the right child
     * @param i index of the current node
     * @return index of the child
     */
    int indexRightChild(int i);

    /**
     * Calculate the index of the left child
     * @param i index of the current node
     * @return index of the child
     */
    int indexLeftChild(int i);

    /**
     * Calculate the index of the parent
     * @param i index of the current node
     * @return index of the parent
     */
    int indexParent(int i);

    /**
     * Add a value at the position i
     * @param value
     * @param i
     * @return true if the node is added, false otherwise
     */
    bool addAtIndex(Node *value, int i);

    /**
     * Extract a value at the position i
     * @param value
     * @param the value
     * @throw std::out_of_range
     */
    Node *extractAtIndex(int i);

    /**
     * Find an empty node
     * @return the index of this node
     * @throw std::out_of_range
     */
    int foundFreeNode();

    /**
     * Will move the node up until it will be at the top of his subtree as the minimum value
     * @param nodeIndex index of the node to heapifyUp
     */
    void heapifyUp(int nodeIndex);

    /**
     * Will move the node up until it will be at the top of his subtree as the minimum value
     * @param nodeIndex index of the node to heapifyDown
     */
    void heapifyDown(int nodeIndex);

    /**
     * Switch the position of two nodes
     *
     * @param first node index
     * @param second node index
     */
    void switchNodes(int first, int second);

    void display();

};

#endif //MAZESOLVER_MINHEAP_HPP
