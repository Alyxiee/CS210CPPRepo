//
// Created by Alex Chenoweth on 9/23/2026.
//

#pragma once

template <typename T>
class Node {
public:
    T* data;
    Node<T>* next;
    explicit Node(T* value) : data(value), next(nullptr) {}
};