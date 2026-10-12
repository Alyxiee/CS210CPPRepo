//
// Created by Alex Chenoweth on 10/11/2026

#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <typename T>

class ArrayList : public List<T> {
public:
   void addAnywhere(int position, T* value) override {
      if (size_ >= CAPACITY) {
         std::cout << "ArrayList is full." << std::endl;
         return;
      }
      if (position >= size_) {
         std::cout << "Position out of bounds." << std::endl;
      } else if (position < 0) {
         std::cout << "Position out of bounds." << std::endl;
         return;
      }
      //Shifts everything up one from position, then adds the value to data[position]
      for (int i = size_; i > position; --i) {
         data_[i] = data_[i - 1];
      }
      data_[position] = value;
      ++size_;
   }

   void deleteAnywhere(int position) override {
      if (size_ == 0) {
         std::cout << "ArrayList is empty." << std::endl;
      }
      if (position >= size_) {
         //std::cout << "Position out of bounds." << std::endl;
      } else if (position < 0) {
         std::cout << "Position out of bounds." << std::endl;
         return;
      }
      //deletes at position then shifts everything above it, down. To fill in the gap.
      delete data_[position];
      for (int i = position; i < size_ - 1; ++i) {
         data_[i] = data_[i + 1];
      }
      data_[size_ - 1] = nullptr;
      --size_;
   }

   void reverse() override {
      if (size_ <= 1) {
         return;
      }

      for (int i = 0; i < size_/2; ++i) {
         T* temp = data_[i];
         data_[i] = data_[size_ - 1 - i];
         data_[size_ - 1 - i] = temp;
      }
   }

   void concat (List<T>* other) override {
      ArrayList<T>* otherList = dynamic_cast<ArrayList<T>* >(other);
      if ( otherList == nullptr ) {
         std::cout << "Wrong list types." << std::endl;
         return;
      }

      if (size_ +otherList->size_ > CAPACITY) {
         std::cout << "No room to merge lists." << std::endl;
         return;
      }

      for (int i = 0; i < otherList->size_; ++i) {
         data_[size_+ i] = otherList->data_[i];
      }
      size_ += otherList->size_;
      otherList->size_ = 0;
   }

   void addFront(T* value) override {
      if (size_ >= CAPACITY) {
         std::cout << "ArrayList is full." << std::endl;
         return;
      }
      for (int i = size_; i > 0; --i) {
         data_[i] = data_[i - 1];
      }
      data_[0] = value;
      ++size_;
   }
   void deleteFront() override {
      if (size_ == 0) {
         std::cout << "ArrayList is empty." << std::endl;
         return;
      }
      delete data_[0];
      for (int i = 0; i < size_ - 1; ++i) {
         data_[i] = data_[i + 1];
      }
      --size_;
   }
   bool search(T* value) const override {
      for (int i = 0; i < size_; ++i) {
         if (*data_[i] == *value) return true;
      }
      return false;
   }
   void print() const override {
      for (int i = 0; i < size_; ++i) {
         std::cout << *data_[i] << ",";
      }
      std::cout << std::endl;
   }
   int getSize() const override {
      return size_;
   }
   ~ArrayList() override {
      for (int i = 0; i < size_; ++i) {
         delete data_[i];
      }
   }
private:
   static const int CAPACITY = 20;
   T*data_[CAPACITY] = {};
   int size_ = 0;
};




