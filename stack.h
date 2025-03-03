#ifndef STACK_H
#define STACK_H
#include "list.h"

class Stack : public List{
 public:
  Stack();
  void push(Node* newNode);
  Node* peek();
  Node* pop();
  void print();
  ~Stack();
};

#endif







