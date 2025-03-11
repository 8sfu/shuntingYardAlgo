#include <iostream>
#include "node.h"

using namespace std;

Node::Node(char* token){
  next = nullptr;
  left = nullptr;
  right = nullptr;
  value = token;
}

char* Node::getValue(){
  return value;
}

Node* Node::getNext(){
  return next;
}

void Node::setNext(Node* newNode){
  next = newNode;
}

void Node::setLeft(Node* newNode){
  left = newNode;
}

void Node::setRight(Node* newNode){
  right = newNode;
}

void Node::print(){
  if(left != nullptr){
    //cout << "      ";
    left->print();
  }
  cout << value << endl;
  if(right != nullptr){
    //cout << "      ";
    right->print();
  }
  if(left == nullptr && right == nullptr && next != nullptr){
    //cout << "  ";
    next->print();
  }
}

int Node::tokenLength(){
  int i = 0;
  while(value[i] != '\0'){
    i++;
  }
  return i;
}

int Node::getPrecedence(){
  char check = value[0];
  if(check == '+' || check == '-'){
    return 2;
  }else if(check == '*' || check == '/'){
    return 4;
  }else if(check == '^'){
    return 5;
  }else if(check == '('){
    return 6;
  }else if(check == ')'){
    return 7;
  }else{
    return 0;
  }
}

bool Node::isNumber(){
  int i = 0;
  while(value[i] != '\0'){
    if(!isdigit(value[i])){
      return false;
    }
    i++;
  }
  return true;
}

bool Node::isRightAssoc(){
  if(this->tokenLength() == 1 && this->getPrecedence() == 5){
    return true;
  }
  return false;
}

bool Node::isOperator(){
  if(this->tokenLength() == 1 && this->getPrecedence() < 6 && this->getPrecedence() > 0){
    return true;
  }
  return false;
}

bool Node::isLeftParen(){
  if(this->tokenLength() == 1 && this->getPrecedence() == 6){
    return true;
  }
  return false;
}

bool Node::isRightParen(){
  if(this->tokenLength() == 1 && this->getPrecedence() == 7){
    return true;
  }
  return false;
}
