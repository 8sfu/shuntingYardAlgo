#ifndef TREE_H
#define TREE_H
#include "list.h"
#include "stack.h"
#include "queue.h"

class Tree : protected List{
 public:
  Tree(Queue* postfix);
  void printPostfix();
  void printInfix();
  void printPrefix();
 private:
  Stack* root;
};

#endif
