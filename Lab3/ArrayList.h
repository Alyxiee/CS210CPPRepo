//
// Created by Alex Chenoweth on 9/17/2026

#pragma once
#include <iostream>
using namespace std;

template <typename T>

class ArrayList {
   private:
   static const int CAPACITY = 20;
   T data [CAPACITY];
   int size = 0;
   public:
   ArrayList():size(0) {

   }

   //Just checks if the array has a specified item.
   bool search(T item) {
      if (size !=0) {
         for (int i = 0; i < size; i++) {
            if (data[i] == item) {
               return true;
            }
            return false;
         }
      }
      return false;
   }

   //Methods to add: Add front/back of list, Delete front/back of list.
   void addBack(T item) {
      if (size < CAPACITY) {
         data[size] = item;
         size++;
      }
   }
   void addFront(T item) {
      if (size < CAPACITY) {
         for (int i = size; i > 0; i--) {
            data[i] = data[i-1];
         }
         data[0] = item;
         size++;
      }
   }
   void removeFront() {
      if (size > 0) {
         for (int i = 0; i < size; i++) {
            data[i] = data[i+1];
         }
         size--;
      }
   }
   void removeBack() {
      if (size > 0) {
         size--;
      }
   }
};




