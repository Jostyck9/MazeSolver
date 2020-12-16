//
// Created by Hugo on 16/12/2020.
//

#ifndef MAZESOLVER_IHEAP_HPP
#define MAZESOLVER_IHEAP_HPP

#include "../Node/Node.hpp"

class IHeap {
public:
    virtual ~IHeap() = default;

    /**
     * Insert the element in the Heap at the according position
     * @param The value to insert
     * @return true is succeed, false otherwise
     * @throw std::out_of_range
     */
    virtual bool insert(Node *value) = 0;

    /**
     * Extract the value at the top of the heap
     * @return the corresponding value
     * @throw std::out_of_range
     */
    virtual Node *extractTop() = 0;

    /**
     * Say if the heap is empty
     * @return true if empty, false otherwise
     */
    virtual bool isEmpty() = 0;
};

#endif //MAZESOLVER_IHEAP_HPP
