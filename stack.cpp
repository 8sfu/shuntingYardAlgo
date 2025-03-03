#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack(){
  List();
}

void Stack::push(Node* newNode){
  this->addHead(newNode);
}

Node* Stack::peek(){
  return this->getHead();
}

Node* Stack::pop(){
  Node* temp = this->getHead();
  this->removeHead();
  return temp;
}

void Stack::print(){
  if(this->getHead() != nullptr){
    cout << "Stack:  ";
    this->print();
    cout << endl;
  }
}

Stack::~Stack(){
  
}
