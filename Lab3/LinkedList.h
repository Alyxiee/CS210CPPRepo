//
// Created by cheno on 9/23/2026.
//

#pragma once
#include <iostream>
#include <ostream>

#include "Node.h"

template <typename T>

class LinkedList {
    Node<T>* head;
    int size;

    LinkedList(T* value) : head(value), size(0) {
        Node<T>*temp = new Node<T>(value);
        head = temp;
        size = 1;
    }

    void print() {
        Node<T>*temp1 = head;
        while (temp1 != nullptr) {
            cout << temp1->print() << endl;
            temp1 = temp1->next;
        }
    }

    void append(T* value) {
        Node<T>*newnode = new Node<T>(value);
        if (head == nullptr) {
            head = newnode;
            size++;
        }
        Node<T>*temp = head;
        while (temp != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        size++;
    }


};
