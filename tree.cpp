#include <iostream>
#include "queue.h"
#include "tree.h"

using namespace std;

Tree::Tree(Queue* postfix){
  root = new Stack();
  Node* addNode;
  Node* leftChild;
  Node* rightChild;
  while(postfix->isNotEmpty()){
    addNode = postfix->dequeue();
    //cout << "dequeued " << addNode->getValue() << " from postfix" << endl;
    if(addNode->isOperator()){
      rightChild = root->pop();
      //cout << "right child of " << addNode->getValue() << " is " << rightChild->getValue() << endl;
      leftChild = root->pop();
      //cout << "left child of " << addNode->getValue() << " is " << leftChild->getValue() << endl;
      addNode->setLeft(leftChild);
      addNode->setRight(rightChild);
    }
    root->push(addNode);
    //cout << "pushed " << root->peek()->getValue() << " to root" << endl;
  }
  root->print();
}

void Tree::printPrefix(){
  
}

void Tree::printInfix(){
  
}

void Tree::printPostfix(){
  
}
