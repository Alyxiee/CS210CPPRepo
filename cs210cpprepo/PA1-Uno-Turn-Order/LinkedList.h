//
// Created by Alex Chenoweth on 10/11/2026.
//

#pragma once
#include <iostream>
#include <ostream>

#include "Node.h"
#include "List.h"

template <typename T>

class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), size_(0) {}

    void addAnywhere (int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
            Node<T>* current = head_;
            Node<T>* fresh = new Node<T>(value);
            // for loop finds the node before desired position
            for (int i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            fresh->next = current->next;
            current->next = fresh;
            size_++;
    }

    void deleteAnywhere (int position) override {
        if (position < 0 || position > (size_- 1)) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
            Node<T>* current = head_;
            for (int i = 0; i < position - 1; ++i) {
                current = current->next;
            }
            Node<T>* doomed = current->next;
            current->next = current->next->next;
            delete doomed->data;
            delete doomed;
            --size_;
    }

    void reverse() override {
        if (size_ <= 1) {
            return;
        }
        Node<T>* previousOne = nullptr;
        Node<T>* current = head_;
        Node<T>* nextOne = nullptr;

        while (current != nullptr) {
            nextOne = current->next;
            current->next = previousOne;
            previousOne = current;
            current = nextOne;
        }
        head_ = previousOne;
    }

    void concat (List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>* >(other);
        if ( otherList == nullptr ) {
            std::cout << "Incompatible List Types." << std::endl;
            return;
        }
        if (otherList->size_ == 0) {
            return;
        }
        if (size_ == 0) {
            head_ = otherList->head_;
        }
        else {
            Node<T>* current = head_;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = otherList->head_;
        }
        size_ += otherList->size_;

        otherList->size_ = 0;
        otherList->head_ = nullptr;

    }

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        size_++;
    }
    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
        size_--;
    }
    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    int getSize() const override {
        return size_;
    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;
    int size_;


};
