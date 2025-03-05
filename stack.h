#ifndef STACK_H
#define STACK_H
#include "list.h"

class Stack : protected List{
 public:
  Stack();
  bool isNotEmpty();
  void push(Node* newNode);
  Node* peek();
  Node* pop();
  void print();
  ~Stack();
};

#endif







