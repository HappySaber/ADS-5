// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
 private:
  int top;
  T arr[100];

 public:
  TStack() : top(-1) {}

  bool isEmpty()const { return top == -1; }
  bool isFull() const { return top == size - 1; }

  const T& pop() {
    if (isEmpty())
      throw std::string("String is empty");
    else
      return arr[top--];
  }
  void push(T val) {
    if (isFull())
      throw std::string("Stack is full");
    else
      arr[++top] = val;
  }
  const T& getValue() const { return arr[top]; }
};

#endif  // INCLUDE_TSTACK_H_
