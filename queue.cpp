#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue(){
  List();
}

bool Queue::isNotEmpty(){
  if(this->firstNull()){
    return false;
  }
  return true;
}

void Queue::enqueue(Node* newNode){
  this->addHead(newNode);
}

Node* Queue::dequeue(){
  // if(this->getTail() != nullptr){
    Node* temp = this->getTail();
    this->removeTail();
    return temp;
    // }
}

void Queue::print(){
  if(this->getHead() != nullptr){
    cout << "Queue:  ";
    this->printList();
    cout << endl;
  }
}

Queue::~Queue(){
  
}
