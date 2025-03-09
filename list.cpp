#include <iostream>

#include "list.h"

using namespace std;

List::List(){
  first = nullptr;
}

bool List::firstNull(){
  if(first == nullptr){
    return true;
  }
  return false;
}

void List::addHead(Node* newNode){
  newNode->setNext(first);
  first = newNode;
}

void List::addTail(Node* newNode){
  Node* temp = first;
  while(temp->getNext() != nullptr){
    temp = temp->getNext();
  }
  temp->setNext(newNode);
}

Node* List::getHead(){
    return first;
}

Node* List::getTail(){
  Node* temp = first;
  while(temp->getNext() != nullptr){
    temp = temp->getNext();
  }
  return temp;
}

void List::removeHead(){
  if(first != nullptr){

    first = first->getNext();

  }
}

void List::removeTail(){
  Node* temp = first;
  if(first->getNext() == nullptr){
    first = nullptr;
  }else{
    while(temp->getNext()->getNext() != nullptr){
      temp = temp->getNext();
    }
    temp->setNext(nullptr);
  }
}

void List::printList(){
  if(first != nullptr){
    first->print();
  }
}

List::~List(){
  delete[] first;
}


