#ifndef LIST_H
#define LIST_H
#include "node.h"

class List {
 public:
  List();
  bool firstNull();
  void addHead(Node* newNode);
  void addTail(Node* newNode);
  Node* getHead();
  Node* getTail();
  void removeHead();
  void removeTail();
  void printList();
  ~List();
 private:
  Node* first;
};

#endif
