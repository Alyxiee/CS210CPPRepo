//
// Created by cheno on 10/6/2026.
//

#pragma once

#include "List.h"
#include "Queue.h"

template <typename T>

class QueueList : public Queue<T> {
public:
    void enqueue(T* value) override {
        queue_.addBack(value);
    }
    void dequeue() override {
        queue_.deleteFront();
    }
    T* front() const override {
        return queue_.getFront();
    }
    bool isEmpty() const override {
        return queue_.isEmpty();
    }
    int size() const override {
        return queue_.size();
    }
    void print() const override {
        queue_.print();
    }
private:
    LinkedList<T> queue_;
};
