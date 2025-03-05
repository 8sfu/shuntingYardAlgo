#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

class Queue : protected List{
 public:
  Queue();
  bool isNotEmpty();
  void enqueue(Node* newNode);
  Node* dequeue();
  void print();
  ~Queue();
};

#endif










