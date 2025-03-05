#ifndef LIST_H
#define LIST_H

struct Node {
public:
  Node();
  int getValue();
  Node* getNext();
  void setNext(Node* newNode);
  void print();
private:
  int value;
  Node* next;
  Node* left;
  Node* right;
};

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
