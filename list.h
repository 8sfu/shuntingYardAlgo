#ifndef LIST_H
#define LIST_H

struct Node {
public:
  Node(char* token);
  char* getValue();
  Node* getNext();
  void setNext(Node* newNode);
  void print();
  
  int tokenLength();
  int getPrecedence();
  bool isNumber();
  bool isRightAssoc();
  bool isOperator();
  bool isLeftParen();
  bool isRightParen();
  
private:
  char* value;
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
