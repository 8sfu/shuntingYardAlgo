#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(char* token);
  char* getValue();
  Node* getNext();
  void setNext(Node* newNode);
  void setLeft(Node* newNode);
  void setRight(Node* newNode);
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

#endif
