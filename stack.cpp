#include <iostream>
#include "stack.h"
#include "list.h"

using namespace std;

Stack::Stack(){
  List();
}

bool Stack::isNotEmpty(){
  if(this->firstNull()){
    return false;
  }
  return true;
}

void Stack::push(Node* newNode){
  this->addHead(newNode);
}

Node* Stack::peek(){
  return this->getHead();
}

Node* Stack::pop(){
  // if(this->getHead() != nullptr){
    Node* temp = this->getHead();
    this->removeHead();
    return temp;
    // }
}

void Stack::print(){
  if(this->getHead() != nullptr){
    cout << "Stack:  ";
    this->printList();
    cout << endl;
  }
}

Stack::~Stack(){

}
